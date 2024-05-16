#include "slicer.h"

namespace slicer {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Change __m_change_33;
	Change __m_change_37;
	Change __m_change_38;
	Change __m_change_36;
	Change __m_change_31;
	Change __m_change_32;
	Change __m_change_30;
	Change __m_change_39;
	Change __m_change_47;
	Change __m_change_41;
	Change __m_change_45;
	Change __m_change_43;
	Data m_loop_24;
	Delta __m_delta_46;
	Phasor __m_phasor_35;
	PlusEquals __m_pluseq_42;
	int __exception;
	int vectorsize;
	t_sample __m_latch_48;
	t_sample __m_latch_49;
	t_sample m_mf_53;
	t_sample m_y_54;
	t_sample m_sw_15;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_history_2;
	t_sample __m_latch_44;
	t_sample m_history_3;
	t_sample m_z_55;
	t_sample m_z_57;
	t_sample m_z_67;
	t_sample m_z_68;
	t_sample m_z_69;
	t_sample m_z_56;
	t_sample m_y_66;
	t_sample m_z_59;
	t_sample m_mf_65;
	t_sample m_z_58;
	t_sample m_overdub_14;
	t_sample m_history_4;
	t_sample m_history_5;
	t_sample m_q_21;
	t_sample m_sw_22;
	t_sample m_spread_23;
	t_sample m_sw_13;
	t_sample m_bpm_20;
	t_sample m_jump_18;
	t_sample m_sw_19;
	t_sample m_sw_16;
	t_sample m_randomness_17;
	t_sample __m_latch_40;
	t_sample m_sw_12;
	t_sample m_gate_10;
	t_sample m_history_8;
	t_sample m_history_7;
	t_sample m_history_6;
	t_sample m_sw_11;
	t_sample m_sw_9;
	t_sample __m_latch_34;
	t_sample samples_to_seconds;
	t_sample m_z_70;
	t_sample m_z_71;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_sw_9 = ((int)0);
		m_gate_10 = ((int)0);
		m_sw_11 = ((int)0);
		m_sw_12 = ((int)0);
		m_sw_13 = ((int)0);
		m_overdub_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_randomness_17 = 1;
		m_jump_18 = 1.25;
		m_sw_19 = ((int)0);
		m_bpm_20 = ((int)0);
		m_q_21 = ((int)0);
		m_sw_22 = ((int)0);
		m_spread_23 = ((int)0);
		m_loop_24.reset("loop", ((int)352800), ((int)2));
		__m_change_30.reset(0);
		__m_change_31.reset(0);
		__m_change_32.reset(0);
		__m_change_33.reset(0);
		__m_latch_34 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_35.reset(0);
		__m_change_36.reset(0);
		__m_change_37.reset(0);
		__m_change_38.reset(0);
		__m_change_39.reset(0);
		__m_latch_40 = 0;
		__m_change_41.reset(0);
		__m_pluseq_42.reset(0);
		__m_change_43.reset(0);
		__m_latch_44 = 11025;
		__m_change_45.reset(0);
		__m_delta_46.reset(0);
		__m_change_47.reset(0);
		__m_latch_48 = 0;
		__m_latch_49 = 0;
		m_mf_53 = ((int)0);
		m_y_54 = ((int)0);
		m_z_55 = ((int)0);
		m_z_56 = ((int)0);
		m_z_57 = ((int)0);
		m_z_58 = ((int)0);
		m_z_59 = ((int)0);
		m_mf_65 = ((int)0);
		m_y_66 = ((int)0);
		m_z_67 = ((int)0);
		m_z_68 = ((int)0);
		m_z_69 = ((int)0);
		m_z_70 = ((int)0);
		m_z_71 = ((int)0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		t_sample * __out7 = __outs[6];
		t_sample * __out8 = __outs[7];
		t_sample * __out9 = __outs[8];
		t_sample * __out10 = __outs[9];
		t_sample * __out11 = __outs[10];
		t_sample * __out12 = __outs[11];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample rsub_34690 = (((int)1) - m_overdub_14);
		int loop_dim = m_loop_24.dim;
		int loop_channels = m_loop_24.channels;
		bool chan_ignore_25 = ((((int)1) < 0) || (((int)1) >= loop_channels));
		t_sample sub_79489 = (m_spread_23 - ((int)0));
		t_sample scale_79486 = ((safepow((sub_79489 * ((t_sample)1)), ((int)1)) * ((int)-60)) + ((int)60));
		t_sample sub_79493 = (m_spread_23 - ((int)0));
		t_sample scale_79490 = ((safepow((sub_79493 * ((t_sample)1)), ((int)1)) * ((int)67)) + ((int)60));
		t_sample orange_79496 = (scale_79490 - scale_79486);
		int int_82 = int(m_sw_11);
		int int_79127 = int(m_sw_16);
		int int_79130 = int(m_sw_12);
		int int_79133 = int(m_sw_15);
		t_sample sub_79501 = (m_bpm_20 - ((int)0));
		t_sample scale_79498 = ((safepow((sub_79501 * ((t_sample)1)), ((int)1)) * ((int)160)) + ((int)40));
		t_sample scale_74177 = scale_79498;
		t_sample div_37 = (scale_74177 * ((t_sample)0.016666666666667));
		t_sample mul_39 = (div_37 * ((int)1));
		t_sample div_34 = (mul_39 * ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		int int_79136 = int(m_sw_19);
		int int_79139 = int(m_sw_22);
		int int_79140 = int(m_sw_9);
		int int_79143 = int(m_sw_13);
		int gt_74176 = (m_bpm_20 > ((t_sample)0.99));
		int sync_78026 = gt_74176;
		int sync_77905 = sync_78026;
		t_sample mstosamps_1 = (((int)0) * (samplerate * 0.001));
		t_sample max_2 = ((mstosamps_1 < vectorsize) ? vectorsize : mstosamps_1);
		int gt_7 = (m_gate_10 > ((int)0));
		t_sample history_74240_next_74267 = fixdenorm(((int)4));
		t_sample max_52 = (samplerate * ((t_sample)0.25));
		t_sample res = ((m_q_21 <= ((int)0)) ? ((int)0) : ((m_q_21 >= ((int)1)) ? ((int)1) : m_q_21));
		bool chan_ignore_62 = ((1 < 0) || (1 >= loop_channels));
		t_sample max_63 = (samplerate * ((t_sample)0.25));
		t_sample res_79162 = ((m_q_21 <= ((int)0)) ? ((int)0) : ((m_q_21 >= ((int)1)) ? ((int)1) : m_q_21));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			int index_trunc_26 = fixnan(floor(m_history_1));
			bool index_ignore_27 = ((index_trunc_26 >= loop_dim) || (index_trunc_26 < 0));
			if ((!(chan_ignore_25 || index_ignore_27))) {
				m_loop_24.write((in1 + (m_loop_24.read(index_trunc_26, ((int)1)) * rsub_34690)), index_trunc_26, ((int)1));
				
			};
			int index_trunc_28 = fixnan(floor(m_history_1));
			bool index_ignore_29 = ((index_trunc_28 >= loop_dim) || (index_trunc_28 < 0));
			if ((!index_ignore_29)) {
				m_loop_24.write((in2 + (m_loop_24.read(index_trunc_28, 0) * rsub_34690)), index_trunc_28, 0);
				
			};
			t_sample noise_43061 = noise();
			t_sample sub_79497 = (noise_43061 - (-1));
			t_sample scale_79494 = ((safepow((sub_79497 * ((t_sample)0.5)), ((int)1)) * orange_79496) + scale_79486);
			int change_83 = __m_change_30(int_82);
			int eqp_84 = ((int_82 == change_83) ? int_82 : 0);
			int gen_89 = eqp_84;
			int gt_69594 = (gen_89 > ((int)0));
			int switch_71591 = (gt_69594 ? ((int)32) : ((int)0));
			int change_79125 = __m_change_31(int_79127);
			int eqp_79126 = ((int_79127 == change_79125) ? int_79127 : 0);
			int gen_90 = eqp_79126;
			int gt_69473 = (gen_90 > ((int)0));
			int switch_71530 = (gt_69473 ? ((int)16) : ((int)0));
			int change_79129 = __m_change_32(int_79130);
			int eqp_79128 = ((int_79130 == change_79129) ? int_79130 : 0);
			int gen_91 = eqp_79128;
			int gt_69352 = (gen_91 > ((int)0));
			int switch_71469 = (gt_69352 ? ((int)8) : ((int)0));
			int change_79132 = __m_change_33(int_79133);
			int eqp_79131 = ((int_79133 == change_79132) ? int_79133 : 0);
			int gen_69170 = eqp_79131;
			int gt_69231 = (gen_69170 > ((int)0));
			int switch_71408 = (gt_69231 ? ((int)4) : ((int)0));
			__m_latch_34 = (((((switch_71408 + switch_71469) + switch_71530) + switch_71591) != 0) ? (((switch_71408 + switch_71469) + switch_71530) + switch_71591) : __m_latch_34);
			int latch_71832 = __m_latch_34;
			int numBeats_64877 = latch_71832;
			t_sample out12 = numBeats_64877;
			int numBeats_62539 = numBeats_64877;
			int eq_62161 = (numBeats_62539 == ((int)16));
			t_sample out5 = eq_62161;
			int eq_62209 = (numBeats_62539 == ((int)32));
			t_sample out6 = eq_62209;
			int eq_61731 = (numBeats_62539 == ((int)4));
			int eq_62113 = (numBeats_62539 == ((int)8));
			t_sample out4 = eq_62113;
			int numBeats_60937 = numBeats_64877;
			t_sample phasor_35 = __m_phasor_35(div_34, samples_to_seconds);
			t_sample gen_41 = phasor_35;
			int change_79135 = __m_change_36(int_79136);
			int eqp_79134 = ((int_79136 == change_79135) ? int_79136 : 0);
			int gen_72314 = eqp_79134;
			int gt_72306 = (gen_72314 > ((int)0));
			int switch_72310 = (gt_72306 ? ((int)4) : ((int)0));
			int change_79138 = __m_change_37(int_79139);
			int eqp_79137 = ((int_79139 == change_79138) ? int_79139 : 0);
			int gen_72313 = eqp_79137;
			int gt_72305 = (gen_72313 > ((int)0));
			int switch_72309 = (gt_72305 ? ((int)8) : ((int)0));
			int change_79142 = __m_change_38(int_79140);
			int eqp_79141 = ((int_79140 == change_79142) ? int_79140 : 0);
			int gen_72312 = eqp_79141;
			int gt_72304 = (gen_72312 > ((int)0));
			int switch_72308 = (gt_72304 ? ((int)16) : ((int)0));
			int change_79145 = __m_change_39(int_79143);
			int eqp_79144 = ((int_79143 == change_79145) ? int_79143 : 0);
			int gen_72311 = eqp_79144;
			int gt_72303 = (gen_72311 > ((int)0));
			int switch_72307 = (gt_72303 ? ((int)32) : ((int)0));
			__m_latch_40 = (((((switch_72307 + switch_72308) + switch_72309) + switch_72310) != 0) ? (((switch_72307 + switch_72308) + switch_72309) + switch_72310) : __m_latch_40);
			int latch_72302 = __m_latch_40;
			int numSlices_64079 = latch_72302;
			int numSlices_64756 = numSlices_64079;
			t_sample out11 = numSlices_64756;
			int numSlices_62635 = numSlices_64079;
			int eq_62684 = (numSlices_62635 == ((int)16));
			t_sample out9 = eq_62684;
			int eq_62685 = (numSlices_62635 == ((int)8));
			t_sample out8 = eq_62685;
			int eq_62686 = (numSlices_62635 == ((int)4));
			t_sample out7 = eq_62686;
			int eq_62683 = (numSlices_62635 == ((int)32));
			t_sample out10 = eq_62683;
			int change_6 = __m_change_41(gt_7);
			int gt_5 = (change_6 > ((int)0));
			int plusequals_4 = __m_pluseq_42.post(((int)1), gt_5, 0);
			int lte_3 = (plusequals_4 <= max_2);
			int gen_8 = lte_3;
			int gt_17 = (gen_8 > ((int)0));
			int change_16 = __m_change_43(gt_17);
			int gt_15 = (change_16 > ((int)0));
			int gen_18 = gt_15;
			t_sample add_23 = (m_history_8 + ((int)1));
			t_sample switch_20 = (gen_18 ? ((int)0) : add_23);
			__m_latch_44 = ((gen_18 != 0) ? add_23 : __m_latch_44);
			t_sample latch_22 = __m_latch_44;
			t_sample gen_25 = latch_22;
			t_sample history_21_next_24 = fixdenorm(switch_20);
			t_sample rdiv_19 = safediv(samplerate, gen_25);
			t_sample div_9 = (rdiv_19 * ((t_sample)0.016666666666667));
			t_sample gen_31 = div_9;
			t_sample rdiv_12 = safediv(((int)1), gen_25);
			t_sample add_14 = (m_history_7 + rdiv_12);
			t_sample switch_11 = (gen_18 ? ((int)0) : add_14);
			t_sample wrap_13 = wrap(switch_11, ((int)0), ((int)1));
			t_sample gen_28 = wrap_13;
			t_sample history_10_next_26 = fixdenorm(wrap_13);
			t_sample switch_77484 = (sync_78026 ? scale_74177 : gen_31);
			t_sample rdiv_55091 = safediv(((int)60), switch_77484);
			t_sample mul_35762 = (rdiv_55091 * samplerate);
			t_sample mul_53155 = (mul_35762 * numBeats_60937);
			t_sample mul_74245 = (gen_28 * ((t_sample)0.25));
			t_sample sub_197 = (gen_28 - m_history_6);
			t_sample add_198 = (gen_28 + m_history_6);
			t_sample div_196 = safediv(sub_197, add_198);
			t_sample abs_195 = fabs(div_196);
			int gt_193 = (abs_195 > ((t_sample)0.5));
			int change_192 = __m_change_45(gt_193);
			int gt_191 = (change_192 > ((int)0));
			int gen_74255 = gt_191;
			t_sample history_194_next_199 = fixdenorm(gen_28);
			t_sample delta_74261 = __m_delta_46(gen_28);
			t_sample wrap_74262 = wrap(delta_74261, (-0.5), ((t_sample)0.5));
			t_sample gen_74263 = wrap_74262;
			t_sample mul_74258 = (gen_74263 * ((t_sample)0.25));
			t_sample add_74256 = (mul_74258 + m_history_3);
			t_sample sub_74243 = (add_74256 - mul_74245);
			t_sample round_74254 = (trunc((sub_74243 * ((t_sample)4))) * ((t_sample)0.25));
			t_sample add_74244 = (round_74254 + mul_74245);
			t_sample sub_74265 = (m_history_4 - ((int)4));
			t_sample add_74266 = (m_history_4 + ((int)4));
			t_sample div_74264 = safediv(sub_74265, add_74266);
			t_sample abs_74238 = fabs(div_74264);
			int gt_74239 = (abs_74238 > ((t_sample)0.015625));
			int and_74242 = (gt_74239 && ((int)1));
			t_sample switch_74246 = (and_74242 ? and_74242 : m_history_5);
			t_sample switch_74249 = (gen_74255 ? switch_74246 : ((int)0));
			t_sample gen_74252 = switch_74249;
			t_sample switch_74248 = (switch_74249 ? ((int)0) : switch_74246);
			t_sample history_74250_next_74251 = fixdenorm(switch_74248);
			int or_74241 = (gen_74252 || ((int)0));
			t_sample switch_74260 = (or_74241 ? add_74244 : add_74256);
			t_sample wrap_74257 = wrap(switch_74260, ((int)0), ((int)1));
			t_sample gen_74269 = wrap_74257;
			t_sample history_74259_next_74268 = fixdenorm(wrap_74257);
			t_sample switch_74175 = (sync_77905 ? gen_41 : gen_74269);
			t_sample mul_635 = (switch_74175 * numSlices_64079);
			t_sample wrap_633 = wrap(mul_635, ((int)0), ((int)1));
			t_sample gen_30595 = wrap_633;
			t_sample rdiv_632 = safediv(((int)1), numSlices_64079);
			t_sample mul_630 = (wrap_633 * rdiv_632);
			t_sample gen_30596 = mul_630;
			t_sample sub_79152 = (gen_30595 - m_history_2);
			t_sample add_79151 = (gen_30595 + m_history_2);
			t_sample div_79150 = safediv(sub_79152, add_79151);
			t_sample abs_79147 = fabs(div_79150);
			int gt_79149 = (abs_79147 > ((t_sample)0.5));
			int change_79148 = __m_change_47(gt_79149);
			int gt_79146 = (change_79148 > ((int)0));
			int gen_28698 = gt_79146;
			t_sample history_194_next_79153 = fixdenorm(gen_30595);
			__m_latch_48 = ((gen_28698 != 0) ? scale_79494 : __m_latch_48);
			t_sample latch_42865 = __m_latch_48;
			t_sample mtof_42083 = mtof(latch_42865, ((int)440));
			t_sample mtof_42474 = mtof(latch_42865, ((int)440));
			t_sample mul_33087 = (switch_74175 * m_jump_18);
			int numBeats_60976 = numBeats_64877;
			t_sample noise_31482 = noise();
			t_sample mul_31661 = (noise_31482 * m_randomness_17);
			t_sample div_52509 = safediv(mul_31661, numBeats_60976);
			t_sample add_51003 = (div_52509 + mul_33087);
			t_sample mul_79160 = (add_51003 * numSlices_64079);
			t_sample floor_79156 = floor(mul_79160);
			t_sample rdiv_79158 = safediv(((int)1), numSlices_64079);
			t_sample mul_79157 = (floor_79156 * rdiv_79158);
			t_sample gen_27488 = mul_79157;
			__m_latch_49 = ((gen_28698 != 0) ? gen_27488 : __m_latch_49);
			t_sample latch_28525 = __m_latch_49;
			t_sample add_29215 = (latch_28525 + gen_30596);
			t_sample wrap_29560 = wrap(add_29215, ((int)0), ((int)1));
			t_sample mul_55524 = (wrap_29560 * mul_53155);
			int index_trunc_50 = fixnan(floor(mul_55524));
			bool index_ignore_51 = ((index_trunc_50 >= loop_dim) || (index_trunc_50 < 0));
			// samples loop channel 1;
			t_sample sample_loop_57018 = (index_ignore_51 ? 0 : m_loop_24.read(index_trunc_50, 0));
			t_sample index_loop_57019 = mul_55524;
			t_sample cf = ((mtof_42083 <= ((int)20)) ? ((int)20) : ((mtof_42083 >= max_52) ? max_52 : mtof_42083));
			t_sample expr_79123 = moogLadder_d_d_d(sample_loop_57018, cf, res);
			t_sample out1 = (eq_61731 + expr_79123);
			int index_trunc_60 = fixnan(floor(mul_55524));
			bool index_ignore_61 = ((index_trunc_60 >= loop_dim) || (index_trunc_60 < 0));
			// samples loop channel 1;
			t_sample sample_loop_57235 = ((chan_ignore_62 || index_ignore_61) ? 0 : m_loop_24.read(index_trunc_60, 1));
			t_sample index_loop_57236 = mul_55524;
			t_sample cf_79163 = ((mtof_42474 <= ((int)20)) ? ((int)20) : ((mtof_42474 >= max_63) ? max_63 : mtof_42474));
			t_sample expr_79121 = moogLadder_d_d_d_64(sample_loop_57235, cf_79163, res_79162);
			t_sample out2 = expr_79121;
			t_sample history_64250_next_79164 = fixdenorm(mul_55524);
			m_history_8 = history_21_next_24;
			m_history_7 = history_10_next_26;
			m_history_6 = history_194_next_199;
			m_history_3 = history_74259_next_74268;
			m_history_4 = history_74240_next_74267;
			m_history_5 = history_74250_next_74251;
			m_history_2 = history_194_next_79153;
			m_history_1 = history_64250_next_79164;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = 0;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			(*(__out7++)) = out7;
			(*(__out8++)) = out8;
			(*(__out9++)) = out9;
			(*(__out10++)) = out10;
			(*(__out11++)) = out11;
			(*(__out12++)) = out12;
			
		};
		return __exception;
		
	};
	inline void set_sw7(t_param _value) {
		m_sw_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_10 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_overdub(t_param _value) {
		m_overdub_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_randomness(t_param _value) {
		m_randomness_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_jump(t_param _value) {
		m_jump_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bpm(t_param _value) {
		m_bpm_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_q(t_param _value) {
		m_q_21 = (_value < 0 ? 0 : (_value > 0.999 ? 0.999 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_spread(t_param _value) {
		m_spread_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop(void * _value) {
		m_loop_24.setbuffer(_value);
	};
	inline t_sample moogLadder_d_d_d(t_sample asig, t_sample cf, t_sample res) {
		int i2v = ((int)40000);
		t_sample akfc = safediv(cf, (samplerate * ((t_sample)0.5)));
		t_sample akf = safediv(cf, samplerate);
		t_sample fcr = ((((((t_sample)1.873) * safepow(akfc, ((int)3))) + (((t_sample)0.4955) * safepow(akfc, ((int)2)))) - (((t_sample)0.649) * akfc)) + ((t_sample)0.9988));
		t_sample acr = ((((-((t_sample)3.9364)) * safepow(akfc, ((int)2))) + (((t_sample)1.8409) * akfc)) + ((t_sample)0.9968));
		t_sample twovg = (i2v * (((int)1) - exp(((((-((int)2)) * ((t_sample)3.1415926535898)) * fcr) * akf))));
		t_sample y1 = (m_z_59 + (twovg * (tanh(safediv((asig - (((((int)4) * res) * m_mf_53) * acr)), i2v)) - tanh(safediv(m_z_59, i2v)))));
		m_z_59 = y1;
		t_sample y2 = (m_z_58 + (twovg * (tanh(safediv(y1, i2v)) - tanh(safediv(m_z_58, i2v)))));
		m_z_58 = y2;
		t_sample y3 = (m_z_57 + (twovg * (tanh(safediv(y2, i2v)) - tanh(safediv(m_z_57, i2v)))));
		m_z_57 = y3;
		m_y_54 = (m_z_56 + (twovg * (tanh(safediv(y3, i2v)) - tanh(safediv(m_z_56, i2v)))));
		m_z_56 = m_y_54;
		m_mf_53 = ((m_y_54 + m_z_55) * ((t_sample)0.5));
		m_z_55 = m_y_54;
		return m_mf_53;
		
	};
	inline t_sample moogLadder_d_d_d_64(t_sample asig, t_sample cf, t_sample res) {
		int i2v = ((int)40000);
		t_sample akfc = safediv(cf, (samplerate * ((t_sample)0.5)));
		t_sample akf = safediv(cf, samplerate);
		t_sample fcr = ((((((t_sample)1.873) * safepow(akfc, ((int)3))) + (((t_sample)0.4955) * safepow(akfc, ((int)2)))) - (((t_sample)0.649) * akfc)) + ((t_sample)0.9988));
		t_sample acr = ((((-((t_sample)3.9364)) * safepow(akfc, ((int)2))) + (((t_sample)1.8409) * akfc)) + ((t_sample)0.9968));
		t_sample twovg = (i2v * (((int)1) - exp(((((-((int)2)) * ((t_sample)3.1415926535898)) * fcr) * akf))));
		t_sample y1 = (m_z_71 + (twovg * (tanh(safediv((asig - (((((int)4) * res) * m_mf_65) * acr)), i2v)) - tanh(safediv(m_z_71, i2v)))));
		m_z_71 = y1;
		t_sample y2 = (m_z_70 + (twovg * (tanh(safediv(y1, i2v)) - tanh(safediv(m_z_70, i2v)))));
		m_z_70 = y2;
		t_sample y3 = (m_z_69 + (twovg * (tanh(safediv(y2, i2v)) - tanh(safediv(m_z_69, i2v)))));
		m_z_69 = y3;
		m_y_66 = (m_z_68 + (twovg * (tanh(safediv(y3, i2v)) - tanh(safediv(m_z_68, i2v)))));
		m_z_68 = m_y_66;
		m_mf_65 = ((m_y_66 + m_z_67) * ((t_sample)0.5));
		m_z_67 = m_y_66;
		return m_mf_65;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 12;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 16; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "cvout1", "out12" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_bpm(value); break;
		case 1: self->set_gate1(value); break;
		case 2: self->set_jump(value); break;
		case 3: self->set_loop(ref); break;
		case 4: self->set_overdub(value); break;
		case 5: self->set_q(value); break;
		case 6: self->set_randomness(value); break;
		case 7: self->set_spread(value); break;
		case 8: self->set_sw1(value); break;
		case 9: self->set_sw2(value); break;
		case 10: self->set_sw3(value); break;
		case 11: self->set_sw4(value); break;
		case 12: self->set_sw5(value); break;
		case 13: self->set_sw6(value); break;
		case 14: self->set_sw7(value); break;
		case 15: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_bpm_20; break;
		case 1: *value = self->m_gate_10; break;
		case 2: *value = self->m_jump_18; break;
		
		case 4: *value = self->m_overdub_14; break;
		case 5: *value = self->m_q_21; break;
		case 6: *value = self->m_randomness_17; break;
		case 7: *value = self->m_spread_23; break;
		case 8: *value = self->m_sw_15; break;
		case 9: *value = self->m_sw_12; break;
		case 10: *value = self->m_sw_16; break;
		case 11: *value = self->m_sw_11; break;
		case 12: *value = self->m_sw_19; break;
		case 13: *value = self->m_sw_22; break;
		case 14: *value = self->m_sw_9; break;
		case 15: *value = self->m_sw_13; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(16 * sizeof(ParamInfo));
	self->__commonstate.numparams = 16;
	// initialize parameter 0 ("m_bpm_20")
	pi = self->__commonstate.params + 0;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_gate_10")
	pi = self->__commonstate.params + 1;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_jump_18")
	pi = self->__commonstate.params + 2;
	pi->name = "jump";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_jump_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_loop_24")
	pi = self->__commonstate.params + 3;
	pi->name = "loop";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_overdub_14")
	pi = self->__commonstate.params + 4;
	pi->name = "overdub";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_overdub_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_q_21")
	pi = self->__commonstate.params + 5;
	pi->name = "q";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_q_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.999;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_randomness_17")
	pi = self->__commonstate.params + 6;
	pi->name = "randomness";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_randomness_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_spread_23")
	pi = self->__commonstate.params + 7;
	pi->name = "spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_spread_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_sw_15")
	pi = self->__commonstate.params + 8;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_12")
	pi = self->__commonstate.params + 9;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_16")
	pi = self->__commonstate.params + 10;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_sw_11")
	pi = self->__commonstate.params + 11;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_19")
	pi = self->__commonstate.params + 12;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_22")
	pi = self->__commonstate.params + 13;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_sw_9")
	pi = self->__commonstate.params + 14;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_13")
	pi = self->__commonstate.params + 15;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // slicer::
