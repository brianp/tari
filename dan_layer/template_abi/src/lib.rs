//  Copyright 2022. The Tari Project
//
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
//  following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//  disclaimer.
//
//  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
//  following disclaimer in the documentation and/or other materials provided with the distribution.
//
//  3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
//  products derived from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
//  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
//  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//! # Tari WASM module ABI (application binary interface)
//!
//! This library provides types and encoding that allow low-level communication between the Tari WASM runtime and the
//! WASM modules.

mod encoding;
pub mod ops;

use std::collections::HashMap;

pub use borsh::{self, BorshDeserialize as Decode, BorshSerialize as Encode};
pub use encoding::{decode, decode_len, encode, encode_into, encode_with_len};

#[derive(Debug, Clone, Encode, Decode)]
pub struct TemplateDef {
    pub template_name: String,
    pub functions: Vec<FunctionDef>,
}

impl TemplateDef {
    pub fn get_function(&self, name: &str) -> Option<&FunctionDef> {
        self.functions.iter().find(|f| f.name.as_str() == name)
    }
}

#[derive(Debug, Clone, Encode, Decode)]
pub struct FunctionDef {
    pub name: String,
    pub arguments: Vec<Type>,
    pub output: Type,
}

#[derive(Debug, Clone, PartialEq, Eq, Encode, Decode)]
pub enum Type {
    Unit,
    Bool,
    I8,
    I16,
    I32,
    I64,
    I128,
    U8,
    U16,
    U32,
    U64,
    U128,
    String,
}

#[derive(Debug, Clone, Encode, Decode)]
pub struct CallInfo {
    pub func_name: String,
    pub args: Vec<Vec<u8>>,
}

#[derive(Debug, Clone, Encode, Decode)]
pub struct EmitLogArg {
    pub message: String,
    pub level: LogLevel,
}

#[derive(Debug, Clone, Encode, Decode)]
pub enum LogLevel {
    Error,
    Warn,
    Info,
    Debug,
}

#[derive(Debug, Clone, Encode, Decode)]
pub struct CreateComponentArg {
    // asset/component metadata
    pub name: String,
    pub quantity: u64,
    pub metadata: HashMap<Vec<u8>, Vec<u8>>,
    // encoded asset/component state
    pub state: Vec<u8>,
}