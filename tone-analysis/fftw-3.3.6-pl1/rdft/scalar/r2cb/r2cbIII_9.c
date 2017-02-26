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
/* Generated on Mon Jan 16 09:11:51 EST 2017 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cb.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 9 -name r2cbIII_9 -dft-III -include r2cbIII.h */

/*
 * This function contains 32 FP additions, 24 FP multiplications,
 * (or, 8 additions, 0 multiplications, 24 fused multiply/add),
 * 40 stack variables, 12 constants, and 18 memory accesses
 */
#include "r2cbIII.h"

static void r2cbIII_9(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_326827896, +1.326827896337876792410842639271782594433726619);
     DK(KP1_705737063, +1.705737063904886419256501927880148143872040591);
     DK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DK(KP1_532088886, +1.532088886237956070404785301110833347871664914);
     DK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DK(KP1_969615506, +1.969615506024416118733486049179046027341286503);
     DK(KP839099631, +0.839099631177280011763127298123181364687434283);
     DK(KP176326980, +0.176326980708464973471090386868618986121633062);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(36, rs), MAKE_VOLATILE_STRIDE(36, csr), MAKE_VOLATILE_STRIDE(36, csi)) {
	       E T4, Td, T3, Th, Tr, Tm, T7, Tc, Tj, Tg, T1, T2;
	       Tg = Ci[WS(csi, 1)];
	       T1 = Cr[WS(csr, 4)];
	       T2 = Cr[WS(csr, 1)];
	       T4 = Cr[WS(csr, 3)];
	       Td = Ci[WS(csi, 3)];
	       {
		    E T5, Tf, T6, Ta, Tb;
		    T5 = Cr[0];
		    Tf = T2 - T1;
		    T3 = FMA(KP2_000000000, T2, T1);
		    T6 = Cr[WS(csr, 2)];
		    Ta = Ci[WS(csi, 2)];
		    Tb = Ci[0];
		    Th = FNMS(KP1_732050807, Tg, Tf);
		    Tr = FMA(KP1_732050807, Tg, Tf);
		    Tm = T5 - T6;
		    T7 = T5 + T6;
		    Tc = Ta - Tb;
		    Tj = Tb + Ta;
	       }
	       {
		    E Tw, Tq, Tv, Tp, Ti, T8;
		    Ti = FNMS(KP500000000, T7, T4);
		    T8 = T4 + T7;
		    {
			 E Te, Tl, Tt, Tk, T9;
			 Te = Tc - Td;
			 Tl = FMA(KP500000000, Tc, Td);
			 Tt = FNMS(KP866025403, Tj, Ti);
			 Tk = FMA(KP866025403, Tj, Ti);
			 T9 = T8 - T3;
			 R0[0] = FMA(KP2_000000000, T8, T3);
			 {
			      E Ts, Tn, Tu, To;
			      Ts = FMA(KP866025403, Tm, Tl);
			      Tn = FNMS(KP866025403, Tm, Tl);
			      R0[WS(rs, 3)] = FMS(KP1_732050807, Te, T9);
			      R1[WS(rs, 1)] = FMA(KP1_732050807, Te, T9);
			      Tu = FMA(KP176326980, Tt, Ts);
			      Tw = FNMS(KP176326980, Ts, Tt);
			      To = FMA(KP839099631, Tn, Tk);
			      Tq = FNMS(KP839099631, Tk, Tn);
			      R0[WS(rs, 1)] = FMS(KP1_969615506, Tu, Tr);
			      Tv = FMA(KP984807753, Tu, Tr);
			      R1[0] = FNMS(KP1_532088886, To, Th);
			      Tp = FMA(KP766044443, To, Th);
			 }
		    }
		    R0[WS(rs, 4)] = FMS(KP1_705737063, Tw, Tv);
		    R1[WS(rs, 2)] = FMA(KP1_705737063, Tw, Tv);
		    R0[WS(rs, 2)] = FMS(KP1_326827896, Tq, Tp);
		    R1[WS(rs, 3)] = FMA(KP1_326827896, Tq, Tp);
	       }
	  }
     }
}

