/*
 * Generated by the protobluff compiler - do not edit.
 * ----------------------------------------------------------------------------
 * Date:     03/29/16 14:06:32
 * Filename: payload.proto
 * Package:  -
 * ----------------------------------------------------------------------------
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef PAYLOAD_PB_H
#define PAYLOAD_PB_H

#include <protobluff.h>

#if PB_VERSION != 4000000
  #error version mismatch - please regenerate this file using protoc
#endif

/* ----------------------------------------------------------------------------
 * Tags
 * ------------------------------------------------------------------------- */

/* MapEntry : tags */
#define MAPENTRY_KEY_T 1
#define MAPENTRY_VALUE_T 2

/* Payload : tags */
#define PAYLOAD_CORE_T 1
#define PAYLOAD_PID_T 2
#define PAYLOAD_TID_T 3
#define PAYLOAD_TIMESTAMP_T 4
#define PAYLOAD_COUNTERS_T 5
#define PAYLOAD_TRACES_T 6

/* ----------------------------------------------------------------------------
 * Descriptors
 * ------------------------------------------------------------------------- */

/* MapEntry : descriptor */
extern pb_descriptor_t
mapentry_descriptor;

/* Payload : descriptor */
extern pb_descriptor_t
payload_descriptor;

/* ----------------------------------------------------------------------------
 * Decoders
 * ------------------------------------------------------------------------- */

/* MapEntry : create */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_decoder_t
mapentry_decoder_create(
    const pb_buffer_t *buffer) {
  return pb_decoder_create(
    &mapentry_descriptor, buffer);
}

/* MapEntry : decode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
mapentry_decode(
    pb_decoder_t *decoder, pb_decoder_handler_f handler, void *user) {
  assert(pb_decoder_descriptor(decoder) == 
    &mapentry_descriptor);
  return pb_decoder_decode(decoder, handler, user);
}

/* MapEntry : destroy */
PB_INLINE void
mapentry_decoder_destroy(
    pb_decoder_t *decoder) {
  assert(pb_decoder_descriptor(decoder) == 
    &mapentry_descriptor);
  return pb_decoder_destroy(decoder);
}

/* Payload : create */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_decoder_t
payload_decoder_create(
    const pb_buffer_t *buffer) {
  return pb_decoder_create(
    &payload_descriptor, buffer);
}

/* Payload : decode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_decode(
    pb_decoder_t *decoder, pb_decoder_handler_f handler, void *user) {
  assert(pb_decoder_descriptor(decoder) == 
    &payload_descriptor);
  return pb_decoder_decode(decoder, handler, user);
}

/* Payload : destroy */
PB_INLINE void
payload_decoder_destroy(
    pb_decoder_t *decoder) {
  assert(pb_decoder_descriptor(decoder) == 
    &payload_descriptor);
  return pb_decoder_destroy(decoder);
}

/* ----------------------------------------------------------------------------
 * Encoders
 * ------------------------------------------------------------------------- */

/* MapEntry : create */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_encoder_t
mapentry_encoder_create(void) {
  return pb_encoder_create(
    &mapentry_descriptor);
}

/* MapEntry : create with allocator */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_encoder_t
mapentry_encoder_create_with_allocator(
    pb_allocator_t *allocator) {
  return pb_encoder_create_with_allocator(
    allocator, &mapentry_descriptor);
}

/* MapEntry : destroy */
PB_INLINE void
mapentry_encoder_destroy(
    pb_encoder_t *encoder) {
  assert(pb_encoder_descriptor(encoder) == 
    &mapentry_descriptor);
  return pb_encoder_destroy(encoder);
}

/* MapEntry.key : encode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
mapentry_encode_key(
    pb_encoder_t *encoder, const pb_string_t *value) {
  assert(pb_encoder_descriptor(encoder) == 
    &mapentry_descriptor);
  return pb_encoder_encode(encoder, 1, value, 1);
}

/* MapEntry.value : encode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
mapentry_encode_value(
    pb_encoder_t *encoder, const uint64_t *value) {
  assert(pb_encoder_descriptor(encoder) == 
    &mapentry_descriptor);
  return pb_encoder_encode(encoder, 2, value, 1);
}

/* Payload : create */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_encoder_t
payload_encoder_create(void) {
  return pb_encoder_create(
    &payload_descriptor);
}

/* Payload : create with allocator */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_encoder_t
payload_encoder_create_with_allocator(
    pb_allocator_t *allocator) {
  return pb_encoder_create_with_allocator(
    allocator, &payload_descriptor);
}

/* Payload : destroy */
PB_INLINE void
payload_encoder_destroy(
    pb_encoder_t *encoder) {
  assert(pb_encoder_descriptor(encoder) == 
    &payload_descriptor);
  return pb_encoder_destroy(encoder);
}

