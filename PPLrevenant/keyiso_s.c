

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for keyiso.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/

#include <string.h>
#include "keyiso_h.h"

#define TYPE_FORMAT_STRING_SIZE   93                                
#define PROC_FORMAT_STRING_SIZE   1387                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _keyiso_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } keyiso_MIDL_TYPE_FORMAT_STRING;

typedef struct _keyiso_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } keyiso_MIDL_PROC_FORMAT_STRING;

typedef struct _keyiso_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } keyiso_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax_2_0 = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax_1_0 = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};

#if defined(_CONTROL_FLOW_GUARD_XFG)
#define XFG_TRAMPOLINES(ObjectType)\
NDR_SHAREABLE unsigned long ObjectType ## _UserSize_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize(pFlags, Offset, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserMarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserUnmarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE void ObjectType ## _UserFree_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree(pFlags, (ObjectType *)pObject);\
}
#define XFG_TRAMPOLINES64(ObjectType)\
NDR_SHAREABLE unsigned long ObjectType ## _UserSize64_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize64(pFlags, Offset, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserMarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal64(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserUnmarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal64(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE void ObjectType ## _UserFree64_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree64(pFlags, (ObjectType *)pObject);\
}
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)\
static void* ObjectType ## _bind_XFG(HandleType pObject)\
{\
return ObjectType ## _bind((ObjectType) pObject);\
}\
static void ObjectType ## _unbind_XFG(HandleType pObject, handle_t ServerHandle)\
{\
ObjectType ## _unbind((ObjectType) pObject, ServerHandle);\
}
#define XFG_TRAMPOLINE_FPTR(Function) Function ## _XFG
#define XFG_TRAMPOLINE_FPTR_DEPENDENT_SYMBOL(Symbol) Symbol ## _XFG
#else
#define XFG_TRAMPOLINES(ObjectType)
#define XFG_TRAMPOLINES64(ObjectType)
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)
#define XFG_TRAMPOLINE_FPTR(Function) Function
#define XFG_TRAMPOLINE_FPTR_DEPENDENT_SYMBOL(Symbol) Symbol
#endif


extern const keyiso_MIDL_TYPE_FORMAT_STRING keyiso__MIDL_TypeFormatString;
extern const keyiso_MIDL_PROC_FORMAT_STRING keyiso__MIDL_ProcFormatString;
extern const keyiso_MIDL_EXPR_FORMAT_STRING keyiso__MIDL_ExprFormatString;

/* Standard interface: keyiso, ver. 2.0,
   GUID={0xb25a52bf,0xe5dd,0x4f4a,{0xae,0xa6,0x8c,0xa7,0x27,0x2a,0x0e,0x86}} */


extern const MIDL_SERVER_INFO keyiso_ServerInfo;

extern const RPC_DISPATCH_TABLE keyiso_v2_0_DispatchTable;

static const RPC_SERVER_INTERFACE keyiso___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0xb25a52bf,0xe5dd,0x4f4a,{0xae,0xa6,0x8c,0xa7,0x27,0x2a,0x0e,0x86}},{2,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&keyiso_v2_0_DispatchTable,
    0,
    0,
    0,
    &keyiso_ServerInfo,
    0x06000000
    };
RPC_IF_HANDLE keyiso_v2_0_s_ifspec = (RPC_IF_HANDLE)& keyiso___RpcServerInterface;
#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC keyiso_StubDesc;
#ifdef __cplusplus
}
#endif

extern const NDR_RUNDOWN RundownRoutines[];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const keyiso_MIDL_PROC_FORMAT_STRING keyiso__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure s_SrvRpcCreateContext */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	NdrFcShort( 0x40 ),	/* 64 */
/* 18 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 20 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 30 */	NdrFcShort( 0x110 ),	/* Flags:  out, simple ref, */
/* 32 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcReleaseContext */

/* 42 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x1 ),	/* 1 */
/* 50 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 52 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 54 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 56 */	NdrFcShort( 0x38 ),	/* 56 */
/* 58 */	NdrFcShort( 0x40 ),	/* 64 */
/* 60 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 62 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 72 */	NdrFcShort( 0x118 ),	/* Flags:  in, out, simple ref, */
/* 74 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 76 */	NdrFcShort( 0xe ),	/* Type Offset=14 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptOpenStorageProvider */

/* 84 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x2 ),	/* 2 */
/* 92 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 94 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 98 */	NdrFcShort( 0x2c ),	/* 44 */
/* 100 */	NdrFcShort( 0x2c ),	/* 44 */
/* 102 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 104 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 114 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 116 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 118 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter hProvider */

/* 120 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 122 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 124 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pszProviderName */

/* 126 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 128 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 130 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter dwFlags */

/* 132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 134 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptIsAlgSupported */

/* 144 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x3 ),	/* 3 */
/* 152 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 154 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 156 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 162 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 164 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptEnumAlgorithms */

/* 180 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x4 ),	/* 4 */
/* 188 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 190 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 192 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x8 ),	/* 8 */
/* 198 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 200 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 212 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptEnumKeys */

/* 216 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x5 ),	/* 5 */
/* 224 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 226 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 228 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 230 */	NdrFcShort( 0x60 ),	/* 96 */
/* 232 */	NdrFcShort( 0x2c ),	/* 44 */
/* 234 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 236 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 246 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 248 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 250 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter hProvider */

/* 252 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 254 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 256 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pszScope */

/* 258 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 260 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 262 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Parameter ppKeyName */

/* 264 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 266 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 268 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */

	/* Parameter ppEnumState */

/* 270 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 272 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 274 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter dwFlags */

/* 276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 278 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptFreeBuffer */

