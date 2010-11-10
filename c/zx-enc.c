/* c/zx-enc.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** enc-templ.c  -  XML encoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: enc-templ.c,v 1.27 2007-10-05 22:24:28 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006,  factored data structure walking to aux-templ.c --Sampo
 ** 8.8.2006,  reworked namespace handling --Sampo
 ** 26.8.2006, some CSE --Sampo
 ** 23.9.2006, added WO logic --Sampo
 ** 30.9.2007, improvements to WO encoding --Sampo
 ** 8.2.2010,  better handling of schema order encoding of unknown namespace prefixes --Sampo
 ** 27.10.2010, re-engineered namespace handling --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 ** N.B2: This template is meant to be processed by pd/xsd2sg.pl. Beware
 ** of special markers that xsd2sg.pl expects to find and understand.
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-ns.h"



#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   root
#define EL_STRUCT zx_root_s
#define EL_NS     
#define EL_TAG    root

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_root) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_root(struct zx_ctx* c, struct zx_root_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;

  /* root node has no begin tag */
  int len = 0;

  
  for (se = &x->Assertion->gg;
       se && se->g.tok == zx_sa_Assertion_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sa_Assertion(c, (struct zx_sa_Assertion_s*)se);
  for (se = &x->EncryptedAssertion->gg;
       se && se->g.tok == zx_sa_EncryptedAssertion_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sa_EncryptedAssertion(c, (struct zx_sa_EncryptedAssertion_s*)se);
  for (se = &x->NameID->gg;
       se && se->g.tok == zx_sa_NameID_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sa_NameID(c, (struct zx_sa_NameID_s*)se);
  for (se = &x->EncryptedID->gg;
       se && se->g.tok == zx_sa_EncryptedID_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sa_EncryptedID(c, (struct zx_sa_EncryptedID_s*)se);
  for (se = x->NewID;
    se && se->g.tok == zx_sp_NewID_ELEM;
    se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sp:NewID")-1, zx_ns_tab+(zx_sp_NS >> ZX_TOK_NS_SHIFT));
  for (se = &x->AuthnRequest->gg;
       se && se->g.tok == zx_sp_AuthnRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp_AuthnRequest(c, (struct zx_sp_AuthnRequest_s*)se);
  for (se = &x->Response->gg;
       se && se->g.tok == zx_sp_Response_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp_Response(c, (struct zx_sp_Response_s*)se);
  for (se = &x->LogoutRequest->gg;
       se && se->g.tok == zx_sp_LogoutRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp_LogoutRequest(c, (struct zx_sp_LogoutRequest_s*)se);
  for (se = &x->LogoutResponse->gg;
       se && se->g.tok == zx_sp_LogoutResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp_LogoutResponse(c, (struct zx_sp_LogoutResponse_s*)se);
  for (se = &x->ManageNameIDRequest->gg;
       se && se->g.tok == zx_sp_ManageNameIDRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp_ManageNameIDRequest(c, (struct zx_sp_ManageNameIDRequest_s*)se);
  for (se = &x->ManageNameIDResponse->gg;
       se && se->g.tok == zx_sp_ManageNameIDResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp_ManageNameIDResponse(c, (struct zx_sp_ManageNameIDResponse_s*)se);
  for (se = &x->Envelope->gg;
       se && se->g.tok == zx_e_Envelope_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_e_Envelope(c, (struct zx_e_Envelope_s*)se);
  for (se = &x->Header->gg;
       se && se->g.tok == zx_e_Header_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_e_Header(c, (struct zx_e_Header_s*)se);
  for (se = &x->Body->gg;
       se && se->g.tok == zx_e_Body_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_e_Body(c, (struct zx_e_Body_s*)se);
  for (se = &x->EntityDescriptor->gg;
       se && se->g.tok == zx_md_EntityDescriptor_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_md_EntityDescriptor(c, (struct zx_md_EntityDescriptor_s*)se);
  for (se = &x->EntitiesDescriptor->gg;
       se && se->g.tok == zx_md_EntitiesDescriptor_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_md_EntitiesDescriptor(c, (struct zx_md_EntitiesDescriptor_s*)se);
  for (se = &x->XACMLAuthzDecisionQuery->gg;
       se && se->g.tok == zx_xasp_XACMLAuthzDecisionQuery_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_xasp_XACMLAuthzDecisionQuery(c, (struct zx_xasp_XACMLAuthzDecisionQuery_s*)se);
  for (se = &x->XACMLPolicyQuery->gg;
       se && se->g.tok == zx_xasp_XACMLPolicyQuery_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_xasp_XACMLPolicyQuery(c, (struct zx_xasp_XACMLPolicyQuery_s*)se);
  for (se = &x->xaspcd1_XACMLAuthzDecisionQuery->gg;
       se && se->g.tok == zx_xaspcd1_XACMLAuthzDecisionQuery_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_xaspcd1_XACMLAuthzDecisionQuery(c, (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)se);
  for (se = &x->xaspcd1_XACMLPolicyQuery->gg;
       se && se->g.tok == zx_xaspcd1_XACMLPolicyQuery_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_xaspcd1_XACMLPolicyQuery(c, (struct zx_xaspcd1_XACMLPolicyQuery_s*)se);
  for (se = &x->EndpointReference->gg;
       se && se->g.tok == zx_a_EndpointReference_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_a_EndpointReference(c, (struct zx_a_EndpointReference_s*)se);
  for (se = &x->Token->gg;
       se && se->g.tok == zx_sec_Token_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sec_Token(c, (struct zx_sec_Token_s*)se);
  for (se = &x->Candidate->gg;
       se && se->g.tok == zx_hrxml_Candidate_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_hrxml_Candidate(c, (struct zx_hrxml_Candidate_s*)se);
  for (se = &x->sa11_Assertion->gg;
       se && se->g.tok == zx_sa11_Assertion_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sa11_Assertion(c, (struct zx_sa11_Assertion_s*)se);
  for (se = &x->Request->gg;
       se && se->g.tok == zx_sp11_Request_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp11_Request(c, (struct zx_sp11_Request_s*)se);
  for (se = &x->sp11_Response->gg;
       se && se->g.tok == zx_sp11_Response_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_sp11_Response(c, (struct zx_sp11_Response_s*)se);
  for (se = &x->ff12_Assertion->gg;
       se && se->g.tok == zx_ff12_Assertion_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_Assertion(c, (struct zx_ff12_Assertion_s*)se);
  for (se = &x->ff12_AuthnRequest->gg;
       se && se->g.tok == zx_ff12_AuthnRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_AuthnRequest(c, (struct zx_ff12_AuthnRequest_s*)se);
  for (se = &x->AuthnResponse->gg;
       se && se->g.tok == zx_ff12_AuthnResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_AuthnResponse(c, (struct zx_ff12_AuthnResponse_s*)se);
  for (se = &x->AuthnRequestEnvelope->gg;
       se && se->g.tok == zx_ff12_AuthnRequestEnvelope_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_AuthnRequestEnvelope(c, (struct zx_ff12_AuthnRequestEnvelope_s*)se);
  for (se = &x->AuthnResponseEnvelope->gg;
       se && se->g.tok == zx_ff12_AuthnResponseEnvelope_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_AuthnResponseEnvelope(c, (struct zx_ff12_AuthnResponseEnvelope_s*)se);
  for (se = &x->RegisterNameIdentifierRequest->gg;
       se && se->g.tok == zx_ff12_RegisterNameIdentifierRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_RegisterNameIdentifierRequest(c, (struct zx_ff12_RegisterNameIdentifierRequest_s*)se);
  for (se = &x->RegisterNameIdentifierResponse->gg;
       se && se->g.tok == zx_ff12_RegisterNameIdentifierResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_RegisterNameIdentifierResponse(c, (struct zx_ff12_RegisterNameIdentifierResponse_s*)se);
  for (se = &x->FederationTerminationNotification->gg;
       se && se->g.tok == zx_ff12_FederationTerminationNotification_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_FederationTerminationNotification(c, (struct zx_ff12_FederationTerminationNotification_s*)se);
  for (se = &x->ff12_LogoutRequest->gg;
       se && se->g.tok == zx_ff12_LogoutRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_LogoutRequest(c, (struct zx_ff12_LogoutRequest_s*)se);
  for (se = &x->ff12_LogoutResponse->gg;
       se && se->g.tok == zx_ff12_LogoutResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_LogoutResponse(c, (struct zx_ff12_LogoutResponse_s*)se);
  for (se = &x->NameIdentifierMappingRequest->gg;
       se && se->g.tok == zx_ff12_NameIdentifierMappingRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_NameIdentifierMappingRequest(c, (struct zx_ff12_NameIdentifierMappingRequest_s*)se);
  for (se = &x->NameIdentifierMappingResponse->gg;
       se && se->g.tok == zx_ff12_NameIdentifierMappingResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_ff12_NameIdentifierMappingResponse(c, (struct zx_ff12_NameIdentifierMappingResponse_s*)se);
  for (se = &x->m20_EntityDescriptor->gg;
       se && se->g.tok == zx_m20_EntityDescriptor_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_m20_EntityDescriptor(c, (struct zx_m20_EntityDescriptor_s*)se);
  for (se = &x->m20_EntitiesDescriptor->gg;
       se && se->g.tok == zx_m20_EntitiesDescriptor_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_m20_EntitiesDescriptor(c, (struct zx_m20_EntitiesDescriptor_s*)se);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, ":root", len);
  return len;
}

/* FUNC(zx_ENC_SO_root) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_root(struct zx_ctx* c, struct zx_root_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;

  /* root node has no begin tag */

  
  for (se = &x->Assertion->gg;
       se && se->g.tok == zx_sa_Assertion_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sa_Assertion(c, (struct zx_sa_Assertion_s*)se, p);
  for (se = &x->EncryptedAssertion->gg;
       se && se->g.tok == zx_sa_EncryptedAssertion_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sa_EncryptedAssertion(c, (struct zx_sa_EncryptedAssertion_s*)se, p);
  for (se = &x->NameID->gg;
       se && se->g.tok == zx_sa_NameID_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sa_NameID(c, (struct zx_sa_NameID_s*)se, p);
  for (se = &x->EncryptedID->gg;
       se && se->g.tok == zx_sa_EncryptedID_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sa_EncryptedID(c, (struct zx_sa_EncryptedID_s*)se, p);
  for (se = x->NewID;
       se && se->g.tok == zx_sp_NewID_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sp:NewID", sizeof("sp:NewID")-1, zx_ns_tab+(zx_sp_NS >> ZX_TOK_NS_SHIFT));
  for (se = &x->AuthnRequest->gg;
       se && se->g.tok == zx_sp_AuthnRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp_AuthnRequest(c, (struct zx_sp_AuthnRequest_s*)se, p);
  for (se = &x->Response->gg;
       se && se->g.tok == zx_sp_Response_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp_Response(c, (struct zx_sp_Response_s*)se, p);
  for (se = &x->LogoutRequest->gg;
       se && se->g.tok == zx_sp_LogoutRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp_LogoutRequest(c, (struct zx_sp_LogoutRequest_s*)se, p);
  for (se = &x->LogoutResponse->gg;
       se && se->g.tok == zx_sp_LogoutResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp_LogoutResponse(c, (struct zx_sp_LogoutResponse_s*)se, p);
  for (se = &x->ManageNameIDRequest->gg;
       se && se->g.tok == zx_sp_ManageNameIDRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp_ManageNameIDRequest(c, (struct zx_sp_ManageNameIDRequest_s*)se, p);
  for (se = &x->ManageNameIDResponse->gg;
       se && se->g.tok == zx_sp_ManageNameIDResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp_ManageNameIDResponse(c, (struct zx_sp_ManageNameIDResponse_s*)se, p);
  for (se = &x->Envelope->gg;
       se && se->g.tok == zx_e_Envelope_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_e_Envelope(c, (struct zx_e_Envelope_s*)se, p);
  for (se = &x->Header->gg;
       se && se->g.tok == zx_e_Header_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_e_Header(c, (struct zx_e_Header_s*)se, p);
  for (se = &x->Body->gg;
       se && se->g.tok == zx_e_Body_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_e_Body(c, (struct zx_e_Body_s*)se, p);
  for (se = &x->EntityDescriptor->gg;
       se && se->g.tok == zx_md_EntityDescriptor_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_md_EntityDescriptor(c, (struct zx_md_EntityDescriptor_s*)se, p);
  for (se = &x->EntitiesDescriptor->gg;
       se && se->g.tok == zx_md_EntitiesDescriptor_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_md_EntitiesDescriptor(c, (struct zx_md_EntitiesDescriptor_s*)se, p);
  for (se = &x->XACMLAuthzDecisionQuery->gg;
       se && se->g.tok == zx_xasp_XACMLAuthzDecisionQuery_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_xasp_XACMLAuthzDecisionQuery(c, (struct zx_xasp_XACMLAuthzDecisionQuery_s*)se, p);
  for (se = &x->XACMLPolicyQuery->gg;
       se && se->g.tok == zx_xasp_XACMLPolicyQuery_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_xasp_XACMLPolicyQuery(c, (struct zx_xasp_XACMLPolicyQuery_s*)se, p);
  for (se = &x->xaspcd1_XACMLAuthzDecisionQuery->gg;
       se && se->g.tok == zx_xaspcd1_XACMLAuthzDecisionQuery_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_xaspcd1_XACMLAuthzDecisionQuery(c, (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)se, p);
  for (se = &x->xaspcd1_XACMLPolicyQuery->gg;
       se && se->g.tok == zx_xaspcd1_XACMLPolicyQuery_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_xaspcd1_XACMLPolicyQuery(c, (struct zx_xaspcd1_XACMLPolicyQuery_s*)se, p);
  for (se = &x->EndpointReference->gg;
       se && se->g.tok == zx_a_EndpointReference_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_a_EndpointReference(c, (struct zx_a_EndpointReference_s*)se, p);
  for (se = &x->Token->gg;
       se && se->g.tok == zx_sec_Token_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sec_Token(c, (struct zx_sec_Token_s*)se, p);
  for (se = &x->Candidate->gg;
       se && se->g.tok == zx_hrxml_Candidate_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_hrxml_Candidate(c, (struct zx_hrxml_Candidate_s*)se, p);
  for (se = &x->sa11_Assertion->gg;
       se && se->g.tok == zx_sa11_Assertion_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sa11_Assertion(c, (struct zx_sa11_Assertion_s*)se, p);
  for (se = &x->Request->gg;
       se && se->g.tok == zx_sp11_Request_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp11_Request(c, (struct zx_sp11_Request_s*)se, p);
  for (se = &x->sp11_Response->gg;
       se && se->g.tok == zx_sp11_Response_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_sp11_Response(c, (struct zx_sp11_Response_s*)se, p);
  for (se = &x->ff12_Assertion->gg;
       se && se->g.tok == zx_ff12_Assertion_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_Assertion(c, (struct zx_ff12_Assertion_s*)se, p);
  for (se = &x->ff12_AuthnRequest->gg;
       se && se->g.tok == zx_ff12_AuthnRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_AuthnRequest(c, (struct zx_ff12_AuthnRequest_s*)se, p);
  for (se = &x->AuthnResponse->gg;
       se && se->g.tok == zx_ff12_AuthnResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_AuthnResponse(c, (struct zx_ff12_AuthnResponse_s*)se, p);
  for (se = &x->AuthnRequestEnvelope->gg;
       se && se->g.tok == zx_ff12_AuthnRequestEnvelope_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_AuthnRequestEnvelope(c, (struct zx_ff12_AuthnRequestEnvelope_s*)se, p);
  for (se = &x->AuthnResponseEnvelope->gg;
       se && se->g.tok == zx_ff12_AuthnResponseEnvelope_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_AuthnResponseEnvelope(c, (struct zx_ff12_AuthnResponseEnvelope_s*)se, p);
  for (se = &x->RegisterNameIdentifierRequest->gg;
       se && se->g.tok == zx_ff12_RegisterNameIdentifierRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_RegisterNameIdentifierRequest(c, (struct zx_ff12_RegisterNameIdentifierRequest_s*)se, p);
  for (se = &x->RegisterNameIdentifierResponse->gg;
       se && se->g.tok == zx_ff12_RegisterNameIdentifierResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_RegisterNameIdentifierResponse(c, (struct zx_ff12_RegisterNameIdentifierResponse_s*)se, p);
  for (se = &x->FederationTerminationNotification->gg;
       se && se->g.tok == zx_ff12_FederationTerminationNotification_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_FederationTerminationNotification(c, (struct zx_ff12_FederationTerminationNotification_s*)se, p);
  for (se = &x->ff12_LogoutRequest->gg;
       se && se->g.tok == zx_ff12_LogoutRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_LogoutRequest(c, (struct zx_ff12_LogoutRequest_s*)se, p);
  for (se = &x->ff12_LogoutResponse->gg;
       se && se->g.tok == zx_ff12_LogoutResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_LogoutResponse(c, (struct zx_ff12_LogoutResponse_s*)se, p);
  for (se = &x->NameIdentifierMappingRequest->gg;
       se && se->g.tok == zx_ff12_NameIdentifierMappingRequest_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_NameIdentifierMappingRequest(c, (struct zx_ff12_NameIdentifierMappingRequest_s*)se, p);
  for (se = &x->NameIdentifierMappingResponse->gg;
       se && se->g.tok == zx_ff12_NameIdentifierMappingResponse_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_ff12_NameIdentifierMappingResponse(c, (struct zx_ff12_NameIdentifierMappingResponse_s*)se, p);
  for (se = &x->m20_EntityDescriptor->gg;
       se && se->g.tok == zx_m20_EntityDescriptor_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_m20_EntityDescriptor(c, (struct zx_m20_EntityDescriptor_s*)se, p);
  for (se = &x->m20_EntitiesDescriptor->gg;
       se && se->g.tok == zx_m20_EntitiesDescriptor_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_m20_EntitiesDescriptor(c, (struct zx_m20_EntitiesDescriptor_s*)se, p);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  

  /* root node has no end tag either */

  ENC_LEN_DEBUG(x, ":root", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_root) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_root(struct zx_ctx* c, struct zx_root_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_root(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_root(c, x, buf ), buf, len);
}

#if 1 /* ENC_WO_SUBTEMPL */
/* Empty ENC_WO_SUBTEMPL */
#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   simple_elem
#define EL_STRUCT zx_elem_s
#define EL_NS     
#define EL_TAG    simple_elem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_simple_elem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x , int simplelen, struct zx_ns_s* ns)
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = ZX_LEN_SIMPLE_TAG(x->g.tok, simplelen, ns) + 1 + ZX_LEN_SIMPLE_TAG(x->g.tok, simplelen, ns)+2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, x, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "simple_elem", len);
  return len;
}

/* FUNC(zx_ENC_SO_simple_elem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, char* p , char* simpletag, int simplelen, struct zx_ns_s* ns)
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_SIMPLE_TAG(p, x->g.tok, simpletag, simplelen, ns);
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, ns, &pop_seen);
  zx_see_attr_ns(c, x->attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  for (attr = x->attr; attr; attr = (struct zx_attr_s*)attr->g.n)
    if (attr->g.tok != ZX_TOK_ATTR_NOT_FOUND)
      p = zx_attr_wo_enc(p, attr);
  ZX_OUT_CH(p, '>');
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, x);
  
#if 1 /* NORMALMODE */
  ZX_OUT_SIMPLE_CLOSE_TAG(p, x->g.tok, simpletag, simplelen, ns);
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "simple_elem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_simple_elem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x , char* simpletag, int simplelen, struct zx_ns_s* ns)
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_simple_elem(c, x , simplelen, ns);
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_simple_elem(c, x, buf , simpletag, simplelen, ns), buf, len);
}

#if 1 /* ENC_WO_SUBTEMPL */
/* Empty ENC_WO_SUBTEMPL */
#endif


/* EOF -- c/zx-enc.c */
