/* c/zx-wsc-enc.c - WARNING: This file was auto generated by xsd2sg.pl. DO NOT EDIT!
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
#include "c/zx-wsc-data.h"
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

#define EL_NAME   wsc_DerivedKeyToken
#define EL_STRUCT zx_wsc_DerivedKeyToken_s
#define EL_NS     wsc
#define EL_TAG    DerivedKeyToken

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

/* FUNC(zx_LEN_SO_wsc_DerivedKeyToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsc:DerivedKeyToken")-1 + 1 + sizeof("</wsc:DerivedKeyToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsc_NS >>  ZX_TOK_NS_SHIFT), &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsu_NS >> ZX_TOK_NS_SHIFT), &pop_seen);

  len += zx_attr_so_len(c, x->Algorithm, sizeof("Algorithm")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Id, sizeof("wsu:Id")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = &x->SecurityTokenReference->gg;
       se && se->g.tok == zx_wsse_SecurityTokenReference_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_wsse_SecurityTokenReference(c, (struct zx_wsse_SecurityTokenReference_s*)se);
  for (se = &x->Properties->gg;
       se && se->g.tok == zx_wsc_Properties_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_wsc_Properties(c, (struct zx_wsc_Properties_s*)se);
  for (se = x->Generation;
    se && se->g.tok == zx_wsc_Generation_ELEM;
    se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wsc:Generation")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));
  for (se = x->Offset;
    se && se->g.tok == zx_wsc_Offset_ELEM;
    se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wsc:Offset")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));
  for (se = x->Length;
    se && se->g.tok == zx_wsc_Length_ELEM;
    se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wsc:Length")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));
  for (se = x->Label;
    se && se->g.tok == zx_wsc_Label_ELEM;
    se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wsc:Label")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));
  for (se = x->Nonce;
    se && se->g.tok == zx_wsc_Nonce_ELEM;
    se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wsc:Nonce")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsc:DerivedKeyToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsc_DerivedKeyToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsc:DerivedKeyToken");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT), &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsu_NS >> ZX_TOK_NS_SHIFT), &pop_seen);

  zx_see_attr_ns(c, x->gg.attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->Algorithm, " Algorithm=\"", sizeof(" Algorithm=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  for (attr = x->gg.attr; attr; attr = (struct zx_attr_s*)attr->g.n)
    if (attr->g.tok != ZX_TOK_ATTR_NOT_FOUND)
      p = zx_attr_wo_enc(p, attr);
  ZX_OUT_CH(p, '>');
#else
  /* root node has no begin tag */
#endif
  
  for (se = &x->SecurityTokenReference->gg;
       se && se->g.tok == zx_wsse_SecurityTokenReference_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_wsse_SecurityTokenReference(c, (struct zx_wsse_SecurityTokenReference_s*)se, p);
  for (se = &x->Properties->gg;
       se && se->g.tok == zx_wsc_Properties_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_wsc_Properties(c, (struct zx_wsc_Properties_s*)se, p);
  for (se = x->Generation;
       se && se->g.tok == zx_wsc_Generation_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wsc:Generation", sizeof("wsc:Generation")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));
  for (se = x->Offset;
       se && se->g.tok == zx_wsc_Offset_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wsc:Offset", sizeof("wsc:Offset")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));
  for (se = x->Length;
       se && se->g.tok == zx_wsc_Length_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wsc:Length", sizeof("wsc:Length")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));
  for (se = x->Label;
       se && se->g.tok == zx_wsc_Label_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wsc:Label", sizeof("wsc:Label")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));
  for (se = x->Nonce;
       se && se->g.tok == zx_wsc_Nonce_ELEM;
       se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wsc:Nonce", sizeof("wsc:Nonce")-1, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT));

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsc:DerivedKeyToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsc:DerivedKeyToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsc_DerivedKeyToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsc_DerivedKeyToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsc_DerivedKeyToken(c, x, buf ), buf, len);
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

#define EL_NAME   wsc_Properties
#define EL_STRUCT zx_wsc_Properties_s
#define EL_NS     wsc
#define EL_TAG    Properties

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

/* FUNC(zx_LEN_SO_wsc_Properties) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsc:Properties")-1 + 1 + sizeof("</wsc:Properties>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsc_NS >>  ZX_TOK_NS_SHIFT), &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsc:Properties", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsc_Properties) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsc:Properties");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT), &pop_seen);

  zx_see_attr_ns(c, x->gg.attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  for (attr = x->gg.attr; attr; attr = (struct zx_attr_s*)attr->g.n)
    if (attr->g.tok != ZX_TOK_ATTR_NOT_FOUND)
      p = zx_attr_wo_enc(p, attr);
  ZX_OUT_CH(p, '>');
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsc:Properties>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsc:Properties", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsc_Properties) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsc_Properties(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsc_Properties(c, x, buf ), buf, len);
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

#define EL_NAME   wsc_SecurityContextToken
#define EL_STRUCT zx_wsc_SecurityContextToken_s
#define EL_NS     wsc
#define EL_TAG    SecurityContextToken

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

/* FUNC(zx_LEN_SO_wsc_SecurityContextToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsc:SecurityContextToken")-1 + 1 + sizeof("</wsc:SecurityContextToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsc_NS >>  ZX_TOK_NS_SHIFT), &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsu_NS >> ZX_TOK_NS_SHIFT), &pop_seen);

  len += zx_attr_so_len(c, x->Id, sizeof("wsu:Id")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsc:SecurityContextToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsc_SecurityContextToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_attr_s* attr MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsc:SecurityContextToken");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsc_NS >> ZX_TOK_NS_SHIFT), &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, zx_ns_tab+(zx_wsu_NS >> ZX_TOK_NS_SHIFT), &pop_seen);

  zx_see_attr_ns(c, x->gg.attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  for (attr = x->gg.attr; attr; attr = (struct zx_attr_s*)attr->g.n)
    if (attr->g.tok != ZX_TOK_ATTR_NOT_FOUND)
      p = zx_attr_wo_enc(p, attr);
  ZX_OUT_CH(p, '>');
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsc:SecurityContextToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsc:SecurityContextToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsc_SecurityContextToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsc_SecurityContextToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsc_SecurityContextToken(c, x, buf ), buf, len);
}

#if 1 /* ENC_WO_SUBTEMPL */
/* Empty ENC_WO_SUBTEMPL */
#endif


/* EOF -- c/zx-wsc-enc.c */