/* 288 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x6 ),	/* 6 */
/* 296 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 298 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 300 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 302 */	NdrFcShort( 0x34 ),	/* 52 */
/* 304 */	NdrFcShort( 0x8 ),	/* 8 */
/* 306 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 308 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 318 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 320 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 322 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter hBuffer */

/* 324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 326 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 328 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 332 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptFreeProvider */

/* 336 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0x7 ),	/* 7 */
/* 344 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 346 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 348 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 350 */	NdrFcShort( 0x34 ),	/* 52 */
/* 352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 354 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 356 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 366 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 368 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 370 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter hProvider */

/* 372 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 374 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 376 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 380 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptFreeKey */

/* 384 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 392 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 394 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 396 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 398 */	NdrFcShort( 0x44 ),	/* 68 */
/* 400 */	NdrFcShort( 0x8 ),	/* 8 */
/* 402 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 404 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 414 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 416 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 418 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter hProvider */

/* 420 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 422 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 424 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter hKey */

/* 426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 428 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 430 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 434 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptOpenKey */

/* 438 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x9 ),	/* 9 */
/* 446 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 448 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 450 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 456 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 458 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 470 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptCreatePersistedKey */

/* 474 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0xa ),	/* 10 */
/* 482 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 484 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 486 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 488 */	NdrFcShort( 0x44 ),	/* 68 */
/* 490 */	NdrFcShort( 0x2c ),	/* 44 */
/* 492 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 494 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 504 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 506 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 508 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter hProvider */

/* 510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 512 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 514 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter phKey */

/* 516 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 518 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 520 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pszAlgId */

/* 522 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 524 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 526 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter pszKeyName */

/* 528 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 530 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 532 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Parameter dwLegacyKeySpec */

/* 534 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 536 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwFlags */

/* 540 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 542 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 548 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptGetProviderProperty */

/* 552 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0xb ),	/* 11 */
/* 560 */	NdrFcShort( 0x48 ),	/* X64 Stack size/offset = 72 */
/* 562 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 564 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 566 */	NdrFcShort( 0x44 ),	/* 68 */
/* 568 */	NdrFcShort( 0x24 ),	/* 36 */
/* 570 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 572 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 574 */	NdrFcShort( 0x1 ),	/* 1 */
/* 576 */	NdrFcShort( 0x1 ),	/* 1 */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 582 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 584 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 586 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter hProvider */

/* 588 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 590 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 592 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pszPropertyName */

/* 594 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 596 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 598 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter pBuffer */

/* 600 */	NdrFcShort( 0x1b ),	/* Flags:  must size, must free, in, out, */
/* 602 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 604 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Parameter cbBuffer */

/* 606 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 608 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbWritten */

/* 612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 614 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwFlags */

/* 618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 620 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 626 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptSetProviderProperty */

/* 630 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0xc ),	/* 12 */
/* 638 */	NdrFcShort( 0x40 ),	/* X64 Stack size/offset = 64 */
/* 640 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 642 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 644 */	NdrFcShort( 0x44 ),	/* 68 */
/* 646 */	NdrFcShort( 0x8 ),	/* 8 */
/* 648 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 650 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x1 ),	/* 1 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hContext */

/* 660 */	NdrFcShort( 0x8 ),	/* Flags:  in, */
/* 662 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 664 */	NdrFcShort( 0x12 ),	/* Type Offset=18 */

	/* Parameter hProvider */

/* 666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 668 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 670 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pszPropertyName */

/* 672 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 674 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 676 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter pBuffer */

/* 678 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 680 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 682 */	NdrFcShort( 0x48 ),	/* Type Offset=72 */

	/* Parameter cbBuffer */

/* 684 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 686 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwFlags */

/* 690 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 692 */	NdrFcShort( 0x30 ),	/* X64 Stack size/offset = 48 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 698 */	NdrFcShort( 0x38 ),	/* X64 Stack size/offset = 56 */
/* 700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptGetKeyProperty */

/* 702 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0xd ),	/* 13 */
/* 710 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 712 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 714 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x8 ),	/* 8 */
/* 720 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 722 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 734 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptSetKeyProperty */

/* 738 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0xe ),	/* 14 */
/* 746 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 748 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 750 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x8 ),	/* 8 */
/* 756 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 758 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 770 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptFinalizeKey */

/* 774 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0xf ),	/* 15 */
/* 782 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 784 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 786 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 792 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 794 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 806 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptEncrypt */

/* 810 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x10 ),	/* 16 */
/* 818 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 820 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 828 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 830 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 842 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptDecrypt */

/* 846 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x11 ),	/* 17 */
/* 854 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 856 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 858 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 864 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 866 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 878 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptImportKey */

/* 882 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x12 ),	/* 18 */
/* 890 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 892 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 894 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 902 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 914 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptExportKey */

/* 918 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x13 ),	/* 19 */
/* 926 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 928 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 930 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 936 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 938 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 950 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptSignHash */

/* 954 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x14 ),	/* 20 */
/* 962 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 964 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 966 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 972 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 974 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 986 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptVerifySignature */

/* 990 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x15 ),	/* 21 */
/* 998 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1000 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1002 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1008 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1010 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptDeleteKey */

/* 1026 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1034 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1036 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1038 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1046 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1058 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptNotifyChangeKey */

/* 1062 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1070 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1072 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1074 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1080 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1082 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptSecretAgreement */

/* 1098 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1106 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1108 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1110 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1116 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1118 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1130 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptDeriveKey */

/* 1134 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1142 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1144 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1146 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1152 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1154 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1166 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptFreeSecret */

