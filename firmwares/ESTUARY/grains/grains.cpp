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
	Change __m_change_30;
	Change __m_change_45;
	Change __m_change_47;
	Change __m_change_51;
	Change __m_change_44;
	Change __m_change_39;
	Change __m_change_40;
	Change __m_change_35;
	Change __m_change_53;
	Change __m_change_50;
	Change __m_change_57;
	Change __m_change_63;
	Delay m_delay_3;
	Delta __m_delta_48;
	PlusEquals __m_pluseq_56;
	PlusEquals __m_pluseq_38;
	PlusEquals __m_pluseq_52;
	PlusEquals __m_pluseq_43;
	PlusEquals __m_pluseq_66;
	PlusEquals __m_pluseq_60;
	PlusEquals __m_pluseq_33;
	SineCycle __m_cycle_61;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_7;
	t_sample m_history_8;
	t_sample m_gatein_22;
	t_sample m_history_6;
	t_sample __m_latch_54;
	t_sample m_history_9;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample __m_latch_46;
	t_sample m_history_12;
	t_sample __m_latch_55;
	t_sample m_history_4;
	t_sample samplerate;
	t_sample __m_latch_64;
	t_sample m_history_5;
	t_sample m_history_1;
	t_sample __m_latch_59;
	t_sample m_history_2;
	t_sample __m_latch_58;
	t_sample m_knob_21;
	t_sample m_history_13;
	t_sample __m_latch_42;
	t_sample m_gate_27;
	t_sample m_knob_28;
	t_sample m_knob_29;
	t_sample m_knob_20;
	t_sample m_gate_26;
	t_sample m_knob_24;
	t_sample m_knob_25;
	t_sample m_cvin_23;
	t_sample m_history_14;
	t_sample __m_latch_65;
	t_sample m_knob_19;
	t_sample m_cvin_16;
	t_sample m_cvin_15;
	t_sample __m_latch_41;
	t_sample __m_latch_32;
	t_sample m_cvin_17;
	t_sample __m_latch_36;
	t_sample __m_latch_37;
	t_sample m_knob_18;
	t_sample __m_latch_31;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_delay_3.reset("m_delay_3", samplerate);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_cvin_15 = ((int)0);
		m_cvin_16 = ((int)0);
		m_cvin_17 = ((int)0);
		m_knob_18 = ((int)0);
		m_knob_19 = ((int)0);
		m_knob_20 = ((int)1);
		m_knob_21 = ((int)0);
		m_gatein_22 = ((int)0);
		m_cvin_23 = ((int)0);
		m_knob_24 = ((int)0);
		m_knob_25 = ((int)1);
		m_gate_26 = ((int)0);
		m_gate_27 = ((int)0);
		m_knob_28 = ((int)1);
		m_knob_29 = ((int)1);
		__m_change_30.reset(0);
		__m_latch_31 = 0;
		__m_latch_32 = 0;
		__m_pluseq_33.reset(0);
		__m_change_35.reset(0);
		__m_latch_36 = 0;
		__m_latch_37 = 0;
		__m_pluseq_38.reset(0);
		__m_change_39.reset(0);
		__m_change_40.reset(0);
		__m_latch_41 = 0;
		__m_latch_42 = 0;
		__m_pluseq_43.reset(0);
		__m_change_44.reset(0);
		__m_change_45.reset(0);
		__m_latch_46 = 11025;
		__m_change_47.reset(0);
		__m_delta_48.reset(0);
		__m_change_50.reset(0);
		__m_change_51.reset(0);
		__m_pluseq_52.reset(0);
		__m_change_53.reset(0);
		__m_latch_54 = 0;
		__m_latch_55 = 0;
		__m_pluseq_56.reset(0);
		__m_change_57.reset(0);
		__m_latch_58 = 0;
		__m_latch_59 = 0;
		__m_pluseq_60.reset(0);
		__m_cycle_61.reset(samplerate, 0);
		__m_change_63.reset(0);
		__m_latch_64 = 0;
		__m_latch_65 = 0;
		__m_pluseq_66.reset(0);
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
		t_sample * __out13 = __outs[12];
		t_sample * __out14 = __outs[13];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample min_348 = ((m_knob_29 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_29);
		t_sample rdiv_341 = safediv(safediv(1000, samplerate), min_348);
		int iftrue_34 = (-1);
		int switch_439 = (m_knob_28 ? iftrue_34 : ((int)1));
		t_sample min_2655 = ((m_knob_29 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_29);
		t_sample rdiv_2660 = safediv(safediv(1000, samplerate), min_2655);
		int int_196 = int(m_gate_27);
		t_sample min_2666 = ((m_knob_29 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_29);
		t_sample rdiv_2671 = safediv(safediv(1000, samplerate), min_2666);
		int int_2677 = int(m_gatein_22);
		t_sample history_248_next_284 = fixdenorm(((int)8));
		t_sample mstosamps_235 = (((int)0) * (samplerate * 0.001));
		t_sample max_236 = ((mstosamps_235 < vectorsize) ? vectorsize : mstosamps_235);
		t_sample min_2680 = ((m_knob_29 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_29);
		t_sample rdiv_2681 = safediv(safediv(1000, samplerate), min_2680);
		t_sample min_2691 = ((m_knob_29 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_29);
		t_sample rdiv_2692 = safediv(safediv(1000, samplerate), min_2691);
		t_sample min_2708 = ((m_knob_29 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_29);
		t_sample rdiv_2703 = safediv(safediv(1000, samplerate), min_2708);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out14 = ((int)0);
			t_sample out13 = ((int)0);
			t_sample out2 = ((int)0);
			int change_349 = __m_change_30(m_knob_25);
			__m_latch_31 = ((change_349 != 0) ? m_history_14 : __m_latch_31);
			t_sample latch_346 = __m_latch_31;
			__m_latch_32 = ((change_349 != 0) ? m_knob_25 : __m_latch_32);
			t_sample latch_345 = __m_latch_32;
			t_sample plusequals_347 = __m_pluseq_33.pre(rdiv_341, change_349, 0);
			t_sample clamp_342 = ((plusequals_347 <= ((int)0)) ? ((int)0) : ((plusequals_347 >= ((int)1)) ? ((int)1) : plusequals_347));
			t_sample mix_2721 = (latch_346 + (clamp_342 * (latch_345 - latch_346)));
			t_sample mix_344 = mix_2721;
			t_sample gen_445 = mix_344;
			t_sample history_343_next_350 = fixdenorm(mix_344);
			int change_2664 = __m_change_35(m_knob_20);
			__m_latch_36 = ((change_2664 != 0) ? m_history_13 : __m_latch_36);
			t_sample latch_2659 = __m_latch_36;
			__m_latch_37 = ((change_2664 != 0) ? m_knob_20 : __m_latch_37);
			t_sample latch_2656 = __m_latch_37;
			t_sample plusequals_2657 = __m_pluseq_38.pre(rdiv_2660, change_2664, 0);
			t_sample clamp_2662 = ((plusequals_2657 <= ((int)0)) ? ((int)0) : ((plusequals_2657 >= ((int)1)) ? ((int)1) : plusequals_2657));
			t_sample mix_2722 = (latch_2659 + (clamp_2662 * (latch_2656 - latch_2659)));
			t_sample mix_2658 = mix_2722;
			t_sample gen_444 = mix_2658;
			t_sample history_343_next_2661 = fixdenorm(mix_2658);
			int change_197 = __m_change_39(int_196);
			int eqp_198 = ((int_196 == change_197) ? int_196 : 0);
			int gen_199 = eqp_198;
			int change_2675 = __m_change_40(m_knob_18);
			__m_latch_41 = ((change_2675 != 0) ? m_history_12 : __m_latch_41);
			t_sample latch_2670 = __m_latch_41;
			__m_latch_42 = ((change_2675 != 0) ? m_knob_18 : __m_latch_42);
			t_sample latch_2673 = __m_latch_42;
			t_sample plusequals_2668 = __m_pluseq_43.pre(rdiv_2671, change_2675, 0);
			t_sample clamp_2667 = ((plusequals_2668 <= ((int)0)) ? ((int)0) : ((plusequals_2668 >= ((int)1)) ? ((int)1) : plusequals_2668));
			t_sample mix_2723 = (latch_2670 + (clamp_2667 * (latch_2673 - latch_2670)));
			t_sample mix_2669 = mix_2723;
			t_sample gen_447 = mix_2669;
			t_sample history_343_next_2674 = fixdenorm(mix_2669);
			t_sample mstosamps_460 = (gen_447 * (samplerate * 0.001));
			int change_2678 = __m_change_44(int_2677);
			int eqp_2679 = ((int_2677 == change_2678) ? int_2677 : 0);
			int gen_211 = eqp_2679;
			int gt_220 = (gen_211 > ((int)0));
			int change_219 = __m_change_45(gt_220);
			int gt_218 = (change_219 > ((int)0));
			int gen_221 = gt_218;
			t_sample add_226 = (m_history_11 + ((int)1));
			t_sample switch_223 = (gen_221 ? ((int)0) : add_226);
			__m_latch_46 = ((gen_221 != 0) ? add_226 : __m_latch_46);
			t_sample latch_225 = __m_latch_46;
			t_sample gen_228 = latch_225;
			t_sample history_224_next_227 = fixdenorm(switch_223);
			t_sample rdiv_215 = safediv(((int)1), gen_228);
			t_sample add_217 = (m_history_10 + rdiv_215);
			t_sample switch_214 = (gen_221 ? ((int)0) : add_217);
			t_sample wrap_216 = wrap(switch_214, ((int)0), ((int)1));
			t_sample gen_231 = wrap_216;
			t_sample history_213_next_229 = fixdenorm(wrap_216);
			t_sample mul_253 = (gen_231 * ((t_sample)0.125));
			t_sample sub_269 = (gen_231 - m_history_9);
			t_sample add_270 = (gen_231 + m_history_9);
			t_sample div_268 = safediv(sub_269, add_270);
			t_sample abs_267 = fabs(div_268);
			int gt_265 = (abs_267 > ((t_sample)0.5));
			int change_264 = __m_change_47(gt_265);
			int gt_263 = (change_264 > ((int)0));
			int gen_272 = gt_263;
			t_sample history_266_next_271 = fixdenorm(gen_231);
			t_sample delta_278 = __m_delta_48(gen_231);
			t_sample wrap_279 = wrap(delta_278, (-0.5), ((t_sample)0.5));
			t_sample gen_280 = wrap_279;
			t_sample mul_275 = (gen_280 * ((t_sample)0.125));
			t_sample add_273 = (mul_275 + m_history_6);
			t_sample sub_251 = (add_273 - mul_253);
			t_sample round_262 = (trunc((sub_251 * ((t_sample)8))) * ((t_sample)0.125));
			t_sample add_252 = (round_262 + mul_253);
			t_sample sub_282 = (m_history_7 - ((int)8));
			t_sample add_283 = (m_history_7 + ((int)8));
			t_sample div_281 = safediv(sub_282, add_283);
			t_sample abs_246 = fabs(div_281);
			int gt_247 = (abs_246 > ((t_sample)0.015625));
			int and_250 = (gt_247 && ((int)1));
			t_sample switch_254 = (and_250 ? and_250 : m_history_8);
			t_sample switch_257 = (gen_272 ? switch_254 : ((int)0));
			t_sample gen_260 = switch_257;
			t_sample switch_256 = (switch_257 ? ((int)0) : switch_254);
			t_sample history_258_next_259 = fixdenorm(switch_256);
			int or_249 = (gen_260 || gen_199);
			t_sample switch_277 = (or_249 ? add_252 : add_273);
			t_sample wrap_274 = wrap(switch_277, ((int)0), ((int)1));
			t_sample gen_286 = wrap_274;
			t_sample history_276_next_285 = fixdenorm(wrap_274);
			t_sample mul_202 = (gen_286 * ((int)8));
			t_sample floor_201 = floor(mul_202);
			t_sample add_182 = (floor_201 + ((int)1));
			t_sample choice_49 = int(add_182);
			t_sample gate_188 = (((choice_49 >= 1) && (choice_49 < 2)) ? ((int)1) : 0);
			t_sample gate_189 = (((choice_49 >= 2) && (choice_49 < 3)) ? ((int)1) : 0);
			t_sample gate_190 = (((choice_49 >= 3) && (choice_49 < 4)) ? ((int)1) : 0);
			t_sample gate_191 = (((choice_49 >= 4) && (choice_49 < 5)) ? ((int)1) : 0);
			t_sample gate_192 = (((choice_49 >= 5) && (choice_49 < 6)) ? ((int)1) : 0);
			t_sample gate_193 = (((choice_49 >= 6) && (choice_49 < 7)) ? ((int)1) : 0);
			t_sample gate_194 = (((choice_49 >= 7) && (choice_49 < 8)) ? ((int)1) : 0);
			t_sample gate_195 = ((choice_49 >= 8) ? ((int)1) : 0);
			t_sample out5 = gate_190;
			t_sample out10 = gate_195;
			t_sample out7 = gate_192;
			t_sample out3 = gate_188;
			t_sample out6 = gate_191;
			t_sample out8 = gate_193;
			t_sample out4 = gate_189;
			t_sample out9 = gate_194;
			t_sample add_184 = (add_182 + ((int)1));
			int change_244 = __m_change_50(add_184);
			int neq_243 = (change_244 != ((int)0));
			int gt_241 = (neq_243 > ((int)0));
			int change_240 = __m_change_51(gt_241);
			int gt_239 = (change_240 > ((int)0));
			int plusequals_238 = __m_pluseq_52.post(((int)1), gt_239, 0);
			int lte_237 = (plusequals_238 <= max_236);
			t_sample out11 = lte_237;
			t_sample out12 = lte_237;
			int change_2689 = __m_change_53(m_knob_19);
			__m_latch_54 = ((change_2689 != 0) ? m_history_5 : __m_latch_54);
			t_sample latch_2684 = __m_latch_54;
			__m_latch_55 = ((change_2689 != 0) ? m_knob_19 : __m_latch_55);
			t_sample latch_2682 = __m_latch_55;
			t_sample plusequals_2685 = __m_pluseq_56.pre(rdiv_2681, change_2689, 0);
			t_sample clamp_2686 = ((plusequals_2685 <= ((int)0)) ? ((int)0) : ((plusequals_2685 >= ((int)1)) ? ((int)1) : plusequals_2685));
			t_sample mix_2724 = (latch_2684 + (clamp_2686 * (latch_2682 - latch_2684)));
			t_sample mix_2687 = mix_2724;
			t_sample gen_449 = mix_2687;
			t_sample history_343_next_2683 = fixdenorm(mix_2687);
			int change_2700 = __m_change_57(m_knob_24);
			__m_latch_58 = ((change_2700 != 0) ? m_history_4 : __m_latch_58);
			t_sample latch_2695 = __m_latch_58;
			__m_latch_59 = ((change_2700 != 0) ? m_knob_24 : __m_latch_59);
			t_sample latch_2693 = __m_latch_59;
			t_sample plusequals_2696 = __m_pluseq_60.pre(rdiv_2692, change_2700, 0);
			t_sample clamp_2697 = ((plusequals_2696 <= ((int)0)) ? ((int)0) : ((plusequals_2696 >= ((int)1)) ? ((int)1) : plusequals_2696));
			t_sample mix_2725 = (latch_2695 + (clamp_2697 * (latch_2693 - latch_2695)));
			t_sample mix_2698 = mix_2725;
			t_sample gen_448 = mix_2698;
			t_sample history_343_next_2694 = fixdenorm(mix_2698);
			__m_cycle_61.freq(gen_448);
			t_sample cycle_456 = __m_cycle_61(__sinedata);
			t_sample cycleindex_457 = __m_cycle_61.phase();
			t_sample mul_455 = (cycle_456 * gen_449);
			t_sample mul_440 = (mstosamps_460 * mul_455);
			t_sample maxa_62 = (mul_440 + mstosamps_460);
			t_sample max_451 = ((maxa_62 < ((int)1)) ? ((int)1) : maxa_62);
			t_sample tap_462 = m_delay_3.read_linear(max_451);
			t_sample sub_334 = (tap_462 - m_history_2);
			t_sample abs_336 = fabs(gen_444);
			t_sample clamp_335 = ((abs_336 <= ((int)0)) ? ((int)0) : ((abs_336 >= ((int)1)) ? ((int)1) : abs_336));
			t_sample mul_333 = (sub_334 * clamp_335);
			t_sample add_332 = (mul_333 + m_history_2);
			t_sample gen_441 = add_332;
			t_sample history_331_next_337 = fixdenorm((mul_333 + add_332));
			t_sample mul_458 = (gen_441 * switch_439);
			t_sample mix_2726 = (in1 + (gen_445 * (mul_458 - in1)));
			t_sample out1 = mix_2726;
			int change_2712 = __m_change_63(m_knob_21);
			__m_latch_64 = ((change_2712 != 0) ? m_history_1 : __m_latch_64);
			t_sample latch_2706 = __m_latch_64;
			__m_latch_65 = ((change_2712 != 0) ? m_knob_21 : __m_latch_65);
			t_sample latch_2704 = __m_latch_65;
			t_sample plusequals_2707 = __m_pluseq_66.pre(rdiv_2703, change_2712, 0);
			t_sample clamp_2709 = ((plusequals_2707 <= ((int)0)) ? ((int)0) : ((plusequals_2707 >= ((int)1)) ? ((int)1) : plusequals_2707));
			t_sample mix_2727 = (latch_2706 + (clamp_2709 * (latch_2704 - latch_2706)));
			t_sample mix_2710 = mix_2727;
			t_sample gen_446 = mix_2710;
			t_sample history_343_next_2705 = fixdenorm(mix_2710);
			t_sample mstosamps_450 = (gen_446 * (samplerate * 0.001));
			t_sample div_453 = safediv(mstosamps_450, max_451);
			t_sample t_454 = exp(safediv(-6.9077552789821, div_453));
			t_sample mul_438 = (mul_458 * t_454);
			t_sample add_452 = (in1 + mul_438);
			m_history_14 = history_343_next_350;
			m_history_13 = history_343_next_2661;
			m_history_12 = history_343_next_2674;
			m_history_11 = history_224_next_227;
			m_history_10 = history_213_next_229;
			m_history_9 = history_266_next_271;
			m_history_6 = history_276_next_285;
			m_history_7 = history_248_next_284;
			m_history_8 = history_258_next_259;
			m_history_5 = history_343_next_2683;
			m_history_4 = history_343_next_2694;
			m_delay_3.write(add_452);
			m_history_2 = history_331_next_337;
			m_history_1 = history_343_next_2705;
			m_delay_3.step();
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
			(*(__out13++)) = out13;
			(*(__out14++)) = out14;
			
		};
		return __exception;
		
	};
	inline void set_cvin2(t_param _value) {
		m_cvin_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin3(t_param _value) {
		m_cvin_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin4(t_param _value) {
		m_cvin_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2(t_param _value) {
		m_knob_18 = (_value < 0 ? 0 : (_value > 10000 ? 10000 : _value));
	};
	inline void set_knob4(t_param _value) {
		m_knob_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6(t_param _value) {
		m_knob_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1(t_param _value) {
		m_knob_21 = (_value < 0.001 ? 0.001 : (_value > 12000 ? 12000 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin1(t_param _value) {
		m_cvin_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3(t_param _value) {
		m_knob_24 = (_value < 0.001 ? 0.001 : (_value > 10 ? 10 : _value));
	};
	inline void set_knob8(t_param _value) {
		m_knob_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate2(t_param _value) {
		m_gate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob7(t_param _value) {
		m_knob_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5(t_param _value) {
		m_knob_29 = (_value < 0 ? 0 : (_value > 5000 ? 5000 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 14;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 15; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "gateout1", "gateout2", "cvout1", "cvout2" };

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
		case 1: self->set_cvin2(value); break;
		case 2: self->set_cvin3(value); break;
		case 3: self->set_cvin4(value); break;
		case 4: self->set_gate1(value); break;
		case 5: self->set_gate2(value); break;
		case 6: self->set_gatein1(value); break;
		case 7: self->set_knob1(value); break;
		case 8: self->set_knob2(value); break;
		case 9: self->set_knob3(value); break;
		case 10: self->set_knob4(value); break;
		case 11: self->set_knob5(value); break;
		case 12: self->set_knob6(value); break;
		case 13: self->set_knob7(value); break;
		case 14: self->set_knob8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_cvin_23; break;
		case 1: *value = self->m_cvin_15; break;
		case 2: *value = self->m_cvin_16; break;
		case 3: *value = self->m_cvin_17; break;
		case 4: *value = self->m_gate_26; break;
		case 5: *value = self->m_gate_27; break;
		case 6: *value = self->m_gatein_22; break;
		case 7: *value = self->m_knob_21; break;
		case 8: *value = self->m_knob_18; break;
		case 9: *value = self->m_knob_24; break;
		case 10: *value = self->m_knob_19; break;
		case 11: *value = self->m_knob_29; break;
		case 12: *value = self->m_knob_20; break;
		case 13: *value = self->m_knob_28; break;
		case 14: *value = self->m_knob_25; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(15 * sizeof(ParamInfo));
	self->__commonstate.numparams = 15;
	// initialize parameter 0 ("m_cvin_23")
	pi = self->__commonstate.params + 0;
	pi->name = "cvin1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cvin_15")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_cvin_16")
	pi = self->__commonstate.params + 2;
	pi->name = "cvin3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_cvin_17")
	pi = self->__commonstate.params + 3;
	pi->name = "cvin4";
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
	// initialize parameter 4 ("m_gate_26")
	pi = self->__commonstate.params + 4;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_gate_27")
	pi = self->__commonstate.params + 5;
	pi->name = "gate2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_gatein_22")
	pi = self->__commonstate.params + 6;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob_21")
	pi = self->__commonstate.params + 7;
	pi->name = "knob1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.001;
	pi->outputmax = 12000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob_18")
	pi = self->__commonstate.params + 8;
	pi->name = "knob2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 10000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob_24")
	pi = self->__commonstate.params + 9;
	pi->name = "knob3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.001;
	pi->outputmax = 10;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob_19")
	pi = self->__commonstate.params + 10;
	pi->name = "knob4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_knob_29")
	pi = self->__commonstate.params + 11;
	pi->name = "knob5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_knob_20")
	pi = self->__commonstate.params + 12;
	pi->name = "knob6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_knob_28")
	pi = self->__commonstate.params + 13;
	pi->name = "knob7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_knob_25")
	pi = self->__commonstate.params + 14;
	pi->name = "knob8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_25;
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