/* Payload.core : encode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_encode_core(
    pb_encoder_t *encoder, const uint32_t *value) {
  assert(pb_encoder_descriptor(encoder) == 
    &payload_descriptor);
  return pb_encoder_encode(encoder, 1, value, 1);
}

/* Payload.pid : encode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_encode_pid(
    pb_encoder_t *encoder, const uint32_t *value) {
  assert(pb_encoder_descriptor(encoder) == 
    &payload_descriptor);
  return pb_encoder_encode(encoder, 2, value, 1);
}

/* Payload.tid : encode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_encode_tid(
    pb_encoder_t *encoder, const uint32_t *value) {
  assert(pb_encoder_descriptor(encoder) == 
    &payload_descriptor);
  return pb_encoder_encode(encoder, 3, value, 1);
}

/* Payload.timestamp : encode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_encode_timestamp(
    pb_encoder_t *encoder, const uint64_t *value) {
  assert(pb_encoder_descriptor(encoder) == 
    &payload_descriptor);
  return pb_encoder_encode(encoder, 4, value, 1);
}

/* Payload.counters : encode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_encode_counters(
    pb_encoder_t *encoder, const pb_encoder_t *value, size_t size) {
  assert(pb_encoder_descriptor(encoder) == 
    &payload_descriptor);
  return pb_encoder_encode(encoder, 5, value, size);
}

/* Payload.traces : encode */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_encode_traces(
    pb_encoder_t *encoder, const pb_string_t *value, size_t size) {
  assert(pb_encoder_descriptor(encoder) == 
    &payload_descriptor);
  return pb_encoder_encode(encoder, 6, value, size);
}

/* ----------------------------------------------------------------------------
 * Accessors
 * ------------------------------------------------------------------------- */

/* MapEntry : create */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_message_t
mapentry_create(
    pb_journal_t *journal) {
  return pb_message_create(
    &mapentry_descriptor, journal);
}

/* MapEntry : destroy */
PB_INLINE void
mapentry_destroy(
    pb_message_t *message) {
  assert(pb_message_descriptor(message) == 
    &mapentry_descriptor);
  return pb_message_destroy(message);
}

/* MapEntry.key : get */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
mapentry_get_key(
    pb_message_t *message, pb_string_t *value) {
  assert(pb_message_descriptor(message) == 
    &mapentry_descriptor);
  return pb_message_get(message, 1, value);
}

/* MapEntry.key : put */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
mapentry_put_key(
    pb_message_t *message, const pb_string_t *value) {
  assert(pb_message_descriptor(message) == 
    &mapentry_descriptor);
  return pb_message_put(message, 1, value);
}

/* MapEntry.value : get */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
mapentry_get_value(
    pb_message_t *message, uint64_t *value) {
  assert(pb_message_descriptor(message) == 
    &mapentry_descriptor);
  return pb_message_get(message, 2, value);
}

/* MapEntry.value : put */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
mapentry_put_value(
    pb_message_t *message, const uint64_t *value) {
  assert(pb_message_descriptor(message) == 
    &mapentry_descriptor);
  return pb_message_put(message, 2, value);
}

/* Payload : create */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_message_t
payload_create(
    pb_journal_t *journal) {
  return pb_message_create(
    &payload_descriptor, journal);
}

/* Payload : destroy */
PB_INLINE void
payload_destroy(
    pb_message_t *message) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_destroy(message);
}

/* Payload.core : get */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_get_core(
    pb_message_t *message, uint32_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_get(message, 1, value);
}

/* Payload.core : put */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_put_core(
    pb_message_t *message, const uint32_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_put(message, 1, value);
}

/* Payload.pid : get */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_get_pid(
    pb_message_t *message, uint32_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_get(message, 2, value);
}

/* Payload.pid : put */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_put_pid(
    pb_message_t *message, const uint32_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_put(message, 2, value);
}

/* Payload.tid : get */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_get_tid(
    pb_message_t *message, uint32_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_get(message, 3, value);
}

/* Payload.tid : put */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_put_tid(
    pb_message_t *message, const uint32_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_put(message, 3, value);
}

/* Payload.timestamp : get */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_get_timestamp(
    pb_message_t *message, uint64_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_get(message, 4, value);
}

/* Payload.timestamp : put */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_put_timestamp(
    pb_message_t *message, const uint64_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_put(message, 4, value);
}

/* Payload.counters : has */
PB_INLINE int
payload_has_counters(
    pb_message_t *message) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_has(message, 5);
}

/* Payload.counters : create */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_message_t
payload_create_counters(
    pb_message_t *message) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_create_within(message, 5);
}

/* Payload.counters : cursor.create */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_cursor_t
payload_create_counters_cursor(
    pb_message_t *message) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_cursor_create(message, 5);
}

/* Payload.traces : has */
PB_INLINE int
payload_has_traces(
    pb_message_t *message) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_has(message, 6);
}

/* Payload.traces : put */
PB_WARN_UNUSED_RESULT
PB_INLINE pb_error_t
payload_put_traces(
    pb_message_t *message, const pb_string_t *value) {
  assert(pb_message_descriptor(message) == 
    &payload_descriptor);
  return pb_message_put(message, 6, value);
}

#endif /* PAYLOAD_PB_H */