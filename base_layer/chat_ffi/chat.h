// Copyright 2023. The Tari Project
// SPDX-License-Identifier: BSD-3-Clause

// This file was generated by cargo-bindgen. Please do not edit manually.

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

struct ApplicationConfig;

struct ChatByteVector;

struct ChatClient;

struct Confirmation;

struct ContactsLivenessData;

struct ContactsServiceHandle;

struct ConversationalistsVector;

struct Message;

struct MessageMetadata;

struct MessageVector;

struct TariAddress;

struct TransportConfig;

typedef void (*CallbackContactStatusChange)(struct ContactsLivenessData*);

typedef void (*CallbackMessageReceived)(struct Message*);

typedef void (*CallbackDeliveryConfirmationReceived)(struct Confirmation*);

typedef void (*CallbackReadConfirmationReceived)(struct Confirmation*);

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Creates a Chat Client
 *
 * ## Arguments
 * `config` - The ApplicationConfig pointer
 * `error_out` - Pointer to an int which will be modified
 * `callback_contact_status_change` - A callback function pointer. this is called whenever a
 * contacts liveness event comes in.
 * `callback_message_received` - A callback function pointer. This is called whenever a chat
 * message is received.
 * `callback_delivery_confirmation_received` - A callback function pointer. This is called when the
 * client receives a confirmation of message delivery.
 * `callback_read_confirmation_received` - A callback function pointer. This is called when the
 * client receives a confirmation of message read.
 *
 * ## Returns
 * `*mut ChatClient` - Returns a pointer to a ChatClient, note that it returns ptr::null_mut()
 * if any error was encountered or if the runtime could not be created.
 *
 * # Safety
 * The ```destroy_chat_client``` method must be called when finished with a ClientFFI to prevent a memory leak
 */
struct ChatClient *create_chat_client(struct ApplicationConfig *config,
                                      int *error_out,
                                      CallbackContactStatusChange callback_contact_status_change,
                                      CallbackMessageReceived callback_message_received,
                                      CallbackDeliveryConfirmationReceived callback_delivery_confirmation_received,
                                      CallbackReadConfirmationReceived callback_read_confirmation_received);

/**
 * Side loads a chat client
 *
 * ## Arguments
 * `config` - The ApplicationConfig pointer
 * `contacts_handler` - A pointer to a contacts handler extracted from the wallet ffi
 * `error_out` - Pointer to an int which will be modified
 * `callback_contact_status_change` - A callback function pointer. this is called whenever a
 * contacts liveness event comes in.
 * `callback_message_received` - A callback function pointer. This is called whenever a chat
 * message is received.
 * `callback_delivery_confirmation_received` - A callback function pointer. This is called when the
 * client receives a confirmation of message delivery.
 * `callback_read_confirmation_received` - A callback function pointer. This is called when the
 * client receives a confirmation of message read.
 *
 * ## Returns
 * `*mut ChatClient` - Returns a pointer to a ChatClient, note that it returns ptr::null_mut()
 * if any error was encountered or if the runtime could not be created.
 *
 * # Safety
 * The ```destroy_chat_client``` method must be called when finished with a ClientFFI to prevent a memory leak
 */
struct ChatClient *sideload_chat_client(struct ApplicationConfig *config,
                                        struct ContactsServiceHandle *contacts_handle,
                                        int *error_out,
                                        CallbackContactStatusChange callback_contact_status_change,
                                        CallbackMessageReceived callback_message_received,
                                        CallbackDeliveryConfirmationReceived callback_delivery_confirmation_received,
                                        CallbackReadConfirmationReceived callback_read_confirmation_received);

/**
 * Frees memory for a ChatClient
 *
 * ## Arguments
 * `ptr` - The pointer of a ChatClient
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_chat_client(struct ChatClient *ptr);

/**
 * Creates a ChatClient config
 *
 * ## Arguments
 * `network` - The network to run on
 * `public_address` - The nodes public address
 * `datastore_path` - The directory for config and db files
 * `identity_file_path` - The location of the identity file
 * `tor_transport_config` - A pointer to the TransportConfig
 * `log_path` - directory for storing log files
 * `log_verbosity` - how verbose should logging be as a c_int 0-5, or 11
 *        0 => Off
 *        1 => Error
 *        2 => Warn
 *        3 => Info
 *        4 => Debug
 *        5 | 11 => Trace // Cranked up to 11
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut ApplicationConfig` - Returns a pointer to an ApplicationConfig
 *
 * # Safety
 * The ```destroy_config``` method must be called when finished with a Config to prevent a memory leak
 */
