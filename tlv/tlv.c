//
//  tlv.c
//  tlv
//
//  Created by jichen on 2022/1/19.
//

#include "tlv.h"

static tlv_handler_t *tlv_map[64];
static uint8_t tlv_buf[512];

tlv_handler_t *tlv_register_handler(uint8_t type, tlv_handler_t *handler) {
    if (type >= (sizeof(tlv_map) / sizeof(tlv_map[0]))) {
        return NULL;
    }
    tlv_map[type] = handler;
    return handler;
}
