#include "packet_interface.h"

#include <stdlib.h>
#include <stdio.h>
/* Extra #includes */
/* Your code will be inserted here */

struct __attribute__((__packed__)) pkt {
	/* Your code will be inserted here */
	const ptypes_t type;
	const uint8_t window;
	const uint8_t seqnum;
	const uint16_t length;
	char* payload;
	const uint32_t crc;
};
/* Extra code */
/* Your code will be inserted here */

pkt_t* pkt_new()
{
	/* Your code will be inserted here */
	pkt_t *pkt = (pkt_t *)malloc(sizeof(pkt_t));
	return pkt;
}

void pkt_del(pkt_t *pkt)
{
    /* Your code will be inserted here */
    free(pkt);
}

pkt_status_code pkt_decode(const char *data, const size_t len, pkt_t *pkt)
{
	/* Your code will be inserted here */
}

pkt_status_code pkt_encode(const pkt_t* pkt, char *buf, size_t *len)
{
	/* Your code will be inserted here */
}

ptypes_t pkt_get_type  (const pkt_t *pkt)
{
	/* Your code will be inserted here */
	return pkt->type;
}

uint8_t  pkt_get_window(const pkt_t *pkt)
{
	/* Your code will be inserted here */
	return pkt->window;
}

uint8_t  pkt_get_seqnum(const pkt_t *pkt)
{
	/* Your code will be inserted here */
	return pkt->seqnum;
}

uint16_t pkt_get_length(const pkt_t *pkt)
{
	/* Your code will be inserted here */
	return pkt->length;
}

uint32_t pkt_get_crc   (const pkt_t *pkt)
{
	/* Your code will be inserted here */
	return pkt->crc;
}

const char* pkt_get_payload(const pkt_t *pkt)
{
	/* Your code will be inserted here */
	return pkt->payload;
}


pkt_status_code pkt_set_type(pkt_t *pkt, const ptypes_t type)
{
	/* Your code will be inserted here */
	if(type == 1 || type == 2 || type == 4){
	pkt->type = type;
	return PKT_OK;
	}
	else{
	return E_TYPE;
	}
}
//peut retourner E_WINDOW |PKT_OK
pkt_status_code pkt_set_window(pkt_t *pkt, const uint8_t window)
{
	/* Your code will be inserted here */
	if(window >= 1 && window <= 31){
	pkt->window = window;
	return PKT_OK;
	}
	else{
	return E_WINDOW;
	}
}
//peut retourner E_SEQNUM |PKT_OK
pkt_status_code pkt_set_seqnum(pkt_t *pkt, const uint8_t seqnum)
{
	/* Your code will be inserted here */
	if(seqnum >= 0 && seqnum <= 255){
	pkt->seqnum = seqnum;
	return PKT_OK;
	}
	else{
	return E_SEQNUM;
	}
}
//peut retourner E_LENGTH |PKT_OK
pkt_status_code pkt_set_length(pkt_t *pkt, const uint16_t length)
{
	/* Your code will be inserted here */
	if(length >= 0 && length <= 512){
	pkt->length = length;
	return PKT_OK;
	}
	else{
	return E_LENGTH;
	}
}
//peut retourner E_CRC | PKT_OK
pkt_status_code pkt_set_crc(pkt_t *pkt, const uint32_t crc)
{
	/* Your code will be inserted here */
}
//peut retourner
pkt_status_code pkt_set_payload(pkt_t *pkt,
							    const char *data,
								const uint16_t length)
{
	/* Your code will be inserted here */
}
