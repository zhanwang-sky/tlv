//
//  tlv.h
//  tlv
//
//  Created by jichen on 2022/1/19.
//

#ifndef tlv_h
#define tlv_h

#include <stdbool.h>
#include <stdint.h>

typedef void (*tlv_read_cb_t)(const uint8_t *buf, uint16_t len);
typedef uint16_t (*tlv_write_cb_t)(uint8_t *buf, uint16_t len);

typedef struct tlv_handler {
    tlv_read_cb_t read_cb;
    tlv_write_cb_t write_cb;
} tlv_handler_t;

// @RETVAL pointing to handler on success, NULL on error
tlv_handler_t *tlv_register_handler(uint8_t type, tlv_handler_t *handler);

// @RETVAL body length, -1 on error
int16_t tlv_read_header(const uint8_t *buf, uint16_t len);

// @RETVAL bytes remaining, -1 on error
int16_t tlv_read_body(const uint8_t *buf, uint16_t len, bool first);

// @RETVAL bytes to write, -1 on error
int16_t tlv_write_body(uint8_t *buf, uint16_t len, bool first);

// @RETVAL header length, -1 on error
int16_t tlv_write_header(uint8_t *buf, uint16_t len);

#endif /* tlv_h */
