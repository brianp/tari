// Copyright 2024 The Tari Project
// SPDX-License-Identifier: BSD-3-Clause

use ledger_device_sdk::io::Comm;
use tari_crypto::ristretto::RistrettoPublicKey;
use zeroize::Zeroizing;

use crate::{utils::get_key_from_canonical_bytes, AppSW, RESPONSE_VERSION};

pub struct MetadataSigMessageCtx {
    receiver_address: Option<Zeroizing<RistrettoPublicKey>>,
}

// Implement constructor for TxInfo with default values
impl MetadataSigMessageCtx {
    pub fn new() -> Self {
        Self { receiver_address: None }
    }

    // Implement reset for TxInfo
    fn reset(&mut self) {
        self.receiver_address = None;
    }
}

pub fn handler_set_one_sided_metadata_signature_message(
    comm: &mut Comm,
    chunk_number: u8,
    more: bool,
    message_ctx: &mut MetadataSigMessageCtx,
) -> Result<(), AppSW> {
    let data = comm.get_data().map_err(|_| AppSW::WrongApduLength)?;

    if chunk_number == 0 {
        message_ctx.receiver_address = Some(get_key_from_canonical_bytes::<RistrettoPublicKey>(&data[0..32])?.into());
    }

    comm.append(&[RESPONSE_VERSION]); // version
    message_ctx.reset();
    comm.reply_ok();

    Ok(())
}
