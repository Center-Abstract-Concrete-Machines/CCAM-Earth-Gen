#include "summer_2dlfo.h"

namespace summer_2dlfo {

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
	Change __m_change_36;
	Change __m_change_37;
	Change __m_change_39;
	Change __m_change_28;
	Change __m_change_31;
	Change __m_change_26;
	Phasor __m_phasor_30;
	PlusEquals __m_pluseq_27;
	int __exception;
	int vectorsize;
	t_sample m_knob5_amplitude_24;
	t_sample m_knob6_offset_25;
	t_sample __m_latch_29;
	t_sample m_knob4_shape_23;
	t_sample samples_to_seconds;
	t_sample __m_latch_32;
	t_sample __m_latch_33;
	t_sample __m_latch_40;
	t_sample __m_latch_41;
	t_sample m_gate_22;
	t_sample __m_latch_38;
	t_sample __m_latch_34;
	t_sample __m_latch_35;
	t_sample __m_latch_42;
	t_sample m_knob1_hz_21;
	t_sample m_sw_19;
	t_sample m_history_5;
	t_sample m_history_6;
	t_sample m_history_7;
	t_sample m_knob3_skew_8;
	t_sample m_history_4;
	t_sample m_history_2;
	t_sample m_history_3;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_sw_20;
	t_sample m_bipolar_9;
	t_sample m_sw_11;
	t_sample m_sw_16;
	t_sample m_cvin_17;
	t_sample m_sw_18;
	t_sample m_symmetry_10;
	t_sample m_sw_15;
	t_sample m_sw_13;
	t_sample m_sw_14;
	t_sample m_knob2_random_12;
	t_sample __m_latch_43;
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
		m_knob3_skew_8 = ((int)0);
		m_bipolar_9 = ((int)0);
		m_symmetry_10 = ((int)0);
		m_sw_11 = ((int)0);
		m_knob2_random_12 = ((int)0);
		m_sw_13 = ((int)0);
		m_sw_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_cvin_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_sw_19 = ((int)0);
		m_sw_20 = ((int)0);
		m_knob1_hz_21 = ((int)0);
		m_gate_22 = ((int)0);
		m_knob4_shape_23 = ((int)0);
		m_knob5_amplitude_24 = ((int)1);
		m_knob6_offset_25 = ((int)1);
		__m_change_26.reset(0);
		__m_pluseq_27.reset(0);
		__m_change_28.reset(0);
		__m_latch_29 = 11025;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_30.reset(0);
		__m_change_31.reset(0);
		__m_latch_32 = 0;
		__m_latch_33 = 0;
		__m_latch_34 = 0;
		__m_latch_35 = 0;
		__m_change_36.reset(0);
		__m_change_37.reset(0);
		__m_latch_38 = 0;
		__m_change_39.reset(0);
		__m_latch_40 = 0;
		__m_latch_41 = 0;
		__m_latch_42 = 0;
		__m_latch_43 = 0;
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
		t_sample mstosamps_6189 = (((int)0) * (samplerate * 0.001));
		t_sample max_6190 = ((mstosamps_6189 < vectorsize) ? vectorsize : mstosamps_6189);
		int gt_6195 = (m_gate_22 > ((int)0));
		t_sample rsub_17970 = (((int)1) - m_knob5_amplitude_24);
		t_sample mul_17969 = (rsub_17970 * m_knob6_offset_25);
		t_sample rsub_16240 = (((int)1) - m_knob5_amplitude_24);
		t_sample mul_16487 = (rsub_16240 * m_knob6_offset_25);
		t_sample neg_10491 = (-m_bipolar_9);
		t_sample sub_22280 = (m_knob1_hz_21 - ((int)0));
		t_sample scale_22277 = ((safepow((sub_22280 * ((t_sample)1)), ((int)1)) * ((int)8)) + ((int)0));
		t_sample scale_17843 = scale_22277;
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out1 = ((int)0);
			int change_6194 = __m_change_26(gt_6195);
			int gt_6193 = (change_6194 > ((int)0));
			int plusequals_6192 = __m_pluseq_27.post(((int)1), gt_6193, 0);
			int lte_6191 = (plusequals_6192 <= max_6190);
			int gen_10352 = lte_6191;
			int gt_10361 = (gen_10352 > ((int)0));
			int change_10360 = __m_change_28(gt_10361);
			int gt_10359 = (change_10360 > ((int)0));
			int gen_10362 = gt_10359;
			t_sample add_10367 = (m_history_7 + ((int)1));
			t_sample switch_10364 = (gen_10362 ? ((int)0) : add_10367);
			__m_latch_29 = ((gen_10362 != 0) ? add_10367 : __m_latch_29);
			t_sample latch_10366 = __m_latch_29;
			t_sample gen_10369 = latch_10366;
			t_sample history_10365_next_10368 = fixdenorm(switch_10364);
			t_sample rdiv_10363 = safediv(samplerate, gen_10369);
			t_sample div_10353 = (rdiv_10363 * ((t_sample)0.016666666666667));
			t_sample rdiv_10356 = safediv(((int)1), gen_10369);
			t_sample add_10358 = (m_history_6 + rdiv_10356);
			t_sample switch_10355 = (gen_10362 ? ((int)0) : add_10358);
			t_sample wrap_10357 = wrap(switch_10355, ((int)0), ((int)1));
			t_sample history_10354_next_10370 = fixdenorm(wrap_10357);
			t_sample out2 = div_10353;
			t_sample noise_10503 = noise();
			t_sample abs_10504 = fabs(noise_10503);
			t_sample phasor_10753 = __m_phasor_30(scale_17843, samples_to_seconds);
			t_sample sub_236 = (phasor_10753 - m_history_5);
			t_sample add_237 = (phasor_10753 + m_history_5);
			t_sample div_235 = safediv(sub_236, add_237);
			t_sample abs_234 = fabs(div_235);
			int gt_232 = (abs_234 > ((t_sample)0.5));
			int change_231 = __m_change_31(gt_232);
			int gt_230 = (change_231 > ((int)0));
			int gen_10502 = gt_230;
			t_sample history_233_next_238 = fixdenorm(phasor_10753);
			__m_latch_32 = ((gen_10502 != 0) ? neg_10491 : __m_latch_32);
			t_sample latch_10493 = __m_latch_32;
			__m_latch_33 = ((gen_10502 != 0) ? m_knob4_shape_23 : __m_latch_33);
			t_sample latch_10500 = __m_latch_33;
			t_sample rsub_10498 = (((int)1) - latch_10500);
			__m_latch_34 = ((gen_10502 != 0) ? m_knob2_random_12 : __m_latch_34);
			t_sample latch_10492 = __m_latch_34;
			__m_latch_35 = ((gen_10502 != 0) ? m_knob3_skew_8 : __m_latch_35);
			t_sample latch_10511 = __m_latch_35;
			t_sample clamp_271 = ((latch_10511 <= ((int)0)) ? ((int)0) : ((latch_10511 >= ((int)1)) ? ((int)1) : latch_10511));
			t_sample triangle_270 = triangle(phasor_10753, clamp_271);
			t_sample sub_22284 = (triangle_270 - ((int)0));
			t_sample scale_22281 = ((safepow((sub_22284 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_269 = scale_22281;
			t_sample gen_10508 = scale_269;
			t_sample rsub_10489 = (((int)1) - gen_10508);
			int change_10490 = __m_change_36(gen_10508);
			int gt_10510 = (change_10490 > ((int)0));
			t_sample switch_10507 = (gt_10510 ? gen_10508 : rsub_10489);
			t_sample sub_22205 = (switch_10507 - m_history_4);
			t_sample add_22200 = (switch_10507 + m_history_4);
			t_sample div_22198 = safediv(sub_22205, add_22200);
			t_sample abs_22203 = fabs(div_22198);
			int gt_22206 = (abs_22203 > ((t_sample)0.5));
			int change_22202 = __m_change_37(gt_22206);
			int gt_22201 = (change_22202 > ((int)0));
			int gen_10485 = gt_22201;
			t_sample history_233_next_22199 = fixdenorm(switch_10507);
			__m_latch_38 = ((gen_10485 != 0) ? m_history_2 : __m_latch_38);
			t_sample latch_10487 = __m_latch_38;
			t_sample sub_22214 = (switch_10507 - m_history_3);
			t_sample add_22210 = (switch_10507 + m_history_3);
			t_sample div_22208 = safediv(sub_22214, add_22210);
			t_sample abs_22213 = fabs(div_22208);
			int gt_22216 = (abs_22213 > ((t_sample)0.5));
			int change_22212 = __m_change_39(gt_22216);
			int gt_22211 = (change_22212 > ((int)0));
			int gen_10506 = gt_22211;
			t_sample history_233_next_22209 = fixdenorm(switch_10507);
			__m_latch_40 = ((gen_10506 != 0) ? m_history_1 : __m_latch_40);
			t_sample latch_10513 = __m_latch_40;
			t_sample mix_22285 = (gt_10510 + (latch_10492 * (abs_10504 - gt_10510)));
			t_sample mix_10495 = mix_22285;
			t_sample orange_22288 = (((int)1) - latch_10493);
			t_sample sub_22289 = (mix_10495 - ((int)0));
			t_sample scale_22286 = ((safepow((sub_22289 * ((t_sample)1)), ((int)1)) * orange_22288) + latch_10493);
			t_sample scale_10494 = scale_22286;
			__m_latch_41 = ((gen_10485 != 0) ? scale_10494 : __m_latch_41);
			t_sample latch_10488 = __m_latch_41;
			int gte_10482 = (latch_10487 >= latch_10488);
			__m_latch_42 = ((gen_10506 != 0) ? scale_10494 : __m_latch_42);
			t_sample latch_10514 = __m_latch_42;
			__m_latch_43 = ((gen_10502 != 0) ? m_symmetry_10 : __m_latch_43);
			t_sample latch_10496 = __m_latch_43;
			int and_10497 = (gte_10482 && latch_10496);
			t_sample switch_10499 = (and_10497 ? latch_10500 : rsub_10498);
			t_sample clamp_223 = ((switch_10507 <= ((int)0)) ? ((int)0) : ((switch_10507 >= ((int)1)) ? ((int)1) : switch_10507));
			t_sample clamp_217 = ((switch_10499 <= ((int)0)) ? ((int)0) : ((switch_10499 >= ((int)1)) ? ((int)1) : switch_10499));
			int lt_226 = (clamp_217 < ((t_sample)0.5));
			int not_222 = (!lt_226);
			t_sample sub_22293 = (clamp_217 - ((int)1));
			t_sample scale_22290 = ((safepow((sub_22293 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_227 = scale_22290;
			t_sample tan_225 = tan(scale_227);
			t_sample rdiv_224 = safediv(((int)1), tan_225);
			t_sample switch_221 = (lt_226 ? rdiv_224 : tan_225);
			t_sample switch_220 = (lt_226 ? tan_225 : rdiv_224);
			int irange_22295 = (lt_226 - not_222);
			t_sample sub_22297 = (clamp_223 - not_222);
			t_sample scale_22294 = ((safepow(safediv(sub_22297, irange_22295), switch_220) * ((int)-1)) + ((int)1));
			t_sample scale_219 = scale_22294;
			int orange_22300 = (not_222 - lt_226);
			t_sample sub_22301 = (scale_219 - ((int)0));
			t_sample scale_22298 = ((safepow((sub_22301 * ((t_sample)1)), switch_221) * orange_22300) + lt_226);
			t_sample scale_218 = scale_22298;
			t_sample gen_10483 = scale_218;
			t_sample mix_22302 = (latch_10487 + (gen_10483 * (latch_10488 - latch_10487)));
			t_sample mix_10484 = mix_22302;
			t_sample mul_16857 = (mix_10484 * rsub_16240);
			t_sample add_16981 = (mul_16857 + mul_16487);
			t_sample out8 = add_16981;
			t_sample out7 = add_16981;
			t_sample out10 = add_16981;
			t_sample out12 = add_16981;
			t_sample out9 = add_16981;
			t_sample clamp_255 = ((switch_10507 <= ((int)0)) ? ((int)0) : ((switch_10507 >= ((int)1)) ? ((int)1) : switch_10507));
			t_sample round_261 = round(clamp_255);
			t_sample triangle_256 = triangle(clamp_255, ((t_sample)0.5));
			t_sample clamp_259 = ((switch_10499 <= ((int)0)) ? ((int)0) : ((switch_10499 >= ((int)1)) ? ((int)1) : switch_10499));
			t_sample sub_22306 = (clamp_259 - ((int)1));
			t_sample scale_22303 = ((safepow((sub_22306 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_257 = scale_22303;
			t_sample clamp_22224 = ((triangle_256 <= ((int)0)) ? ((int)0) : ((triangle_256 >= ((int)1)) ? ((int)1) : triangle_256));
			t_sample clamp_22227 = ((scale_257 <= ((int)0)) ? ((int)0) : ((scale_257 >= ((int)1)) ? ((int)1) : scale_257));
			int lt_22222 = (clamp_22227 < ((t_sample)0.5));
			int not_22230 = (!lt_22222);
			t_sample sub_22310 = (clamp_22227 - ((int)1));
			t_sample scale_22307 = ((safepow((sub_22310 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_22221 = scale_22307;
			t_sample tan_22228 = tan(scale_22221);
			t_sample rdiv_22220 = safediv(((int)1), tan_22228);
			t_sample switch_22225 = (lt_22222 ? rdiv_22220 : tan_22228);
			t_sample switch_22218 = (lt_22222 ? tan_22228 : rdiv_22220);
			int irange_22312 = (lt_22222 - not_22230);
			t_sample sub_22314 = (clamp_22224 - not_22230);
			t_sample scale_22311 = ((safepow(safediv(sub_22314, irange_22312), switch_22218) * ((int)-1)) + ((int)1));
			t_sample scale_22226 = scale_22311;
			int orange_22317 = (not_22230 - lt_22222);
			t_sample sub_22318 = (scale_22226 - ((int)0));
			t_sample scale_22315 = ((safepow((sub_22318 * ((t_sample)1)), switch_22225) * orange_22317) + lt_22222);
			t_sample scale_22219 = scale_22315;
			t_sample gen_258 = scale_22219;
			t_sample mix_22319 = (round_261 + (gen_258 * (clamp_255 - round_261)));
			t_sample mix_260 = mix_22319;
			t_sample gen_10501 = mix_260;
			t_sample mix_22320 = (latch_10513 + (gen_10501 * (latch_10514 - latch_10513)));
			t_sample mix_10505 = mix_22320;
			t_sample mul_17968 = (mix_10505 * rsub_17970);
			t_sample add_17967 = (mul_17968 + mul_17969);
			t_sample out6 = add_17967;
			t_sample out3 = add_17967;
			t_sample out4 = add_17967;
			t_sample out5 = add_17967;
			t_sample out11 = add_17967;
			t_sample history_10486_next_22231 = fixdenorm(mix_10484);
			t_sample history_10512_next_22232 = fixdenorm(mix_10505);
			m_history_7 = history_10365_next_10368;
			m_history_6 = history_10354_next_10370;
			m_history_5 = history_233_next_238;
			m_history_4 = history_233_next_22199;
			m_history_3 = history_233_next_22209;
			m_history_2 = history_10486_next_22231;
			m_history_1 = history_10512_next_22232;
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
	inline void set_knob3_skew(t_param _value) {
		m_knob3_skew_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bipolar(t_param _value) {
		m_bipolar_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_symmetry(t_param _value) {
		m_symmetry_10 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_random(t_param _value) {
		m_knob2_random_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin1(t_param _value) {
		m_cvin_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_hz(t_param _value) {
		m_knob1_hz_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_shape(t_param _value) {
		m_knob4_shape_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_amplitude(t_param _value) {
		m_knob5_amplitude_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_offset(t_param _value) {
		m_knob6_offset_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 18; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "cvout1", "cvout2" };

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
		case 0: self->set_bipolar(value); break;
		case 1: self->set_cvin1(value); break;
		case 2: self->set_gate1(value); break;
		case 3: self->set_knob1_hz(value); break;
		case 4: self->set_knob2_random(value); break;
		case 5: self->set_knob3_skew(value); break;
		case 6: self->set_knob4_shape(value); break;
		case 7: self->set_knob5_amplitude(value); break;
		case 8: self->set_knob6_offset(value); break;
		case 9: self->set_sw1(value); break;
		case 10: self->set_sw2(value); break;
		case 11: self->set_sw3(value); break;
		case 12: self->set_sw4(value); break;
		case 13: self->set_sw5(value); break;
		case 14: self->set_sw6(value); break;
		case 15: self->set_sw7(value); break;
		case 16: self->set_sw8(value); break;
		case 17: self->set_symmetry(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_bipolar_9; break;
		case 1: *value = self->m_cvin_17; break;
		case 2: *value = self->m_gate_22; break;
		case 3: *value = self->m_knob1_hz_21; break;
		case 4: *value = self->m_knob2_random_12; break;
		case 5: *value = self->m_knob3_skew_8; break;
		case 6: *value = self->m_knob4_shape_23; break;
		case 7: *value = self->m_knob5_amplitude_24; break;
		case 8: *value = self->m_knob6_offset_25; break;
		case 9: *value = self->m_sw_14; break;
		case 10: *value = self->m_sw_19; break;
		case 11: *value = self->m_sw_20; break;
		case 12: *value = self->m_sw_11; break;
		case 13: *value = self->m_sw_18; break;
		case 14: *value = self->m_sw_13; break;
		case 15: *value = self->m_sw_15; break;
		case 16: *value = self->m_sw_16; break;
		case 17: *value = self->m_symmetry_10; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(18 * sizeof(ParamInfo));
	self->__commonstate.numparams = 18;
	// initialize parameter 0 ("m_bipolar_9")
	pi = self->__commonstate.params + 0;
	pi->name = "bipolar";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bipolar_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cvin_17")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_gate_22")
	pi = self->__commonstate.params + 2;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob1_hz_21")
	pi = self->__commonstate.params + 3;
	pi->name = "knob1_hz";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_hz_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob2_random_12")
	pi = self->__commonstate.params + 4;
	pi->name = "knob2_random";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_random_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob3_skew_8")
	pi = self->__commonstate.params + 5;
	pi->name = "knob3_skew";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_skew_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob4_shape_23")
	pi = self->__commonstate.params + 6;
	pi->name = "knob4_shape";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_shape_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob5_amplitude_24")
	pi = self->__commonstate.params + 7;
	pi->name = "knob5_amplitude";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_amplitude_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob6_offset_25")
	pi = self->__commonstate.params + 8;
	pi->name = "knob6_offset";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_offset_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_14")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_19")
	pi = self->__commonstate.params + 10;
	pi->name = "sw2";
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
	// initialize parameter 11 ("m_sw_20")
	pi = self->__commonstate.params + 11;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_11")
	pi = self->__commonstate.params + 12;
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
	// initialize parameter 13 ("m_sw_18")
	pi = self->__commonstate.params + 13;
	pi->name = "sw5";
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
	// initialize parameter 14 ("m_sw_13")
	pi = self->__commonstate.params + 14;
	pi->name = "sw6";
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
	// initialize parameter 15 ("m_sw_15")
	pi = self->__commonstate.params + 15;
	pi->name = "sw7";
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
	// initialize parameter 16 ("m_sw_16")
	pi = self->__commonstate.params + 16;
	pi->name = "sw8";
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
	// initialize parameter 17 ("m_symmetry_10")
	pi = self->__commonstate.params + 17;
	pi->name = "symmetry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_symmetry_10;
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


} // summer_2dlfo::