/* 1170 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1178 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1180 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1182 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1190 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1202 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptCipherEncrypt */

/* 1206 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1214 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1216 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1218 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1224 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1226 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1238 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptCipherDecrypt */

/* 1242 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1250 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1252 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1254 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1274 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptKeyDerivation */

/* 1278 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1286 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1288 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1290 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1296 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1298 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1310 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptCreateClaim */

/* 1314 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1322 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1324 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1326 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1332 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1334 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1346 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure s_SrvRpcCryptVerifyClaim */

/* 1350 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 1352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1358 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 1360 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 1362 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 1364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1368 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1370 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const keyiso_MIDL_TYPE_FORMAT_STRING keyiso__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	0x30,		/* FC_BIND_CONTEXT */
			0xa0,		/* Ctxt flags:  via ptr, out, */
/*  8 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 10 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 12 */	NdrFcShort( 0x2 ),	/* Offset= 2 (14) */
/* 14 */	0x30,		/* FC_BIND_CONTEXT */
			0xe0,		/* Ctxt flags:  via ptr, in, out, */
/* 16 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 18 */	0x30,		/* FC_BIND_CONTEXT */
			0x41,		/* Ctxt flags:  in, can't be null */
/* 20 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 22 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 24 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 26 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 28 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 30 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 32 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 34 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 36 */	NdrFcShort( 0x2 ),	/* Offset= 2 (38) */
/* 38 */	
			0x12, 0x0,	/* FC_UP */
/* 40 */	NdrFcShort( 0x2 ),	/* Offset= 2 (42) */
/* 42 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 44 */	NdrFcShort( 0x18 ),	/* 24 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* Offset= 8 (56) */
/* 50 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 52 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 54 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 56 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 58 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 60 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 62 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 64 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 66 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 68 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 70 */	NdrFcShort( 0x2 ),	/* Offset= 2 (72) */
/* 72 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 74 */	NdrFcShort( 0x1 ),	/* 1 */
/* 76 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 78 */	NdrFcShort( 0x28 ),	/* X64 Stack size/offset = 40 */
/* 80 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 82 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 84 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 86 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 88 */	
			0x11, 0x0,	/* FC_RP */
/* 90 */	NdrFcShort( 0xffee ),	/* Offset= -18 (72) */

			0x0
        }
    };

static const NDR_RUNDOWN RundownRoutines[] = 
    {
    0
    };


static const unsigned short keyiso_FormatStringOffsetTable[] =
    {
    0,
    42,
    84,
    144,
    180,
    216,
    288,
    336,
    384,
    438,
    474,
    552,
    630,
    702,
    738,
    774,
    810,
    846,
    882,
    918,
    954,
    990,
    1026,
    1062,
    1098,
    1134,
    1170,
    1206,
    1242,
    1278,
    1314,
    1350
    };


static const RPC_DISPATCH_FUNCTION keyiso_table[] =
    {
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    NdrServerCall2,
    0
    };
static const RPC_DISPATCH_TABLE keyiso_v2_0_DispatchTable = 
    {
    32,
    (RPC_DISPATCH_FUNCTION*)keyiso_table
    };


#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for keyiso.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)



extern const NDR_RUNDOWN RundownRoutines[];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"
#ifdef __cplusplus
namespace {
#endif


typedef 
NDR64_FORMAT_CHAR
__midl_frag126_t;
extern const __midl_frag126_t __midl_frag126;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
}
__midl_frag125_t;
extern const __midl_frag125_t __midl_frag125;

typedef 
NDR64_FORMAT_CHAR
__midl_frag85_t;
extern const __midl_frag85_t __midl_frag85;

typedef 
struct 
{
    NDR64_FORMAT_UINT32 frag1;
    struct _NDR64_EXPR_VAR frag2;
}
__midl_frag84_t;
extern const __midl_frag84_t __midl_frag84;

typedef 
struct 
{
    struct _NDR64_CONF_ARRAY_HEADER_FORMAT frag1;
    struct _NDR64_ARRAY_ELEMENT_INFO frag2;
}
__midl_frag83_t;
extern const __midl_frag83_t __midl_frag83;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag82_t;
extern const __midl_frag82_t __midl_frag82;

typedef 
struct _NDR64_CONFORMANT_STRING_FORMAT
__midl_frag81_t;
extern const __midl_frag81_t __midl_frag81;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag80_t;
extern const __midl_frag80_t __midl_frag80;

typedef 
NDR64_FORMAT_CHAR
__midl_frag79_t;
extern const __midl_frag79_t __midl_frag79;

typedef 
struct _NDR64_CONTEXT_HANDLE_FORMAT
__midl_frag78_t;
extern const __midl_frag78_t __midl_frag78;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
    struct _NDR64_PARAM_FORMAT frag8;
    struct _NDR64_PARAM_FORMAT frag9;
}
__midl_frag77_t;
extern const __midl_frag77_t __midl_frag77;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag73_t;
extern const __midl_frag73_t __midl_frag73;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag68_t;
extern const __midl_frag68_t __midl_frag68;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
    struct _NDR64_PARAM_FORMAT frag8;
    struct _NDR64_PARAM_FORMAT frag9;
    struct _NDR64_PARAM_FORMAT frag10;
}
__midl_frag63_t;
extern const __midl_frag63_t __midl_frag63;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag58_t;
extern const __midl_frag58_t __midl_frag58;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag54_t;
extern const __midl_frag54_t __midl_frag54;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
    struct _NDR64_PARAM_FORMAT frag8;
    struct _NDR64_PARAM_FORMAT frag9;
    struct _NDR64_PARAM_FORMAT frag10;
}
__midl_frag51_t;
extern const __midl_frag51_t __midl_frag51;

