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
	Change __m_change_43;
	Change __m_change_35;
	Change __m_change_45;
	Change __m_change_42;
	Change __m_change_41;
	Change __m_change_40;
	Change __m_change_47;
	Change __m_change_49;
	Change __m_change_37;
	Change __m_change_36;
	Change __m_change_51;
	Change __m_change_38;
	Data m_loop_28;
	Delta __m_delta_52;
	Phasor __m_phasor_34;
	PlusEquals __m_pluseq_48;
	int __exception;
	int vectorsize;
	t_sample samplerate;
	t_sample __m_latch_50;
	t_sample m_transposition_15;
	t_sample __m_latch_53;
	t_sample m_mf_57;
	t_sample m_history_1;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample m_history_4;
	t_sample __m_latch_46;
	t_sample __m_latch_44;
	t_sample m_y_58;
	t_sample m_z_60;
	t_sample m_z_71;
	t_sample m_z_72;
	t_sample m_z_73;
	t_sample m_z_59;
	t_sample m_y_70;
	t_sample m_z_63;
	t_sample m_mf_69;
	t_sample m_z_61;
	t_sample m_z_62;
	t_sample m_spread_14;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_inversion_22;
	t_sample m_sw_21;
	t_sample m_gate_23;
	t_sample m_sw_24;
	t_sample m_sw_25;
	t_sample m_overdub_20;
	t_sample m_sw_18;
	t_sample m_bpm_19;
	t_sample m_sw_16;
	t_sample m_randomness_17;
	t_sample m_history_6;
	t_sample m_sw_26;
	t_sample m_jump_13;
	t_sample m_q_9;
	t_sample __m_latch_39;
	t_sample m_history_8;
	t_sample m_sw_27;
	t_sample m_K_10;
	t_sample m_N_12;
	t_sample m_sw_11;
	t_sample samples_to_seconds;
	t_sample m_z_74;
	t_sample m_z_75;
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
		m_q_9 = ((int)0);
		m_K_10 = ((int)7);
		m_sw_11 = ((int)0);
		m_N_12 = ((int)12);
		m_jump_13 = 1.25;
		m_spread_14 = ((int)0);
		m_transposition_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_randomness_17 = 1;
		m_sw_18 = ((int)0);
		m_bpm_19 = ((int)0);
		m_overdub_20 = ((int)0);
		m_sw_21 = ((int)0);
		m_inversion_22 = ((int)0);
		m_gate_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_sw_26 = ((int)0);
		m_sw_27 = ((int)0);
		m_loop_28.reset("loop", ((int)352800), ((int)2));
		samples_to_seconds = (1 / samplerate);
		__m_phasor_34.reset(0);
		__m_change_35.reset(0);
		__m_change_36.reset(0);
		__m_change_37.reset(0);
		__m_change_38.reset(0);
		__m_latch_39 = 0;
		__m_change_40.reset(0);
		__m_change_41.reset(0);
		__m_change_42.reset(0);
		__m_change_43.reset(0);
		__m_latch_44 = 0;
		__m_change_45.reset(0);
		__m_latch_46 = 0;
		__m_change_47.reset(0);
		__m_pluseq_48.reset(0);
		__m_change_49.reset(0);
		__m_latch_50 = 11025;
		__m_change_51.reset(0);
		__m_delta_52.reset(0);
		__m_latch_53 = 0;
		m_mf_57 = ((int)0);
		m_y_58 = ((int)0);
		m_z_59 = ((int)0);
		m_z_60 = ((int)0);
		m_z_61 = ((int)0);
		m_z_62 = ((int)0);
		m_z_63 = ((int)0);
		m_mf_69 = ((int)0);
		m_y_70 = ((int)0);
		m_z_71 = ((int)0);
		m_z_72 = ((int)0);
		m_z_73 = ((int)0);
		m_z_74 = ((int)0);
		m_z_75 = ((int)0);
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
		t_sample rsub_153 = (((int)1) - m_overdub_20);
		int loop_dim = m_loop_28.dim;
		int loop_channels = m_loop_28.channels;
		bool chan_ignore_29 = ((((int)1) < 0) || (((int)1) >= loop_channels));
		t_sample sub_363 = (m_spread_14 - ((int)0));
		t_sample scale_360 = ((safepow((sub_363 * ((t_sample)1)), ((int)1)) * ((int)-60)) + ((int)60));
		t_sample sub_367 = (m_spread_14 - ((int)0));
		t_sample scale_364 = ((safepow((sub_367 * ((t_sample)1)), ((int)1)) * ((int)67)) + ((int)60));
		t_sample orange_370 = (scale_364 - scale_360);
		t_sample sub_375 = (m_bpm_19 - ((int)0));
		t_sample scale_372 = ((safepow((sub_375 * ((t_sample)1)), ((int)1)) * ((int)160)) + ((int)40));
		t_sample scale_97 = scale_372;
		t_sample div_222 = (scale_97 * ((t_sample)0.016666666666667));
		t_sample mul_224 = (div_222 * ((int)1));
		t_sample div_219 = (mul_224 * ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		int int_107 = int(m_sw_16);
		int int_237 = int(m_sw_25);
		int int_240 = int(m_sw_11);
		int int_243 = int(m_sw_26);
		int int_246 = int(m_sw_18);
		int int_249 = int(m_sw_21);
		int int_252 = int(m_sw_27);
		int int_255 = int(m_sw_24);
		int lt_96 = (m_bpm_19 < ((t_sample)0.01));
		int sync_50 = lt_96;
		t_sample mstosamps_186 = (((int)0) * (samplerate * 0.001));
		t_sample max_187 = ((mstosamps_186 < vectorsize) ? vectorsize : mstosamps_186);
		int gt_192 = (m_gate_23 > ((int)0));
		int sync_51 = sync_50;
		t_sample history_56_next_92 = fixdenorm(((int)4));
		t_sample max_56 = (samplerate * ((t_sample)0.25));
		t_sample res = ((m_q_9 <= ((int)0)) ? ((int)0) : ((m_q_9 >= ((int)1)) ? ((int)1) : m_q_9));
		bool chan_ignore_66 = ((1 < 0) || (1 >= loop_channels));
		t_sample max_67 = (samplerate * ((t_sample)0.25));
		t_sample res_273 = ((m_q_9 <= ((int)0)) ? ((int)0) : ((m_q_9 >= ((int)1)) ? ((int)1) : m_q_9));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out12 = ((int)0);
			t_sample out11 = ((int)0);
			int index_trunc_30 = fixnan(floor(m_history_1));
			bool index_ignore_31 = ((index_trunc_30 >= loop_dim) || (index_trunc_30 < 0));
			if ((!(chan_ignore_29 || index_ignore_31))) {
				m_loop_28.write((in1 + (m_loop_28.read(index_trunc_30, ((int)1)) * rsub_153)), index_trunc_30, ((int)1));
				
			};
			int index_trunc_32 = fixnan(floor(m_history_1));
			bool index_ignore_33 = ((index_trunc_32 >= loop_dim) || (index_trunc_32 < 0));
			if ((!index_ignore_33)) {
				m_loop_28.write((in2 + (m_loop_28.read(index_trunc_32, 0) * rsub_153)), index_trunc_32, 0);
				
			};
			t_sample noise_142 = noise();
			t_sample sub_371 = (noise_142 - (-1));
			t_sample scale_368 = ((safepow((sub_371 * ((t_sample)0.5)), ((int)1)) * orange_370) + scale_360);
			t_sample phasor_220 = __m_phasor_34(div_219, samples_to_seconds);
			t_sample gen_226 = phasor_220;
			int change_108 = __m_change_35(int_107);
			int eqp_109 = ((int_107 == change_108) ? int_107 : 0);
			int gen_230 = eqp_109;
			int gt_118 = (gen_230 > ((int)0));
			int switch_122 = (gt_118 ? ((int)4) : ((int)0));
			int change_235 = __m_change_36(int_237);
			int eqp_236 = ((int_237 == change_235) ? int_237 : 0);
			int gen_229 = eqp_236;
			int gt_117 = (gen_229 > ((int)0));
			int switch_121 = (gt_117 ? ((int)8) : ((int)0));
			int change_239 = __m_change_37(int_240);
			int eqp_238 = ((int_240 == change_239) ? int_240 : 0);
			int gen_228 = eqp_238;
			int gt_116 = (gen_228 > ((int)0));
			int switch_120 = (gt_116 ? ((int)16) : ((int)0));
			int change_242 = __m_change_38(int_243);
			int eqp_241 = ((int_243 == change_242) ? int_243 : 0);
			int gen_227 = eqp_241;
			int gt_115 = (gen_227 > ((int)0));
			int switch_119 = (gt_115 ? ((int)32) : ((int)0));
			__m_latch_39 = (((((switch_119 + switch_120) + switch_121) + switch_122) != 0) ? (((switch_119 + switch_120) + switch_121) + switch_122) : __m_latch_39);
			int latch_114 = __m_latch_39;
			int numBeats_133 = latch_114;
			int neq_132 = (numBeats_133 != ((int)4));
			int neq_130 = (numBeats_133 != ((int)16));
			t_sample out5 = neq_130;
			int neq_131 = (numBeats_133 != ((int)8));
			t_sample out4 = neq_131;
			int neq_129 = (numBeats_133 != ((int)32));
			t_sample out6 = neq_129;
			int numBeats_137 = numBeats_133;
			int change_245 = __m_change_40(int_246);
			int eqp_244 = ((int_246 == change_245) ? int_246 : 0);
			int gen_110 = eqp_244;
			int gt_99 = (gen_110 > ((int)0));
			int switch_103 = (gt_99 ? ((int)32) : ((int)0));
			int change_248 = __m_change_41(int_249);
			int eqp_247 = ((int_249 == change_248) ? int_249 : 0);
			int gen_111 = eqp_247;
			int gt_100 = (gen_111 > ((int)0));
			int switch_104 = (gt_100 ? ((int)16) : ((int)0));
			int change_251 = __m_change_42(int_252);
			int eqp_250 = ((int_252 == change_251) ? int_252 : 0);
			int gen_112 = eqp_250;
			int gt_101 = (gen_112 > ((int)0));
			int switch_105 = (gt_101 ? ((int)8) : ((int)0));
			int change_254 = __m_change_43(int_255);
			int eqp_253 = ((int_255 == change_254) ? int_255 : 0);
			int gen_113 = eqp_253;
			int gt_102 = (gen_113 > ((int)0));
			int switch_106 = (gt_102 ? ((int)4) : ((int)0));
			__m_latch_44 = (((((switch_106 + switch_105) + switch_104) + switch_103) != 0) ? (((switch_106 + switch_105) + switch_104) + switch_103) : __m_latch_44);
			int latch_98 = __m_latch_44;
			int numSlices_135 = latch_98;
			int numSlices_128 = numSlices_135;
			int neq_126 = (numSlices_128 != ((int)8));
			t_sample out8 = neq_126;
			int neq_127 = (numSlices_128 != ((int)4));
			t_sample out7 = neq_127;
			int neq_125 = (numSlices_128 != ((int)16));
			t_sample out9 = neq_125;
			int neq_124 = (numSlices_128 != ((int)32));
			t_sample out10 = neq_124;
			t_sample mul_163 = (gen_226 * numSlices_135);
			t_sample wrap_161 = wrap(mul_163, ((int)0), ((int)1));
			t_sample gen_166 = wrap_161;
			t_sample rdiv_160 = safediv(((int)1), numSlices_135);
			t_sample mul_158 = (wrap_161 * rdiv_160);
			t_sample gen_167 = mul_158;
			t_sample sub_77 = (gen_166 - m_history_8);
			t_sample add_78 = (gen_166 + m_history_8);
			t_sample div_76 = safediv(sub_77, add_78);
			t_sample abs_75 = fabs(div_76);
			int gt_73 = (abs_75 > ((t_sample)0.5));
			int change_72 = __m_change_45(gt_73);
			int gt_71 = (change_72 > ((int)0));
			int gen_171 = gt_71;
			t_sample history_74_next_79 = fixdenorm(gen_166);
			__m_latch_46 = ((gen_171 != 0) ? scale_368 : __m_latch_46);
			t_sample latch_143 = __m_latch_46;
			t_sample mtof_145 = mtof(latch_143, ((int)440));
			t_sample mtof_144 = mtof(latch_143, ((int)440));
			int change_191 = __m_change_47(gt_192);
			int gt_190 = (change_191 > ((int)0));
			int plusequals_189 = __m_pluseq_48.post(((int)1), gt_190, 0);
			int lte_188 = (plusequals_189 <= max_187);
			int gen_193 = lte_188;
			int gt_202 = (gen_193 > ((int)0));
			int change_201 = __m_change_49(gt_202);
			int gt_200 = (change_201 > ((int)0));
			int gen_203 = gt_200;
			t_sample add_208 = (m_history_7 + ((int)1));
			__m_latch_50 = ((gen_203 != 0) ? add_208 : __m_latch_50);
			t_sample latch_207 = __m_latch_50;
			t_sample gen_210 = latch_207;
			t_sample switch_205 = (gen_203 ? ((int)0) : add_208);
			t_sample history_206_next_209 = fixdenorm(switch_205);
			t_sample rdiv_204 = safediv(samplerate, gen_210);
			t_sample div_194 = (rdiv_204 * ((t_sample)0.016666666666667));
			t_sample gen_216 = div_194;
			t_sample rdiv_197 = safediv(((int)1), gen_210);
			t_sample add_199 = (m_history_6 + rdiv_197);
			t_sample switch_196 = (gen_203 ? ((int)0) : add_199);
			t_sample wrap_198 = wrap(switch_196, ((int)0), ((int)1));
			t_sample gen_213 = wrap_198;
			t_sample history_195_next_211 = fixdenorm(wrap_198);
			t_sample switch_52 = (sync_50 ? gen_216 : scale_97);
			t_sample rdiv_151 = safediv(((int)60), switch_52);
			t_sample mul_152 = (rdiv_151 * samplerate);
			t_sample mul_150 = (mul_152 * numBeats_137);
			int numBeats_136 = numBeats_133;
			t_sample noise_157 = noise();
			t_sample mul_156 = (noise_157 * m_randomness_17);
			t_sample div_155 = safediv(mul_156, numBeats_136);
			t_sample mul_61 = (gen_213 * ((t_sample)0.25));
			t_sample sub_263 = (gen_213 - m_history_5);
			t_sample add_258 = (gen_213 + m_history_5);
			t_sample div_257 = safediv(sub_263, add_258);
			t_sample abs_261 = fabs(div_257);
			int gt_259 = (abs_261 > ((t_sample)0.5));
			int change_262 = __m_change_51(gt_259);
			int gt_264 = (change_262 > ((int)0));
			int gen_80 = gt_264;
			t_sample history_74_next_256 = fixdenorm(gen_213);
			t_sample delta_86 = __m_delta_52(gen_213);
			t_sample wrap_87 = wrap(delta_86, (-0.5), ((t_sample)0.5));
			t_sample gen_88 = wrap_87;
			t_sample mul_83 = (gen_88 * ((t_sample)0.25));
			t_sample add_81 = (mul_83 + m_history_2);
			t_sample sub_59 = (add_81 - mul_61);
			t_sample round_70 = (trunc((sub_59 * ((t_sample)4))) * ((t_sample)0.25));
			t_sample add_60 = (round_70 + mul_61);
			t_sample sub_90 = (m_history_3 - ((int)4));
			t_sample add_91 = (m_history_3 + ((int)4));
			t_sample div_89 = safediv(sub_90, add_91);
			t_sample abs_54 = fabs(div_89);
			int gt_55 = (abs_54 > ((t_sample)0.015625));
			int and_58 = (gt_55 && ((int)1));
			t_sample switch_62 = (and_58 ? and_58 : m_history_4);
			t_sample switch_65 = (gen_80 ? switch_62 : ((int)0));
			t_sample gen_68 = switch_65;
			t_sample switch_64 = (switch_65 ? ((int)0) : switch_62);
			t_sample history_66_next_67 = fixdenorm(switch_64);
			int or_57 = (gen_68 || ((int)0));
			t_sample switch_85 = (or_57 ? add_60 : add_81);
			t_sample wrap_82 = wrap(switch_85, ((int)0), ((int)1));
			t_sample gen_94 = wrap_82;
			t_sample history_84_next_93 = fixdenorm(wrap_82);
			t_sample switch_95 = (sync_51 ? gen_94 : gen_226);
			t_sample mul_154 = (switch_95 * m_jump_13);
			t_sample add_138 = (div_155 + mul_154);
			t_sample mul_271 = (add_138 * numSlices_135);
			t_sample floor_266 = floor(mul_271);
			t_sample rdiv_270 = safediv(((int)1), numSlices_135);
			t_sample mul_267 = (floor_266 * rdiv_270);
			t_sample gen_174 = mul_267;
			__m_latch_53 = ((gen_171 != 0) ? gen_174 : __m_latch_53);
			t_sample latch_172 = __m_latch_53;
			t_sample add_170 = (latch_172 + gen_167);
			t_sample wrap_169 = wrap(add_170, ((int)0), ((int)1));
			t_sample mul_134 = (wrap_169 * mul_150);
			int index_trunc_54 = fixnan(floor(mul_134));
			bool index_ignore_55 = ((index_trunc_54 >= loop_dim) || (index_trunc_54 < 0));
			// samples loop channel 1;
			t_sample sample_loop_182 = (index_ignore_55 ? 0 : m_loop_28.read(index_trunc_54, 0));
			t_sample index_loop_183 = mul_134;
			t_sample cf = ((mtof_145 <= ((int)20)) ? ((int)20) : ((mtof_145 >= max_56) ? max_56 : mtof_145));
			t_sample expr_231 = moogLadder_d_d_d(sample_loop_182, cf, res);
			t_sample out1 = (neq_132 + expr_231);
			int index_trunc_64 = fixnan(floor(mul_134));
			bool index_ignore_65 = ((index_trunc_64 >= loop_dim) || (index_trunc_64 < 0));
			// samples loop channel 1;
			t_sample sample_loop_180 = ((chan_ignore_66 || index_ignore_65) ? 0 : m_loop_28.read(index_trunc_64, 1));
			t_sample index_loop_181 = mul_134;
			t_sample cf_272 = ((mtof_144 <= ((int)20)) ? ((int)20) : ((mtof_144 >= max_67) ? max_67 : mtof_144));
			t_sample expr_233 = moogLadder_d_d_d_68(sample_loop_180, cf_272, res_273);
			t_sample out2 = expr_233;
			t_sample history_123_next_274 = fixdenorm(mul_134);
			m_history_8 = history_74_next_79;
			m_history_7 = history_206_next_209;
			m_history_6 = history_195_next_211;
			m_history_5 = history_74_next_256;
			m_history_2 = history_84_next_93;
			m_history_3 = history_56_next_92;
			m_history_4 = history_66_next_67;
			m_history_1 = history_123_next_274;
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
	inline void set_q(t_param _value) {
		m_q_9 = (_value < 0 ? 0 : (_value > 0.999 ? 0.999 : _value));
	};
	inline void set_K(t_param _value) {
		m_K_10 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_N(t_param _value) {
		m_N_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_jump(t_param _value) {
		m_jump_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_spread(t_param _value) {
		m_spread_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_transposition(t_param _value) {
		m_transposition_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_randomness(t_param _value) {
		m_randomness_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bpm(t_param _value) {
		m_bpm_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_overdub(t_param _value) {
		m_overdub_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_inversion(t_param _value) {
		m_inversion_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop(void * _value) {
		m_loop_28.setbuffer(_value);
	};
	inline t_sample moogLadder_d_d_d(t_sample asig, t_sample cf, t_sample res) {
		int i2v = ((int)40000);
		t_sample akfc = safediv(cf, (samplerate * ((t_sample)0.5)));
		t_sample akf = safediv(cf, samplerate);
		t_sample fcr = ((((((t_sample)1.873) * safepow(akfc, ((int)3))) + (((t_sample)0.4955) * safepow(akfc, ((int)2)))) - (((t_sample)0.649) * akfc)) + ((t_sample)0.9988));
		t_sample acr = ((((-((t_sample)3.9364)) * safepow(akfc, ((int)2))) + (((t_sample)1.8409) * akfc)) + ((t_sample)0.9968));
		t_sample twovg = (i2v * (((int)1) - exp(((((-((int)2)) * ((t_sample)3.1415926535898)) * fcr) * akf))));
		t_sample y1 = (m_z_63 + (twovg * (tanh(safediv((asig - (((((int)4) * res) * m_mf_57) * acr)), i2v)) - tanh(safediv(m_z_63, i2v)))));
		m_z_63 = y1;
		t_sample y2 = (m_z_62 + (twovg * (tanh(safediv(y1, i2v)) - tanh(safediv(m_z_62, i2v)))));
		m_z_62 = y2;
		t_sample y3 = (m_z_61 + (twovg * (tanh(safediv(y2, i2v)) - tanh(safediv(m_z_61, i2v)))));
		m_z_61 = y3;
		m_y_58 = (m_z_60 + (twovg * (tanh(safediv(y3, i2v)) - tanh(safediv(m_z_60, i2v)))));
		m_z_60 = m_y_58;
		m_mf_57 = ((m_y_58 + m_z_59) * ((t_sample)0.5));
		m_z_59 = m_y_58;
		return m_mf_57;
		
	};
	inline t_sample moogLadder_d_d_d_68(t_sample asig, t_sample cf, t_sample res) {
		int i2v = ((int)40000);
		t_sample akfc = safediv(cf, (samplerate * ((t_sample)0.5)));
		t_sample akf = safediv(cf, samplerate);
		t_sample fcr = ((((((t_sample)1.873) * safepow(akfc, ((int)3))) + (((t_sample)0.4955) * safepow(akfc, ((int)2)))) - (((t_sample)0.649) * akfc)) + ((t_sample)0.9988));
		t_sample acr = ((((-((t_sample)3.9364)) * safepow(akfc, ((int)2))) + (((t_sample)1.8409) * akfc)) + ((t_sample)0.9968));
		t_sample twovg = (i2v * (((int)1) - exp(((((-((int)2)) * ((t_sample)3.1415926535898)) * fcr) * akf))));
		t_sample y1 = (m_z_75 + (twovg * (tanh(safediv((asig - (((((int)4) * res) * m_mf_69) * acr)), i2v)) - tanh(safediv(m_z_75, i2v)))));
		m_z_75 = y1;
		t_sample y2 = (m_z_74 + (twovg * (tanh(safediv(y1, i2v)) - tanh(safediv(m_z_74, i2v)))));
		m_z_74 = y2;
		t_sample y3 = (m_z_73 + (twovg * (tanh(safediv(y2, i2v)) - tanh(safediv(m_z_73, i2v)))));
		m_z_73 = y3;
		m_y_70 = (m_z_72 + (twovg * (tanh(safediv(y3, i2v)) - tanh(safediv(m_z_72, i2v)))));
		m_z_72 = m_y_70;
		m_mf_69 = ((m_y_70 + m_z_71) * ((t_sample)0.5));
		m_z_71 = m_y_70;
		return m_mf_69;
		
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
int num_params() { return 20; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "led1", "out2", "out3", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "cvout1", "cvout2" };

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
		case 0: self->set_K(value); break;
		case 1: self->set_N(value); break;
		case 2: self->set_bpm(value); break;
		case 3: self->set_gate1(value); break;
		case 4: self->set_inversion(value); break;
		case 5: self->set_jump(value); break;
		case 6: self->set_loop(ref); break;
		case 7: self->set_overdub(value); break;
		case 8: self->set_q(value); break;
		case 9: self->set_randomness(value); break;
		case 10: self->set_spread(value); break;
		case 11: self->set_sw1(value); break;
		case 12: self->set_sw2(value); break;
		case 13: self->set_sw3(value); break;
		case 14: self->set_sw4(value); break;
		case 15: self->set_sw5(value); break;
		case 16: self->set_sw6(value); break;
		case 17: self->set_sw7(value); break;
		case 18: self->set_sw8(value); break;
		case 19: self->set_transposition(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_K_10; break;
		case 1: *value = self->m_N_12; break;
		case 2: *value = self->m_bpm_19; break;
		case 3: *value = self->m_gate_23; break;
		case 4: *value = self->m_inversion_22; break;
		case 5: *value = self->m_jump_13; break;
		
		case 7: *value = self->m_overdub_20; break;
		case 8: *value = self->m_q_9; break;
		case 9: *value = self->m_randomness_17; break;
		case 10: *value = self->m_spread_14; break;
		case 11: *value = self->m_sw_16; break;
		case 12: *value = self->m_sw_25; break;
		case 13: *value = self->m_sw_11; break;
		case 14: *value = self->m_sw_26; break;
		case 15: *value = self->m_sw_24; break;
		case 16: *value = self->m_sw_27; break;
		case 17: *value = self->m_sw_21; break;
		case 18: *value = self->m_sw_18; break;
		case 19: *value = self->m_transposition_15; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(20 * sizeof(ParamInfo));
	self->__commonstate.numparams = 20;
	// initialize parameter 0 ("m_K_10")
	pi = self->__commonstate.params + 0;
	pi->name = "K";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_K_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_N_12")
	pi = self->__commonstate.params + 1;
	pi->name = "N";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_N_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_bpm_19")
	pi = self->__commonstate.params + 2;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_gate_23")
	pi = self->__commonstate.params + 3;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_inversion_22")
	pi = self->__commonstate.params + 4;
	pi->name = "inversion";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_inversion_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_jump_13")
	pi = self->__commonstate.params + 5;
	pi->name = "jump";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_jump_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_loop_28")
	pi = self->__commonstate.params + 6;
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
	// initialize parameter 7 ("m_overdub_20")
	pi = self->__commonstate.params + 7;
	pi->name = "overdub";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_overdub_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_q_9")
	pi = self->__commonstate.params + 8;
	pi->name = "q";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_q_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.999;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_randomness_17")
	pi = self->__commonstate.params + 9;
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
	// initialize parameter 10 ("m_spread_14")
	pi = self->__commonstate.params + 10;
	pi->name = "spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_spread_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_sw_16")
	pi = self->__commonstate.params + 11;
	pi->name = "sw1";
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
	// initialize parameter 12 ("m_sw_25")
	pi = self->__commonstate.params + 12;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_11")
	pi = self->__commonstate.params + 13;
	pi->name = "sw3";
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
	// initialize parameter 14 ("m_sw_26")
	pi = self->__commonstate.params + 14;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_24")
	pi = self->__commonstate.params + 15;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_sw_27")
	pi = self->__commonstate.params + 16;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_21")
	pi = self->__commonstate.params + 17;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_18")
	pi = self->__commonstate.params + 18;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_transposition_15")
	pi = self->__commonstate.params + 19;
	pi->name = "transposition";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_transposition_15;
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
