#include "grains.h"

namespace grains {

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
	Data m_switches_35;
	Data m_pswitches_55;
	Data m_src_45;
	Delta __m_delta_75;
	Phasor __m_phasor_74;
	PlusEquals __m_pluseq_335;
	PlusEquals __m_pluseq_110;
	PlusEquals __m_pluseq_260;
	PlusEquals __m_pluseq_380;
	PlusEquals __m_pluseq_350;
	PlusEquals __m_pluseq_245;
	PlusEquals __m_pluseq_155;
	PlusEquals __m_pluseq_230;
	PlusEquals __m_pluseq_140;
	PlusEquals __m_pluseq_395;
	PlusEquals __m_pluseq_215;
	PlusEquals __m_pluseq_95;
	PlusEquals __m_pluseq_185;
	PlusEquals __m_pluseq_80;
	PlusEquals __m_pluseq_425;
	PlusEquals __m_pluseq_290;
	PlusEquals __m_pluseq_365;
	PlusEquals __m_pluseq_200;
	PlusEquals __m_pluseq_170;
	PlusEquals __m_pluseq_320;
	PlusEquals __m_pluseq_305;
	PlusEquals __m_pluseq_275;
	PlusEquals __m_pluseq_410;
	PlusEquals __m_pluseq_125;
	int __exception;
	int vectorsize;
	t_sample __m_latch_202;
	t_sample __m_latch_233;
	t_sample __m_latch_274;
	t_sample __m_latch_273;
	t_sample __m_latch_263;
	t_sample __m_latch_276;
	t_sample __m_latch_201;
	t_sample __m_latch_199;
	t_sample __m_latch_198;
	t_sample __m_latch_288;
	t_sample __m_latch_203;
	t_sample __m_latch_278;
	t_sample __m_latch_277;
	t_sample __m_latch_188;
	t_sample __m_latch_243;
	t_sample __m_latch_213;
	t_sample __m_latch_262;
	t_sample __m_latch_246;
	t_sample __m_latch_247;
	t_sample __m_latch_248;
	t_sample __m_latch_229;
	t_sample __m_latch_232;
	t_sample __m_latch_231;
	t_sample __m_latch_214;
	t_sample __m_latch_228;
	t_sample __m_latch_258;
	t_sample __m_latch_261;
	t_sample __m_latch_218;
	t_sample __m_latch_216;
	t_sample __m_latch_217;
	t_sample __m_latch_259;
	t_sample __m_latch_244;
	t_sample __m_latch_303;
	t_sample __m_latch_291;
	t_sample __m_latch_382;
	t_sample __m_latch_383;
	t_sample __m_latch_393;
	t_sample __m_latch_394;
	t_sample __m_latch_381;
	t_sample __m_latch_378;
	t_sample __m_latch_379;
	t_sample __m_latch_367;
	t_sample __m_latch_368;
	t_sample __m_latch_366;
	t_sample __m_latch_396;
	t_sample __m_latch_398;
	t_sample __m_latch_423;
	t_sample __m_latch_424;
	t_sample __m_latch_426;
	t_sample __m_latch_397;
	t_sample __m_latch_413;
	t_sample __m_latch_411;
	t_sample __m_latch_412;
	t_sample __m_latch_408;
	t_sample __m_latch_409;
	t_sample __m_latch_289;
	t_sample __m_latch_364;
	t_sample __m_latch_353;
	t_sample __m_latch_308;
	t_sample __m_latch_318;
	t_sample __m_latch_319;
	t_sample __m_latch_321;
	t_sample __m_latch_307;
	t_sample __m_latch_304;
	t_sample __m_latch_306;
	t_sample __m_latch_292;
	t_sample __m_latch_293;
	t_sample __m_latch_363;
	t_sample __m_latch_322;
	t_sample __m_latch_333;
	t_sample __m_latch_349;
	t_sample __m_latch_351;
	t_sample __m_latch_352;
	t_sample __m_latch_323;
	t_sample __m_latch_348;
	t_sample __m_latch_337;
	t_sample __m_latch_338;
	t_sample __m_latch_334;
	t_sample __m_latch_336;
	t_sample __m_latch_187;
	t_sample __m_latch_171;
	t_sample __m_latch_184;
	t_sample m_history_30;
	t_sample m_history_29;
	t_sample m_history_31;
	t_sample m_history_32;
	t_sample m_history_33;
	t_sample m_history_28;
	t_sample m_history_26;
	t_sample m_history_27;
	t_sample m_history_24;
	t_sample m_history_25;
	t_sample m_history_23;
	t_sample m_knob1_rate_34;
	t_sample m_knob6_drywet_37;
	t_sample m_sw_43;
	t_sample m_knob4_duration_44;
	t_sample m_width_46;
	t_sample m_knob5_durationspread_36;
	t_sample m_sw_42;
	t_sample m_knob3_feedback_40;
	t_sample m_sw_41;
	t_sample m_knob2_skew_38;
	t_sample m_sw_39;
	t_sample m_rate_spread_47;
	t_sample m_history_22;
	t_sample m_history_20;
	t_sample m_offset_5;
	t_sample m_pan_6;
	t_sample m_skew_7;
	t_sample m_octave_8;
	t_sample m_speed_4;
	t_sample m_history_2;
	t_sample m_slope_3;
	t_sample samplerate;
	t_sample m_subsample_1;
	t_sample m_history_21;
	t_sample m_octave_spread_9;
	t_sample m_history_11;
	t_sample m_history_17;
	t_sample m_history_18;
	t_sample m_history_19;
	t_sample m_history_10;
	t_sample m_history_16;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample m_history_12;
	t_sample m_history_13;
	t_sample __m_latch_186;
	t_sample m_cvin_48;
	t_sample m_gate_50;
	t_sample __m_latch_139;
	t_sample __m_latch_138;
	t_sample __m_latch_141;
	t_sample __m_latch_142;
	t_sample __m_latch_143;
	t_sample __m_latch_128;
	t_sample __m_latch_126;
	t_sample __m_latch_127;
	t_sample __m_latch_123;
	t_sample __m_latch_124;
	t_sample __m_latch_113;
	t_sample __m_latch_153;
	t_sample __m_latch_156;
	t_sample __m_latch_172;
	t_sample __m_latch_173;
	t_sample __m_latch_183;
	t_sample __m_latch_154;
	t_sample __m_latch_427;
	t_sample __m_latch_168;
	t_sample __m_latch_169;
	t_sample __m_latch_157;
	t_sample __m_latch_158;
	t_sample m_sw_49;
	t_sample __m_latch_112;
	t_sample __m_latch_109;
	t_sample __m_carry_65;
	t_sample __m_latch_73;
	t_sample samples_to_seconds;
	t_sample __m_latch_76;
	t_sample __m_count_63;
	t_sample m_sw_53;
	t_sample m_position_spread_54;
	t_sample m_sw_51;
	t_sample m_sw_52;
	t_sample __m_latch_111;
	t_sample __m_latch_78;
	t_sample __m_latch_81;
	t_sample __m_latch_97;
	t_sample __m_latch_98;
	t_sample __m_latch_108;
	t_sample __m_latch_79;
	t_sample __m_latch_96;
	t_sample __m_latch_93;
	t_sample __m_latch_94;
	t_sample __m_latch_82;
	t_sample __m_latch_83;
	t_sample __m_latch_428;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_subsample_1 = ((int)0);
		m_history_2 = ((int)0);
		m_slope_3 = ((int)0);
		m_speed_4 = ((int)0);
		m_offset_5 = ((int)0);
		m_pan_6 = ((int)0);
		m_skew_7 = ((int)0);
		m_octave_8 = ((int)0);
		m_octave_spread_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_history_24 = ((int)0);
		m_history_25 = ((int)0);
		m_history_26 = ((int)0);
		m_history_27 = ((int)0);
		m_history_28 = ((int)0);
		m_history_29 = ((int)0);
		m_history_30 = ((int)0);
		m_history_31 = ((int)0);
		m_history_32 = ((int)0);
		m_history_33 = ((int)0);
		m_knob1_rate_34 = ((int)0);
		m_switches_35.reset("switches", ((int)8), ((int)1));
		m_knob5_durationspread_36 = ((t_sample)0.5);
		m_knob6_drywet_37 = ((t_sample)0.5);
		m_knob2_skew_38 = ((t_sample)0.5);
		m_sw_39 = ((int)0);
		m_knob3_feedback_40 = ((int)0);
		m_sw_41 = ((int)0);
		m_sw_42 = ((int)0);
		m_sw_43 = ((int)0);
		m_knob4_duration_44 = ((int)50);
		m_src_45.reset("src", ((int)88200), ((int)1));
		m_width_46 = ((int)1);
		m_rate_spread_47 = ((t_sample)0.5);
		m_cvin_48 = ((int)0);
		m_sw_49 = ((int)0);
		m_gate_50 = ((int)0);
		m_sw_51 = ((int)0);
		m_sw_52 = ((int)0);
		m_sw_53 = ((int)0);
		m_position_spread_54 = ((t_sample)0.001);
		m_pswitches_55.reset("pswitches", ((int)8), ((int)1));
		__m_count_63 = 0;
		__m_carry_65 = 0;
		__m_latch_73 = 1;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_74.reset(0);
		__m_delta_75.reset(0);
		__m_latch_76 = 0.5;
		__m_latch_78 = 0;
		__m_latch_79 = 0;
		__m_pluseq_80.reset(0);
		__m_latch_81 = 0;
		__m_latch_82 = 0;
		__m_latch_83 = 0;
		__m_latch_93 = 0;
		__m_latch_94 = 0;
		__m_pluseq_95.reset(0);
		__m_latch_96 = 0;
		__m_latch_97 = 0;
		__m_latch_98 = 0;
		__m_latch_108 = 0;
		__m_latch_109 = 0;
		__m_pluseq_110.reset(0);
		__m_latch_111 = 0;
		__m_latch_112 = 0;
		__m_latch_113 = 0;
		__m_latch_123 = 0;
		__m_latch_124 = 0;
		__m_pluseq_125.reset(0);
		__m_latch_126 = 0;
		__m_latch_127 = 0;
		__m_latch_128 = 0;
		__m_latch_138 = 0;
		__m_latch_139 = 0;
		__m_pluseq_140.reset(0);
		__m_latch_141 = 0;
		__m_latch_142 = 0;
		__m_latch_143 = 0;
		__m_latch_153 = 0;
		__m_latch_154 = 0;
		__m_pluseq_155.reset(0);
		__m_latch_156 = 0;
		__m_latch_157 = 0;
		__m_latch_158 = 0;
		__m_latch_168 = 0;
		__m_latch_169 = 0;
		__m_pluseq_170.reset(0);
		__m_latch_171 = 0;
		__m_latch_172 = 0;
		__m_latch_173 = 0;
		__m_latch_183 = 0;
		__m_latch_184 = 0;
		__m_pluseq_185.reset(0);
		__m_latch_186 = 0;
		__m_latch_187 = 0;
		__m_latch_188 = 0;
		__m_latch_198 = 0;
		__m_latch_199 = 0;
		__m_pluseq_200.reset(0);
		__m_latch_201 = 0;
		__m_latch_202 = 0;
		__m_latch_203 = 0;
		__m_latch_213 = 0;
		__m_latch_214 = 0;
		__m_pluseq_215.reset(0);
		__m_latch_216 = 0;
		__m_latch_217 = 0;
		__m_latch_218 = 0;
		__m_latch_228 = 0;
		__m_latch_229 = 0;
		__m_pluseq_230.reset(0);
		__m_latch_231 = 0;
		__m_latch_232 = 0;
		__m_latch_233 = 0;
		__m_latch_243 = 0;
		__m_latch_244 = 0;
		__m_pluseq_245.reset(0);
		__m_latch_246 = 0;
		__m_latch_247 = 0;
		__m_latch_248 = 0;
		__m_latch_258 = 0;
		__m_latch_259 = 0;
		__m_pluseq_260.reset(0);
		__m_latch_261 = 0;
		__m_latch_262 = 0;
		__m_latch_263 = 0;
		__m_latch_273 = 0;
		__m_latch_274 = 0;
		__m_pluseq_275.reset(0);
		__m_latch_276 = 0;
		__m_latch_277 = 0;
		__m_latch_278 = 0;
		__m_latch_288 = 0;
		__m_latch_289 = 0;
		__m_pluseq_290.reset(0);
		__m_latch_291 = 0;
		__m_latch_292 = 0;
		__m_latch_293 = 0;
		__m_latch_303 = 0;
		__m_latch_304 = 0;
		__m_pluseq_305.reset(0);
		__m_latch_306 = 0;
		__m_latch_307 = 0;
		__m_latch_308 = 0;
		__m_latch_318 = 0;
		__m_latch_319 = 0;
		__m_pluseq_320.reset(0);
		__m_latch_321 = 0;
		__m_latch_322 = 0;
		__m_latch_323 = 0;
		__m_latch_333 = 0;
		__m_latch_334 = 0;
		__m_pluseq_335.reset(0);
		__m_latch_336 = 0;
		__m_latch_337 = 0;
		__m_latch_338 = 0;
		__m_latch_348 = 0;
		__m_latch_349 = 0;
		__m_pluseq_350.reset(0);
		__m_latch_351 = 0;
		__m_latch_352 = 0;
		__m_latch_353 = 0;
		__m_latch_363 = 0;
		__m_latch_364 = 0;
		__m_pluseq_365.reset(0);
		__m_latch_366 = 0;
		__m_latch_367 = 0;
		__m_latch_368 = 0;
		__m_latch_378 = 0;
		__m_latch_379 = 0;
		__m_pluseq_380.reset(0);
		__m_latch_381 = 0;
		__m_latch_382 = 0;
		__m_latch_383 = 0;
		__m_latch_393 = 0;
		__m_latch_394 = 0;
		__m_pluseq_395.reset(0);
		__m_latch_396 = 0;
		__m_latch_397 = 0;
		__m_latch_398 = 0;
		__m_latch_408 = 0;
		__m_latch_409 = 0;
		__m_pluseq_410.reset(0);
		__m_latch_411 = 0;
		__m_latch_412 = 0;
		__m_latch_413 = 0;
		__m_latch_423 = 0;
		__m_latch_424 = 0;
		__m_pluseq_425.reset(0);
		__m_latch_426 = 0;
		__m_latch_427 = 0;
		__m_latch_428 = 0;
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
		int src_dim = m_src_45.dim;
		int src_channels = m_src_45.channels;
		int src_dim_126 = src_dim;
		int switches_dim = m_switches_35.dim;
		int switches_channels = m_switches_35.channels;
		bool index_ignore_56 = (((int)3) >= switches_dim);
		bool index_ignore_57 = (((int)5) >= switches_dim);
		bool index_ignore_58 = (((int)2) >= switches_dim);
		bool index_ignore_59 = (((int)1) >= switches_dim);
		bool index_ignore_60 = (((int)7) >= switches_dim);
		bool index_ignore_61 = (((int)4) >= switches_dim);
		bool index_ignore_62 = (((int)6) >= switches_dim);
		int pswitches_dim = m_pswitches_55.dim;
		int pswitches_channels = m_pswitches_55.channels;
		bool index_ignore_71 = (((int)1) >= pswitches_dim);
		bool index_ignore_72 = (((int)1) >= switches_dim);
		samples_to_seconds = (1 / samplerate);
		t_sample octave_spread_next_8824 = fixdenorm(m_cvin_48);
		t_sample skew_next_8825 = fixdenorm(m_knob2_skew_38);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			if ((!index_ignore_56)) {
				m_switches_35.write(m_sw_39, ((int)3), 0);
				
			};
			if ((!index_ignore_57)) {
				m_switches_35.write(m_sw_42, ((int)5), 0);
				
			};
			if ((!index_ignore_58)) {
				m_switches_35.write(m_sw_52, ((int)2), 0);
				
			};
			if ((!index_ignore_59)) {
				m_switches_35.write(m_sw_53, ((int)1), 0);
				
			};
			m_switches_35.write(m_sw_51, 0, 0);
			if ((!index_ignore_60)) {
				m_switches_35.write(m_sw_41, ((int)7), 0);
				
			};
			if ((!index_ignore_61)) {
				m_switches_35.write(m_sw_43, ((int)4), 0);
				
			};
			if ((!index_ignore_62)) {
				m_switches_35.write(m_sw_49, ((int)6), 0);
				
			};
			__m_count_63 = (((int)0) ? 0 : (fixdenorm(__m_count_63 + ((int)1))));
			int carry_64 = 0;
			if ((((int)0) != 0)) {
				__m_count_63 = 0;
				__m_carry_65 = 0;
				
			} else if (((src_dim_126 > 0) && (__m_count_63 >= src_dim_126))) {
				int wraps_66 = (__m_count_63 / src_dim_126);
				__m_carry_65 = (__m_carry_65 + wraps_66);
				__m_count_63 = (__m_count_63 - (wraps_66 * src_dim_126));
				carry_64 = 1;
				
			};
			int counter_411 = __m_count_63;
			int counter_412 = carry_64;
			int counter_413 = __m_carry_65;
			double index_fract_67 = (counter_411 - counter_411);
			int index_trunc_68 = (counter_411 + 1);
			int index_wrap_69 = ((counter_411 < 0) ? ((src_dim - 1) + ((counter_411 + 1) % src_dim)) : (counter_411 % src_dim));
			int index_wrap_70 = ((index_trunc_68 < 0) ? ((src_dim - 1) + ((index_trunc_68 + 1) % src_dim)) : (index_trunc_68 % src_dim));
			m_src_45.blend(mix((in2 + in1), m_src_45.read(index_wrap_69, 0), m_knob3_feedback_40), index_wrap_69, 0, index_fract_67);
			m_src_45.blend(mix((in2 + in1), m_src_45.read(index_wrap_70, 0), m_knob3_feedback_40), index_wrap_70, 0, (1 - index_fract_67));
			// samples pswitches channel 1;
			t_sample sample_pswitches_2 = (index_ignore_71 ? 0 : m_pswitches_55.read(((int)1), 0));
			t_sample index_pswitches_3 = ((int)1);
			t_sample out11 = sample_pswitches_2;
			// samples switches channel 1;
			t_sample sample_switches_5 = (index_ignore_72 ? 0 : m_switches_35.read(((int)1), 0));
			t_sample index_switches_6 = ((int)1);
			t_sample out12 = sample_switches_5;
			t_sample noise_336 = noise();
			t_sample mul_334 = (m_width_46 * noise_336);
			t_sample sub_14818 = (mul_334 - (-1));
			t_sample scale_14815 = ((safepow((sub_14818 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_335 = scale_14815;
			t_sample noise_118 = noise();
			t_sample mul_117 = (noise_118 * ((t_sample)3.1415926535898));
			t_sample noise_120 = noise();
			t_sample abs_119 = fabs(noise_120);
			t_sample log_113 = log(abs_119);
			t_sample mul_112 = (log_113 * (-0.25));
			t_sample sqrt_114 = sqrt(mul_112);
			t_sample poltocar_14819 = (sqrt_114 * cos(mul_117));
			t_sample x_115 = poltocar_14819;
			t_sample gen_405 = x_115;
			t_sample mul_111 = (m_position_spread_54 * gen_405);
			t_sample mul_125 = (mul_111 * src_dim_126);
			t_sample noise_7861 = noise();
			t_sample mul_7860 = (noise_7861 * ((t_sample)3.1415926535898));
			t_sample noise_7857 = noise();
			t_sample abs_7859 = fabs(noise_7857);
			t_sample log_7858 = log(abs_7859);
			t_sample mul_7854 = (log_7858 * (-0.25));
			t_sample sqrt_7856 = sqrt(mul_7854);
			t_sample poltocar_14821 = (sqrt_7856 * cos(mul_7860));
			t_sample x_7862 = poltocar_14821;
			t_sample gen_159 = x_7862;
			t_sample mul_158 = (m_octave_spread_9 * gen_159);
			t_sample round_163 = round((m_octave_8 + mul_158));
			t_sample exp_110 = exp2(round_163);
			t_sample curOct_23 = round_163;
			int expr_14885 = ((int)0);
			int expr_14886 = ((int)0);
			int expr_14887 = ((int)0);
			int expr_14888 = ((int)0);
			int expr_14889 = ((int)0);
			int expr_14890 = ((int)0);
			int expr_14891 = ((int)0);
			if ((curOct_23 == (-((int)3)))) {
				expr_14885 = ((int)1);
				
			} else {
				if ((curOct_23 == (-((int)2)))) {
					expr_14886 = ((int)1);
					
				} else {
					if ((curOct_23 == (-((int)1)))) {
						expr_14887 = ((int)1);
						
					} else {
						if ((curOct_23 == ((int)0))) {
							expr_14888 = ((int)1);
							
						} else {
							if ((curOct_23 == ((int)1))) {
								expr_14889 = ((int)1);
								
							} else {
								if ((curOct_23 == ((int)2))) {
									expr_14890 = ((int)1);
									
								} else {
									if ((curOct_23 == ((int)3))) {
										expr_14891 = ((int)1);
										
									};
									
								};
								
							};
							
						};
						
					};
					
				};
				
			};
			t_sample out7 = expr_14888;
			t_sample out5 = expr_14886;
			t_sample out8 = expr_14889;
			t_sample out10 = expr_14891;
			t_sample out6 = expr_14887;
			t_sample out9 = expr_14890;
			t_sample out4 = expr_14885;
			t_sample noise_7868 = noise();
			t_sample mul_7866 = (noise_7868 * ((t_sample)3.1415926535898));
			t_sample noise_7869 = noise();
			t_sample abs_7871 = fabs(noise_7869);
			t_sample log_7870 = log(abs_7871);
			t_sample mul_7867 = (log_7870 * (-0.25));
			t_sample sqrt_7865 = sqrt(mul_7867);
			t_sample poltocar_14823 = (sqrt_7865 * cos(mul_7866));
			t_sample x_7864 = poltocar_14823;
			t_sample gen_403 = x_7864;
			t_sample mul_402 = (m_knob5_durationspread_36 * gen_403);
			t_sample mul_401 = (m_knob4_duration_44 * mul_402);
			t_sample mstosamps_409 = ((m_knob4_duration_44 + mul_401) * (samplerate * 0.001));
			t_sample max_407 = ((mstosamps_409 < ((int)1)) ? ((int)1) : mstosamps_409);
			t_sample rdiv_408 = safediv(((int)1), max_407);
			t_sample noise_7877 = noise();
			t_sample mul_7875 = (noise_7877 * ((t_sample)3.1415926535898));
			t_sample noise_7878 = noise();
			t_sample abs_7880 = fabs(noise_7878);
			t_sample log_7879 = log(abs_7880);
			t_sample mul_7876 = (log_7879 * (-0.25));
			t_sample sqrt_7874 = sqrt(mul_7876);
			t_sample poltocar_14825 = (sqrt_7874 * cos(mul_7875));
			t_sample x_7873 = poltocar_14825;
			t_sample gen_131 = x_7873;
			t_sample abs_19 = fabs(gen_131);
			t_sample mul_130 = (abs_19 * m_rate_spread_47);
			t_sample exp_135 = exp2(mul_130);
			__m_latch_73 = ((m_history_2 != 0) ? exp_135 : __m_latch_73);
			t_sample latch_129 = __m_latch_73;
			t_sample mul_128 = (m_knob1_rate_34 * latch_129);
			t_sample phasor_137 = __m_phasor_74(mul_128, samples_to_seconds);
			t_sample delta_138 = __m_delta_75(phasor_137);
			t_sample wrap_139 = wrap(delta_138, (-0.5), ((t_sample)0.5));
			t_sample gen_141 = wrap_139;
			int lt_143 = (gen_141 < ((int)0));
			t_sample sub_144 = (phasor_137 - lt_143);
			t_sample div_149 = safediv(sub_144, gen_141);
			int lt_148 = (div_149 < ((int)1));
			int and_147 = (lt_148 && gen_141);
			int gen_154 = and_147;
			__m_latch_76 = ((and_147 != 0) ? div_149 : __m_latch_76);
			t_sample latch_145 = __m_latch_76;
			t_sample gen_156 = latch_145;
			int switch_197 = (m_history_33 ? ((int)1) : ((int)2));
			int choice_77 = switch_197;
			int gate_198 = (((choice_77 >= 1) && (choice_77 < 2)) ? gen_154 : 0);
			int gate_199 = ((choice_77 >= 2) ? gen_154 : 0);
			int gen_377 = gate_198;
			t_sample mul_173 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_78 = ((gate_199 != 0) ? mul_173 : __m_latch_78);
			t_sample latch_174 = __m_latch_78;
			t_sample add_203 = (((int)0) + m_offset_5);
			__m_latch_79 = ((gate_199 != 0) ? add_203 : __m_latch_79);
			t_sample latch_196 = __m_latch_79;
			int plusequals_176 = __m_pluseq_80.post(((int)1), gate_199, 0);
			t_sample add_166 = (((int)0) + m_speed_4);
			__m_latch_81 = ((gate_199 != 0) ? add_166 : __m_latch_81);
			t_sample latch_164 = __m_latch_81;
			t_sample add_202 = (((int)0) + m_slope_3);
			__m_latch_82 = ((gate_199 != 0) ? add_202 : __m_latch_82);
			t_sample latch_195 = __m_latch_82;
			t_sample add_170 = (((int)0) + m_subsample_1);
			__m_latch_83 = ((gate_199 != 0) ? add_170 : __m_latch_83);
			t_sample latch_169 = __m_latch_83;
			t_sample add_168 = (plusequals_176 + latch_169);
			t_sample mul_165 = (add_168 * latch_164);
			t_sample add_175 = (mul_165 + latch_196);
			int index_trunc_84 = fixnan(floor(add_175));
			double index_fract_85 = (add_175 - index_trunc_84);
			int index_trunc_86 = (index_trunc_84 + 1);
			int index_wrap_87 = ((index_trunc_84 < 0) ? ((src_dim - 1) + ((index_trunc_84 + 1) % src_dim)) : (index_trunc_84 % src_dim));
			int index_wrap_88 = ((index_trunc_86 < 0) ? ((src_dim - 1) + ((index_trunc_86 + 1) % src_dim)) : (index_trunc_86 % src_dim));
			// samples src channel 1;
			double read_src_89 = m_src_45.read(index_wrap_87, 0);
			double read_src_90 = m_src_45.read(index_wrap_88, 0);
			double readinterp_91 = linear_interp(index_fract_85, read_src_89, read_src_90);
			t_sample sample_src_177 = readinterp_91;
			t_sample index_src_178 = add_175;
			t_sample mul_167 = (latch_195 * add_168);
			t_sample clamp_180 = ((mul_167 <= ((int)0)) ? ((int)0) : ((mul_167 >= ((int)1)) ? ((int)1) : mul_167));
			t_sample triangle_181 = triangle(clamp_180, m_skew_7);
			t_sample clamp_191 = ((triangle_181 <= ((int)0)) ? ((int)0) : ((triangle_181 >= ((int)1)) ? ((int)1) : triangle_181));
			int gt_183 = (clamp_191 > ((t_sample)0.5));
			t_sample mul_186 = (clamp_191 * clamp_191);
			t_sample mul_185 = (mul_186 * clamp_191);
			t_sample mul_184 = (mul_185 * ((int)2));
			t_sample rsub_192 = (((int)1) - clamp_191);
			t_sample mul_190 = (rsub_192 * rsub_192);
			t_sample mul_188 = (mul_190 * clamp_191);
			t_sample mul_189 = (mul_188 * ((int)6));
			t_sample rsub_187 = (((int)1) - mul_189);
			t_sample switch_182 = (gt_183 ? rsub_187 : mul_184);
			t_sample gen_194 = switch_182;
			int gt_201 = (gen_194 > ((int)0));
			int gen_378 = gt_201;
			t_sample mul_179 = (gen_194 * sample_src_177);
			t_sample poltocar_14827 = (mul_179 * cos(latch_174));
			t_sample poltocar_14828 = (mul_179 * sin(latch_174));
			t_sample history_200_next_209 = fixdenorm(gt_201);
			int switch_7911 = (m_history_32 ? ((int)1) : ((int)2));
			int choice_92 = switch_7911;
			int gate_7916 = (((choice_92 >= 1) && (choice_92 < 2)) ? gen_377 : 0);
			int gate_7914 = ((choice_92 >= 2) ? gen_377 : 0);
			int gen_369 = gate_7916;
			t_sample mul_7890 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_93 = ((gate_7914 != 0) ? mul_7890 : __m_latch_93);
			t_sample latch_7885 = __m_latch_93;
			t_sample add_7913 = (((int)0) + m_offset_5);
			__m_latch_94 = ((gate_7914 != 0) ? add_7913 : __m_latch_94);
			t_sample latch_7904 = __m_latch_94;
			int plusequals_7901 = __m_pluseq_95.post(((int)1), gate_7914, 0);
			t_sample add_7917 = (((int)0) + m_speed_4);
			__m_latch_96 = ((gate_7914 != 0) ? add_7917 : __m_latch_96);
			t_sample latch_7893 = __m_latch_96;
			t_sample add_7910 = (((int)0) + m_slope_3);
			__m_latch_97 = ((gate_7914 != 0) ? add_7910 : __m_latch_97);
			t_sample latch_7899 = __m_latch_97;
			t_sample add_7909 = (((int)0) + m_subsample_1);
			__m_latch_98 = ((gate_7914 != 0) ? add_7909 : __m_latch_98);
			t_sample latch_7881 = __m_latch_98;
			t_sample add_7886 = (plusequals_7901 + latch_7881);
			t_sample mul_7908 = (add_7886 * latch_7893);
			t_sample add_7907 = (mul_7908 + latch_7904);
			int index_trunc_99 = fixnan(floor(add_7907));
			double index_fract_100 = (add_7907 - index_trunc_99);
			int index_trunc_101 = (index_trunc_99 + 1);
			int index_wrap_102 = ((index_trunc_99 < 0) ? ((src_dim - 1) + ((index_trunc_99 + 1) % src_dim)) : (index_trunc_99 % src_dim));
			int index_wrap_103 = ((index_trunc_101 < 0) ? ((src_dim - 1) + ((index_trunc_101 + 1) % src_dim)) : (index_trunc_101 % src_dim));
			// samples src channel 1;
			double read_src_104 = m_src_45.read(index_wrap_102, 0);
			double read_src_105 = m_src_45.read(index_wrap_103, 0);
			double readinterp_106 = linear_interp(index_fract_100, read_src_104, read_src_105);
			t_sample sample_src_7892 = readinterp_106;
			t_sample index_src_7889 = add_7907;
			t_sample mul_7891 = (latch_7899 * add_7886);
			t_sample clamp_7902 = ((mul_7891 <= ((int)0)) ? ((int)0) : ((mul_7891 >= ((int)1)) ? ((int)1) : mul_7891));
			t_sample triangle_7883 = triangle(clamp_7902, m_skew_7);
			t_sample clamp_7906 = ((triangle_7883 <= ((int)0)) ? ((int)0) : ((triangle_7883 >= ((int)1)) ? ((int)1) : triangle_7883));
			int gt_7895 = (clamp_7906 > ((t_sample)0.5));
			t_sample mul_7905 = (clamp_7906 * clamp_7906);
			t_sample mul_7918 = (mul_7905 * clamp_7906);
			t_sample mul_7884 = (mul_7918 * ((int)2));
			t_sample rsub_7919 = (((int)1) - clamp_7906);
			t_sample mul_7903 = (rsub_7919 * rsub_7919);
			t_sample mul_7912 = (mul_7903 * clamp_7906);
			t_sample mul_7896 = (mul_7912 * ((int)6));
			t_sample rsub_7897 = (((int)1) - mul_7896);
			t_sample switch_7900 = (gt_7895 ? rsub_7897 : mul_7884);
			t_sample gen_7920 = switch_7900;
			int gt_7882 = (gen_7920 > ((int)0));
			int gen_370 = gt_7882;
			t_sample mul_7888 = (gen_7920 * sample_src_7892);
			t_sample poltocar_14829 = (mul_7888 * cos(latch_7885));
			t_sample poltocar_14830 = (mul_7888 * sin(latch_7885));
			t_sample history_200_next_7887 = fixdenorm(gt_7882);
			int switch_7952 = (m_history_31 ? ((int)1) : ((int)2));
			int choice_107 = switch_7952;
			int gate_7956 = (((choice_107 >= 1) && (choice_107 < 2)) ? gen_369 : 0);
			int gate_7955 = ((choice_107 >= 2) ? gen_369 : 0);
			int gen_393 = gate_7956;
			t_sample mul_7931 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_108 = ((gate_7955 != 0) ? mul_7931 : __m_latch_108);
			t_sample latch_7926 = __m_latch_108;
			t_sample add_7945 = (((int)0) + m_offset_5);
			__m_latch_109 = ((gate_7955 != 0) ? add_7945 : __m_latch_109);
			t_sample latch_7948 = __m_latch_109;
			int plusequals_7953 = __m_pluseq_110.post(((int)1), gate_7955, 0);
			t_sample add_7958 = (((int)0) + m_speed_4);
			__m_latch_111 = ((gate_7955 != 0) ? add_7958 : __m_latch_111);
			t_sample latch_7934 = __m_latch_111;
			t_sample add_7936 = (((int)0) + m_slope_3);
			__m_latch_112 = ((gate_7955 != 0) ? add_7936 : __m_latch_112);
			t_sample latch_7944 = __m_latch_112;
			t_sample add_7937 = (((int)0) + m_subsample_1);
			__m_latch_113 = ((gate_7955 != 0) ? add_7937 : __m_latch_113);
			t_sample latch_7922 = __m_latch_113;
			t_sample add_7927 = (plusequals_7953 + latch_7922);
			t_sample mul_7951 = (add_7927 * latch_7934);
			t_sample add_7950 = (mul_7951 + latch_7948);
			int index_trunc_114 = fixnan(floor(add_7950));
			double index_fract_115 = (add_7950 - index_trunc_114);
			int index_trunc_116 = (index_trunc_114 + 1);
			int index_wrap_117 = ((index_trunc_114 < 0) ? ((src_dim - 1) + ((index_trunc_114 + 1) % src_dim)) : (index_trunc_114 % src_dim));
			int index_wrap_118 = ((index_trunc_116 < 0) ? ((src_dim - 1) + ((index_trunc_116 + 1) % src_dim)) : (index_trunc_116 % src_dim));
			// samples src channel 1;
			double read_src_119 = m_src_45.read(index_wrap_117, 0);
			double read_src_120 = m_src_45.read(index_wrap_118, 0);
			double readinterp_121 = linear_interp(index_fract_115, read_src_119, read_src_120);
			t_sample sample_src_7933 = readinterp_121;
			t_sample index_src_7930 = add_7950;
			t_sample mul_7932 = (latch_7944 * add_7927);
			t_sample clamp_7947 = ((mul_7932 <= ((int)0)) ? ((int)0) : ((mul_7932 >= ((int)1)) ? ((int)1) : mul_7932));
			t_sample triangle_7924 = triangle(clamp_7947, m_skew_7);
			t_sample clamp_7949 = ((triangle_7924 <= ((int)0)) ? ((int)0) : ((triangle_7924 >= ((int)1)) ? ((int)1) : triangle_7924));
			int gt_7939 = (clamp_7949 > ((t_sample)0.5));
			t_sample mul_7938 = (clamp_7949 * clamp_7949);
			t_sample mul_7959 = (mul_7938 * clamp_7949);
			t_sample mul_7925 = (mul_7959 * ((int)2));
			t_sample rsub_7960 = (((int)1) - clamp_7949);
			t_sample mul_7946 = (rsub_7960 * rsub_7960);
			t_sample mul_7954 = (mul_7946 * clamp_7949);
			t_sample mul_7940 = (mul_7954 * ((int)6));
			t_sample rsub_7941 = (((int)1) - mul_7940);
			t_sample switch_7943 = (gt_7939 ? rsub_7941 : mul_7925);
			t_sample gen_7961 = switch_7943;
			int gt_7923 = (gen_7961 > ((int)0));
			int gen_394 = gt_7923;
			t_sample mul_7929 = (gen_7961 * sample_src_7933);
			t_sample poltocar_14831 = (mul_7929 * cos(latch_7926));
			t_sample poltocar_14832 = (mul_7929 * sin(latch_7926));
			t_sample history_200_next_7928 = fixdenorm(gt_7923);
			int switch_7997 = (m_history_30 ? ((int)1) : ((int)2));
			int choice_122 = switch_7997;
			int gate_7996 = (((choice_122 >= 1) && (choice_122 < 2)) ? gen_393 : 0);
			int gate_7967 = ((choice_122 >= 2) ? gen_393 : 0);
			int gen_385 = gate_7996;
			t_sample mul_7973 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_123 = ((gate_7967 != 0) ? mul_7973 : __m_latch_123);
			t_sample latch_7968 = __m_latch_123;
			t_sample add_7994 = (((int)0) + m_offset_5);
			__m_latch_124 = ((gate_7967 != 0) ? add_7994 : __m_latch_124);
			t_sample latch_7989 = __m_latch_124;
			int plusequals_7993 = __m_pluseq_125.post(((int)1), gate_7967, 0);
			t_sample add_7999 = (((int)0) + m_speed_4);
			__m_latch_126 = ((gate_7967 != 0) ? add_7999 : __m_latch_126);
			t_sample latch_7977 = __m_latch_126;
			t_sample add_7979 = (((int)0) + m_slope_3);
			__m_latch_127 = ((gate_7967 != 0) ? add_7979 : __m_latch_127);
			t_sample latch_7985 = __m_latch_127;
			t_sample add_7992 = (((int)0) + m_subsample_1);
			__m_latch_128 = ((gate_7967 != 0) ? add_7992 : __m_latch_128);
			t_sample latch_7963 = __m_latch_128;
			t_sample add_7969 = (plusequals_7993 + latch_7963);
			t_sample mul_7991 = (add_7969 * latch_7977);
			t_sample add_7990 = (mul_7991 + latch_7989);
			int index_trunc_129 = fixnan(floor(add_7990));
			double index_fract_130 = (add_7990 - index_trunc_129);
			int index_trunc_131 = (index_trunc_129 + 1);
			int index_wrap_132 = ((index_trunc_129 < 0) ? ((src_dim - 1) + ((index_trunc_129 + 1) % src_dim)) : (index_trunc_129 % src_dim));
			int index_wrap_133 = ((index_trunc_131 < 0) ? ((src_dim - 1) + ((index_trunc_131 + 1) % src_dim)) : (index_trunc_131 % src_dim));
			// samples src channel 1;
			double read_src_134 = m_src_45.read(index_wrap_132, 0);
			double read_src_135 = m_src_45.read(index_wrap_133, 0);
			double readinterp_136 = linear_interp(index_fract_130, read_src_134, read_src_135);
			t_sample sample_src_7976 = readinterp_136;
			t_sample index_src_7972 = add_7990;
			t_sample mul_7975 = (latch_7985 * add_7969);
			t_sample clamp_7987 = ((mul_7975 <= ((int)0)) ? ((int)0) : ((mul_7975 >= ((int)1)) ? ((int)1) : mul_7975));
			t_sample triangle_7965 = triangle(clamp_7987, m_skew_7);
			t_sample clamp_7974 = ((triangle_7965 <= ((int)0)) ? ((int)0) : ((triangle_7965 >= ((int)1)) ? ((int)1) : triangle_7965));
			int gt_7980 = (clamp_7974 > ((t_sample)0.5));
			t_sample mul_7988 = (clamp_7974 * clamp_7974);
			t_sample mul_8000 = (mul_7988 * clamp_7974);
			t_sample mul_7966 = (mul_8000 * ((int)2));
			t_sample rsub_8001 = (((int)1) - clamp_7974);
			t_sample mul_7986 = (rsub_8001 * rsub_8001);
			t_sample mul_7995 = (mul_7986 * clamp_7974);
			t_sample mul_7981 = (mul_7995 * ((int)6));
			t_sample rsub_7982 = (((int)1) - mul_7981);
			t_sample switch_7984 = (gt_7980 ? rsub_7982 : mul_7966);
			t_sample gen_8002 = switch_7984;
			int gt_7964 = (gen_8002 > ((int)0));
			int gen_386 = gt_7964;
			t_sample mul_7971 = (gen_8002 * sample_src_7976);
			t_sample poltocar_14833 = (mul_7971 * cos(latch_7968));
			t_sample poltocar_14834 = (mul_7971 * sin(latch_7968));
			t_sample history_200_next_7970 = fixdenorm(gt_7964);
			int switch_8010 = (m_history_29 ? ((int)1) : ((int)2));
			int choice_137 = switch_8010;
			int gate_8032 = (((choice_137 >= 1) && (choice_137 < 2)) ? gen_385 : 0);
			int gate_8042 = ((choice_137 >= 2) ? gen_385 : 0);
			int gen_345 = gate_8032;
			t_sample mul_8022 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_138 = ((gate_8042 != 0) ? mul_8022 : __m_latch_138);
			t_sample latch_8019 = __m_latch_138;
			t_sample add_8026 = (((int)0) + m_offset_5);
			__m_latch_139 = ((gate_8042 != 0) ? add_8026 : __m_latch_139);
			t_sample latch_8033 = __m_latch_139;
			int plusequals_8007 = __m_pluseq_140.post(((int)1), gate_8042, 0);
			t_sample add_8037 = (((int)0) + m_speed_4);
			__m_latch_141 = ((gate_8042 != 0) ? add_8037 : __m_latch_141);
			t_sample latch_8027 = __m_latch_141;
			t_sample add_8041 = (((int)0) + m_slope_3);
			__m_latch_142 = ((gate_8042 != 0) ? add_8041 : __m_latch_142);
			t_sample latch_8031 = __m_latch_142;
			t_sample add_8025 = (((int)0) + m_subsample_1);
			__m_latch_143 = ((gate_8042 != 0) ? add_8025 : __m_latch_143);
			t_sample latch_8016 = __m_latch_143;
			t_sample add_8034 = (plusequals_8007 + latch_8016);
			t_sample mul_8012 = (add_8034 * latch_8027);
			t_sample add_8023 = (mul_8012 + latch_8033);
			int index_trunc_144 = fixnan(floor(add_8023));
			double index_fract_145 = (add_8023 - index_trunc_144);
			int index_trunc_146 = (index_trunc_144 + 1);
			int index_wrap_147 = ((index_trunc_144 < 0) ? ((src_dim - 1) + ((index_trunc_144 + 1) % src_dim)) : (index_trunc_144 % src_dim));
			int index_wrap_148 = ((index_trunc_146 < 0) ? ((src_dim - 1) + ((index_trunc_146 + 1) % src_dim)) : (index_trunc_146 % src_dim));
			// samples src channel 1;
			double read_src_149 = m_src_45.read(index_wrap_147, 0);
			double read_src_150 = m_src_45.read(index_wrap_148, 0);
			double readinterp_151 = linear_interp(index_fract_145, read_src_149, read_src_150);
			t_sample sample_src_8008 = readinterp_151;
			t_sample index_src_8020 = add_8023;
			t_sample mul_8024 = (latch_8031 * add_8034);
			t_sample clamp_8011 = ((mul_8024 <= ((int)0)) ? ((int)0) : ((mul_8024 >= ((int)1)) ? ((int)1) : mul_8024));
			t_sample triangle_8017 = triangle(clamp_8011, m_skew_7);
			t_sample clamp_8040 = ((triangle_8017 <= ((int)0)) ? ((int)0) : ((triangle_8017 >= ((int)1)) ? ((int)1) : triangle_8017));
			int gt_8028 = (clamp_8040 > ((t_sample)0.5));
			t_sample mul_8005 = (clamp_8040 * clamp_8040);
			t_sample mul_8039 = (mul_8005 * clamp_8040);
			t_sample mul_8018 = (mul_8039 * ((int)2));
			t_sample rsub_8014 = (((int)1) - clamp_8040);
			t_sample mul_8013 = (rsub_8014 * rsub_8014);
			t_sample mul_8035 = (mul_8013 * clamp_8040);
			t_sample mul_8029 = (mul_8035 * ((int)6));
			t_sample rsub_8030 = (((int)1) - mul_8029);
			t_sample switch_8015 = (gt_8028 ? rsub_8030 : mul_8018);
			t_sample gen_8043 = switch_8015;
			int gt_8004 = (gen_8043 > ((int)0));
			int gen_346 = gt_8004;
			t_sample mul_8006 = (gen_8043 * sample_src_8008);
			t_sample poltocar_14835 = (mul_8006 * cos(latch_8019));
			t_sample poltocar_14836 = (mul_8006 * sin(latch_8019));
			t_sample history_200_next_8038 = fixdenorm(gt_8004);
			int switch_8050 = (m_history_28 ? ((int)1) : ((int)2));
			int choice_152 = switch_8050;
			int gate_8081 = (((choice_152 >= 1) && (choice_152 < 2)) ? gen_345 : 0);
			int gate_8083 = ((choice_152 >= 2) ? gen_345 : 0);
			int gen_337 = gate_8081;
			t_sample mul_8062 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_153 = ((gate_8083 != 0) ? mul_8062 : __m_latch_153);
			t_sample latch_8058 = __m_latch_153;
			t_sample add_8066 = (((int)0) + m_offset_5);
			__m_latch_154 = ((gate_8083 != 0) ? add_8066 : __m_latch_154);
			t_sample latch_8073 = __m_latch_154;
			int plusequals_8047 = __m_pluseq_155.post(((int)1), gate_8083, 0);
			t_sample add_8078 = (((int)0) + m_speed_4);
			__m_latch_156 = ((gate_8083 != 0) ? add_8078 : __m_latch_156);
			t_sample latch_8067 = __m_latch_156;
			t_sample add_8082 = (((int)0) + m_slope_3);
			__m_latch_157 = ((gate_8083 != 0) ? add_8082 : __m_latch_157);
			t_sample latch_8072 = __m_latch_157;
			t_sample add_8065 = (((int)0) + m_subsample_1);
			__m_latch_158 = ((gate_8083 != 0) ? add_8065 : __m_latch_158);
			t_sample latch_8055 = __m_latch_158;
			t_sample add_8075 = (plusequals_8047 + latch_8055);
			t_sample mul_8068 = (add_8075 * latch_8067);
			t_sample add_8063 = (mul_8068 + latch_8073);
			int index_trunc_159 = fixnan(floor(add_8063));
			double index_fract_160 = (add_8063 - index_trunc_159);
			int index_trunc_161 = (index_trunc_159 + 1);
			int index_wrap_162 = ((index_trunc_159 < 0) ? ((src_dim - 1) + ((index_trunc_159 + 1) % src_dim)) : (index_trunc_159 % src_dim));
			int index_wrap_163 = ((index_trunc_161 < 0) ? ((src_dim - 1) + ((index_trunc_161 + 1) % src_dim)) : (index_trunc_161 % src_dim));
			// samples src channel 1;
			double read_src_164 = m_src_45.read(index_wrap_162, 0);
			double read_src_165 = m_src_45.read(index_wrap_163, 0);
			double readinterp_166 = linear_interp(index_fract_160, read_src_164, read_src_165);
			t_sample sample_src_8048 = readinterp_166;
			t_sample index_src_8060 = add_8063;
			t_sample mul_8064 = (latch_8072 * add_8075);
			t_sample clamp_8051 = ((mul_8064 <= ((int)0)) ? ((int)0) : ((mul_8064 >= ((int)1)) ? ((int)1) : mul_8064));
			t_sample triangle_8056 = triangle(clamp_8051, m_skew_7);
			t_sample clamp_8080 = ((triangle_8056 <= ((int)0)) ? ((int)0) : ((triangle_8056 >= ((int)1)) ? ((int)1) : triangle_8056));
			int gt_8069 = (clamp_8080 > ((t_sample)0.5));
			t_sample mul_8059 = (clamp_8080 * clamp_8080);
			t_sample mul_8079 = (mul_8059 * clamp_8080);
			t_sample mul_8057 = (mul_8079 * ((int)2));
			t_sample rsub_8053 = (((int)1) - clamp_8080);
			t_sample mul_8052 = (rsub_8053 * rsub_8053);
			t_sample mul_8076 = (mul_8052 * clamp_8080);
			t_sample mul_8070 = (mul_8076 * ((int)6));
			t_sample rsub_8071 = (((int)1) - mul_8070);
			t_sample switch_8054 = (gt_8069 ? rsub_8071 : mul_8057);
			t_sample gen_8084 = switch_8054;
			int gt_8045 = (gen_8084 > ((int)0));
			int gen_338 = gt_8045;
			t_sample mul_8046 = (gen_8084 * sample_src_8048);
			t_sample poltocar_14837 = (mul_8046 * cos(latch_8058));
			t_sample poltocar_14838 = (mul_8046 * sin(latch_8058));
			t_sample history_200_next_8074 = fixdenorm(gt_8045);
			int switch_8092 = (m_history_27 ? ((int)1) : ((int)2));
			int choice_167 = switch_8092;
			int gate_8122 = (((choice_167 >= 1) && (choice_167 < 2)) ? gen_337 : 0);
			int gate_8124 = ((choice_167 >= 2) ? gen_337 : 0);
			int gen_361 = gate_8122;
			t_sample mul_8103 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_168 = ((gate_8124 != 0) ? mul_8103 : __m_latch_168);
			t_sample latch_8100 = __m_latch_168;
			t_sample add_8107 = (((int)0) + m_offset_5);
			__m_latch_169 = ((gate_8124 != 0) ? add_8107 : __m_latch_169);
			t_sample latch_8114 = __m_latch_169;
			int plusequals_8089 = __m_pluseq_170.post(((int)1), gate_8124, 0);
			t_sample add_8119 = (((int)0) + m_speed_4);
			__m_latch_171 = ((gate_8124 != 0) ? add_8119 : __m_latch_171);
			t_sample latch_8108 = __m_latch_171;
			t_sample add_8123 = (((int)0) + m_slope_3);
			__m_latch_172 = ((gate_8124 != 0) ? add_8123 : __m_latch_172);
			t_sample latch_8113 = __m_latch_172;
			t_sample add_8106 = (((int)0) + m_subsample_1);
			__m_latch_173 = ((gate_8124 != 0) ? add_8106 : __m_latch_173);
			t_sample latch_8097 = __m_latch_173;
			t_sample add_8115 = (plusequals_8089 + latch_8097);
			t_sample mul_8112 = (add_8115 * latch_8108);
			t_sample add_8104 = (mul_8112 + latch_8114);
			int index_trunc_174 = fixnan(floor(add_8104));
			double index_fract_175 = (add_8104 - index_trunc_174);
			int index_trunc_176 = (index_trunc_174 + 1);
			int index_wrap_177 = ((index_trunc_174 < 0) ? ((src_dim - 1) + ((index_trunc_174 + 1) % src_dim)) : (index_trunc_174 % src_dim));
			int index_wrap_178 = ((index_trunc_176 < 0) ? ((src_dim - 1) + ((index_trunc_176 + 1) % src_dim)) : (index_trunc_176 % src_dim));
			// samples src channel 1;
			double read_src_179 = m_src_45.read(index_wrap_177, 0);
			double read_src_180 = m_src_45.read(index_wrap_178, 0);
			double readinterp_181 = linear_interp(index_fract_175, read_src_179, read_src_180);
			t_sample sample_src_8090 = readinterp_181;
			t_sample index_src_8101 = add_8104;
			t_sample mul_8105 = (latch_8113 * add_8115);
			t_sample clamp_8093 = ((mul_8105 <= ((int)0)) ? ((int)0) : ((mul_8105 >= ((int)1)) ? ((int)1) : mul_8105));
			t_sample triangle_8098 = triangle(clamp_8093, m_skew_7);
			t_sample clamp_8121 = ((triangle_8098 <= ((int)0)) ? ((int)0) : ((triangle_8098 >= ((int)1)) ? ((int)1) : triangle_8098));
			int gt_8109 = (clamp_8121 > ((t_sample)0.5));
			t_sample mul_8087 = (clamp_8121 * clamp_8121);
			t_sample mul_8120 = (mul_8087 * clamp_8121);
			t_sample mul_8099 = (mul_8120 * ((int)2));
			t_sample rsub_8095 = (((int)1) - clamp_8121);
			t_sample mul_8094 = (rsub_8095 * rsub_8095);
			t_sample mul_8116 = (mul_8094 * clamp_8121);
			t_sample mul_8110 = (mul_8116 * ((int)6));
			t_sample rsub_8111 = (((int)1) - mul_8110);
			t_sample switch_8096 = (gt_8109 ? rsub_8111 : mul_8099);
			t_sample gen_8125 = switch_8096;
			int gt_8086 = (gen_8125 > ((int)0));
			int gen_362 = gt_8086;
			t_sample mul_8088 = (gen_8125 * sample_src_8090);
			t_sample poltocar_14839 = (mul_8088 * cos(latch_8100));
			t_sample poltocar_14840 = (mul_8088 * sin(latch_8100));
			t_sample history_200_next_8118 = fixdenorm(gt_8086);
			int switch_8133 = (m_history_26 ? ((int)1) : ((int)2));
			int choice_182 = switch_8133;
			int gate_8164 = (((choice_182 >= 1) && (choice_182 < 2)) ? gen_361 : 0);
			int gate_8151 = ((choice_182 >= 2) ? gen_361 : 0);
			int gen_353 = gate_8164;
			t_sample mul_8145 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_183 = ((gate_8151 != 0) ? mul_8145 : __m_latch_183);
			t_sample latch_8141 = __m_latch_183;
			t_sample add_8149 = (((int)0) + m_offset_5);
			__m_latch_184 = ((gate_8151 != 0) ? add_8149 : __m_latch_184);
			t_sample latch_8156 = __m_latch_184;
			int plusequals_8130 = __m_pluseq_185.post(((int)1), gate_8151, 0);
			t_sample add_8160 = (((int)0) + m_speed_4);
			__m_latch_186 = ((gate_8151 != 0) ? add_8160 : __m_latch_186);
			t_sample latch_8150 = __m_latch_186;
			t_sample add_8165 = (((int)0) + m_slope_3);
			__m_latch_187 = ((gate_8151 != 0) ? add_8165 : __m_latch_187);
			t_sample latch_8155 = __m_latch_187;
			t_sample add_8148 = (((int)0) + m_subsample_1);
			__m_latch_188 = ((gate_8151 != 0) ? add_8148 : __m_latch_188);
			t_sample latch_8138 = __m_latch_188;
			t_sample add_8157 = (plusequals_8130 + latch_8138);
			t_sample mul_8163 = (add_8157 * latch_8150);
			t_sample add_8146 = (mul_8163 + latch_8156);
			int index_trunc_189 = fixnan(floor(add_8146));
			double index_fract_190 = (add_8146 - index_trunc_189);
			int index_trunc_191 = (index_trunc_189 + 1);
			int index_wrap_192 = ((index_trunc_189 < 0) ? ((src_dim - 1) + ((index_trunc_189 + 1) % src_dim)) : (index_trunc_189 % src_dim));
			int index_wrap_193 = ((index_trunc_191 < 0) ? ((src_dim - 1) + ((index_trunc_191 + 1) % src_dim)) : (index_trunc_191 % src_dim));
			// samples src channel 1;
			double read_src_194 = m_src_45.read(index_wrap_192, 0);
			double read_src_195 = m_src_45.read(index_wrap_193, 0);
			double readinterp_196 = linear_interp(index_fract_190, read_src_194, read_src_195);
			t_sample sample_src_8131 = readinterp_196;
			t_sample index_src_8143 = add_8146;
			t_sample mul_8147 = (latch_8155 * add_8157);
			t_sample clamp_8134 = ((mul_8147 <= ((int)0)) ? ((int)0) : ((mul_8147 >= ((int)1)) ? ((int)1) : mul_8147));
			t_sample triangle_8139 = triangle(clamp_8134, m_skew_7);
			t_sample clamp_8162 = ((triangle_8139 <= ((int)0)) ? ((int)0) : ((triangle_8139 >= ((int)1)) ? ((int)1) : triangle_8139));
			int gt_8152 = (clamp_8162 > ((t_sample)0.5));
			t_sample mul_8128 = (clamp_8162 * clamp_8162);
			t_sample mul_8161 = (mul_8128 * clamp_8162);
			t_sample mul_8140 = (mul_8161 * ((int)2));
			t_sample rsub_8136 = (((int)1) - clamp_8162);
			t_sample mul_8135 = (rsub_8136 * rsub_8136);
			t_sample mul_8158 = (mul_8135 * clamp_8162);
			t_sample mul_8153 = (mul_8158 * ((int)6));
			t_sample rsub_8154 = (((int)1) - mul_8153);
			t_sample switch_8137 = (gt_8152 ? rsub_8154 : mul_8140);
			t_sample gen_8166 = switch_8137;
			int gt_8127 = (gen_8166 > ((int)0));
			int gen_354 = gt_8127;
			t_sample mul_8129 = (gen_8166 * sample_src_8131);
			t_sample poltocar_14841 = (mul_8129 * cos(latch_8141));
			t_sample poltocar_14842 = (mul_8129 * sin(latch_8141));
			t_sample history_200_next_8142 = fixdenorm(gt_8127);
			int switch_8175 = (m_history_25 ? ((int)1) : ((int)2));
			int choice_197 = switch_8175;
			int gate_8179 = (((choice_197 >= 1) && (choice_197 < 2)) ? gen_353 : 0);
			int gate_8204 = ((choice_197 >= 2) ? gen_353 : 0);
			int gen_310 = gate_8179;
			t_sample mul_8188 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_198 = ((gate_8204 != 0) ? mul_8188 : __m_latch_198);
			t_sample latch_8185 = __m_latch_198;
			t_sample add_8192 = (((int)0) + m_offset_5);
			__m_latch_199 = ((gate_8204 != 0) ? add_8192 : __m_latch_199);
			t_sample latch_8199 = __m_latch_199;
			int plusequals_8172 = __m_pluseq_200.post(((int)1), gate_8204, 0);
			t_sample add_8202 = (((int)0) + m_speed_4);
			__m_latch_201 = ((gate_8204 != 0) ? add_8202 : __m_latch_201);
			t_sample latch_8193 = __m_latch_201;
			t_sample add_8194 = (((int)0) + m_slope_3);
			__m_latch_202 = ((gate_8204 != 0) ? add_8194 : __m_latch_202);
			t_sample latch_8198 = __m_latch_202;
			t_sample add_8191 = (((int)0) + m_subsample_1);
			__m_latch_203 = ((gate_8204 != 0) ? add_8191 : __m_latch_203);
			t_sample latch_8181 = __m_latch_203;
			t_sample add_8169 = (plusequals_8172 + latch_8181);
			t_sample mul_8206 = (add_8169 * latch_8193);
			t_sample add_8189 = (mul_8206 + latch_8199);
			int index_trunc_204 = fixnan(floor(add_8189));
			double index_fract_205 = (add_8189 - index_trunc_204);
			int index_trunc_206 = (index_trunc_204 + 1);
			int index_wrap_207 = ((index_trunc_204 < 0) ? ((src_dim - 1) + ((index_trunc_204 + 1) % src_dim)) : (index_trunc_204 % src_dim));
			int index_wrap_208 = ((index_trunc_206 < 0) ? ((src_dim - 1) + ((index_trunc_206 + 1) % src_dim)) : (index_trunc_206 % src_dim));
			// samples src channel 1;
			double read_src_209 = m_src_45.read(index_wrap_207, 0);
			double read_src_210 = m_src_45.read(index_wrap_208, 0);
			double readinterp_211 = linear_interp(index_fract_205, read_src_209, read_src_210);
			t_sample sample_src_8173 = readinterp_211;
			t_sample index_src_8186 = add_8189;
			t_sample mul_8190 = (latch_8198 * add_8169);
			t_sample clamp_8176 = ((mul_8190 <= ((int)0)) ? ((int)0) : ((mul_8190 >= ((int)1)) ? ((int)1) : mul_8190));
			t_sample triangle_8183 = triangle(clamp_8176, m_skew_7);
			t_sample clamp_8205 = ((triangle_8183 <= ((int)0)) ? ((int)0) : ((triangle_8183 >= ((int)1)) ? ((int)1) : triangle_8183));
			int gt_8195 = (clamp_8205 > ((t_sample)0.5));
			t_sample mul_8170 = (clamp_8205 * clamp_8205);
			t_sample mul_8203 = (mul_8170 * clamp_8205);
			t_sample mul_8184 = (mul_8203 * ((int)2));
			t_sample rsub_8178 = (((int)1) - clamp_8205);
			t_sample mul_8177 = (rsub_8178 * rsub_8178);
			t_sample mul_8200 = (mul_8177 * clamp_8205);
			t_sample mul_8196 = (mul_8200 * ((int)6));
			t_sample rsub_8197 = (((int)1) - mul_8196);
			t_sample switch_8180 = (gt_8195 ? rsub_8197 : mul_8184);
			t_sample gen_8207 = switch_8180;
			int gt_8168 = (gen_8207 > ((int)0));
			int gen_311 = gt_8168;
			t_sample mul_8171 = (gen_8207 * sample_src_8173);
			t_sample poltocar_14843 = (mul_8171 * cos(latch_8185));
			t_sample poltocar_14844 = (mul_8171 * sin(latch_8185));
			t_sample history_200_next_8182 = fixdenorm(gt_8168);
			int switch_8212 = (m_history_24 ? ((int)1) : ((int)2));
			int choice_212 = switch_8212;
			int gate_8216 = (((choice_212 >= 1) && (choice_212 < 2)) ? gen_310 : 0);
			int gate_8213 = ((choice_212 >= 2) ? gen_310 : 0);
			int gen_302 = gate_8216;
			t_sample mul_8238 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_213 = ((gate_8213 != 0) ? mul_8238 : __m_latch_213);
			t_sample latch_8220 = __m_latch_213;
			t_sample add_8248 = (((int)0) + m_offset_5);
			__m_latch_214 = ((gate_8213 != 0) ? add_8248 : __m_latch_214);
			t_sample latch_8224 = __m_latch_214;
			int plusequals_8210 = __m_pluseq_215.post(((int)1), gate_8213, 0);
			t_sample add_8228 = (((int)0) + m_speed_4);
			__m_latch_216 = ((gate_8213 != 0) ? add_8228 : __m_latch_216);
			t_sample latch_8241 = __m_latch_216;
			t_sample add_8225 = (((int)0) + m_slope_3);
			__m_latch_217 = ((gate_8213 != 0) ? add_8225 : __m_latch_217);
			t_sample latch_8223 = __m_latch_217;
			t_sample add_8221 = (((int)0) + m_subsample_1);
			__m_latch_218 = ((gate_8213 != 0) ? add_8221 : __m_latch_218);
			t_sample latch_8217 = __m_latch_218;
			t_sample add_8232 = (plusequals_8210 + latch_8217);
			t_sample mul_8240 = (add_8232 * latch_8241);
			t_sample add_8239 = (mul_8240 + latch_8224);
			int index_trunc_219 = fixnan(floor(add_8239));
			double index_fract_220 = (add_8239 - index_trunc_219);
			int index_trunc_221 = (index_trunc_219 + 1);
			int index_wrap_222 = ((index_trunc_219 < 0) ? ((src_dim - 1) + ((index_trunc_219 + 1) % src_dim)) : (index_trunc_219 % src_dim));
			int index_wrap_223 = ((index_trunc_221 < 0) ? ((src_dim - 1) + ((index_trunc_221 + 1) % src_dim)) : (index_trunc_221 % src_dim));
			// samples src channel 1;
			double read_src_224 = m_src_45.read(index_wrap_222, 0);
			double read_src_225 = m_src_45.read(index_wrap_223, 0);
			double readinterp_226 = linear_interp(index_fract_220, read_src_224, read_src_225);
			t_sample sample_src_8211 = readinterp_226;
			t_sample index_src_8236 = add_8239;
			t_sample mul_8247 = (latch_8223 * add_8232);
			t_sample clamp_8243 = ((mul_8247 <= ((int)0)) ? ((int)0) : ((mul_8247 >= ((int)1)) ? ((int)1) : mul_8247));
			t_sample triangle_8218 = triangle(clamp_8243, m_skew_7);
			t_sample clamp_8246 = ((triangle_8218 <= ((int)0)) ? ((int)0) : ((triangle_8218 >= ((int)1)) ? ((int)1) : triangle_8218));
			int gt_8242 = (clamp_8246 > ((t_sample)0.5));
			t_sample mul_8235 = (clamp_8246 * clamp_8246);
			t_sample mul_8229 = (mul_8235 * clamp_8246);
			t_sample mul_8219 = (mul_8229 * ((int)2));
			t_sample rsub_8215 = (((int)1) - clamp_8246);
			t_sample mul_8214 = (rsub_8215 * rsub_8215);
			t_sample mul_8226 = (mul_8214 * clamp_8246);
			t_sample mul_8222 = (mul_8226 * ((int)6));
			t_sample rsub_8244 = (((int)1) - mul_8222);
			t_sample switch_8234 = (gt_8242 ? rsub_8244 : mul_8219);
			t_sample gen_8230 = switch_8234;
			int gt_8231 = (gen_8230 > ((int)0));
			int gen_303 = gt_8231;
			t_sample mul_8209 = (gen_8230 * sample_src_8211);
			t_sample poltocar_14845 = (mul_8209 * cos(latch_8220));
			t_sample poltocar_14846 = (mul_8209 * sin(latch_8220));
			t_sample history_200_next_8245 = fixdenorm(gt_8231);
			int switch_8253 = (m_history_23 ? ((int)1) : ((int)2));
			int choice_227 = switch_8253;
			int gate_8257 = (((choice_227 >= 1) && (choice_227 < 2)) ? gen_302 : 0);
			int gate_8254 = ((choice_227 >= 2) ? gen_302 : 0);
			int gen_326 = gate_8257;
			t_sample mul_8279 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_228 = ((gate_8254 != 0) ? mul_8279 : __m_latch_228);
			t_sample latch_8261 = __m_latch_228;
			t_sample add_8289 = (((int)0) + m_offset_5);
			__m_latch_229 = ((gate_8254 != 0) ? add_8289 : __m_latch_229);
			t_sample latch_8265 = __m_latch_229;
			int plusequals_8251 = __m_pluseq_230.post(((int)1), gate_8254, 0);
			t_sample add_8269 = (((int)0) + m_speed_4);
			__m_latch_231 = ((gate_8254 != 0) ? add_8269 : __m_latch_231);
			t_sample latch_8282 = __m_latch_231;
			t_sample add_8266 = (((int)0) + m_slope_3);
			__m_latch_232 = ((gate_8254 != 0) ? add_8266 : __m_latch_232);
			t_sample latch_8264 = __m_latch_232;
			t_sample add_8262 = (((int)0) + m_subsample_1);
			__m_latch_233 = ((gate_8254 != 0) ? add_8262 : __m_latch_233);
			t_sample latch_8258 = __m_latch_233;
			t_sample add_8273 = (plusequals_8251 + latch_8258);
			t_sample mul_8281 = (add_8273 * latch_8282);
			t_sample add_8280 = (mul_8281 + latch_8265);
			int index_trunc_234 = fixnan(floor(add_8280));
			double index_fract_235 = (add_8280 - index_trunc_234);
			int index_trunc_236 = (index_trunc_234 + 1);
			int index_wrap_237 = ((index_trunc_234 < 0) ? ((src_dim - 1) + ((index_trunc_234 + 1) % src_dim)) : (index_trunc_234 % src_dim));
			int index_wrap_238 = ((index_trunc_236 < 0) ? ((src_dim - 1) + ((index_trunc_236 + 1) % src_dim)) : (index_trunc_236 % src_dim));
			// samples src channel 1;
			double read_src_239 = m_src_45.read(index_wrap_237, 0);
			double read_src_240 = m_src_45.read(index_wrap_238, 0);
			double readinterp_241 = linear_interp(index_fract_235, read_src_239, read_src_240);
			t_sample sample_src_8252 = readinterp_241;
			t_sample index_src_8277 = add_8280;
			t_sample mul_8288 = (latch_8264 * add_8273);
			t_sample clamp_8285 = ((mul_8288 <= ((int)0)) ? ((int)0) : ((mul_8288 >= ((int)1)) ? ((int)1) : mul_8288));
			t_sample triangle_8259 = triangle(clamp_8285, m_skew_7);
			t_sample clamp_8287 = ((triangle_8259 <= ((int)0)) ? ((int)0) : ((triangle_8259 >= ((int)1)) ? ((int)1) : triangle_8259));
			int gt_8284 = (clamp_8287 > ((t_sample)0.5));
			t_sample mul_8276 = (clamp_8287 * clamp_8287);
			t_sample mul_8270 = (mul_8276 * clamp_8287);
			t_sample mul_8260 = (mul_8270 * ((int)2));
			t_sample rsub_8256 = (((int)1) - clamp_8287);
			t_sample mul_8255 = (rsub_8256 * rsub_8256);
			t_sample mul_8267 = (mul_8255 * clamp_8287);
			t_sample mul_8263 = (mul_8267 * ((int)6));
			t_sample rsub_8286 = (((int)1) - mul_8263);
			t_sample switch_8275 = (gt_8284 ? rsub_8286 : mul_8260);
			t_sample gen_8271 = switch_8275;
			int gt_8272 = (gen_8271 > ((int)0));
			int gen_327 = gt_8272;
			t_sample mul_8250 = (gen_8271 * sample_src_8252);
			t_sample poltocar_14847 = (mul_8250 * cos(latch_8261));
			t_sample poltocar_14848 = (mul_8250 * sin(latch_8261));
			t_sample history_200_next_8283 = fixdenorm(gt_8272);
			int switch_8294 = (m_history_22 ? ((int)1) : ((int)2));
			int choice_242 = switch_8294;
			int gate_8299 = (((choice_242 >= 1) && (choice_242 < 2)) ? gen_326 : 0);
			int gate_8296 = ((choice_242 >= 2) ? gen_326 : 0);
			int gen_318 = gate_8299;
			t_sample mul_8322 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_243 = ((gate_8296 != 0) ? mul_8322 : __m_latch_243);
			t_sample latch_8303 = __m_latch_243;
			t_sample add_8324 = (((int)0) + m_offset_5);
			__m_latch_244 = ((gate_8296 != 0) ? add_8324 : __m_latch_244);
			t_sample latch_8308 = __m_latch_244;
			int plusequals_8292 = __m_pluseq_245.post(((int)1), gate_8296, 0);
			t_sample add_8312 = (((int)0) + m_speed_4);
			__m_latch_246 = ((gate_8296 != 0) ? add_8312 : __m_latch_246);
			t_sample latch_8325 = __m_latch_246;
			t_sample add_8309 = (((int)0) + m_slope_3);
			__m_latch_247 = ((gate_8296 != 0) ? add_8309 : __m_latch_247);
			t_sample latch_8307 = __m_latch_247;
			t_sample add_8305 = (((int)0) + m_subsample_1);
			__m_latch_248 = ((gate_8296 != 0) ? add_8305 : __m_latch_248);
			t_sample latch_8300 = __m_latch_248;
			t_sample add_8316 = (plusequals_8292 + latch_8300);
			t_sample mul_8295 = (add_8316 * latch_8325);
			t_sample add_8323 = (mul_8295 + latch_8308);
			int index_trunc_249 = fixnan(floor(add_8323));
			double index_fract_250 = (add_8323 - index_trunc_249);
			int index_trunc_251 = (index_trunc_249 + 1);
			int index_wrap_252 = ((index_trunc_249 < 0) ? ((src_dim - 1) + ((index_trunc_249 + 1) % src_dim)) : (index_trunc_249 % src_dim));
			int index_wrap_253 = ((index_trunc_251 < 0) ? ((src_dim - 1) + ((index_trunc_251 + 1) % src_dim)) : (index_trunc_251 % src_dim));
			// samples src channel 1;
			double read_src_254 = m_src_45.read(index_wrap_252, 0);
			double read_src_255 = m_src_45.read(index_wrap_253, 0);
			double readinterp_256 = linear_interp(index_fract_250, read_src_254, read_src_255);
			t_sample sample_src_8293 = readinterp_256;
			t_sample index_src_8321 = add_8323;
			t_sample mul_8330 = (latch_8307 * add_8316);
			t_sample clamp_8327 = ((mul_8330 <= ((int)0)) ? ((int)0) : ((mul_8330 >= ((int)1)) ? ((int)1) : mul_8330));
			t_sample triangle_8301 = triangle(clamp_8327, m_skew_7);
			t_sample clamp_8329 = ((triangle_8301 <= ((int)0)) ? ((int)0) : ((triangle_8301 >= ((int)1)) ? ((int)1) : triangle_8301));
			int gt_8326 = (clamp_8329 > ((t_sample)0.5));
			t_sample mul_8320 = (clamp_8329 * clamp_8329);
			t_sample mul_8313 = (mul_8320 * clamp_8329);
			t_sample mul_8302 = (mul_8313 * ((int)2));
			t_sample rsub_8298 = (((int)1) - clamp_8329);
			t_sample mul_8297 = (rsub_8298 * rsub_8298);
			t_sample mul_8310 = (mul_8297 * clamp_8329);
			t_sample mul_8306 = (mul_8310 * ((int)6));
			t_sample rsub_8328 = (((int)1) - mul_8306);
			t_sample switch_8318 = (gt_8326 ? rsub_8328 : mul_8302);
			t_sample gen_8314 = switch_8318;
			int gt_8315 = (gen_8314 > ((int)0));
			int gen_319 = gt_8315;
			t_sample mul_8291 = (gen_8314 * sample_src_8293);
			t_sample poltocar_14849 = (mul_8291 * cos(latch_8303));
			t_sample poltocar_14850 = (mul_8291 * sin(latch_8303));
			t_sample history_200_next_8304 = fixdenorm(gt_8315);
			int switch_8335 = (m_history_21 ? ((int)1) : ((int)2));
			int choice_257 = switch_8335;
			int gate_8340 = (((choice_257 >= 1) && (choice_257 < 2)) ? gen_318 : 0);
			int gate_8337 = ((choice_257 >= 2) ? gen_318 : 0);
			int gen_278 = gate_8340;
			t_sample mul_8362 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_258 = ((gate_8337 != 0) ? mul_8362 : __m_latch_258);
			t_sample latch_8344 = __m_latch_258;
			t_sample add_8364 = (((int)0) + m_offset_5);
			__m_latch_259 = ((gate_8337 != 0) ? add_8364 : __m_latch_259);
			t_sample latch_8348 = __m_latch_259;
			int plusequals_8333 = __m_pluseq_260.post(((int)1), gate_8337, 0);
			t_sample add_8352 = (((int)0) + m_speed_4);
			__m_latch_261 = ((gate_8337 != 0) ? add_8352 : __m_latch_261);
			t_sample latch_8365 = __m_latch_261;
			t_sample add_8349 = (((int)0) + m_slope_3);
			__m_latch_262 = ((gate_8337 != 0) ? add_8349 : __m_latch_262);
			t_sample latch_8347 = __m_latch_262;
			t_sample add_8345 = (((int)0) + m_subsample_1);
			__m_latch_263 = ((gate_8337 != 0) ? add_8345 : __m_latch_263);
			t_sample latch_8341 = __m_latch_263;
			t_sample add_8356 = (plusequals_8333 + latch_8341);
			t_sample mul_8336 = (add_8356 * latch_8365);
			t_sample add_8363 = (mul_8336 + latch_8348);
			int index_trunc_264 = fixnan(floor(add_8363));
			double index_fract_265 = (add_8363 - index_trunc_264);
			int index_trunc_266 = (index_trunc_264 + 1);
			int index_wrap_267 = ((index_trunc_264 < 0) ? ((src_dim - 1) + ((index_trunc_264 + 1) % src_dim)) : (index_trunc_264 % src_dim));
			int index_wrap_268 = ((index_trunc_266 < 0) ? ((src_dim - 1) + ((index_trunc_266 + 1) % src_dim)) : (index_trunc_266 % src_dim));
			// samples src channel 1;
			double read_src_269 = m_src_45.read(index_wrap_267, 0);
			double read_src_270 = m_src_45.read(index_wrap_268, 0);
			double readinterp_271 = linear_interp(index_fract_265, read_src_269, read_src_270);
			t_sample sample_src_8334 = readinterp_271;
			t_sample index_src_8360 = add_8363;
			t_sample mul_8371 = (latch_8347 * add_8356);
			t_sample clamp_8368 = ((mul_8371 <= ((int)0)) ? ((int)0) : ((mul_8371 >= ((int)1)) ? ((int)1) : mul_8371));
			t_sample triangle_8342 = triangle(clamp_8368, m_skew_7);
			t_sample clamp_8370 = ((triangle_8342 <= ((int)0)) ? ((int)0) : ((triangle_8342 >= ((int)1)) ? ((int)1) : triangle_8342));
			int gt_8367 = (clamp_8370 > ((t_sample)0.5));
			t_sample mul_8359 = (clamp_8370 * clamp_8370);
			t_sample mul_8353 = (mul_8359 * clamp_8370);
			t_sample mul_8343 = (mul_8353 * ((int)2));
			t_sample rsub_8339 = (((int)1) - clamp_8370);
			t_sample mul_8338 = (rsub_8339 * rsub_8339);
			t_sample mul_8350 = (mul_8338 * clamp_8370);
			t_sample mul_8346 = (mul_8350 * ((int)6));
			t_sample rsub_8369 = (((int)1) - mul_8346);
			t_sample switch_8358 = (gt_8367 ? rsub_8369 : mul_8343);
			t_sample gen_8354 = switch_8358;
			int gt_8355 = (gen_8354 > ((int)0));
			int gen_279 = gt_8355;
			t_sample mul_8332 = (gen_8354 * sample_src_8334);
			t_sample poltocar_14851 = (mul_8332 * cos(latch_8344));
			t_sample poltocar_14852 = (mul_8332 * sin(latch_8344));
			t_sample history_200_next_8366 = fixdenorm(gt_8355);
			int switch_8376 = (m_history_20 ? ((int)1) : ((int)2));
			int choice_272 = switch_8376;
			int gate_8381 = (((choice_272 >= 1) && (choice_272 < 2)) ? gen_278 : 0);
			int gate_8378 = ((choice_272 >= 2) ? gen_278 : 0);
			int gen_270 = gate_8381;
			t_sample mul_8403 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_273 = ((gate_8378 != 0) ? mul_8403 : __m_latch_273);
			t_sample latch_8385 = __m_latch_273;
			t_sample add_8412 = (((int)0) + m_offset_5);
			__m_latch_274 = ((gate_8378 != 0) ? add_8412 : __m_latch_274);
			t_sample latch_8390 = __m_latch_274;
			int plusequals_8374 = __m_pluseq_275.post(((int)1), gate_8378, 0);
			t_sample add_8394 = (((int)0) + m_speed_4);
			__m_latch_276 = ((gate_8378 != 0) ? add_8394 : __m_latch_276);
			t_sample latch_8406 = __m_latch_276;
			t_sample add_8391 = (((int)0) + m_slope_3);
			__m_latch_277 = ((gate_8378 != 0) ? add_8391 : __m_latch_277);
			t_sample latch_8389 = __m_latch_277;
			t_sample add_8387 = (((int)0) + m_subsample_1);
			__m_latch_278 = ((gate_8378 != 0) ? add_8387 : __m_latch_278);
			t_sample latch_8382 = __m_latch_278;
			t_sample add_8398 = (plusequals_8374 + latch_8382);
			t_sample mul_8377 = (add_8398 * latch_8406);
			t_sample add_8404 = (mul_8377 + latch_8390);
			int index_trunc_279 = fixnan(floor(add_8404));
			double index_fract_280 = (add_8404 - index_trunc_279);
			int index_trunc_281 = (index_trunc_279 + 1);
			int index_wrap_282 = ((index_trunc_279 < 0) ? ((src_dim - 1) + ((index_trunc_279 + 1) % src_dim)) : (index_trunc_279 % src_dim));
			int index_wrap_283 = ((index_trunc_281 < 0) ? ((src_dim - 1) + ((index_trunc_281 + 1) % src_dim)) : (index_trunc_281 % src_dim));
			// samples src channel 1;
			double read_src_284 = m_src_45.read(index_wrap_282, 0);
			double read_src_285 = m_src_45.read(index_wrap_283, 0);
			double readinterp_286 = linear_interp(index_fract_280, read_src_284, read_src_285);
			t_sample sample_src_8375 = readinterp_286;
			t_sample index_src_8402 = add_8404;
			t_sample mul_8405 = (latch_8389 * add_8398);
			t_sample clamp_8408 = ((mul_8405 <= ((int)0)) ? ((int)0) : ((mul_8405 >= ((int)1)) ? ((int)1) : mul_8405));
			t_sample triangle_8383 = triangle(clamp_8408, m_skew_7);
			t_sample clamp_8410 = ((triangle_8383 <= ((int)0)) ? ((int)0) : ((triangle_8383 >= ((int)1)) ? ((int)1) : triangle_8383));
			int gt_8407 = (clamp_8410 > ((t_sample)0.5));
			t_sample mul_8399 = (clamp_8410 * clamp_8410);
			t_sample mul_8395 = (mul_8399 * clamp_8410);
			t_sample mul_8384 = (mul_8395 * ((int)2));
			t_sample rsub_8380 = (((int)1) - clamp_8410);
			t_sample mul_8379 = (rsub_8380 * rsub_8380);
			t_sample mul_8392 = (mul_8379 * clamp_8410);
			t_sample mul_8388 = (mul_8392 * ((int)6));
			t_sample rsub_8409 = (((int)1) - mul_8388);
			t_sample switch_8401 = (gt_8407 ? rsub_8409 : mul_8384);
			t_sample gen_8396 = switch_8401;
			int gt_8397 = (gen_8396 > ((int)0));
			int gen_271 = gt_8397;
			t_sample mul_8373 = (gen_8396 * sample_src_8375);
			t_sample poltocar_14853 = (mul_8373 * cos(latch_8385));
			t_sample poltocar_14854 = (mul_8373 * sin(latch_8385));
			t_sample history_200_next_8386 = fixdenorm(gt_8397);
			int switch_8417 = (m_history_19 ? ((int)1) : ((int)2));
			int choice_287 = switch_8417;
			int gate_8422 = (((choice_287 >= 1) && (choice_287 < 2)) ? gen_270 : 0);
			int gate_8419 = ((choice_287 >= 2) ? gen_270 : 0);
			int gen_294 = gate_8422;
			t_sample mul_8445 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_288 = ((gate_8419 != 0) ? mul_8445 : __m_latch_288);
			t_sample latch_8426 = __m_latch_288;
			t_sample add_8448 = (((int)0) + m_offset_5);
			__m_latch_289 = ((gate_8419 != 0) ? add_8448 : __m_latch_289);
			t_sample latch_8430 = __m_latch_289;
			int plusequals_8415 = __m_pluseq_290.post(((int)1), gate_8419, 0);
			t_sample add_8434 = (((int)0) + m_speed_4);
			__m_latch_291 = ((gate_8419 != 0) ? add_8434 : __m_latch_291);
			t_sample latch_8449 = __m_latch_291;
			t_sample add_8431 = (((int)0) + m_slope_3);
			__m_latch_292 = ((gate_8419 != 0) ? add_8431 : __m_latch_292);
			t_sample latch_8429 = __m_latch_292;
			t_sample add_8427 = (((int)0) + m_subsample_1);
			__m_latch_293 = ((gate_8419 != 0) ? add_8427 : __m_latch_293);
			t_sample latch_8423 = __m_latch_293;
			t_sample add_8438 = (plusequals_8415 + latch_8423);
			t_sample mul_8418 = (add_8438 * latch_8449);
			t_sample add_8446 = (mul_8418 + latch_8430);
			int index_trunc_294 = fixnan(floor(add_8446));
			double index_fract_295 = (add_8446 - index_trunc_294);
			int index_trunc_296 = (index_trunc_294 + 1);
			int index_wrap_297 = ((index_trunc_294 < 0) ? ((src_dim - 1) + ((index_trunc_294 + 1) % src_dim)) : (index_trunc_294 % src_dim));
			int index_wrap_298 = ((index_trunc_296 < 0) ? ((src_dim - 1) + ((index_trunc_296 + 1) % src_dim)) : (index_trunc_296 % src_dim));
			// samples src channel 1;
			double read_src_299 = m_src_45.read(index_wrap_297, 0);
			double read_src_300 = m_src_45.read(index_wrap_298, 0);
			double readinterp_301 = linear_interp(index_fract_295, read_src_299, read_src_300);
			t_sample sample_src_8416 = readinterp_301;
			t_sample index_src_8443 = add_8446;
			t_sample mul_8442 = (latch_8429 * add_8438);
			t_sample clamp_8451 = ((mul_8442 <= ((int)0)) ? ((int)0) : ((mul_8442 >= ((int)1)) ? ((int)1) : mul_8442));
			t_sample triangle_8424 = triangle(clamp_8451, m_skew_7);
			t_sample clamp_8453 = ((triangle_8424 <= ((int)0)) ? ((int)0) : ((triangle_8424 >= ((int)1)) ? ((int)1) : triangle_8424));
			int gt_8450 = (clamp_8453 > ((t_sample)0.5));
			t_sample mul_8439 = (clamp_8453 * clamp_8453);
			t_sample mul_8435 = (mul_8439 * clamp_8453);
			t_sample mul_8425 = (mul_8435 * ((int)2));
			t_sample rsub_8421 = (((int)1) - clamp_8453);
			t_sample mul_8420 = (rsub_8421 * rsub_8421);
			t_sample mul_8432 = (mul_8420 * clamp_8453);
			t_sample mul_8428 = (mul_8432 * ((int)6));
			t_sample rsub_8452 = (((int)1) - mul_8428);
			t_sample switch_8441 = (gt_8450 ? rsub_8452 : mul_8425);
			t_sample gen_8436 = switch_8441;
			int gt_8437 = (gen_8436 > ((int)0));
			int gen_295 = gt_8437;
			t_sample mul_8414 = (gen_8436 * sample_src_8416);
			t_sample poltocar_14855 = (mul_8414 * cos(latch_8426));
			t_sample poltocar_14856 = (mul_8414 * sin(latch_8426));
			t_sample history_200_next_8447 = fixdenorm(gt_8437);
			int switch_8458 = (m_history_18 ? ((int)1) : ((int)2));
			int choice_302 = switch_8458;
			int gate_8463 = (((choice_302 >= 1) && (choice_302 < 2)) ? gen_294 : 0);
			int gate_8460 = ((choice_302 >= 2) ? gen_294 : 0);
			int gen_286 = gate_8463;
			t_sample mul_8485 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_303 = ((gate_8460 != 0) ? mul_8485 : __m_latch_303);
			t_sample latch_8467 = __m_latch_303;
			t_sample add_8478 = (((int)0) + m_offset_5);
			__m_latch_304 = ((gate_8460 != 0) ? add_8478 : __m_latch_304);
			t_sample latch_8471 = __m_latch_304;
			int plusequals_8456 = __m_pluseq_305.post(((int)1), gate_8460, 0);
			t_sample add_8475 = (((int)0) + m_speed_4);
			__m_latch_306 = ((gate_8460 != 0) ? add_8475 : __m_latch_306);
			t_sample latch_8487 = __m_latch_306;
			t_sample add_8472 = (((int)0) + m_slope_3);
			__m_latch_307 = ((gate_8460 != 0) ? add_8472 : __m_latch_307);
			t_sample latch_8470 = __m_latch_307;
			t_sample add_8468 = (((int)0) + m_subsample_1);
			__m_latch_308 = ((gate_8460 != 0) ? add_8468 : __m_latch_308);
			t_sample latch_8464 = __m_latch_308;
			t_sample add_8480 = (plusequals_8456 + latch_8464);
			t_sample mul_8459 = (add_8480 * latch_8487);
			t_sample add_8486 = (mul_8459 + latch_8471);
			int index_trunc_309 = fixnan(floor(add_8486));
			double index_fract_310 = (add_8486 - index_trunc_309);
			int index_trunc_311 = (index_trunc_309 + 1);
			int index_wrap_312 = ((index_trunc_309 < 0) ? ((src_dim - 1) + ((index_trunc_309 + 1) % src_dim)) : (index_trunc_309 % src_dim));
			int index_wrap_313 = ((index_trunc_311 < 0) ? ((src_dim - 1) + ((index_trunc_311 + 1) % src_dim)) : (index_trunc_311 % src_dim));
			// samples src channel 1;
			double read_src_314 = m_src_45.read(index_wrap_312, 0);
			double read_src_315 = m_src_45.read(index_wrap_313, 0);
			double readinterp_316 = linear_interp(index_fract_310, read_src_314, read_src_315);
			t_sample sample_src_8457 = readinterp_316;
			t_sample index_src_8484 = add_8486;
			t_sample mul_8494 = (latch_8470 * add_8480);
			t_sample clamp_8490 = ((mul_8494 <= ((int)0)) ? ((int)0) : ((mul_8494 >= ((int)1)) ? ((int)1) : mul_8494));
			t_sample triangle_8465 = triangle(clamp_8490, m_skew_7);
			t_sample clamp_8492 = ((triangle_8465 <= ((int)0)) ? ((int)0) : ((triangle_8465 >= ((int)1)) ? ((int)1) : triangle_8465));
			int gt_8489 = (clamp_8492 > ((t_sample)0.5));
			t_sample mul_8483 = (clamp_8492 * clamp_8492);
			t_sample mul_8476 = (mul_8483 * clamp_8492);
			t_sample mul_8466 = (mul_8476 * ((int)2));
			t_sample rsub_8462 = (((int)1) - clamp_8492);
			t_sample mul_8461 = (rsub_8462 * rsub_8462);
			t_sample mul_8473 = (mul_8461 * clamp_8492);
			t_sample mul_8469 = (mul_8473 * ((int)6));
			t_sample rsub_8491 = (((int)1) - mul_8469);
			t_sample switch_8482 = (gt_8489 ? rsub_8491 : mul_8466);
			t_sample gen_8477 = switch_8482;
			int gt_8479 = (gen_8477 > ((int)0));
			int gen_287 = gt_8479;
			t_sample mul_8455 = (gen_8477 * sample_src_8457);
			t_sample poltocar_14857 = (mul_8455 * cos(latch_8467));
			t_sample poltocar_14858 = (mul_8455 * sin(latch_8467));
			t_sample history_200_next_8488 = fixdenorm(gt_8479);
			int switch_8499 = (m_history_17 ? ((int)1) : ((int)2));
			int choice_317 = switch_8499;
			int gate_8504 = (((choice_317 >= 1) && (choice_317 < 2)) ? gen_286 : 0);
			int gate_8501 = ((choice_317 >= 2) ? gen_286 : 0);
			int gen_246 = gate_8504;
			t_sample mul_8527 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_318 = ((gate_8501 != 0) ? mul_8527 : __m_latch_318);
			t_sample latch_8508 = __m_latch_318;
			t_sample add_8530 = (((int)0) + m_offset_5);
			__m_latch_319 = ((gate_8501 != 0) ? add_8530 : __m_latch_319);
			t_sample latch_8513 = __m_latch_319;
			int plusequals_8497 = __m_pluseq_320.post(((int)1), gate_8501, 0);
			t_sample add_8517 = (((int)0) + m_speed_4);
			__m_latch_321 = ((gate_8501 != 0) ? add_8517 : __m_latch_321);
			t_sample latch_8531 = __m_latch_321;
			t_sample add_8514 = (((int)0) + m_slope_3);
			__m_latch_322 = ((gate_8501 != 0) ? add_8514 : __m_latch_322);
			t_sample latch_8512 = __m_latch_322;
			t_sample add_8510 = (((int)0) + m_subsample_1);
			__m_latch_323 = ((gate_8501 != 0) ? add_8510 : __m_latch_323);
			t_sample latch_8505 = __m_latch_323;
			t_sample add_8521 = (plusequals_8497 + latch_8505);
			t_sample mul_8500 = (add_8521 * latch_8531);
			t_sample add_8528 = (mul_8500 + latch_8513);
			int index_trunc_324 = fixnan(floor(add_8528));
			double index_fract_325 = (add_8528 - index_trunc_324);
			int index_trunc_326 = (index_trunc_324 + 1);
			int index_wrap_327 = ((index_trunc_324 < 0) ? ((src_dim - 1) + ((index_trunc_324 + 1) % src_dim)) : (index_trunc_324 % src_dim));
			int index_wrap_328 = ((index_trunc_326 < 0) ? ((src_dim - 1) + ((index_trunc_326 + 1) % src_dim)) : (index_trunc_326 % src_dim));
			// samples src channel 1;
			double read_src_329 = m_src_45.read(index_wrap_327, 0);
			double read_src_330 = m_src_45.read(index_wrap_328, 0);
			double readinterp_331 = linear_interp(index_fract_325, read_src_329, read_src_330);
			t_sample sample_src_8498 = readinterp_331;
			t_sample index_src_8525 = add_8528;
			t_sample mul_8529 = (latch_8512 * add_8521);
			t_sample clamp_8533 = ((mul_8529 <= ((int)0)) ? ((int)0) : ((mul_8529 >= ((int)1)) ? ((int)1) : mul_8529));
			t_sample triangle_8506 = triangle(clamp_8533, m_skew_7);
			t_sample clamp_8535 = ((triangle_8506 <= ((int)0)) ? ((int)0) : ((triangle_8506 >= ((int)1)) ? ((int)1) : triangle_8506));
			int gt_8532 = (clamp_8535 > ((t_sample)0.5));
			t_sample mul_8524 = (clamp_8535 * clamp_8535);
			t_sample mul_8518 = (mul_8524 * clamp_8535);
			t_sample mul_8507 = (mul_8518 * ((int)2));
			t_sample rsub_8503 = (((int)1) - clamp_8535);
			t_sample mul_8502 = (rsub_8503 * rsub_8503);
			t_sample mul_8515 = (mul_8502 * clamp_8535);
			t_sample mul_8511 = (mul_8515 * ((int)6));
			t_sample rsub_8534 = (((int)1) - mul_8511);
			t_sample switch_8523 = (gt_8532 ? rsub_8534 : mul_8507);
			t_sample gen_8519 = switch_8523;
			int gt_8520 = (gen_8519 > ((int)0));
			int gen_247 = gt_8520;
			t_sample mul_8496 = (gen_8519 * sample_src_8498);
			t_sample poltocar_14859 = (mul_8496 * cos(latch_8508));
			t_sample poltocar_14860 = (mul_8496 * sin(latch_8508));
			t_sample history_200_next_8509 = fixdenorm(gt_8520);
			int switch_8540 = (m_history_16 ? ((int)1) : ((int)2));
			int choice_332 = switch_8540;
			int gate_8545 = (((choice_332 >= 1) && (choice_332 < 2)) ? gen_246 : 0);
			int gate_8542 = ((choice_332 >= 2) ? gen_246 : 0);
			int gen_238 = gate_8545;
			t_sample mul_8566 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_333 = ((gate_8542 != 0) ? mul_8566 : __m_latch_333);
			t_sample latch_8549 = __m_latch_333;
			t_sample add_8569 = (((int)0) + m_offset_5);
			__m_latch_334 = ((gate_8542 != 0) ? add_8569 : __m_latch_334);
			t_sample latch_8553 = __m_latch_334;
			int plusequals_8538 = __m_pluseq_335.post(((int)1), gate_8542, 0);
			t_sample add_8557 = (((int)0) + m_speed_4);
			__m_latch_336 = ((gate_8542 != 0) ? add_8557 : __m_latch_336);
			t_sample latch_8570 = __m_latch_336;
			t_sample add_8554 = (((int)0) + m_slope_3);
			__m_latch_337 = ((gate_8542 != 0) ? add_8554 : __m_latch_337);
			t_sample latch_8552 = __m_latch_337;
			t_sample add_8550 = (((int)0) + m_subsample_1);
			__m_latch_338 = ((gate_8542 != 0) ? add_8550 : __m_latch_338);
			t_sample latch_8546 = __m_latch_338;
			t_sample add_8561 = (plusequals_8538 + latch_8546);
			t_sample mul_8541 = (add_8561 * latch_8570);
			t_sample add_8567 = (mul_8541 + latch_8553);
			int index_trunc_339 = fixnan(floor(add_8567));
			double index_fract_340 = (add_8567 - index_trunc_339);
			int index_trunc_341 = (index_trunc_339 + 1);
			int index_wrap_342 = ((index_trunc_339 < 0) ? ((src_dim - 1) + ((index_trunc_339 + 1) % src_dim)) : (index_trunc_339 % src_dim));
			int index_wrap_343 = ((index_trunc_341 < 0) ? ((src_dim - 1) + ((index_trunc_341 + 1) % src_dim)) : (index_trunc_341 % src_dim));
			// samples src channel 1;
			double read_src_344 = m_src_45.read(index_wrap_342, 0);
			double read_src_345 = m_src_45.read(index_wrap_343, 0);
			double readinterp_346 = linear_interp(index_fract_340, read_src_344, read_src_345);
			t_sample sample_src_8539 = readinterp_346;
			t_sample index_src_8565 = add_8567;
			t_sample mul_8568 = (latch_8552 * add_8561);
			t_sample clamp_8572 = ((mul_8568 <= ((int)0)) ? ((int)0) : ((mul_8568 >= ((int)1)) ? ((int)1) : mul_8568));
			t_sample triangle_8547 = triangle(clamp_8572, m_skew_7);
			t_sample clamp_8575 = ((triangle_8547 <= ((int)0)) ? ((int)0) : ((triangle_8547 >= ((int)1)) ? ((int)1) : triangle_8547));
			int gt_8571 = (clamp_8575 > ((t_sample)0.5));
			t_sample mul_8564 = (clamp_8575 * clamp_8575);
			t_sample mul_8558 = (mul_8564 * clamp_8575);
			t_sample mul_8548 = (mul_8558 * ((int)2));
			t_sample rsub_8544 = (((int)1) - clamp_8575);
			t_sample mul_8543 = (rsub_8544 * rsub_8544);
			t_sample mul_8555 = (mul_8543 * clamp_8575);
			t_sample mul_8551 = (mul_8555 * ((int)6));
			t_sample rsub_8573 = (((int)1) - mul_8551);
			t_sample switch_8563 = (gt_8571 ? rsub_8573 : mul_8548);
			t_sample gen_8559 = switch_8563;
			int gt_8560 = (gen_8559 > ((int)0));
			int gen_239 = gt_8560;
			t_sample mul_8537 = (gen_8559 * sample_src_8539);
			t_sample poltocar_14861 = (mul_8537 * cos(latch_8549));
			t_sample poltocar_14862 = (mul_8537 * sin(latch_8549));
			t_sample history_200_next_8574 = fixdenorm(gt_8560);
			int switch_8581 = (m_history_15 ? ((int)1) : ((int)2));
			int choice_347 = switch_8581;
			int gate_8586 = (((choice_347 >= 1) && (choice_347 < 2)) ? gen_238 : 0);
			int gate_8583 = ((choice_347 >= 2) ? gen_238 : 0);
			int gen_262 = gate_8586;
			t_sample mul_8610 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_348 = ((gate_8583 != 0) ? mul_8610 : __m_latch_348);
			t_sample latch_8590 = __m_latch_348;
			t_sample add_8591 = (((int)0) + m_offset_5);
			__m_latch_349 = ((gate_8583 != 0) ? add_8591 : __m_latch_349);
			t_sample latch_8596 = __m_latch_349;
			int plusequals_8579 = __m_pluseq_350.post(((int)1), gate_8583, 0);
			t_sample add_8600 = (((int)0) + m_speed_4);
			__m_latch_351 = ((gate_8583 != 0) ? add_8600 : __m_latch_351);
			t_sample latch_8613 = __m_latch_351;
			t_sample add_8597 = (((int)0) + m_slope_3);
			__m_latch_352 = ((gate_8583 != 0) ? add_8597 : __m_latch_352);
			t_sample latch_8595 = __m_latch_352;
			t_sample add_8593 = (((int)0) + m_subsample_1);
			__m_latch_353 = ((gate_8583 != 0) ? add_8593 : __m_latch_353);
			t_sample latch_8587 = __m_latch_353;
			t_sample add_8604 = (plusequals_8579 + latch_8587);
			t_sample mul_8582 = (add_8604 * latch_8613);
			t_sample add_8611 = (mul_8582 + latch_8596);
			int index_trunc_354 = fixnan(floor(add_8611));
			double index_fract_355 = (add_8611 - index_trunc_354);
			int index_trunc_356 = (index_trunc_354 + 1);
			int index_wrap_357 = ((index_trunc_354 < 0) ? ((src_dim - 1) + ((index_trunc_354 + 1) % src_dim)) : (index_trunc_354 % src_dim));
			int index_wrap_358 = ((index_trunc_356 < 0) ? ((src_dim - 1) + ((index_trunc_356 + 1) % src_dim)) : (index_trunc_356 % src_dim));
			// samples src channel 1;
			double read_src_359 = m_src_45.read(index_wrap_357, 0);
			double read_src_360 = m_src_45.read(index_wrap_358, 0);
			double readinterp_361 = linear_interp(index_fract_355, read_src_359, read_src_360);
			t_sample sample_src_8580 = readinterp_361;
			t_sample index_src_8609 = add_8611;
			t_sample mul_8612 = (latch_8595 * add_8604);
			t_sample clamp_8608 = ((mul_8612 <= ((int)0)) ? ((int)0) : ((mul_8612 >= ((int)1)) ? ((int)1) : mul_8612));
			t_sample triangle_8588 = triangle(clamp_8608, m_skew_7);
			t_sample clamp_8616 = ((triangle_8588 <= ((int)0)) ? ((int)0) : ((triangle_8588 >= ((int)1)) ? ((int)1) : triangle_8588));
			int gt_8614 = (clamp_8616 > ((t_sample)0.5));
			t_sample mul_8605 = (clamp_8616 * clamp_8616);
			t_sample mul_8601 = (mul_8605 * clamp_8616);
			t_sample mul_8589 = (mul_8601 * ((int)2));
			t_sample rsub_8585 = (((int)1) - clamp_8616);
			t_sample mul_8584 = (rsub_8585 * rsub_8585);
			t_sample mul_8598 = (mul_8584 * clamp_8616);
			t_sample mul_8594 = (mul_8598 * ((int)6));
			t_sample rsub_8615 = (((int)1) - mul_8594);
			t_sample switch_8607 = (gt_8614 ? rsub_8615 : mul_8589);
			t_sample gen_8602 = switch_8607;
			int gt_8603 = (gen_8602 > ((int)0));
			int gen_263 = gt_8603;
			t_sample mul_8578 = (gen_8602 * sample_src_8580);
			t_sample poltocar_14863 = (mul_8578 * cos(latch_8590));
			t_sample poltocar_14864 = (mul_8578 * sin(latch_8590));
			t_sample history_200_next_8592 = fixdenorm(gt_8603);
			int switch_8622 = (m_history_14 ? ((int)1) : ((int)2));
			int choice_362 = switch_8622;
			int gate_8627 = (((choice_362 >= 1) && (choice_362 < 2)) ? gen_262 : 0);
			int gate_8624 = ((choice_362 >= 2) ? gen_262 : 0);
			int gen_254 = gate_8627;
			t_sample mul_8651 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_363 = ((gate_8624 != 0) ? mul_8651 : __m_latch_363);
			t_sample latch_8632 = __m_latch_363;
			t_sample add_8647 = (((int)0) + m_offset_5);
			__m_latch_364 = ((gate_8624 != 0) ? add_8647 : __m_latch_364);
			t_sample latch_8637 = __m_latch_364;
			int plusequals_8620 = __m_pluseq_365.post(((int)1), gate_8624, 0);
			t_sample add_8641 = (((int)0) + m_speed_4);
			__m_latch_366 = ((gate_8624 != 0) ? add_8641 : __m_latch_366);
			t_sample latch_8654 = __m_latch_366;
			t_sample add_8638 = (((int)0) + m_slope_3);
			__m_latch_367 = ((gate_8624 != 0) ? add_8638 : __m_latch_367);
			t_sample latch_8636 = __m_latch_367;
			t_sample add_8634 = (((int)0) + m_subsample_1);
			__m_latch_368 = ((gate_8624 != 0) ? add_8634 : __m_latch_368);
			t_sample latch_8628 = __m_latch_368;
			t_sample add_8645 = (plusequals_8620 + latch_8628);
			t_sample mul_8623 = (add_8645 * latch_8654);
			t_sample add_8652 = (mul_8623 + latch_8637);
			int index_trunc_369 = fixnan(floor(add_8652));
			double index_fract_370 = (add_8652 - index_trunc_369);
			int index_trunc_371 = (index_trunc_369 + 1);
			int index_wrap_372 = ((index_trunc_369 < 0) ? ((src_dim - 1) + ((index_trunc_369 + 1) % src_dim)) : (index_trunc_369 % src_dim));
			int index_wrap_373 = ((index_trunc_371 < 0) ? ((src_dim - 1) + ((index_trunc_371 + 1) % src_dim)) : (index_trunc_371 % src_dim));
			// samples src channel 1;
			double read_src_374 = m_src_45.read(index_wrap_372, 0);
			double read_src_375 = m_src_45.read(index_wrap_373, 0);
			double readinterp_376 = linear_interp(index_fract_370, read_src_374, read_src_375);
			t_sample sample_src_8621 = readinterp_376;
			t_sample index_src_8650 = add_8652;
			t_sample mul_8653 = (latch_8636 * add_8645);
			t_sample clamp_8629 = ((mul_8653 <= ((int)0)) ? ((int)0) : ((mul_8653 >= ((int)1)) ? ((int)1) : mul_8653));
			t_sample triangle_8630 = triangle(clamp_8629, m_skew_7);
			t_sample clamp_8657 = ((triangle_8630 <= ((int)0)) ? ((int)0) : ((triangle_8630 >= ((int)1)) ? ((int)1) : triangle_8630));
			int gt_8655 = (clamp_8657 > ((t_sample)0.5));
			t_sample mul_8649 = (clamp_8657 * clamp_8657);
			t_sample mul_8642 = (mul_8649 * clamp_8657);
			t_sample mul_8631 = (mul_8642 * ((int)2));
			t_sample rsub_8626 = (((int)1) - clamp_8657);
			t_sample mul_8625 = (rsub_8626 * rsub_8626);
			t_sample mul_8639 = (mul_8625 * clamp_8657);
			t_sample mul_8635 = (mul_8639 * ((int)6));
			t_sample rsub_8656 = (((int)1) - mul_8635);
			t_sample switch_8648 = (gt_8655 ? rsub_8656 : mul_8631);
			t_sample gen_8643 = switch_8648;
			int gt_8644 = (gen_8643 > ((int)0));
			int gen_255 = gt_8644;
			t_sample mul_8619 = (gen_8643 * sample_src_8621);
			t_sample poltocar_14865 = (mul_8619 * cos(latch_8632));
			t_sample poltocar_14866 = (mul_8619 * sin(latch_8632));
			t_sample history_200_next_8633 = fixdenorm(gt_8644);
			int switch_8664 = (m_history_13 ? ((int)1) : ((int)2));
			int choice_377 = switch_8664;
			int gate_8668 = (((choice_377 >= 1) && (choice_377 < 2)) ? gen_254 : 0);
			int gate_8665 = ((choice_377 >= 2) ? gen_254 : 0);
			int gen_214 = gate_8668;
			t_sample mul_8691 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_378 = ((gate_8665 != 0) ? mul_8691 : __m_latch_378);
			t_sample latch_8672 = __m_latch_378;
			t_sample add_8661 = (((int)0) + m_offset_5);
			__m_latch_379 = ((gate_8665 != 0) ? add_8661 : __m_latch_379);
			t_sample latch_8676 = __m_latch_379;
			int plusequals_8662 = __m_pluseq_380.post(((int)1), gate_8665, 0);
			t_sample add_8680 = (((int)0) + m_speed_4);
			__m_latch_381 = ((gate_8665 != 0) ? add_8680 : __m_latch_381);
			t_sample latch_8695 = __m_latch_381;
			t_sample add_8677 = (((int)0) + m_slope_3);
			__m_latch_382 = ((gate_8665 != 0) ? add_8677 : __m_latch_382);
			t_sample latch_8675 = __m_latch_382;
			t_sample add_8673 = (((int)0) + m_subsample_1);
			__m_latch_383 = ((gate_8665 != 0) ? add_8673 : __m_latch_383);
			t_sample latch_8669 = __m_latch_383;
			t_sample add_8684 = (plusequals_8662 + latch_8669);
			t_sample mul_8694 = (add_8684 * latch_8695);
			t_sample add_8692 = (mul_8694 + latch_8676);
			int index_trunc_384 = fixnan(floor(add_8692));
			double index_fract_385 = (add_8692 - index_trunc_384);
			int index_trunc_386 = (index_trunc_384 + 1);
			int index_wrap_387 = ((index_trunc_384 < 0) ? ((src_dim - 1) + ((index_trunc_384 + 1) % src_dim)) : (index_trunc_384 % src_dim));
			int index_wrap_388 = ((index_trunc_386 < 0) ? ((src_dim - 1) + ((index_trunc_386 + 1) % src_dim)) : (index_trunc_386 % src_dim));
			// samples src channel 1;
			double read_src_389 = m_src_45.read(index_wrap_387, 0);
			double read_src_390 = m_src_45.read(index_wrap_388, 0);
			double readinterp_391 = linear_interp(index_fract_385, read_src_389, read_src_390);
			t_sample sample_src_8663 = readinterp_391;
			t_sample index_src_8689 = add_8692;
			t_sample mul_8693 = (latch_8675 * add_8684);
			t_sample clamp_8698 = ((mul_8693 <= ((int)0)) ? ((int)0) : ((mul_8693 >= ((int)1)) ? ((int)1) : mul_8693));
			t_sample triangle_8670 = triangle(clamp_8698, m_skew_7);
			t_sample clamp_8699 = ((triangle_8670 <= ((int)0)) ? ((int)0) : ((triangle_8670 >= ((int)1)) ? ((int)1) : triangle_8670));
			int gt_8696 = (clamp_8699 > ((t_sample)0.5));
			t_sample mul_8688 = (clamp_8699 * clamp_8699);
			t_sample mul_8681 = (mul_8688 * clamp_8699);
			t_sample mul_8671 = (mul_8681 * ((int)2));
			t_sample rsub_8667 = (((int)1) - clamp_8699);
			t_sample mul_8666 = (rsub_8667 * rsub_8667);
			t_sample mul_8678 = (mul_8666 * clamp_8699);
			t_sample mul_8674 = (mul_8678 * ((int)6));
			t_sample rsub_8697 = (((int)1) - mul_8674);
			t_sample switch_8687 = (gt_8696 ? rsub_8697 : mul_8671);
			t_sample gen_8682 = switch_8687;
			int gt_8683 = (gen_8682 > ((int)0));
			int gen_215 = gt_8683;
			t_sample mul_8660 = (gen_8682 * sample_src_8663);
			t_sample poltocar_14867 = (mul_8660 * cos(latch_8672));
			t_sample poltocar_14868 = (mul_8660 * sin(latch_8672));
			t_sample history_200_next_8686 = fixdenorm(gt_8683);
			int switch_8702 = (m_history_12 ? ((int)1) : ((int)2));
			int choice_392 = switch_8702;
			int gate_8705 = (((choice_392 >= 1) && (choice_392 < 2)) ? gen_214 : 0);
			int gate_8729 = ((choice_392 >= 2) ? gen_214 : 0);
			int gen_397 = gate_8705;
			t_sample mul_8714 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_393 = ((gate_8729 != 0) ? mul_8714 : __m_latch_393);
			t_sample latch_8720 = __m_latch_393;
			t_sample add_8735 = (((int)0) + m_offset_5);
			__m_latch_394 = ((gate_8729 != 0) ? add_8735 : __m_latch_394);
			t_sample latch_8709 = __m_latch_394;
			int plusequals_8701 = __m_pluseq_395.post(((int)1), gate_8729, 0);
			t_sample add_8711 = (((int)0) + m_speed_4);
			__m_latch_396 = ((gate_8729 != 0) ? add_8711 : __m_latch_396);
			t_sample latch_8736 = __m_latch_396;
			t_sample add_8724 = (((int)0) + m_slope_3);
			__m_latch_397 = ((gate_8729 != 0) ? add_8724 : __m_latch_397);
			t_sample latch_8723 = __m_latch_397;
			t_sample add_8708 = (((int)0) + m_subsample_1);
			__m_latch_398 = ((gate_8729 != 0) ? add_8708 : __m_latch_398);
			t_sample latch_8706 = __m_latch_398;
			t_sample add_8728 = (plusequals_8701 + latch_8706);
			t_sample mul_8718 = (add_8728 * latch_8736);
			t_sample add_8733 = (mul_8718 + latch_8709);
			int index_trunc_399 = fixnan(floor(add_8733));
			double index_fract_400 = (add_8733 - index_trunc_399);
			int index_trunc_401 = (index_trunc_399 + 1);
			int index_wrap_402 = ((index_trunc_399 < 0) ? ((src_dim - 1) + ((index_trunc_399 + 1) % src_dim)) : (index_trunc_399 % src_dim));
			int index_wrap_403 = ((index_trunc_401 < 0) ? ((src_dim - 1) + ((index_trunc_401 + 1) % src_dim)) : (index_trunc_401 % src_dim));
			// samples src channel 1;
			double read_src_404 = m_src_45.read(index_wrap_402, 0);
			double read_src_405 = m_src_45.read(index_wrap_403, 0);
			double readinterp_406 = linear_interp(index_fract_400, read_src_404, read_src_405);
			t_sample sample_src_8730 = readinterp_406;
			t_sample index_src_8740 = add_8733;
			t_sample mul_8734 = (latch_8723 * add_8728);
			t_sample clamp_8717 = ((mul_8734 <= ((int)0)) ? ((int)0) : ((mul_8734 >= ((int)1)) ? ((int)1) : mul_8734));
			t_sample triangle_8719 = triangle(clamp_8717, m_skew_7);
			t_sample clamp_8715 = ((triangle_8719 <= ((int)0)) ? ((int)0) : ((triangle_8719 >= ((int)1)) ? ((int)1) : triangle_8719));
			int gt_8737 = (clamp_8715 > ((t_sample)0.5));
			t_sample mul_8739 = (clamp_8715 * clamp_8715);
			t_sample mul_8712 = (mul_8739 * clamp_8715);
			t_sample mul_8707 = (mul_8712 * ((int)2));
			t_sample rsub_8704 = (((int)1) - clamp_8715);
			t_sample mul_8703 = (rsub_8704 * rsub_8704);
			t_sample mul_8725 = (mul_8703 * clamp_8715);
			t_sample mul_8722 = (mul_8725 * ((int)6));
			t_sample rsub_8738 = (((int)1) - mul_8722);
			t_sample switch_8731 = (gt_8737 ? rsub_8738 : mul_8707);
			t_sample gen_8726 = switch_8731;
			int gt_8727 = (gen_8726 > ((int)0));
			int gen_398 = gt_8727;
			t_sample mul_8716 = (gen_8726 * sample_src_8730);
			t_sample poltocar_14869 = (mul_8716 * cos(latch_8720));
			t_sample poltocar_14870 = (mul_8716 * sin(latch_8720));
			t_sample history_200_next_8721 = fixdenorm(gt_8727);
			int switch_8743 = (m_history_11 ? ((int)1) : ((int)2));
			int choice_407 = switch_8743;
			int gate_8745 = (((choice_407 >= 1) && (choice_407 < 2)) ? gen_397 : 0);
			int gate_8772 = ((choice_407 >= 2) ? gen_397 : 0);
			int gen_230 = gate_8745;
			t_sample mul_8754 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_408 = ((gate_8772 != 0) ? mul_8754 : __m_latch_408);
			t_sample latch_8759 = __m_latch_408;
			t_sample add_8776 = (((int)0) + m_offset_5);
			__m_latch_409 = ((gate_8772 != 0) ? add_8776 : __m_latch_409);
			t_sample latch_8748 = __m_latch_409;
			int plusequals_8742 = __m_pluseq_410.post(((int)1), gate_8772, 0);
			t_sample add_8750 = (((int)0) + m_speed_4);
			__m_latch_411 = ((gate_8772 != 0) ? add_8750 : __m_latch_411);
			t_sample latch_8777 = __m_latch_411;
			t_sample add_8763 = (((int)0) + m_slope_3);
			__m_latch_412 = ((gate_8772 != 0) ? add_8763 : __m_latch_412);
			t_sample latch_8762 = __m_latch_412;
			t_sample add_8747 = (((int)0) + m_subsample_1);
			__m_latch_413 = ((gate_8772 != 0) ? add_8747 : __m_latch_413);
			t_sample latch_8746 = __m_latch_413;
			t_sample add_8767 = (plusequals_8742 + latch_8746);
			t_sample mul_8771 = (add_8767 * latch_8777);
			t_sample add_8781 = (mul_8771 + latch_8748);
			int index_trunc_414 = fixnan(floor(add_8781));
			double index_fract_415 = (add_8781 - index_trunc_414);
			int index_trunc_416 = (index_trunc_414 + 1);
			int index_wrap_417 = ((index_trunc_414 < 0) ? ((src_dim - 1) + ((index_trunc_414 + 1) % src_dim)) : (index_trunc_414 % src_dim));
			int index_wrap_418 = ((index_trunc_416 < 0) ? ((src_dim - 1) + ((index_trunc_416 + 1) % src_dim)) : (index_trunc_416 % src_dim));
			// samples src channel 1;
			double read_src_419 = m_src_45.read(index_wrap_417, 0);
			double read_src_420 = m_src_45.read(index_wrap_418, 0);
			double readinterp_421 = linear_interp(index_fract_415, read_src_419, read_src_420);
			t_sample sample_src_8769 = readinterp_421;
			t_sample index_src_8753 = add_8781;
			t_sample mul_8775 = (latch_8762 * add_8767);
			t_sample clamp_8757 = ((mul_8775 <= ((int)0)) ? ((int)0) : ((mul_8775 >= ((int)1)) ? ((int)1) : mul_8775));
			t_sample triangle_8758 = triangle(clamp_8757, m_skew_7);
			t_sample clamp_8755 = ((triangle_8758 <= ((int)0)) ? ((int)0) : ((triangle_8758 >= ((int)1)) ? ((int)1) : triangle_8758));
			int gt_8778 = (clamp_8755 > ((t_sample)0.5));
			t_sample mul_8780 = (clamp_8755 * clamp_8755);
			t_sample mul_8751 = (mul_8780 * clamp_8755);
			t_sample mul_8768 = (mul_8751 * ((int)2));
			t_sample rsub_8773 = (((int)1) - clamp_8755);
			t_sample mul_8744 = (rsub_8773 * rsub_8773);
			t_sample mul_8764 = (mul_8744 * clamp_8755);
			t_sample mul_8761 = (mul_8764 * ((int)6));
			t_sample rsub_8779 = (((int)1) - mul_8761);
			t_sample switch_8770 = (gt_8778 ? rsub_8779 : mul_8768);
			t_sample gen_8765 = switch_8770;
			int gt_8766 = (gen_8765 > ((int)0));
			int gen_231 = gt_8766;
			t_sample mul_8756 = (gen_8765 * sample_src_8769);
			t_sample poltocar_14871 = (mul_8756 * cos(latch_8759));
			t_sample poltocar_14872 = (mul_8756 * sin(latch_8759));
			t_sample history_200_next_8760 = fixdenorm(gt_8766);
			int switch_8784 = (m_history_10 ? ((int)1) : ((int)2));
			int choice_422 = switch_8784;
			int gate_8786 = (((choice_422 >= 1) && (choice_422 < 2)) ? gen_230 : 0);
			int gate_8813 = ((choice_422 >= 2) ? gen_230 : 0);
			t_sample mul_8795 = (((t_sample)1.5707963267949) * m_pan_6);
			__m_latch_423 = ((gate_8813 != 0) ? mul_8795 : __m_latch_423);
			t_sample latch_8801 = __m_latch_423;
			t_sample add_8817 = (((int)0) + m_offset_5);
			__m_latch_424 = ((gate_8813 != 0) ? add_8817 : __m_latch_424);
			t_sample latch_8789 = __m_latch_424;
			int plusequals_8783 = __m_pluseq_425.post(((int)1), gate_8813, 0);
			t_sample add_8791 = (((int)0) + m_speed_4);
			__m_latch_426 = ((gate_8813 != 0) ? add_8791 : __m_latch_426);
			t_sample latch_8818 = __m_latch_426;
			t_sample add_8805 = (((int)0) + m_slope_3);
			__m_latch_427 = ((gate_8813 != 0) ? add_8805 : __m_latch_427);
			t_sample latch_8804 = __m_latch_427;
			t_sample add_8788 = (((int)0) + m_subsample_1);
			__m_latch_428 = ((gate_8813 != 0) ? add_8788 : __m_latch_428);
			t_sample latch_8787 = __m_latch_428;
			t_sample add_8810 = (plusequals_8783 + latch_8787);
			t_sample mul_8809 = (add_8810 * latch_8818);
			t_sample add_8822 = (mul_8809 + latch_8789);
			int index_trunc_429 = fixnan(floor(add_8822));
			double index_fract_430 = (add_8822 - index_trunc_429);
			int index_trunc_431 = (index_trunc_429 + 1);
			int index_wrap_432 = ((index_trunc_429 < 0) ? ((src_dim - 1) + ((index_trunc_429 + 1) % src_dim)) : (index_trunc_429 % src_dim));
			int index_wrap_433 = ((index_trunc_431 < 0) ? ((src_dim - 1) + ((index_trunc_431 + 1) % src_dim)) : (index_trunc_431 % src_dim));
			// samples src channel 1;
			double read_src_434 = m_src_45.read(index_wrap_432, 0);
			double read_src_435 = m_src_45.read(index_wrap_433, 0);
			double readinterp_436 = linear_interp(index_fract_430, read_src_434, read_src_435);
			t_sample sample_src_8811 = readinterp_436;
			t_sample index_src_8794 = add_8822;
			t_sample mul_8816 = (latch_8804 * add_8810);
			t_sample clamp_8799 = ((mul_8816 <= ((int)0)) ? ((int)0) : ((mul_8816 >= ((int)1)) ? ((int)1) : mul_8816));
			t_sample triangle_8800 = triangle(clamp_8799, m_skew_7);
			t_sample clamp_8796 = ((triangle_8800 <= ((int)0)) ? ((int)0) : ((triangle_8800 >= ((int)1)) ? ((int)1) : triangle_8800));
			int gt_8819 = (clamp_8796 > ((t_sample)0.5));
			t_sample mul_8797 = (clamp_8796 * clamp_8796);
			t_sample mul_8792 = (mul_8797 * clamp_8796);
			t_sample mul_8815 = (mul_8792 * ((int)2));
			t_sample rsub_8814 = (((int)1) - clamp_8796);
			t_sample mul_8785 = (rsub_8814 * rsub_8814);
			t_sample mul_8806 = (mul_8785 * clamp_8796);
			t_sample mul_8803 = (mul_8806 * ((int)6));
			t_sample rsub_8820 = (((int)1) - mul_8803);
			t_sample switch_8812 = (gt_8819 ? rsub_8820 : mul_8815);
			t_sample gen_8807 = switch_8812;
			int gt_8808 = (gen_8807 > ((int)0));
			int gen_223 = gt_8808;
			t_sample mul_8798 = (gen_8807 * sample_src_8811);
			t_sample poltocar_14873 = (mul_8798 * cos(latch_8801));
			t_sample poltocar_14874 = (mul_8798 * sin(latch_8801));
			t_sample history_200_next_8802 = fixdenorm(gt_8808);
			t_sample out3 = (((((((((((((((((((((((gen_398 + gen_327) + gen_319) + gen_311) + gen_362) + gen_303) + gen_354) + gen_346) + gen_295) + gen_338) + gen_378) + gen_287) + gen_370) + gen_279) + gen_386) + gen_271) + gen_263) + gen_255) + gen_247) + gen_239) + gen_231) + gen_223) + gen_215) + gen_394);
			t_sample R_32 = (((((((((((((((((((((((poltocar_14870 + poltocar_14848) + poltocar_14850) + poltocar_14844) + poltocar_14840) + poltocar_14846) + poltocar_14842) + poltocar_14836) + poltocar_14856) + poltocar_14838) + poltocar_14828) + poltocar_14858) + poltocar_14830) + poltocar_14852) + poltocar_14834) + poltocar_14854) + poltocar_14864) + poltocar_14866) + poltocar_14860) + poltocar_14862) + poltocar_14872) + poltocar_14874) + poltocar_14868) + poltocar_14832);
			t_sample mix_14875 = (in2 + (m_knob6_drywet_37 * (R_32 - in2)));
			t_sample out2 = mix_14875;
			t_sample L_33 = (((((((((((((((((((((((poltocar_14869 + poltocar_14847) + poltocar_14849) + poltocar_14843) + poltocar_14839) + poltocar_14845) + poltocar_14841) + poltocar_14835) + poltocar_14855) + poltocar_14837) + poltocar_14827) + poltocar_14857) + poltocar_14829) + poltocar_14851) + poltocar_14833) + poltocar_14853) + poltocar_14863) + poltocar_14865) + poltocar_14859) + poltocar_14861) + poltocar_14871) + poltocar_14873) + poltocar_14867) + poltocar_14831);
			t_sample mix_14876 = (in1 + (m_knob6_drywet_37 * (L_33 - in1)));
			t_sample out1 = mix_14876;
			t_sample pan_next_8826 = fixdenorm(scale_335);
			t_sample offset_next_8827 = fixdenorm(mul_125);
			t_sample speed_next_8828 = fixdenorm(exp_110);
			t_sample slope_next_8829 = fixdenorm(rdiv_408);
			t_sample history_136_next_8830 = fixdenorm(gen_154);
			t_sample subsample_next_8831 = fixdenorm(gen_156);
			m_history_33 = history_200_next_209;
			m_history_32 = history_200_next_7887;
			m_history_31 = history_200_next_7928;
			m_history_30 = history_200_next_7970;
			m_history_29 = history_200_next_8038;
			m_history_28 = history_200_next_8074;
			m_history_27 = history_200_next_8118;
			m_history_26 = history_200_next_8142;
			m_history_25 = history_200_next_8182;
			m_history_24 = history_200_next_8245;
			m_history_23 = history_200_next_8283;
			m_history_22 = history_200_next_8304;
			m_history_21 = history_200_next_8366;
			m_history_20 = history_200_next_8386;
			m_history_19 = history_200_next_8447;
			m_history_18 = history_200_next_8488;
			m_history_17 = history_200_next_8509;
			m_history_16 = history_200_next_8574;
			m_history_15 = history_200_next_8592;
			m_history_14 = history_200_next_8633;
			m_history_13 = history_200_next_8686;
			m_history_12 = history_200_next_8721;
			m_history_11 = history_200_next_8760;
			m_history_10 = history_200_next_8802;
			m_octave_spread_9 = octave_spread_next_8824;
			m_skew_7 = skew_next_8825;
			m_pan_6 = pan_next_8826;
			m_offset_5 = offset_next_8827;
			m_speed_4 = speed_next_8828;
			m_slope_3 = slope_next_8829;
			m_history_2 = history_136_next_8830;
			m_subsample_1 = subsample_next_8831;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
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
	inline void set_knob1_rate(t_param _value) {
		m_knob1_rate_34 = (_value < 0 ? 0 : (_value > 500 ? 500 : _value));
	};
	inline void set_switches(void * _value) {
		m_switches_35.setbuffer(_value);
	};
	inline void set_knob5_durationspread(t_param _value) {
		m_knob5_durationspread_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_drywet(t_param _value) {
		m_knob6_drywet_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_skew(t_param _value) {
		m_knob2_skew_38 = (_value < 0.001 ? 0.001 : (_value > 0.999 ? 0.999 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_feedback(t_param _value) {
		m_knob3_feedback_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_42 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_43 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_duration(t_param _value) {
		m_knob4_duration_44 = (_value < 10 ? 10 : (_value > 2000 ? 2000 : _value));
	};
	inline void set_src(void * _value) {
		m_src_45.setbuffer(_value);
	};
	inline void set_width(t_param _value) {
		m_width_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_rate_spread(t_param _value) {
		m_rate_spread_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin1(t_param _value) {
		m_cvin_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_50 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_51 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_position_spread(t_param _value) {
		m_position_spread_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_pswitches(void * _value) {
		m_pswitches_55.setbuffer(_value);
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
int num_params() { return 22; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "busy", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "cvout1", "cvout2" };

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
		case 0: self->set_cvin1(value); break;
		case 1: self->set_gate1(value); break;
		case 2: self->set_knob1_rate(value); break;
		case 3: self->set_knob2_skew(value); break;
		case 4: self->set_knob3_feedback(value); break;
		case 5: self->set_knob4_duration(value); break;
		case 6: self->set_knob5_durationspread(value); break;
		case 7: self->set_knob6_drywet(value); break;
		case 8: self->set_position_spread(value); break;
		case 9: self->set_pswitches(ref); break;
		case 10: self->set_rate_spread(value); break;
		case 11: self->set_src(ref); break;
		case 12: self->set_sw1(value); break;
		case 13: self->set_sw2(value); break;
		case 14: self->set_sw3(value); break;
		case 15: self->set_sw4(value); break;
		case 16: self->set_sw5(value); break;
		case 17: self->set_sw6(value); break;
		case 18: self->set_sw7(value); break;
		case 19: self->set_sw8(value); break;
		case 20: self->set_switches(ref); break;
		case 21: self->set_width(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_cvin_48; break;
		case 1: *value = self->m_gate_50; break;
		case 2: *value = self->m_knob1_rate_34; break;
		case 3: *value = self->m_knob2_skew_38; break;
		case 4: *value = self->m_knob3_feedback_40; break;
		case 5: *value = self->m_knob4_duration_44; break;
		case 6: *value = self->m_knob5_durationspread_36; break;
		case 7: *value = self->m_knob6_drywet_37; break;
		case 8: *value = self->m_position_spread_54; break;
		
		case 10: *value = self->m_rate_spread_47; break;
		
		case 12: *value = self->m_sw_51; break;
		case 13: *value = self->m_sw_53; break;
		case 14: *value = self->m_sw_52; break;
		case 15: *value = self->m_sw_39; break;
		case 16: *value = self->m_sw_43; break;
		case 17: *value = self->m_sw_42; break;
		case 18: *value = self->m_sw_49; break;
		case 19: *value = self->m_sw_41; break;
		
		case 21: *value = self->m_width_46; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(22 * sizeof(ParamInfo));
	self->__commonstate.numparams = 22;
	// initialize parameter 0 ("m_cvin_48")
	pi = self->__commonstate.params + 0;
	pi->name = "cvin1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_gate_50")
	pi = self->__commonstate.params + 1;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_50;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob1_rate_34")
	pi = self->__commonstate.params + 2;
	pi->name = "knob1_rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_rate_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 500;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob2_skew_38")
	pi = self->__commonstate.params + 3;
	pi->name = "knob2_skew";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_skew_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.001;
	pi->outputmax = 0.999;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob3_feedback_40")
	pi = self->__commonstate.params + 4;
	pi->name = "knob3_feedback";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_feedback_40;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob4_duration_44")
	pi = self->__commonstate.params + 5;
	pi->name = "knob4_duration";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_duration_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 10;
	pi->outputmax = 2000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob5_durationspread_36")
	pi = self->__commonstate.params + 6;
	pi->name = "knob5_durationspread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_durationspread_36;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob6_drywet_37")
	pi = self->__commonstate.params + 7;
	pi->name = "knob6_drywet";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_drywet_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_position_spread_54")
	pi = self->__commonstate.params + 8;
	pi->name = "position_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_position_spread_54;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_pswitches_55")
	pi = self->__commonstate.params + 9;
	pi->name = "pswitches";
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
	// initialize parameter 10 ("m_rate_spread_47")
	pi = self->__commonstate.params + 10;
	pi->name = "rate_spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_rate_spread_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_src_45")
	pi = self->__commonstate.params + 11;
	pi->name = "src";
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
	// initialize parameter 12 ("m_sw_51")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_51;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_53")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_53;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_sw_52")
	pi = self->__commonstate.params + 14;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_52;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_39")
	pi = self->__commonstate.params + 15;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_39;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_sw_43")
	pi = self->__commonstate.params + 16;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_43;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_42")
	pi = self->__commonstate.params + 17;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_42;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_49")
	pi = self->__commonstate.params + 18;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_41")
	pi = self->__commonstate.params + 19;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_switches_35")
	pi = self->__commonstate.params + 20;
	pi->name = "switches";
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
	// initialize parameter 21 ("m_width_46")
	pi = self->__commonstate.params + 21;
	pi->name = "width";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_width_46;
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


} // grains::