struct ApplicationConfig *create_chat_config(const char *network_str,
                                             const char *public_address,
                                             const char *datastore_path,
                                             const char *identity_file_path,
                                             struct TransportConfig *tor_transport_config,
                                             const char *log_path,
                                             int log_verbosity,
                                             int *error_out);

/**
 * Frees memory for an ApplicationConfig
 *
 * ## Arguments
 * `ptr` - The pointer of an ApplicationConfig
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_chat_config(struct ApplicationConfig *ptr);

/**
 * Creates a ChatByteVector
 *
 * ## Arguments
 * `byte_array` - The pointer to the byte array
 * `element_count` - The number of elements in byte_array
 * `error_out` - Pointer to an int which will be modified to an error code should one occur, may not be null. Functions
 * as an out parameter.
 *
 * ## Returns
 * `*mut ChatByteVector` - Pointer to the created ChatByteVector. Note that it will be ptr::null_mut()
 * if the byte_array pointer was null or if the elements in the byte_vector don't match
 * element_count when it is created
 *
 * # Safety
 * The ```byte_vector_destroy``` function must be called when finished with a ChatByteVector to prevent a memory leak
 */
struct ChatByteVector *chat_byte_vector_create(const unsigned char *byte_array,
                                               unsigned int element_count,
                                               int *error_out);

/**
 * Frees memory for a ChatByteVector
 *
 * ## Arguments
 * `bytes` - The pointer to a ChatByteVector
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void chat_byte_vector_destroy(struct ChatByteVector *bytes);

/**
 * Gets a c_uchar at position in a ChatByteVector
 *
 * ## Arguments
 * `ptr` - The pointer to a ChatByteVector
 * `position` - The integer position
 * `error_out` - Pointer to an int which will be modified to an error code should one occur, may not be null. Functions
 * as an out parameter.
 *
 * ## Returns
 * `c_uchar` - Returns a character. Note that the character will be a null terminator (0) if ptr
 * is null or if the position is invalid
 *
 * # Safety
 * None
 */
unsigned char chat_byte_vector_get_at(struct ChatByteVector *ptr,
                                      unsigned int position,
                                      int *error_out);

/**
 * Gets the number of elements in a ChatByteVector
 *
 * ## Arguments
 * `ptr` - The pointer to a ChatByteVector
 * `error_out` - Pointer to an int which will be modified to an error code should one occur, may not be null. Functions
 * as an out parameter.
 *
 * ## Returns
 * `c_uint` - Returns the integer number of elements in the ChatByteVector. Note that it will be zero
 * if ptr is null
 *
 * # Safety
 * None
 */
unsigned int chat_byte_vector_get_length(const struct ChatByteVector *vec,
                                         int *error_out);

/**
 * Send a read confirmation for a given message
 *
 * ## Arguments
 * `client` - Pointer to the ChatClient
 * `message` - Pointer to the Message that was read
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * The `client` When done with the ChatClient it should be destroyed
 * The `message` When done with the Message it should be destroyed
 */
void send_read_confirmation_for_message(struct ChatClient *client,
                                        struct Message *message,
                                        int *error_out);

/**
 * Get a pointer to a ChatByteVector representation of the message id associated to the confirmation
 *
 * ## Arguments
 * `confirmation` - A pointer to the Confirmation you'd like to read from
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut ChatByteVector` - A ptr to a ChatByteVector
 *
 * # Safety
 * `confirmation` should be destroyed when finished
 * ```ChatByteVector``` When done with the returned ChatByteVector it should be destroyed
 */
struct ChatByteVector *read_confirmation_message_id(struct Confirmation *confirmation,
                                                    int *error_out);

/**
 * Get a c_ulonglong timestamp for the Confirmation
 *
 * ## Arguments
 * `confirmation` - A pointer to the Confirmation
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_ulonglong` - A uint representation of time since epoch. May return 0 on error
 *
 * # Safety
 * The ```confirmation``` When done with the Confirmation it should be destroyed
 */
unsigned long long read_confirmation_timestamp(struct Confirmation *confirmation, int *error_out);

/**
 * Frees memory for a Confirmation
 *
 * ## Arguments
 * `ptr` - The pointer of a Confirmation
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_confirmation(struct Confirmation *ptr);

/**
 * Add a contact
 *
 * ## Arguments
 * `client` - The ChatClient pointer
 * `address` - A TariAddress ptr
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * The ```receiver``` should be destroyed after use
 */
void add_chat_contact(struct ChatClient *client, struct TariAddress *address, int *error_out);

