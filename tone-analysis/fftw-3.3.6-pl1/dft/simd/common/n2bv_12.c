/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Jan 16 09:09:10 EST 2017 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 12 -name n2bv_12 -with-ostride 2 -include n2b.h -store-multiple 2 */

/*
 * This function contains 48 FP additions, 20 FP multiplications,
 * (or, 30 additions, 2 multiplications, 18 fused multiply/add),
 * 61 stack variables, 2 constants, and 30 memory accesses
 */
#include "n2b.h"

static void n2bv_12(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(24, is), MAKE_VOLATILE_STRIDE(24, os)) {
	       V T1, T6, Tc, Th, Td, Te, Ti, Tz, T4, TA, T9, Tj, Tf, Tw;
	       {
		    V T2, T3, T7, T8;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T6 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T3 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    T7 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    Tc = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    Th = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    Td = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    Te = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
		    Ti = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    Tz = VSUB(T2, T3);
		    T4 = VADD(T2, T3);
		    TA = VSUB(T7, T8);
		    T9 = VADD(T7, T8);
		    Tj = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       }
	       Tf = VADD(Td, Te);
	       Tw = VSUB(Td, Te);
	       {
		    V T5, Tp, TJ, TB, Ta, Tq, Tk, Tx, Tg, Ts;
		    T5 = VADD(T1, T4);
		    Tp = VFNMS(LDK(KP500000000), T4, T1);
		    TJ = VSUB(Tz, TA);
		    TB = VADD(Tz, TA);
		    Ta = VADD(T6, T9);
		    Tq = VFNMS(LDK(KP500000000), T9, T6);
		    Tk = VADD(Ti, Tj);
		    Tx = VSUB(Tj, Ti);
		    Tg = VADD(Tc, Tf);
		    Ts = VFNMS(LDK(KP500000000), Tf, Tc);
		    {
			 V Tr, TF, Tb, Tn, TG, Ty, Tl, Tt;
			 Tr = VADD(Tp, Tq);
			 TF = VSUB(Tp, Tq);
			 Tb = VSUB(T5, Ta);
			 Tn = VADD(T5, Ta);
			 TG = VADD(Tw, Tx);
			 Ty = VSUB(Tw, Tx);
			 Tl = VADD(Th, Tk);
			 Tt = VFNMS(LDK(KP500000000), Tk, Th);
			 {
			      V TC, TE, TH, TL, Tu, TI, Tm, To;
			      TC = VMUL(LDK(KP866025403), VSUB(Ty, TB));
			      TE = VMUL(LDK(KP866025403), VADD(TB, Ty));
			      TH = VFNMS(LDK(KP866025403), TG, TF);
			      TL = VFMA(LDK(KP866025403), TG, TF);
			      Tu = VADD(Ts, Tt);
			      TI = VSUB(Ts, Tt);
			      Tm = VSUB(Tg, Tl);
			      To = VADD(Tg, Tl);
			      {
				   V TK, TM, Tv, TD;
				   TK = VFMA(LDK(KP866025403), TJ, TI);
				   TM = VFNMS(LDK(KP866025403), TJ, TI);
				   Tv = VSUB(Tr, Tu);
				   TD = VADD(Tr, Tu);
				   {
					V TN, TO, TP, TQ;
					TN = VADD(Tn, To);
					STM2(&(xo[0]), TN, ovs, &(xo[0]));
					TO = VSUB(Tn, To);
					STM2(&(xo[12]), TO, ovs, &(xo[0]));
					TP = VFMAI(Tm, Tb);
					STM2(&(xo[18]), TP, ovs, &(xo[2]));
					TQ = VFNMSI(Tm, Tb);
					STM2(&(xo[6]), TQ, ovs, &(xo[2]));
					{
					     V TR, TS, TT, TU;
					     TR = VFMAI(TM, TL);
					     STM2(&(xo[10]), TR, ovs, &(xo[2]));
					     TS = VFNMSI(TM, TL);
					     STM2(&(xo[14]), TS, ovs, &(xo[2]));
					     STN2(&(xo[12]), TO, TS, ovs);
					     TT = VFNMSI(TK, TH);
					     STM2(&(xo[22]), TT, ovs, &(xo[2]));
					     TU = VFMAI(TK, TH);
					     STM2(&(xo[2]), TU, ovs, &(xo[2]));
					     STN2(&(xo[0]), TN, TU, ovs);
					     {
						  V TV, TW, TX, TY;
						  TV = VFNMSI(TE, TD);
						  STM2(&(xo[16]), TV, ovs, &(xo[0]));
						  STN2(&(xo[16]), TV, TP, ovs);
						  TW = VFMAI(TE, TD);
						  STM2(&(xo[8]), TW, ovs, &(xo[0]));
						  STN2(&(xo[8]), TW, TR, ovs);
						  TX = VFMAI(TC, Tv);
						  STM2(&(xo[4]), TX, ovs, &(xo[0]));
						  STN2(&(xo[4]), TX, TQ, ovs);
						  TY = VFNMSI(TC, Tv);
						  STM2(&(xo[20]), TY, ovs, &(xo[0]));
						  STN2(&(xo[20]), TY, TT, ovs);
					     }
					}
				   }
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 12, XSIMD_STRING("n2bv_12"), {30, 2, 18, 0}, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2bv_12) (planner *p) {
     X(kdft_register) (p, n2bv_12, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 12 -name n2bv_12 -with-ostride 2 -include n2b.h -store-multiple 2 */

/*
 * This function contains 48 FP additions, 8 FP multiplications,
 * (or, 44 additions, 4 multiplications, 4 fused multiply/add),
 * 33 stack variables, 2 constants, and 30 memory accesses
 */
#include "n2b.h"

static void n2bv_12(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(24, is), MAKE_VOLATILE_STRIDE(24, os)) {
	       V T5, Ta, TG, TF, Ty, Tm, Ti, Tp, TJ, TI, Tx, Ts;
	       {
		    V T1, T6, T4, Tk, T9, Tl;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T6 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    {
			 V T2, T3, T7, T8;
			 T2 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 T3 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 T4 = VADD(T2, T3);
			 Tk = VSUB(T2, T3);
			 T7 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T9 = VADD(T7, T8);
			 Tl = VSUB(T7, T8);
		    }
		    T5 = VFNMS(LDK(KP500000000), T4, T1);
		    Ta = VFNMS(LDK(KP500000000), T9, T6);
		    TG = VADD(T6, T9);
		    TF = VADD(T1, T4);
		    Ty = VADD(Tk, Tl);
		    Tm = VMUL(LDK(KP866025403), VSUB(Tk, Tl));
	       }
	       {
		    V Tn, Tq, Te, To, Th, Tr;
		    Tn = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    Tq = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    {
			 V Tc, Td, Tf, Tg;
			 Tc = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 Td = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 Te = VSUB(Tc, Td);
			 To = VADD(Tc, Td);
			 Tf = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tg = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 Th = VSUB(Tf, Tg);
			 Tr = VADD(Tf, Tg);
		    }
		    Ti = VMUL(LDK(KP866025403), VSUB(Te, Th));
		    Tp = VFNMS(LDK(KP500000000), To, Tn);
		    TJ = VADD(Tq, Tr);
		    TI = VADD(Tn, To);
		    Tx = VADD(Te, Th);
		    Ts = VFNMS(LDK(KP500000000), Tr, Tq);
	       }
	       {
		    V TN, TO, TP, TQ, TR, TS;
		    {
			 V TH, TK, TL, TM;
			 TH = VSUB(TF, TG);
			 TK = VBYI(VSUB(TI, TJ));
			 TN = VSUB(TH, TK);
			 STM2(&(xo[6]), TN, ovs, &(xo[2]));
			 TO = VADD(TH, TK);
			 STM2(&(xo[18]), TO, ovs, &(xo[2]));
			 TL = VADD(TF, TG);
			 TM = VADD(TI, TJ);
			 TP = VSUB(TL, TM);
			 STM2(&(xo[12]), TP, ovs, &(xo[0]));
			 TQ = VADD(TL, TM);
			 STM2(&(xo[0]), TQ, ovs, &(xo[0]));
		    }
		    {
			 V Tj, Tv, Tu, Tw, Tb, Tt, TT, TU;
			 Tb = VSUB(T5, Ta);
			 Tj = VSUB(Tb, Ti);
			 Tv = VADD(Tb, Ti);
			 Tt = VSUB(Tp, Ts);
			 Tu = VBYI(VADD(Tm, Tt));
			 Tw = VBYI(VSUB(Tt, Tm));
			 TR = VSUB(Tj, Tu);
			 STM2(&(xo[22]), TR, ovs, &(xo[2]));
			 TS = VADD(Tv, Tw);
			 STM2(&(xo[10]), TS, ovs, &(xo[2]));
			 TT = VADD(Tj, Tu);
			 STM2(&(xo[2]), TT, ovs, &(xo[2]));
			 STN2(&(xo[0]), TQ, TT, ovs);
			 TU = VSUB(Tv, Tw);
			 STM2(&(xo[14]), TU, ovs, &(xo[2]));
			 STN2(&(xo[12]), TP, TU, ovs);
		    }
		    {
			 V Tz, TD, TC, TE, TA, TB;
			 Tz = VBYI(VMUL(LDK(KP866025403), VSUB(Tx, Ty)));
			 TD = VBYI(VMUL(LDK(KP866025403), VADD(Ty, Tx)));
			 TA = VADD(T5, Ta);
			 TB = VADD(Tp, Ts);
			 TC = VSUB(TA, TB);
			 TE = VADD(TA, TB);
			 {
			      V TV, TW, TX, TY;
			      TV = VADD(Tz, TC);
			      STM2(&(xo[4]), TV, ovs, &(xo[0]));
			      STN2(&(xo[4]), TV, TN, ovs);
			      TW = VSUB(TE, TD);
			      STM2(&(xo[16]), TW, ovs, &(xo[0]));
			      STN2(&(xo[16]), TW, TO, ovs);
			      TX = VSUB(TC, Tz);
			      STM2(&(xo[20]), TX, ovs, &(xo[0]));
			      STN2(&(xo[20]), TX, TR, ovs);
			      TY = VADD(TD, TE);
			      STM2(&(xo[8]), TY, ovs, &(xo[0]));
			      STN2(&(xo[8]), TY, TS, ovs);
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 12, XSIMD_STRING("n2bv_12"), {44, 4, 4, 0}, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2bv_12) (planner *p) {
     X(kdft_register) (p, n2bv_12, &desc);
}

#endif				/* HAVE_FMA */
