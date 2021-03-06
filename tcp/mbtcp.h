/*
 * FreeModbus Libary: A portable Modbus implementation for Modbus ASCII/RTU.
 * Copyright (c) 2016, 2017 Nucleron R&D LLC <main@nucleron.ru>
 * Copyright (c) 2006 Christian Walter <wolti@sil.at>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * File: $Id: mbtcp.h,v 1.2 2006/12/07 22:10:34 wolti Exp $
 */

#ifndef _MB_TCP_H
#define _MB_TCP_H

#ifdef __cplusplus
PR_BEGIN_EXTERN_C
#endif
#include "mb_types.h"
typedef struct
{
    mb_trans_base_struct                   base;
    //MBTCPPortInstance tcp_port;
    BOOL is_master;
    USHORT snd_pdu_len;
    //BOOL xFrameIsBroadcast;
} mb_tcp_tr;
/* ----------------------- Defines ------------------------------------------*/
#define MB_TCP_PSEUDO_ADDRESS   255
extern const mb_tr_mtab mb_tcp_mtab;
/* ----------------------- Function prototypes ------------------------------*/
mb_err_enum	mb_tcp_init       (mb_tcp_tr *inst, USHORT tcp_port_num, SOCKADDR_IN hostaddr, BOOL is_master     );
void        mb_tcp_start      (mb_tcp_tr *inst                                                                );
void        mb_tcp_stop       (mb_tcp_tr *inst                                                                );
mb_err_enum mb_tcp_receive    (mb_tcp_tr *inst, UCHAR * rcv_addr_buf, UCHAR ** frame_ptr_buf, USHORT *len_buf);
mb_err_enum mb_tcp_send       (mb_tcp_tr *inst, UCHAR _unused, const UCHAR *frame_ptr, USHORT len            );
void        mb_tcp_get_rcv_buf(mb_tcp_tr *inst, UCHAR ** frame_ptr_buf                                        );
void        mb_tcp_get_snd_buf(mb_tcp_tr *inst, UCHAR ** frame_ptr_buf                                        );
BOOL        mb_tcp_rq_is_bcast(mb_tcp_tr *inst                                                                );
#ifdef __cplusplus
PR_END_EXTERN_C
#endif
#endif