typedef 
NDR64_FORMAT_CHAR
__midl_frag47_t;
extern const __midl_frag47_t __midl_frag47;

typedef 
struct _NDR64_CONTEXT_HANDLE_FORMAT
__midl_frag45_t;
extern const __midl_frag45_t __midl_frag45;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
}
__midl_frag44_t;
extern const __midl_frag44_t __midl_frag44;

typedef 
NDR64_FORMAT_CHAR
__midl_frag43_t;
extern const __midl_frag43_t __midl_frag43;

typedef 
NDR64_FORMAT_CHAR
__midl_frag42_t;
extern const __midl_frag42_t __midl_frag42;

typedef 
struct _NDR64_CONTEXT_HANDLE_FORMAT
__midl_frag41_t;
extern const __midl_frag41_t __midl_frag41;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
}
__midl_frag40_t;
extern const __midl_frag40_t __midl_frag40;

typedef 
NDR64_FORMAT_CHAR
__midl_frag39_t;
extern const __midl_frag39_t __midl_frag39;

typedef 
NDR64_FORMAT_CHAR
__midl_frag38_t;
extern const __midl_frag38_t __midl_frag38;

typedef 
struct _NDR64_CONTEXT_HANDLE_FORMAT
__midl_frag37_t;
extern const __midl_frag37_t __midl_frag37;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
}
__midl_frag36_t;
extern const __midl_frag36_t __midl_frag36;

typedef 
NDR64_FORMAT_CHAR
__midl_frag35_t;
extern const __midl_frag35_t __midl_frag35;

typedef 
NDR64_FORMAT_CHAR
__midl_frag33_t;
extern const __midl_frag33_t __midl_frag33;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag32_t;
extern const __midl_frag32_t __midl_frag32;

typedef 
struct _NDR64_CONFORMANT_STRING_FORMAT
__midl_frag31_t;
extern const __midl_frag31_t __midl_frag31;

typedef 
struct 
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
    struct 
    {
        struct _NDR64_NO_REPEAT_FORMAT frag1;
        struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag2;
        struct _NDR64_POINTER_FORMAT frag3;
        struct _NDR64_NO_REPEAT_FORMAT frag4;
        struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT frag5;
        struct _NDR64_POINTER_FORMAT frag6;
        NDR64_FORMAT_CHAR frag7;
    } frag2;
}
__midl_frag29_t;
extern const __midl_frag29_t __midl_frag29;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag28_t;
extern const __midl_frag28_t __midl_frag28;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag27_t;
extern const __midl_frag27_t __midl_frag27;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag25_t;
extern const __midl_frag25_t __midl_frag25;

typedef 
struct _NDR64_CONTEXT_HANDLE_FORMAT
__midl_frag23_t;
extern const __midl_frag23_t __midl_frag23;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
    struct _NDR64_PARAM_FORMAT frag8;
    struct _NDR64_PARAM_FORMAT frag9;
}
__midl_frag22_t;
extern const __midl_frag22_t __midl_frag22;

typedef 
NDR64_FORMAT_CHAR
__midl_frag21_t;
extern const __midl_frag21_t __midl_frag21;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
}
__midl_frag20_t;
extern const __midl_frag20_t __midl_frag20;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag14_t;
extern const __midl_frag14_t __midl_frag14;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag12_t;
extern const __midl_frag12_t __midl_frag12;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
}
__midl_frag10_t;
extern const __midl_frag10_t __midl_frag10;

typedef 
struct _NDR64_CONTEXT_HANDLE_FORMAT
__midl_frag8_t;
extern const __midl_frag8_t __midl_frag8;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag7_t;
extern const __midl_frag7_t __midl_frag7;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
}
__midl_frag6_t;
extern const __midl_frag6_t __midl_frag6;

typedef 
struct _NDR64_CONTEXT_HANDLE_FORMAT
__midl_frag4_t;
extern const __midl_frag4_t __midl_frag4;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag3_t;
extern const __midl_frag3_t __midl_frag3;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
}
__midl_frag2_t;
extern const __midl_frag2_t __midl_frag2;

typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag126_t __midl_frag126 =
0x5    /* FC64_INT32 */;