/**
 * Check the online status of a contact
 *
 * ## Arguments
 * `client` - The ChatClient pointer
 * `address` - A TariAddress ptr
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `status` - Returns an c_uchar representing of the online status
 *            Online = 1,
 *            Offline = 2,
 *            NeverSeen = 3,
 *            Banned = 4,
 *
 * # Safety
 * The ```address``` should be destroyed after use
 */
unsigned char check_online_status(struct ChatClient *client,
                                  struct TariAddress *receiver,
                                  int *error_out);

/**
 * Returns a pointer to a TariAddress
 *
 * ## Arguments
 * `liveness` - A pointer to a ContactsLivenessData struct
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut TariAddress` - A ptr to a TariAddress
 *
 * ## Safety
 * `liveness` should be destroyed eventually
 * the returned `TariAddress` should be destroyed eventually
 */
struct TariAddress *read_liveness_data_address(struct ContactsLivenessData *liveness,
                                               int *error_out);

/**
 * Returns an c_uchar representation of a contacts online status
 *
 * ## Arguments
 * `liveness` - A pointer to a ContactsLivenessData struct
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_uchar` - A c_uchar rep of an enum for a contacts online status. May return 0 if an error occurs
 *     Online => 1
 *     Offline => 2
 *     NeverSeen => 3
 *     Banned => 4
 *
 * ## Safety
 * `liveness` should be destroyed eventually
 */
unsigned char read_liveness_data_online_status(struct ContactsLivenessData *liveness,
                                               int *error_out);

/**
 * Returns an c_longlong representation of a timestamp when the contact was last seen
 *
 * ## Arguments
 * `liveness` - A pointer to a ContactsLivenessData struct
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_ulonglong` - A c_longlong rep of timestamp for a contacts last seen status.
 * 0 if the contact has never been seen or an error occurs.
 *
 * ## Safety
 * `liveness` should be destroyed eventually
 */
unsigned long long read_liveness_data_last_seen(struct ContactsLivenessData *liveness,
                                                int *error_out);

/**
 * Frees memory for a ContactsLivenessData
 *
 * ## Arguments
 * `ptr` - The pointer of a ContactsLivenessData
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_contacts_liveness_data(struct ContactsLivenessData *ptr);

/**
 * Return a ptr to a ConversationalistsVector
 *
 * ## Arguments
 * `client` - The ChatClient
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut ptr ConversationalistsVector` - a pointer to a ConversationalistsVector
 *
 * ## Safety
 * The `ConversationalistsVector` should be destroyed after use
 */
struct ConversationalistsVector *get_conversationalists(struct ChatClient *client, int *error_out);

/**
 * Returns the length of the ConversationalistsVector
 *
 * ## Arguments
 * `conversationalists` - A pointer to a ConversationalistsVector
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_uint` - The length of the vector. May return 0 if something goes wrong
 *
 * ## Safety
 * `conversationalists` should be destroyed eventually
 */
unsigned int conversationalists_vector_len(struct ConversationalistsVector *conversationalists,
                                           int *error_out);

/**
 * Reads the ConversationalistsVector and returns a pointer to a TariAddress at a given position
 *
 * ## Arguments
 * `conversationalists` - A pointer to a ConversationalistsVector
 * `position` - The index of the vector for a TariAddress
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut ptr TariAddress` - A pointer to a TariAddress
 *
 * ## Safety
 * `conversationalists` should be destroyed eventually
 * the returned `TariAddress` should be destroyed eventually
 */
struct TariAddress *conversationalists_vector_get_at(struct ConversationalistsVector *conversationalists,
                                                     unsigned int position,
                                                     int *error_out);

/**
 * Frees memory for ConversationalistsVector
 *
 * ## Arguments
 * `ptr` - The pointer of a ConversationalistsVector
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_conversationalists_vector(struct ConversationalistsVector *ptr);

/**
 * Creates a message and returns a pointer to it
 *
 * ## Arguments
 * `receiver` - A pointer to a TariAddress
 * `message` - A string to send as a text message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut Message` - A pointer to a message object
 *
 * # Safety
 * The ```receiver``` should be destroyed after use
 * The ```Message``` received should be destroyed after use
 */
struct Message *create_chat_message(struct TariAddress *receiver,
                                    const char *message,
                                    int *error_out);

/**
 * Frees memory for Message
 *
 * ## Arguments
 * `ptr` - The pointer of a Message
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_chat_message(struct Message *ptr);

/**
 * Sends a message over a client
 *
 * ## Arguments
 * `client` - The ChatClient pointer
 * `message` - Pointer to a Message struct
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * The ```message``` should be destroyed after use
 */
