#ifndef UBX_PARSER_H
#define UBX_PARSER_H

#include <stdint.h>

struct ubx_nav_timels {
    uint8_t version;
    uint8_t reserved1;
    uint8_t srcOfCurrLs;
    uint8_t currLs;
    uint16_t reserved2;
    int32_t lsChange;
    uint32_t timeToLsEvent;
    uint16_t dateOfLsGpsWn;
    uint16_t dateOfLsGpsDn;
    uint8_t reserved3;
    uint8_t valid;
};

void parse_ubx_nav_timels(uint8_t *data, size_t len, struct ubx_nav_timels *timels);

#endif /* UBX_PARSER_H */