static const __midl_frag125_t __midl_frag125 =
{ 
/* s_SrvRpcCryptVerifyClaim */
    { 
    /* s_SrvRpcCryptVerifyClaim */      /* procedure s_SrvRpcCryptVerifyClaim */
        (NDR64_UINT32) 17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
        (NDR64_UINT32) 16 /* 0x10 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 1 /* 0x1 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag126,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    }
};

static const __midl_frag85_t __midl_frag85 =
0x2    /* FC64_INT8 */;

static const __midl_frag84_t __midl_frag84 =
{ 
/*  */
    (NDR64_UINT32) 0 /* 0x0 */,
    { 
    /* struct _NDR64_EXPR_VAR */
        0x3,    /* FC_EXPR_VAR */
        0x5,    /* FC64_INT32 */
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT32) 40 /* 0x28 */  /* Offset */
    }
};

static const __midl_frag83_t __midl_frag83 =
{ 
/* *byte */
    { 
    /* *byte */
        0x41,    /* FC64_CONF_ARRAY */
        (NDR64_UINT8) 0 /* 0x0 */,
        { 
        /* *byte */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 1 /* 0x1 */,
        &__midl_frag84
    },
    { 
    /* struct _NDR64_ARRAY_ELEMENT_INFO */
        (NDR64_UINT32) 1 /* 0x1 */,
        &__midl_frag85
    }
};

static const __midl_frag82_t __midl_frag82 =
{ 
/* *byte */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag83
};

static const __midl_frag81_t __midl_frag81 =
{ 
/* *wchar_t */
    { 
    /* *wchar_t */
        0x64,    /* FC64_CONF_WCHAR_STRING */
        { 
        /* *wchar_t */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT16) 2 /* 0x2 */
    }
};

static const __midl_frag80_t __midl_frag80 =
{ 
/* *wchar_t */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag81
};

static const __midl_frag79_t __midl_frag79 =
0x7    /* FC64_INT64 */;

static const __midl_frag78_t __midl_frag78 =
{ 
/* struct _NDR64_CONTEXT_HANDLE_FORMAT */
    0x70,    /* FC64_BIND_CONTEXT */
    (NDR64_UINT8) 65 /* 0x41 */,
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT8) 1 /* 0x1 */
};

static const __midl_frag77_t __midl_frag77 =
{ 
/* s_SrvRpcCryptSetProviderProperty */
    { 
    /* s_SrvRpcCryptSetProviderProperty */      /* procedure s_SrvRpcCryptSetProviderProperty */
        (NDR64_UINT32) 19660864 /* 0x12c0040 */,    /* explicit handle */ /* IsIntrepreted, ClientMustSize, HasReturn, ServerCorrelation, HasExtensions */
        (NDR64_UINT32) 64 /* 0x40 */ ,  /* Stack size */
        (NDR64_UINT32) 68 /* 0x44 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 7 /* 0x7 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag78,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* hProvider */      /* parameter hProvider */
        &__midl_frag79,
        { 
        /* hProvider */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* pszPropertyName */      /* parameter pszPropertyName */
        &__midl_frag81,
        { 
        /* pszPropertyName */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* pBuffer */      /* parameter pBuffer */
        &__midl_frag83,
        { 
        /* pBuffer */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    { 
    /* cbBuffer */      /* parameter cbBuffer */
        &__midl_frag126,
        { 
        /* cbBuffer */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    { 
    /* dwFlags */      /* parameter dwFlags */
        &__midl_frag126,
        { 
        /* dwFlags */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag126,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        56 /* 0x38 */,   /* Stack offset */
    }
};

static const __midl_frag73_t __midl_frag73 =
{ 
/* *long */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 12 /* 0xc */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag126
};

static const __midl_frag68_t __midl_frag68 =
{ 
/* *byte */
    0x21,    /* FC64_UP */
    (NDR64_UINT8) 32 /* 0x20 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag83
};

static const __midl_frag63_t __midl_frag63 =
{ 
/* s_SrvRpcCryptGetProviderProperty */
    { 
    /* s_SrvRpcCryptGetProviderProperty */      /* procedure s_SrvRpcCryptGetProviderProperty */
        (NDR64_UINT32) 23986240 /* 0x16e0040 */,    /* explicit handle */ /* IsIntrepreted, ServerMustSize, ClientMustSize, HasReturn, ServerCorrelation, ClientCorrelation, HasExtensions */
        (NDR64_UINT32) 72 /* 0x48 */ ,  /* Stack size */
        (NDR64_UINT32) 68 /* 0x44 */,
        (NDR64_UINT32) 40 /* 0x28 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 8 /* 0x8 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag78,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* hProvider */      /* parameter hProvider */
        &__midl_frag79,
        { 
        /* hProvider */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* pszPropertyName */      /* parameter pszPropertyName */
        &__midl_frag81,
        { 
        /* pszPropertyName */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* pBuffer */      /* parameter pBuffer */
        &__midl_frag68,
        { 
        /* pBuffer */
            1,
            1,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], [out] */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    { 
    /* cbBuffer */      /* parameter cbBuffer */
        &__midl_frag126,
        { 
        /* cbBuffer */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    { 
    /* pcbWritten */      /* parameter pcbWritten */
        &__midl_frag126,
        { 
        /* pcbWritten */
            0,
            0,
            0,
            0,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* [out], Basetype, SimpleRef, UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    },
    { 
    /* dwFlags */      /* parameter dwFlags */
        &__midl_frag126,
        { 
        /* dwFlags */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        56 /* 0x38 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag126,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        64 /* 0x40 */,   /* Stack offset */
    }
};

static const __midl_frag58_t __midl_frag58 =
{ 
/* *wchar_t */
    0x21,    /* FC64_UP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag81
};

static const __midl_frag54_t __midl_frag54 =
{ 
/* *hyper */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 12 /* 0xc */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag79
};

static const __midl_frag51_t __midl_frag51 =
{ 
/* s_SrvRpcCryptCreatePersistedKey */
    { 
    /* s_SrvRpcCryptCreatePersistedKey */      /* procedure s_SrvRpcCryptCreatePersistedKey */
        (NDR64_UINT32) 17563712 /* 0x10c0040 */,    /* explicit handle */ /* IsIntrepreted, ClientMustSize, HasReturn, HasExtensions */
        (NDR64_UINT32) 72 /* 0x48 */ ,  /* Stack size */
        (NDR64_UINT32) 68 /* 0x44 */,
        (NDR64_UINT32) 48 /* 0x30 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 8 /* 0x8 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag78,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* hProvider */      /* parameter hProvider */
        &__midl_frag79,
        { 
        /* hProvider */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* phKey */      /* parameter phKey */
        &__midl_frag79,
        { 
        /* phKey */
            0,
            0,
            0,
            0,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* [out], Basetype, SimpleRef, UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* pszAlgId */      /* parameter pszAlgId */
        &__midl_frag81,
        { 
        /* pszAlgId */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    { 
    /* pszKeyName */      /* parameter pszKeyName */
        &__midl_frag58,
        { 
        /* pszKeyName */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    { 
    /* dwLegacyKeySpec */      /* parameter dwLegacyKeySpec */
        &__midl_frag126,
        { 
        /* dwLegacyKeySpec */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    },
    { 
    /* dwFlags */      /* parameter dwFlags */
        &__midl_frag126,
        { 
        /* dwFlags */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        56 /* 0x38 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag126,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        64 /* 0x40 */,   /* Stack offset */
    }
};

static const __midl_frag47_t __midl_frag47 =
0x7    /* FC64_INT64 */;

static const __midl_frag45_t __midl_frag45 =
{ 
/* struct _NDR64_CONTEXT_HANDLE_FORMAT */
    0x70,    /* FC64_BIND_CONTEXT */
    (NDR64_UINT8) 65 /* 0x41 */,
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT8) 1 /* 0x1 */
};

static const __midl_frag44_t __midl_frag44 =
{ 
/* s_SrvRpcCryptFreeKey */
    { 
    /* s_SrvRpcCryptFreeKey */      /* procedure s_SrvRpcCryptFreeKey */
        (NDR64_UINT32) 17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
        (NDR64_UINT32) 40 /* 0x28 */ ,  /* Stack size */
        (NDR64_UINT32) 68 /* 0x44 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 4 /* 0x4 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag45,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* hProvider */      /* parameter hProvider */
        &__midl_frag47,
        { 
        /* hProvider */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* hKey */      /* parameter hKey */
        &__midl_frag47,
        { 
        /* hKey */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag126,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    }
};

static const __midl_frag43_t __midl_frag43 =
0x5    /* FC64_INT32 */;

static const __midl_frag42_t __midl_frag42 =
0x7    /* FC64_INT64 */;

static const __midl_frag41_t __midl_frag41 =
{ 
/* struct _NDR64_CONTEXT_HANDLE_FORMAT */
    0x70,    /* FC64_BIND_CONTEXT */
    (NDR64_UINT8) 65 /* 0x41 */,
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT8) 1 /* 0x1 */
};

static const __midl_frag40_t __midl_frag40 =
{ 
/* s_SrvRpcCryptFreeProvider */
    { 
    /* s_SrvRpcCryptFreeProvider */      /* procedure s_SrvRpcCryptFreeProvider */
        (NDR64_UINT32) 17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
        (NDR64_UINT32) 32 /* 0x20 */ ,  /* Stack size */
        (NDR64_UINT32) 52 /* 0x34 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 3 /* 0x3 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag41,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* hProvider */      /* parameter hProvider */
        &__midl_frag42,
        { 
        /* hProvider */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag43,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    }
};

static const __midl_frag39_t __midl_frag39 =
0x5    /* FC64_INT32 */;

static const __midl_frag38_t __midl_frag38 =
0x7    /* FC64_INT64 */;

static const __midl_frag37_t __midl_frag37 =
{ 
/* struct _NDR64_CONTEXT_HANDLE_FORMAT */
    0x70,    /* FC64_BIND_CONTEXT */
    (NDR64_UINT8) 65 /* 0x41 */,
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT8) 1 /* 0x1 */
};

static const __midl_frag36_t __midl_frag36 =
{ 
/* s_SrvRpcCryptFreeBuffer */
    { 
    /* s_SrvRpcCryptFreeBuffer */      /* procedure s_SrvRpcCryptFreeBuffer */
        (NDR64_UINT32) 17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
        (NDR64_UINT32) 32 /* 0x20 */ ,  /* Stack size */
        (NDR64_UINT32) 52 /* 0x34 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 3 /* 0x3 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag37,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* hBuffer */      /* parameter hBuffer */
        &__midl_frag38,
        { 
        /* hBuffer */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag39,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    }
};

static const __midl_frag35_t __midl_frag35 =
0x5    /* FC64_INT32 */;

static const __midl_frag33_t __midl_frag33 =
0x7    /* FC64_INT64 */;

static const __midl_frag32_t __midl_frag32 =
{ 
/* *hyper */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 8 /* 0x8 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag33
};

static const __midl_frag31_t __midl_frag31 =
{ 
/* *wchar_t */
    { 
    /* *wchar_t */
        0x64,    /* FC64_CONF_WCHAR_STRING */
        { 
        /* *wchar_t */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT16) 2 /* 0x2 */
    }
};

static const __midl_frag29_t __midl_frag29 =
{ 
/* _NCryptKeyName */
    { 
    /* _NCryptKeyName */
        0x31,    /* FC64_PSTRUCT */
        (NDR64_UINT8) 7 /* 0x7 */,
        { 
        /* _NCryptKeyName */
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8) 0 /* 0x0 */,
        (NDR64_UINT32) 24 /* 0x18 */
    },
    { 
    /*  */
        { 
        /* struct _NDR64_NO_REPEAT_FORMAT */
            0x80,    /* FC64_NO_REPEAT */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
            (NDR64_UINT32) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* *wchar_t */
            0x21,    /* FC64_UP */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            &__midl_frag31
        },
        { 
        /* struct _NDR64_NO_REPEAT_FORMAT */
            0x80,    /* FC64_NO_REPEAT */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* struct _NDR64_POINTER_INSTANCE_HEADER_FORMAT */
            (NDR64_UINT32) 8 /* 0x8 */,
            (NDR64_UINT32) 0 /* 0x0 */
        },
        { 
        /* *wchar_t */
            0x21,    /* FC64_UP */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT16) 0 /* 0x0 */,
            &__midl_frag31
        },
        0x93    /* FC64_END */
    }
};

static const __midl_frag28_t __midl_frag28 =
{ 
/* *_NCryptKeyName */
    0x21,    /* FC64_UP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag29
};

static const __midl_frag27_t __midl_frag27 =
{ 
/* **_NCryptKeyName */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 20 /* 0x14 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag28
};

static const __midl_frag25_t __midl_frag25 =
{ 
/* *wchar_t */
    0x21,    /* FC64_UP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag31
};

static const __midl_frag23_t __midl_frag23 =
{ 
/* struct _NDR64_CONTEXT_HANDLE_FORMAT */
    0x70,    /* FC64_BIND_CONTEXT */
    (NDR64_UINT8) 65 /* 0x41 */,
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT8) 1 /* 0x1 */
};

static const __midl_frag22_t __midl_frag22 =
{ 
/* s_SrvRpcCryptEnumKeys */
    { 
    /* s_SrvRpcCryptEnumKeys */      /* procedure s_SrvRpcCryptEnumKeys */
        (NDR64_UINT32) 17694784 /* 0x10e0040 */,    /* explicit handle */ /* IsIntrepreted, ServerMustSize, ClientMustSize, HasReturn, HasExtensions */
        (NDR64_UINT32) 64 /* 0x40 */ ,  /* Stack size */
        (NDR64_UINT32) 100 /* 0x64 */,
        (NDR64_UINT32) 48 /* 0x30 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 7 /* 0x7 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag23,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* hProvider */      /* parameter hProvider */
        &__midl_frag33,
        { 
        /* hProvider */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* pszScope */      /* parameter pszScope */
        &__midl_frag25,
        { 
        /* pszScope */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* ppKeyName */      /* parameter ppKeyName */
        &__midl_frag27,
        { 
        /* ppKeyName */
            1,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* MustSize, MustFree, [out], UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    { 
    /* ppEnumState */      /* parameter ppEnumState */
        &__midl_frag33,
        { 
        /* ppEnumState */
            0,
            0,
            0,
            1,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], [out], Basetype, SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    { 
    /* dwFlags */      /* parameter dwFlags */
        &__midl_frag35,
        { 
        /* dwFlags */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag35,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        56 /* 0x38 */,   /* Stack offset */
    }
};

static const __midl_frag21_t __midl_frag21 =
0x5    /* FC64_INT32 */;

static const __midl_frag20_t __midl_frag20 =
{ 
/* s_SrvRpcCryptEnumAlgorithms */
    { 
    /* s_SrvRpcCryptEnumAlgorithms */      /* procedure s_SrvRpcCryptEnumAlgorithms */
        (NDR64_UINT32) 17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
        (NDR64_UINT32) 16 /* 0x10 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 8 /* 0x8 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 1 /* 0x1 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag21,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    }
};

static const __midl_frag14_t __midl_frag14 =
{ 
/* *wchar_t */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag31
};

static const __midl_frag12_t __midl_frag12 =
{ 
/* *hyper */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 12 /* 0xc */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag33
};

static const __midl_frag10_t __midl_frag10 =
{ 
/* s_SrvRpcCryptOpenStorageProvider */
    { 
    /* s_SrvRpcCryptOpenStorageProvider */      /* procedure s_SrvRpcCryptOpenStorageProvider */
        (NDR64_UINT32) 17563712 /* 0x10c0040 */,    /* explicit handle */ /* IsIntrepreted, ClientMustSize, HasReturn, HasExtensions */
        (NDR64_UINT32) 48 /* 0x30 */ ,  /* Stack size */
        (NDR64_UINT32) 44 /* 0x2c */,
        (NDR64_UINT32) 48 /* 0x30 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 5 /* 0x5 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag23,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in] */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* hProvider */      /* parameter hProvider */
        &__midl_frag33,
        { 
        /* hProvider */
            0,
            0,
            0,
            0,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            1
        },    /* [out], Basetype, SimpleRef, UseCache */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* pszProviderName */      /* parameter pszProviderName */
        &__midl_frag31,
        { 
        /* pszProviderName */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    { 
    /* dwFlags */      /* parameter dwFlags */
        &__midl_frag21,
        { 
        /* dwFlags */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag21,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    }
};

static const __midl_frag8_t __midl_frag8 =
{ 
/* struct _NDR64_CONTEXT_HANDLE_FORMAT */
    0x70,    /* FC64_BIND_CONTEXT */
    (NDR64_UINT8) 224 /* 0xe0 */,
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT8) 1 /* 0x1 */
};

static const __midl_frag7_t __midl_frag7 =
{ 
/* *struct _NDR64_POINTER_FORMAT */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 4 /* 0x4 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag8
};

static const __midl_frag6_t __midl_frag6 =
{ 
/* s_SrvRpcReleaseContext */
    { 
    /* s_SrvRpcReleaseContext */      /* procedure s_SrvRpcReleaseContext */
        (NDR64_UINT32) 17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
        (NDR64_UINT32) 24 /* 0x18 */ ,  /* Stack size */
        (NDR64_UINT32) 60 /* 0x3c */,
        (NDR64_UINT32) 68 /* 0x44 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 2 /* 0x2 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag8,
        { 
        /* hContext */
            0,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], [out], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag21,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    }
};

static const __midl_frag4_t __midl_frag4 =
{ 
/* struct _NDR64_CONTEXT_HANDLE_FORMAT */
    0x70,    /* FC64_BIND_CONTEXT */
    (NDR64_UINT8) 160 /* 0xa0 */,
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT8) 1 /* 0x1 */
};

static const __midl_frag3_t __midl_frag3 =
{ 
/* *struct _NDR64_POINTER_FORMAT */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 4 /* 0x4 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag4
};

static const __midl_frag2_t __midl_frag2 =
{ 
/* s_SrvRpcCreateContext */
    { 
    /* s_SrvRpcCreateContext */      /* procedure s_SrvRpcCreateContext */
        (NDR64_UINT32) 17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
        (NDR64_UINT32) 24 /* 0x18 */ ,  /* Stack size */
        (NDR64_UINT32) 0 /* 0x0 */,
        (NDR64_UINT32) 68 /* 0x44 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 2 /* 0x2 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* hContext */      /* parameter hContext */
        &__midl_frag4,
        { 
        /* hContext */
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* long */      /* parameter long */
        &__midl_frag21,
        { 
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    }
};

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;
#ifdef __cplusplus
}
#endif


#include "poppack.h"


static const FormatInfoRef keyiso_Ndr64ProcTable[] =
    {
    &__midl_frag2,
    &__midl_frag6,
    &__midl_frag10,
    &__midl_frag20,
    &__midl_frag20,
    &__midl_frag22,
    &__midl_frag36,
    &__midl_frag40,
    &__midl_frag44,
    &__midl_frag125,
    &__midl_frag51,
    &__midl_frag63,
    &__midl_frag77,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125,
    &__midl_frag125
    };


#ifdef __cplusplus
namespace {
#endif
static const MIDL_STUB_DESC keyiso_StubDesc = 
    {
    (void *)& keyiso___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    RundownRoutines,
    0,
    0,
    0,
    keyiso__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x8010274, /* MIDL Version 8.1.628 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x2000001, /* MIDL flag */
    0, /* cs routines */
    (void *)& keyiso_ServerInfo,   /* proxy/server info */
    0
    };
#ifdef __cplusplus
}
#endif

static const RPC_DISPATCH_FUNCTION keyiso_NDR64__table[] =
    {
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    NdrServerCallAll,
    0
    };
static const RPC_DISPATCH_TABLE keyiso_NDR64__v2_0_DispatchTable = 
    {
    32,
    (RPC_DISPATCH_FUNCTION*)keyiso_NDR64__table
    };

static const MIDL_SYNTAX_INFO keyiso_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&keyiso_v2_0_DispatchTable,
    keyiso__MIDL_ProcFormatString.Format,
    keyiso_FormatStringOffsetTable,
    keyiso__MIDL_TypeFormatString.Format,
    0,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    (RPC_DISPATCH_TABLE*)&keyiso_NDR64__v2_0_DispatchTable,
    0 ,
    (unsigned short *) keyiso_Ndr64ProcTable,
    0,
    0,
    0,
    0
    }
    };


static const SERVER_ROUTINE keyiso_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)s_SrvRpcCreateContext,
    (SERVER_ROUTINE)s_SrvRpcReleaseContext,
    (SERVER_ROUTINE)s_SrvRpcCryptOpenStorageProvider,
    (SERVER_ROUTINE)s_SrvRpcCryptIsAlgSupported,
    (SERVER_ROUTINE)s_SrvRpcCryptEnumAlgorithms,
    (SERVER_ROUTINE)s_SrvRpcCryptEnumKeys,
    (SERVER_ROUTINE)s_SrvRpcCryptFreeBuffer,
    (SERVER_ROUTINE)s_SrvRpcCryptFreeProvider,
    (SERVER_ROUTINE)s_SrvRpcCryptFreeKey,
    (SERVER_ROUTINE)s_SrvRpcCryptOpenKey,
    (SERVER_ROUTINE)s_SrvRpcCryptCreatePersistedKey,
    (SERVER_ROUTINE)s_SrvRpcCryptGetProviderProperty,
    (SERVER_ROUTINE)s_SrvRpcCryptSetProviderProperty,
    (SERVER_ROUTINE)s_SrvRpcCryptGetKeyProperty,
    (SERVER_ROUTINE)s_SrvRpcCryptSetKeyProperty,
    (SERVER_ROUTINE)s_SrvRpcCryptFinalizeKey,
    (SERVER_ROUTINE)s_SrvRpcCryptEncrypt,
    (SERVER_ROUTINE)s_SrvRpcCryptDecrypt,
    (SERVER_ROUTINE)s_SrvRpcCryptImportKey,
    (SERVER_ROUTINE)s_SrvRpcCryptExportKey,
    (SERVER_ROUTINE)s_SrvRpcCryptSignHash,
    (SERVER_ROUTINE)s_SrvRpcCryptVerifySignature,
    (SERVER_ROUTINE)s_SrvRpcCryptDeleteKey,
    (SERVER_ROUTINE)s_SrvRpcCryptNotifyChangeKey,
    (SERVER_ROUTINE)s_SrvRpcCryptSecretAgreement,
    (SERVER_ROUTINE)s_SrvRpcCryptDeriveKey,
    (SERVER_ROUTINE)s_SrvRpcCryptFreeSecret,
    (SERVER_ROUTINE)s_SrvRpcCryptCipherEncrypt,
    (SERVER_ROUTINE)s_SrvRpcCryptCipherDecrypt,
    (SERVER_ROUTINE)s_SrvRpcCryptKeyDerivation,
    (SERVER_ROUTINE)s_SrvRpcCryptCreateClaim,
    (SERVER_ROUTINE)s_SrvRpcCryptVerifyClaim
    };

static const MIDL_SERVER_INFO keyiso_ServerInfo = 
    {
    &keyiso_StubDesc,
    keyiso_ServerRoutineTable,
    keyiso__MIDL_ProcFormatString.Format,
    (unsigned short *) keyiso_FormatStringOffsetTable,
    0,
    (RPC_SYNTAX_IDENTIFIER*)&_NDR64_RpcTransferSyntax_1_0,
    2,
    (MIDL_SYNTAX_INFO*)keyiso_SyntaxInfo
    };
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