static const kr2c_desc desc = { 9, "r2cbIII_9", {8, 0, 24, 0}, &GENUS };

void X(codelet_r2cbIII_9) (planner *p) {
     X(kr2c_register) (p, r2cbIII_9, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 9 -name r2cbIII_9 -dft-III -include r2cbIII.h */

/*
 * This function contains 32 FP additions, 18 FP multiplications,
 * (or, 22 additions, 8 multiplications, 10 fused multiply/add),
 * 35 stack variables, 12 constants, and 18 memory accesses
 */
#include "r2cbIII.h"

static void r2cbIII_9(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP642787609, +0.642787609686539326322643409907263432907559884);
     DK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DK(KP1_326827896, +1.326827896337876792410842639271782594433726619);
     DK(KP1_113340798, +1.113340798452838732905825904094046265936583811);
     DK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DK(KP173648177, +0.173648177666930348851716626769314796000375677);
     DK(KP1_705737063, +1.705737063904886419256501927880148143872040591);
     DK(KP300767466, +0.300767466360870593278543795225003852144476517);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(36, rs), MAKE_VOLATILE_STRIDE(36, csr), MAKE_VOLATILE_STRIDE(36, csi)) {
	       E T3, Ts, Ti, Td, Tc, T8, To, Tu, Tl, Tt, T9, Te;
	       {
		    E Th, T1, T2, Tf, Tg;
		    Tg = Ci[WS(csi, 1)];
		    Th = KP1_732050807 * Tg;
		    T1 = Cr[WS(csr, 4)];
		    T2 = Cr[WS(csr, 1)];
		    Tf = T2 - T1;
		    T3 = FMA(KP2_000000000, T2, T1);
		    Ts = Tf - Th;
		    Ti = Tf + Th;
	       }
	       {
		    E T4, T7, Tm, Tk, Tn, Tj;
		    T4 = Cr[WS(csr, 3)];
		    Td = Ci[WS(csi, 3)];
		    {
			 E T5, T6, Ta, Tb;
			 T5 = Cr[0];
			 T6 = Cr[WS(csr, 2)];
			 T7 = T5 + T6;
			 Tm = KP866025403 * (T6 - T5);
			 Ta = Ci[WS(csi, 2)];
			 Tb = Ci[0];
			 Tc = Ta - Tb;
			 Tk = KP866025403 * (Tb + Ta);
		    }
		    T8 = T4 + T7;
		    Tn = FMA(KP500000000, Tc, Td);
		    To = Tm - Tn;
		    Tu = Tm + Tn;
		    Tj = FMS(KP500000000, T7, T4);
		    Tl = Tj + Tk;
		    Tt = Tj - Tk;
	       }
	       R0[0] = FMA(KP2_000000000, T8, T3);
	       T9 = T8 - T3;
	       Te = KP1_732050807 * (Tc - Td);
	       R1[WS(rs, 1)] = T9 + Te;
	       R0[WS(rs, 3)] = Te - T9;
	       {
		    E Tr, Tp, Tq, Tx, Tv, Tw;
		    Tr = FNMS(KP1_705737063, Tl, KP300767466 * To);
		    Tp = FMA(KP173648177, Tl, KP984807753 * To);
		    Tq = Ti - Tp;
		    R0[WS(rs, 1)] = -(FMA(KP2_000000000, Tp, Ti));
		    R0[WS(rs, 4)] = Tr - Tq;
		    R1[WS(rs, 2)] = Tq + Tr;
		    Tx = FMA(KP1_113340798, Tt, KP1_326827896 * Tu);
		    Tv = FNMS(KP642787609, Tu, KP766044443 * Tt);
		    Tw = Tv - Ts;
		    R1[0] = FMA(KP2_000000000, Tv, Ts);
		    R1[WS(rs, 3)] = Tx - Tw;
		    R0[WS(rs, 2)] = Tw + Tx;
	       }
	  }
     }
}

static const kr2c_desc desc = { 9, "r2cbIII_9", {22, 8, 10, 0}, &GENUS };

void X(codelet_r2cbIII_9) (planner *p) {
     X(kr2c_register) (p, r2cbIII_9, &desc);
}

#endif				/* HAVE_FMA */