void send_chat_message(struct ChatClient *client, struct Message *message, int *error_out);

/**
 * Reads the message metadata of a message and returns a ptr to the metadata at the given position
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `position` - The index of the array of metadata
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut MessageMetadata` - A pointer to to MessageMetadata
 *
 * ## Safety
 * `message` should be destroyed eventually
 * the returned `MessageMetadata` should be destroyed eventually
 */
struct MessageMetadata *chat_metadata_get_at(struct Message *message,
                                             unsigned int position,
                                             int *error_out);

/**
 * Returns the length of the Metadata Vector a chat Message contains
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_uint` - The length of the metadata vector for a Message. May return 0 if something goes wrong
 *
 * ## Safety
 * `message` should be destroyed eventually
 */
unsigned int chat_message_metadata_len(struct Message *message, int *error_out);

/**
 * Returns a pointer to a ChatByteVector representing the data of the Message
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut ChatByteVector` - A ptr to a ChatByteVector
 *
 * ## Safety
 * `message` should be destroyed eventually
 * the returned `ChatByteVector` should be destroyed eventually
 */
struct ChatByteVector *read_chat_message_body(struct Message *message, int *error_out);

/**
 * Returns a pointer to a TariAddress
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut TariAddress` - A ptr to a TariAddress
 *
 * ## Safety
 * `message` should be destroyed eventually
 * the returned `TariAddress` should be destroyed eventually
 */
struct TariAddress *read_chat_message_address(struct Message *message, int *error_out);

/**
 * Returns a c_uchar representation of the Direction enum
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_uchar` - A c_uchar rep of the direction enum. May return 0 if anything goes wrong
 *     0 => Inbound
 *     1 => Outbound
 *
 * ## Safety
 * `message` should be destroyed eventually
 */
unsigned char read_chat_message_direction(struct Message *message, int *error_out);

/**
 * Returns a c_ulonglong representation of the stored at timestamp as seconds since epoch
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_ulonglong` - The stored_at timestamp, seconds since epoch. Returns 0 if message is null.
 *
 * ## Safety
 * `message` should be destroyed eventually
 */
unsigned long long read_chat_message_stored_at(struct Message *message, int *error_out);

/**
 * Returns a c_ulonglong representation of the delivery confirmation timestamp as seconds since epoch
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_ulonglong` - The delivery_confirmation_at timestamp, seconds since epoch. Returns 0 if message
 * is null or if no confirmation is stored.
 *
 * ## Safety
 * `message` should be destroyed eventually
 */
unsigned long long read_chat_message_delivery_confirmation_at(struct Message *message,
                                                              int *error_out);

/**
 * Returns a c_ulonglong representation of the read confirmation timestamp as seconds since epoch
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_ulonglong` - The read_confirmation_at timestamp, seconds since epoch. Returns 0 if message is
 * null or if no confirmation is stored.
 *
 * ## Safety
 * `message` should be destroyed eventually
 */
unsigned long long read_chat_message_read_confirmation_at(struct Message *message, int *error_out);

/**
 * Returns a pointer to a ChatByteVector representation of the message_id
 *
 * ## Arguments
 * `message` - A pointer to a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut ChatByteVector` - A ChatByteVector for the message id
 *
 * ## Safety
 * `message` should be destroyed eventually
 * The returned ```ChatByteVector``` should be destroyed eventually
 */
struct ChatByteVector *read_chat_message_id(struct Message *message, int *error_out);

/**
 * Creates message metadata and appends it to a Message
 *
 * ## Arguments
 * `message` - A pointer to a message
 * `metadata_type` - An c_uchar that maps to MessageMetadataType enum
 *     '0' -> Reply
 *     '1' -> TokenRequest
 * `data` - A pointer to a byte vector containing bytes for the data field
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * ## Safety
 * `message` should be destroyed eventually
 */
void add_chat_message_metadata(struct Message *message,
                               unsigned char metadata_type,
                               struct ChatByteVector *data,
                               int *error_out);

/**
 * Returns the c_int representation of a metadata type enum
 *
 * ## Arguments
 * `msg_metadata` - A pointer to a MessageMetadata
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_uchar` - An uint8 that maps to MessageMetadataType enum. May return 0 if something goes wrong
 *     '0' -> Reply
 *     '1' -> TokenRequest
 *     '2' -> Gif
 *     '3' -> Link
 *
 * ## Safety
 * `msg_metadata` should be destroyed eventually
 */
unsigned char read_chat_metadata_type(struct MessageMetadata *msg_metadata, int *error_out);

/**
 * Returns a ptr to a ByteVector
 *
 * ## Arguments
 * `msg_metadata` - A pointer to a MessageMetadata
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut ChatByteVector` - A ptr to a ChatByteVector
 *
 * ## Safety
 * `msg_metadata` should be destroyed eventually
 * the returned `ChatByteVector` should be destroyed eventually
 */
struct ChatByteVector *read_chat_metadata_data(struct MessageMetadata *msg_metadata,
                                               int *error_out);

/**
 * Frees memory for MessageMetadata
 *
 * ## Arguments
 * `ptr` - The pointer of a MessageMetadata
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_chat_message_metadata(struct MessageMetadata *ptr);

/**
 * Get a ptr to all messages from or to an address
 *
 * ## Arguments
 * `client` - The ChatClient pointer
 * `address` - A TariAddress pointer
 * `limit` - The amount of messages you want to fetch. Default to 35, max 2500
 * `page` - The page of results you'd like returned. Default to 0, maximum of u64 max
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut MessageVector` - A pointer to a Vector of Messages
 *
 * # Safety
 * The returned pointer to ```MessageVector``` should be destroyed after use
 * ```client``` should be destroyed after use
 * ```address``` should be destroyed after use
 */
struct MessageVector *get_chat_messages(struct ChatClient *client,
                                        struct TariAddress *address,
                                        unsigned int limit,
                                        unsigned int page,
                                        int *error_out);

/**
 * Returns the length of the MessageVector
 *
 * ## Arguments
 * `messages` - A pointer to a MessageVector
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `c_uint` - The length of the metadata vector for a Message. May return 0 if something goes wrong
 *
 * ## Safety
 * `messages` should be destroyed eventually
 */
unsigned int message_vector_len(struct MessageVector *messages, int *error_out);

/**
 * Reads the MessageVector and returns a Message at a given position
 *
 * ## Arguments
 * `messages` - A pointer to a MessageVector
 * `position` - The index of the vector for a Message
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut ptr Message` - A pointer to a Message
 *
 * ## Safety
 * `messages` should be destroyed eventually
 * the returned `Message` should be destroyed eventually
 */
struct Message *message_vector_get_at(struct MessageVector *messages,
                                      unsigned int position,
                                      int *error_out);

/**
 * Frees memory for MessagesVector
 *
 * ## Arguments
 * `ptr` - The pointer of a MessagesVector
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_message_vector(struct MessageVector *ptr);

/**
 * Creates a tor transport config
 *
 * ## Arguments
 * `control_server_address` - The pointer to a char array
 * `tor_cookie` - The pointer to a ChatByteVector containing the contents of the tor cookie file, can be null
 * `tor_port` - The tor port
 * `tor_proxy_bypass_for_outbound` - Whether tor will use a direct tcp connection for a given bypass address instead of
 * the tor proxy if tcp is available, if not it has no effect
 * `socks_password` - The pointer to a char array containing the socks password, can be null
 * `error_out` - Pointer to an int which will be modified to an error code should one occur, may not be null. Functions
 * as an out parameter.
 *
 * ## Returns
 * `*mut TransportConfig` - Returns a pointer to a tor TransportConfig, null on error.
 *
 * # Safety
 * The ```destroy_chat_tor_transport_config``` method must be called when finished with a TransportConfig to prevent a
 * memory leak
 */
struct TransportConfig *create_chat_tor_transport_config(const char *control_server_address,
                                                         const struct ChatByteVector *tor_cookie,
                                                         unsigned short tor_port,
                                                         bool tor_proxy_bypass_for_outbound,
                                                         const char *socks_username,
                                                         const char *socks_password,
                                                         int *error_out);

/**
 * Frees memory for a TransportConfig
 *
 * ## Arguments
 * `ptr` - The pointer to a TransportConfig
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_chat_tor_transport_config(struct TransportConfig *ptr);

/**
 * Creates a TariAddress and returns a ptr
 *
 * ## Arguments
 * `receiver_c_char` - A string containing a tari address hex value
 * `error_out` - Pointer to an int which will be modified
 *
 * ## Returns
 * `*mut TariAddress` - A ptr to a TariAddress
 *
 * # Safety
 * The ```destroy_tari_address``` function should be called when finished with the TariAddress
 */
struct TariAddress *create_tari_address(const char *receiver_c_char, int *error_out);

/**
 * Frees memory for a TariAddress
 *
 * ## Arguments
 * `address` - The pointer of a TariAddress
 *
 * ## Returns
 * `()` - Does not return a value, equivalent to void in C
 *
 * # Safety
 * None
 */
void destroy_tari_address(struct TariAddress *address);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
