#include "POCKET_CALCULATOR.h"

namespace POCKET_CALCULATOR {

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
	Change __m_change_124;
	Change __m_change_120;
	Change __m_change_139;
	Change __m_change_88;
	Change __m_change_113;
	Change __m_change_148;
	Change __m_change_142;
	Change __m_change_108;
	Change __m_change_156;
	Change __m_change_158;
	Change __m_change_149;
	Change __m_change_155;
	Change __m_change_151;
	Data m_euclidean_patterns_86;
	Delay m_delay_37;
	Delay m_delay_22;
	Delay m_delay_31;
	Delay m_delay_24;
	Delay m_delay_23;
	Delay m_delay_25;
	Delay m_delay_39;
	Delay m_delay_41;
	Delay m_delay_27;
	Delay m_delay_35;
	Delay m_delay_29;
	Delay m_delay_33;
	Phasor __m_phasor_87;
	Phasor __m_phasor_141;
	Phasor __m_phasor_119;
	Phasor __m_phasor_112;
	SineCycle __m_cycle_163;
	SineData __sinedata;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample __m_latch_125;
	t_sample m_history_32;
	t_sample __m_latch_126;
	t_sample m_history_8;
	t_sample __m_latch_122;
	t_sample __m_latch_123;
	t_sample __m_latch_121;
	t_sample __m_latch_127;
	t_sample __m_latch_129;
	t_sample __m_latch_132;
	t_sample __m_latch_128;
	t_sample __m_latch_131;
	t_sample __m_latch_130;
	t_sample __m_latch_133;
	t_sample m_history_9;
	t_sample __m_latch_118;
	t_sample m_history_13;
	t_sample __m_latch_109;
	t_sample m_history_14;
	t_sample elapsed;
	t_sample m_history_10;
	t_sample m_history_12;
	t_sample __m_latch_114;
	t_sample __m_latch_117;
	t_sample m_history_11;
	t_sample __m_latch_116;
	t_sample __m_latch_115;
	t_sample __m_latch_134;
	t_sample __m_latch_135;
	t_sample __m_latch_136;
	t_sample __m_latch_154;
	t_sample m_history_1;
	t_sample __m_latch_153;
	t_sample m_history_2;
	t_sample __m_latch_152;
	t_sample __m_latch_150;
	t_sample samplerate;
	t_sample __m_latch_159;
	t_sample __m_latch_162;
	t_sample __m_latch_157;
	t_sample __m_latch_161;
	t_sample __m_latch_160;
	t_sample __m_latch_89;
	t_sample m_history_3;
	t_sample __m_latch_147;
	t_sample m_history_7;
	t_sample __m_latch_140;
	t_sample __m_latch_138;
	t_sample __m_latch_137;
	t_sample m_history_4;
	t_sample m_history_6;
	t_sample __m_latch_143;
	t_sample __m_latch_146;
	t_sample m_history_5;
	t_sample __m_latch_145;
	t_sample __m_latch_144;
	t_sample m_history_30;
	t_sample m_history_15;
	t_sample samples_to_seconds;
	t_sample m_history_50;
	t_sample m_history_51;
	t_sample m_history_49;
	t_sample m_history_47;
	t_sample m_history_48;
	t_sample m_history_46;
	t_sample m_history_52;
	t_sample m_history_54;
	t_sample m_history_57;
	t_sample m_history_53;
	t_sample m_history_56;
	t_sample m_history_55;
	t_sample m_shift_58;
	t_sample m_history_45;
	t_sample m_history_43;
	t_sample m_history_26;
	t_sample m_history_36;
	t_sample m_history_34;
	t_sample m_history_28;
	t_sample m_history_44;
	t_sample m_history_21;
	t_sample m_history_20;
	t_sample m_history_42;
	t_sample m_history_38;
	t_sample m_history_19;
	t_sample m_history_40;
	t_sample m_history_16;
	t_sample m_hits_59;
	t_sample m_beats_61;
	t_sample m_knob3_euclidP_79;
	t_sample m_sw_80;
	t_sample m_cvin_78;
	t_sample m_denom_76;
	t_sample m_shape_77;
	t_sample m_numer_75;
	t_sample m_sw_81;
	t_sample m_knob1_bpm_83;
	t_sample m_history_17;
	t_sample m_bipolar_82;
	t_sample m_knob5_timbre_85;
	t_sample m_sw_84;
	t_sample m_events_60;
	t_sample m_sw_74;
	t_sample m_history_18;
	t_sample m_symmetry_64;
	t_sample m_knob6_filter_65;
	t_sample m_sw_63;
	t_sample m_history_62;
	t_sample m_knob4_shiftVar_73;
	t_sample m_sw_66;
	t_sample m_knob2_envelopeLength_68;
	t_sample m_sw_71;
	t_sample m_gatein_67;
	t_sample m_sw_70;
	t_sample m_random_69;
	t_sample m_skew_72;
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
		m_history_9 = ((int)0);
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
		m_delay_22.reset("m_delay_22", ((int)2000));
		m_delay_23.reset("m_delay_23", ((int)2000));
		m_delay_24.reset("m_delay_24", ((int)2000));
		m_delay_25.reset("m_delay_25", ((int)2000));
		m_history_26 = ((int)0);
		m_delay_27.reset("m_delay_27", ((int)2000));
		m_history_28 = ((int)0);
		m_delay_29.reset("m_delay_29", ((int)2000));
		m_history_30 = ((int)0);
		m_delay_31.reset("m_delay_31", ((int)2000));
		m_history_32 = ((int)0);
		m_delay_33.reset("m_delay_33", ((int)2000));
		m_history_34 = ((int)0);
		m_delay_35.reset("m_delay_35", ((int)2000));
		m_history_36 = ((int)0);
		m_delay_37.reset("m_delay_37", ((int)2000));
		m_history_38 = ((int)0);
		m_delay_39.reset("m_delay_39", ((int)2000));
		m_history_40 = ((int)0);
		m_delay_41.reset("m_delay_41", ((int)2000));
		m_history_42 = ((int)0);
		m_history_43 = ((int)0);
		m_history_44 = ((int)0);
		m_history_45 = ((int)0);
		m_history_46 = ((int)0);
		m_history_47 = ((int)0);
		m_history_48 = ((int)0);
		m_history_49 = ((int)0);
		m_history_50 = ((int)0);
		m_history_51 = ((int)0);
		m_history_52 = ((int)0);
		m_history_53 = ((int)0);
		m_history_54 = ((int)0);
		m_history_55 = ((int)0);
		m_history_56 = ((int)0);
		m_history_57 = ((int)0);
		m_shift_58 = ((int)0);
		m_hits_59 = ((int)0);
		m_events_60 = ((int)0);
		m_beats_61 = ((int)0);
		m_history_62 = ((int)0);
		m_sw_63 = ((int)0);
		m_symmetry_64 = ((int)0);
		m_knob6_filter_65 = ((int)220);
		m_sw_66 = ((int)0);
		m_gatein_67 = ((int)0);
		m_knob2_envelopeLength_68 = ((int)0);
		m_random_69 = ((int)0);
		m_sw_70 = ((int)0);
		m_sw_71 = ((int)0);
		m_skew_72 = ((t_sample)0.5);
		m_knob4_shiftVar_73 = ((t_sample)0.5);
		m_sw_74 = ((int)0);
		m_numer_75 = ((int)5);
		m_denom_76 = ((int)12);
		m_shape_77 = ((t_sample)0.5);
		m_cvin_78 = ((int)0);
		m_knob3_euclidP_79 = ((int)0);
		m_sw_80 = ((int)0);
		m_sw_81 = ((int)0);
		m_bipolar_82 = ((int)0);
		m_knob1_bpm_83 = ((int)0);
		m_sw_84 = ((int)0);
		m_knob5_timbre_85 = ((int)0);
		m_euclidean_patterns_86.reset("euclidean_patterns", ((int)64), ((int)4));
		samples_to_seconds = (1 / samplerate);
		__m_phasor_87.reset(0);
		__m_change_88.reset(0);
		__m_latch_89 = 0;
		elapsed = 0;
		__m_change_108.reset(0);
		__m_latch_109 = 11025;
		__m_phasor_112.reset(0);
		__m_change_113.reset(0);
		__m_latch_114 = 0;
		__m_latch_115 = 0;
		__m_latch_116 = 0;
		__m_latch_117 = 0;
		__m_latch_118 = 0;
		__m_phasor_119.reset(0);
		__m_change_120.reset(0);
		__m_latch_121 = 0;
		__m_latch_122 = 0;
		__m_latch_123 = 0;
		__m_change_124.reset(0);
		__m_latch_125 = 0;
		__m_latch_126 = 0;
		__m_latch_127 = 0;
		__m_latch_128 = 0;
		__m_latch_129 = 0;
		__m_latch_130 = 0;
		__m_latch_131 = 0;
		__m_latch_132 = 0;
		__m_latch_133 = 0;
		__m_latch_134 = 0;
		__m_latch_135 = 0;
		__m_latch_136 = 0;
		__m_latch_137 = 0;
		__m_latch_138 = 0;
		__m_change_139.reset(0);
		__m_latch_140 = 0;
		__m_phasor_141.reset(0);
		__m_change_142.reset(0);
		__m_latch_143 = 0;
		__m_latch_144 = 0;
		__m_latch_145 = 0;
		__m_latch_146 = 0;
		__m_latch_147 = 0;
		__m_change_148.reset(0);
		__m_change_149.reset(0);
		__m_latch_150 = 0;
		__m_change_151.reset(0);
		__m_latch_152 = 0;
		__m_latch_153 = 0;
		__m_latch_154 = 0;
		__m_change_155.reset(0);
		__m_change_156.reset(0);
		__m_latch_157 = 0;
		__m_change_158.reset(0);
		__m_latch_159 = 0;
		__m_latch_160 = 0;
		__m_latch_161 = 0;
		__m_latch_162 = 0;
		__m_cycle_163.reset(samplerate, 0);
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
		samples_to_seconds = (1 / samplerate);
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		int euclidean_patterns_dim = m_euclidean_patterns_86.dim;
		int euclidean_patterns_channels = m_euclidean_patterns_86.channels;
		bool chan_ignore_101 = ((1 < 0) || (1 >= euclidean_patterns_channels));
		bool chan_ignore_104 = ((2 < 0) || (2 >= euclidean_patterns_channels));
		bool chan_ignore_107 = ((3 < 0) || (3 >= euclidean_patterns_channels));
		int gt_375 = (m_gatein_67 > ((int)0));
		t_sample neg_245 = (-m_bipolar_82);
		t_sample mul_431 = (samplerate * m_knob2_envelopeLength_68);
		t_sample t_432 = exp(safediv(-6.9077552789821, mul_431));
		int min_110 = ((-samplerate) * ((t_sample)0.5));
		int max_111 = (samplerate * ((t_sample)0.5));
		t_sample clamp_299 = ((m_knob6_filter_65 <= min_110) ? min_110 : ((m_knob6_filter_65 >= max_111) ? max_111 : m_knob6_filter_65));
		t_sample abs_298 = fabs(clamp_299);
		t_sample mul_297 = (abs_298 * safediv(6.2831853071796, samplerate));
		t_sample cos_296 = cos(mul_297);
		t_sample neg_295 = (-cos_296);
		t_sample mul_285 = (neg_295 * ((int)2));
		t_sample sin_294 = sin(mul_297);
		t_sample mul_293 = (sin_294 * ((t_sample)0.5));
		t_sample div_292 = (mul_293 * ((t_sample)0.5));
		t_sample rsub_284 = (((int)1) - div_292);
		t_sample neg_283 = (-div_292);
		t_sample add_291 = (div_292 + ((int)1));
		t_sample rdiv_290 = safediv(((int)1), add_291);
		t_sample mul_287 = (mul_285 * rdiv_290);
		t_sample gen_304 = mul_287;
		t_sample mul_286 = (rsub_284 * rdiv_290);
		t_sample gen_305 = mul_286;
		t_sample mul_288 = (neg_283 * rdiv_290);
		t_sample gen_303 = mul_288;
		t_sample mul_289 = (div_292 * rdiv_290);
		t_sample gen_301 = mul_289;
		int lt_211 = (m_knob4_shiftVar_73 < ((t_sample)0.1));
		int gt_367 = (m_knob1_bpm_83 > ((t_sample)0.99));
		int int_441 = int(m_numer_75);
		int int_439 = int(m_denom_76);
		t_sample div_438 = safediv(int_441, int_439);
		t_sample sub_12823 = (m_knob1_bpm_83 - ((int)0));
		t_sample scale_12820 = ((safepow((sub_12823 * ((t_sample)1)), ((int)1)) * ((int)-260)) + ((int)320));
		t_sample scale_5799 = scale_12820;
		t_sample div_433 = (scale_5799 * ((t_sample)0.016666666666667));
		int min_164 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample phasor_412 = __m_phasor_87(((int)10), samples_to_seconds);
			t_sample sub_236 = (phasor_412 - m_history_62);
			t_sample add_237 = (phasor_412 + m_history_62);
			t_sample div_235 = safediv(sub_236, add_237);
			t_sample abs_234 = fabs(div_235);
			int gt_232 = (abs_234 > ((t_sample)0.5));
			int change_231 = __m_change_88(gt_232);
			int gt_230 = (change_231 > ((int)0));
			int gen_411 = gt_230;
			t_sample history_233_next_238 = fixdenorm(phasor_412);
			__m_latch_89 = ((gen_411 != 0) ? m_knob3_euclidP_79 : __m_latch_89);
			t_sample latch_413 = __m_latch_89;
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				int euclidean_patterns_dim = m_euclidean_patterns_86.dim;
				int euclidean_patterns_channels = m_euclidean_patterns_86.channels;
				while ((i < euclidean_patterns_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample n2 = noise();
					t_sample n3 = noise();
					t_sample sub_12808 = (n2 - (-1));
					t_sample scale_12805 = ((safepow((sub_12808 * ((t_sample)0.5)), ((int)1)) * ((int)0)) + ((int)16));
					t_sample b = round(scale_12805);
					t_sample sub_12812 = (n3 - (-1));
					t_sample scale_12809 = ((safepow((sub_12812 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)1));
					t_sample c = round(scale_12809);
					bool index_ignore_90 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!index_ignore_90)) {
						m_euclidean_patterns_86.write(((int)8), i, 0);
						
					};
					bool chan_ignore_91 = ((((int)1) < 0) || (((int)1) >= euclidean_patterns_channels));
					bool index_ignore_92 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_91 || index_ignore_92))) {
						m_euclidean_patterns_86.write(b, i, ((int)1));
						
					};
					bool chan_ignore_93 = ((((int)2) < 0) || (((int)2) >= euclidean_patterns_channels));
					bool index_ignore_94 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_93 || index_ignore_94))) {
						m_euclidean_patterns_86.write(c, i, ((int)2));
						
					};
					bool chan_ignore_95 = ((((int)3) < 0) || (((int)3) >= euclidean_patterns_channels));
					bool index_ignore_96 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_95 || index_ignore_96))) {
						m_euclidean_patterns_86.write(((int)0), i, ((int)3));
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			t_sample sub_12816 = (latch_413 - ((int)0));
			t_sample scale_12813 = ((safepow((sub_12816 * ((t_sample)1)), ((int)1)) * ((int)63)) + ((int)1));
			t_sample selection = round(scale_12813);
			int index_trunc_97 = fixnan(floor(selection));
			bool index_ignore_98 = ((index_trunc_97 >= euclidean_patterns_dim) || (index_trunc_97 < 0));
			// samples euclidean_patterns channel 1;
			m_beats_61 = (index_ignore_98 ? 0 : m_euclidean_patterns_86.read(index_trunc_97, 0));
			int index_trunc_99 = fixnan(floor(selection));
			bool index_ignore_100 = ((index_trunc_99 >= euclidean_patterns_dim) || (index_trunc_99 < 0));
			// samples euclidean_patterns channel 1;
			m_events_60 = ((chan_ignore_101 || index_ignore_100) ? 0 : m_euclidean_patterns_86.read(index_trunc_99, 1));
			int index_trunc_102 = fixnan(floor(selection));
			bool index_ignore_103 = ((index_trunc_102 >= euclidean_patterns_dim) || (index_trunc_102 < 0));
			// samples euclidean_patterns channel 1;
			m_hits_59 = ((chan_ignore_104 || index_ignore_103) ? 0 : m_euclidean_patterns_86.read(index_trunc_102, 2));
			int index_trunc_105 = fixnan(floor(selection));
			bool index_ignore_106 = ((index_trunc_105 >= euclidean_patterns_dim) || (index_trunc_105 < 0));
			// samples euclidean_patterns channel 1;
			m_shift_58 = ((chan_ignore_107 || index_ignore_106) ? 0 : m_euclidean_patterns_86.read(index_trunc_105, 3));
			int change_374 = __m_change_108(gt_375);
			int gt_373 = (change_374 > ((int)0));
			int gen_376 = gt_373;
			t_sample noise_384 = noise();
			int gt_383 = (noise_384 > m_knob4_shiftVar_73);
			t_sample add_380 = (m_history_57 + ((int)1));
			__m_latch_109 = ((gen_376 != 0) ? add_380 : __m_latch_109);
			t_sample latch_379 = __m_latch_109;
			t_sample gen_382 = latch_379;
			t_sample switch_377 = (gen_376 ? ((int)0) : add_380);
			t_sample history_378_next_381 = fixdenorm(switch_377);
			t_sample rdiv_370 = safediv(((int)1), gen_382);
			t_sample add_372 = (m_history_21 + rdiv_370);
			t_sample switch_369 = (gen_376 ? ((int)0) : add_372);
			t_sample wrap_371 = wrap(switch_369, ((int)0), ((int)1));
			t_sample noise_351 = noise();
			t_sample abs_352 = fabs(noise_351);
			t_sample mix_12817 = (m_history_56 + (((t_sample)0.0042742627044161) * (m_knob5_timbre_85 - m_history_56)));
			t_sample mix_6201 = mix_12817;
			t_sample mix_12818 = (m_history_55 + (((t_sample)0.0042742627044161) * (mix_6201 - m_history_55)));
			t_sample mix_6199 = mix_12818;
			t_sample mix_12819 = (m_history_54 + (((t_sample)0.0042742627044161) * (mix_6199 - m_history_54)));
			t_sample mix_6197 = mix_12819;
			t_sample gen_6602 = mix_6197;
			t_sample history_6202_next_6204 = fixdenorm(mix_6201);
			t_sample history_6200_next_6205 = fixdenorm(mix_6199);
			t_sample history_6198_next_6206 = fixdenorm(mix_6197);
			t_sample rsub_326 = (((int)1) - gen_6602);
			t_sample noise_264 = noise();
			t_sample abs_265 = fabs(noise_264);
			t_sample phasor_442 = __m_phasor_112(((int)1), samples_to_seconds);
			t_sample sub_9736 = (phasor_442 - m_history_53);
			t_sample add_9734 = (phasor_442 + m_history_53);
			t_sample div_9741 = safediv(sub_9736, add_9734);
			t_sample abs_9738 = fabs(div_9741);
			int gt_9740 = (abs_9738 > ((t_sample)0.5));
			int change_9737 = __m_change_113(gt_9740);
			int gt_9735 = (change_9737 > ((int)0));
			int gen_263 = gt_9735;
			t_sample history_233_next_9733 = fixdenorm(phasor_442);
			__m_latch_114 = ((gen_263 != 0) ? neg_245 : __m_latch_114);
			t_sample latch_247 = __m_latch_114;
			__m_latch_115 = ((gen_263 != 0) ? m_shape_77 : __m_latch_115);
			t_sample latch_254 = __m_latch_115;
			t_sample rsub_252 = (((int)1) - latch_254);
			__m_latch_116 = ((gen_263 != 0) ? ((int)0) : __m_latch_116);
			int latch_246 = __m_latch_116;
			__m_latch_117 = ((gen_263 != 0) ? m_skew_72 : __m_latch_117);
			t_sample latch_275 = __m_latch_117;
			__m_latch_118 = ((gen_263 != 0) ? m_symmetry_64 : __m_latch_118);
			t_sample latch_250 = __m_latch_118;
			t_sample floor_463 = floor(m_shift_58);
			t_sample floor_464 = floor(m_events_60);
			t_sample floor_465 = floor(m_hits_59);
			t_sample phasor_482 = __m_phasor_119(div_433, samples_to_seconds);
			t_sample switch_366 = (gt_367 ? wrap_371 : phasor_482);
			t_sample mul_468 = (switch_366 * m_beats_61);
			t_sample wrap_467 = wrap(mul_468, ((int)0), ((int)1));
			t_sample sub_9751 = (wrap_467 - m_history_52);
			t_sample add_9744 = (wrap_467 + m_history_52);
			t_sample div_9746 = safediv(sub_9751, add_9744);
			t_sample abs_9748 = fabs(div_9746);
			int gt_9750 = (abs_9748 > ((t_sample)0.5));
			int change_9747 = __m_change_120(gt_9750);
			int gt_9745 = (change_9747 > ((int)0));
			int gen_470 = gt_9745;
			t_sample history_233_next_9743 = fixdenorm(wrap_467);
			__m_latch_121 = ((gen_470 != 0) ? floor_463 : __m_latch_121);
			t_sample latch_471 = __m_latch_121;
			t_sample sub_480 = (mul_468 - latch_471);
			__m_latch_122 = ((gen_470 != 0) ? floor_464 : __m_latch_122);
			t_sample latch_473 = __m_latch_122;
			t_sample abs_455 = fabs(latch_473);
			__m_latch_123 = ((gen_470 != 0) ? floor_465 : __m_latch_123);
			t_sample latch_472 = __m_latch_123;
			t_sample abs_454 = fabs(latch_472);
			t_sample max_453 = ((abs_455 < abs_454) ? abs_454 : abs_455);
			t_sample min_452 = ((abs_454 < abs_455) ? abs_454 : abs_455);
			t_sample div_456 = safediv(min_452, max_453);
			t_sample mul_451 = (latch_473 * latch_472);
			int sign_458 = ((mul_451 > 0) ? 1 : ((mul_451 < 0) ? -1 : 0));
			t_sample mul_457 = (sub_480 * sign_458);
			t_sample wrap_474 = wrap(mul_457, ((int)0), max_453);
			t_sample floor_481 = floor(wrap_474);
			t_sample mul_476 = (floor_481 * div_456);
			t_sample floor_479 = floor(mul_476);
			t_sample div_478 = safediv(floor_479, div_456);
			t_sample ceil_477 = ceil(div_478);
			t_sample sub_475 = (wrap_474 - ceil_477);
			t_sample add_460 = (floor_479 + ((int)1));
			t_sample div_462 = safediv(add_460, div_456);
			t_sample ceil_461 = ceil(div_462);
			t_sample sub_459 = (ceil_461 - ceil_477);
			t_sample div_469 = safediv(sub_475, sub_459);
			t_sample sub_9754 = (div_469 - m_history_51);
			t_sample add_9761 = (div_469 + m_history_51);
			t_sample div_9753 = safediv(sub_9754, add_9761);
			t_sample abs_9757 = fabs(div_9753);
			int gt_9760 = (abs_9757 > ((t_sample)0.5));
			int change_9756 = __m_change_124(gt_9760);
			int gt_9755 = (change_9756 > ((int)0));
			int gen_443 = gt_9755;
			t_sample history_233_next_9759 = fixdenorm(div_469);
			int trig_399 = gen_443;
			__m_latch_125 = ((trig_399 != 0) ? m_history_17 : __m_latch_125);
			t_sample latch_391 = __m_latch_125;
			int not_204 = (!latch_391);
			t_sample out8 = not_204;
			__m_latch_126 = ((trig_399 != 0) ? m_history_20 : __m_latch_126);
			t_sample latch_389 = __m_latch_126;
			int not_203 = (!latch_389);
			t_sample out9 = not_203;
			__m_latch_127 = ((trig_399 != 0) ? gt_383 : __m_latch_127);
			int latch_400 = __m_latch_127;
			int not_209 = (!latch_400);
			t_sample out3 = not_209;
			__m_latch_128 = ((trig_399 != 0) ? m_history_15 : __m_latch_128);
			t_sample latch_392 = __m_latch_128;
			int not_205 = (!latch_392);
			t_sample out7 = not_205;
			__m_latch_129 = ((trig_399 != 0) ? m_history_14 : __m_latch_129);
			t_sample latch_396 = __m_latch_129;
			int not_207 = (!latch_396);
			t_sample out5 = not_207;
			__m_latch_130 = ((trig_399 != 0) ? m_history_16 : __m_latch_130);
			t_sample latch_394 = __m_latch_130;
			int not_206 = (!latch_394);
			t_sample out6 = not_206;
			__m_latch_131 = ((trig_399 != 0) ? m_history_18 : __m_latch_131);
			t_sample latch_398 = __m_latch_131;
			int not_208 = (!latch_398);
			t_sample out4 = not_208;
			int trig_497 = trig_399;
			__m_latch_132 = ((trig_497 != 0) ? m_history_9 : __m_latch_132);
			t_sample latch_492 = __m_latch_132;
			__m_latch_133 = ((trig_497 != 0) ? m_history_8 : __m_latch_133);
			t_sample latch_489 = __m_latch_133;
			__m_latch_134 = ((trig_497 != 0) ? m_history_12 : __m_latch_134);
			t_sample latch_487 = __m_latch_134;
			__m_latch_135 = ((trig_497 != 0) ? m_history_2 : __m_latch_135);
			t_sample latch_496 = __m_latch_135;
			__m_latch_136 = ((trig_497 != 0) ? m_history_10 : __m_latch_136);
			t_sample latch_494 = __m_latch_136;
			__m_latch_137 = ((trig_497 != 0) ? m_history_13 : __m_latch_137);
			t_sample latch_490 = __m_latch_137;
			__m_latch_138 = ((trig_399 != 0) ? m_history_19 : __m_latch_138);
			t_sample latch_387 = __m_latch_138;
			int not_202 = (!latch_387);
			t_sample out10 = not_202;
			t_sample switch_212 = (lt_211 ? ((int)1) : latch_387);
			int neq_426 = (gen_443 != ((int)0));
			int change_425 = __m_change_139(neq_426);
			int gt_424 = (change_425 > ((int)0));
			t_sample mul_430 = ((m_history_7 + gt_424) * t_432);
			t_sample clamp_423 = ((mul_430 <= ((int)0)) ? ((int)0) : ((mul_430 >= ((int)1)) ? ((int)1) : mul_430));
			t_sample mix_12824 = (clamp_423 + (((t_sample)0.97) * (m_history_6 - clamp_423)));
			t_sample mix_428 = mix_12824;
			__m_latch_140 = ((trig_497 != 0) ? m_history_11 : __m_latch_140);
			t_sample latch_485 = __m_latch_140;
			t_sample pitch_1 = latch_485;
			t_sample mul_444 = (pitch_1 * ((int)12));
			int int_435 = int(mul_444);
			t_sample mul_437 = (int_435 * div_438);
			t_sample round_440 = round(mul_437);
			t_sample div_436 = safediv(round_440, div_438);
			t_sample add_450 = (div_436 + ((int)36));
			t_sample mtof_449 = mtof(add_450, ((int)440));
			t_sample phasor_363 = __m_phasor_141(mtof_449, samples_to_seconds);
			t_sample saw_189 = phasor_363;
			t_sample sub_9764 = (saw_189 - m_history_50);
			t_sample add_9771 = (saw_189 + m_history_50);
			t_sample div_9763 = safediv(sub_9764, add_9771);
			t_sample abs_9768 = fabs(div_9763);
			int gt_9770 = (abs_9768 > ((t_sample)0.5));
			int change_9767 = __m_change_142(gt_9770);
			int gt_9766 = (change_9767 > ((int)0));
			int gen_350 = gt_9766;
			t_sample history_233_next_9765 = fixdenorm(saw_189);
			__m_latch_143 = ((gen_350 != 0) ? ((int)-1) : __m_latch_143);
			int latch_341 = __m_latch_143;
			__m_latch_144 = ((gen_350 != 0) ? rsub_326 : __m_latch_144);
			t_sample latch_348 = __m_latch_144;
			t_sample rsub_346 = (((int)1) - latch_348);
			__m_latch_145 = ((gen_350 != 0) ? ((int)0) : __m_latch_145);
			int latch_340 = __m_latch_145;
			__m_latch_146 = ((gen_350 != 0) ? ((t_sample)0.5) : __m_latch_146);
			t_sample latch_359 = __m_latch_146;
			__m_latch_147 = ((gen_350 != 0) ? gen_6602 : __m_latch_147);
			t_sample latch_344 = __m_latch_147;
			t_sample saw_187 = saw_189;
			t_sample clamp_271 = ((latch_359 <= ((int)0)) ? ((int)0) : ((latch_359 >= ((int)1)) ? ((int)1) : latch_359));
			t_sample triangle_270 = triangle(saw_187, clamp_271);
			t_sample sub_12828 = (triangle_270 - ((int)0));
			t_sample scale_12825 = ((safepow((sub_12828 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_269 = scale_12825;
			t_sample gen_356 = scale_269;
			t_sample rsub_337 = (((int)1) - gen_356);
			int change_338 = __m_change_148(gen_356);
			int gt_358 = (change_338 > ((int)0));
			t_sample switch_355 = (gt_358 ? gen_356 : rsub_337);
			t_sample sub_9775 = (switch_355 - m_history_49);
			t_sample add_9774 = (switch_355 + m_history_49);
			t_sample div_9773 = safediv(sub_9775, add_9774);
			t_sample abs_9779 = fabs(div_9773);
			int gt_9781 = (abs_9779 > ((t_sample)0.5));
			int change_9778 = __m_change_149(gt_9781);
			int gt_9777 = (change_9778 > ((int)0));
			int gen_354 = gt_9777;
			t_sample history_233_next_9776 = fixdenorm(switch_355);
			__m_latch_150 = ((gen_354 != 0) ? m_history_5 : __m_latch_150);
			t_sample latch_361 = __m_latch_150;
			t_sample sub_9788 = (switch_355 - m_history_48);
			t_sample add_9784 = (switch_355 + m_history_48);
			t_sample div_9787 = safediv(sub_9788, add_9784);
			t_sample abs_9789 = fabs(div_9787);
			int gt_9791 = (abs_9789 > ((t_sample)0.5));
			int change_9786 = __m_change_151(gt_9791);
			int gt_9785 = (change_9786 > ((int)0));
			int gen_333 = gt_9785;
			t_sample history_233_next_9783 = fixdenorm(switch_355);
			__m_latch_152 = ((gen_333 != 0) ? m_history_4 : __m_latch_152);
			t_sample latch_335 = __m_latch_152;
			t_sample mix_12829 = (gt_358 + (latch_340 * (abs_352 - gt_358)));
			t_sample mix_343 = mix_12829;
			int orange_12832 = (((int)1) - latch_341);
			t_sample sub_12833 = (mix_343 - ((int)0));
			t_sample scale_12830 = ((safepow((sub_12833 * ((t_sample)1)), ((int)1)) * orange_12832) + latch_341);
			t_sample scale_342 = scale_12830;
			__m_latch_153 = ((gen_354 != 0) ? scale_342 : __m_latch_153);
			t_sample latch_362 = __m_latch_153;
			__m_latch_154 = ((gen_333 != 0) ? scale_342 : __m_latch_154);
			t_sample latch_336 = __m_latch_154;
			int gte_330 = (latch_335 >= latch_336);
			int and_345 = (gte_330 && latch_344);
			t_sample switch_347 = (and_345 ? latch_348 : rsub_346);
			t_sample clamp_255 = ((switch_355 <= ((int)0)) ? ((int)0) : ((switch_355 >= ((int)1)) ? ((int)1) : switch_355));
			t_sample round_261 = round(clamp_255);
			t_sample triangle_256 = triangle(clamp_255, ((t_sample)0.5));
			t_sample clamp_259 = ((switch_347 <= ((int)0)) ? ((int)0) : ((switch_347 >= ((int)1)) ? ((int)1) : switch_347));
			t_sample sub_12837 = (clamp_259 - ((int)1));
			t_sample scale_12834 = ((safepow((sub_12837 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_257 = scale_12834;
			t_sample clamp_223 = ((triangle_256 <= ((int)0)) ? ((int)0) : ((triangle_256 >= ((int)1)) ? ((int)1) : triangle_256));
			t_sample clamp_217 = ((scale_257 <= ((int)0)) ? ((int)0) : ((scale_257 >= ((int)1)) ? ((int)1) : scale_257));
			int lt_226 = (clamp_217 < ((t_sample)0.5));
			int not_222 = (!lt_226);
			t_sample sub_12841 = (clamp_217 - ((int)1));
			t_sample scale_12838 = ((safepow((sub_12841 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_227 = scale_12838;
			t_sample tan_225 = tan(scale_227);
			t_sample rdiv_224 = safediv(((int)1), tan_225);
			t_sample switch_221 = (lt_226 ? rdiv_224 : tan_225);
			t_sample switch_220 = (lt_226 ? tan_225 : rdiv_224);
			int irange_12843 = (lt_226 - not_222);
			t_sample sub_12845 = (clamp_223 - not_222);
			t_sample scale_12842 = ((safepow(safediv(sub_12845, irange_12843), switch_220) * ((int)-1)) + ((int)1));
			t_sample scale_219 = scale_12842;
			int orange_12848 = (not_222 - lt_226);
			t_sample sub_12849 = (scale_219 - ((int)0));
			t_sample scale_12846 = ((safepow((sub_12849 * ((t_sample)1)), switch_221) * orange_12848) + lt_226);
			t_sample scale_218 = scale_12846;
			t_sample gen_258 = scale_218;
			t_sample mix_12850 = (round_261 + (gen_258 * (clamp_255 - round_261)));
			t_sample mix_260 = mix_12850;
			t_sample gen_349 = mix_260;
			t_sample mix_12851 = (latch_361 + (gen_349 * (latch_362 - latch_361)));
			t_sample mix_353 = mix_12851;
			t_sample out11 = mix_353;
			t_sample clamp_9805 = ((switch_355 <= ((int)0)) ? ((int)0) : ((switch_355 >= ((int)1)) ? ((int)1) : switch_355));
			t_sample clamp_9796 = ((switch_347 <= ((int)0)) ? ((int)0) : ((switch_347 >= ((int)1)) ? ((int)1) : switch_347));
			int lt_9798 = (clamp_9796 < ((t_sample)0.5));
			int not_9803 = (!lt_9798);
			t_sample sub_12855 = (clamp_9796 - ((int)1));
			t_sample scale_12852 = ((safepow((sub_12855 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_9795 = scale_12852;
			t_sample tan_9797 = tan(scale_9795);
			t_sample rdiv_9794 = safediv(((int)1), tan_9797);
			t_sample switch_9799 = (lt_9798 ? rdiv_9794 : tan_9797);
			t_sample switch_9801 = (lt_9798 ? tan_9797 : rdiv_9794);
			int irange_12857 = (lt_9798 - not_9803);
			t_sample sub_12859 = (clamp_9805 - not_9803);
			t_sample scale_12856 = ((safepow(safediv(sub_12859, irange_12857), switch_9801) * ((int)-1)) + ((int)1));
			t_sample scale_9800 = scale_12856;
			int orange_12862 = (not_9803 - lt_9798);
			t_sample sub_12863 = (scale_9800 - ((int)0));
			t_sample scale_12860 = ((safepow((sub_12863 * ((t_sample)1)), switch_9799) * orange_12862) + lt_9798);
			t_sample scale_9802 = scale_12860;
			t_sample gen_331 = scale_9802;
			t_sample mix_12864 = (latch_335 + (gen_331 * (latch_336 - latch_335)));
			t_sample mix_332 = mix_12864;
			t_sample out12 = mix_332;
			t_sample saw_188 = saw_189;
			t_sample clamp_9806 = ((latch_275 <= ((int)0)) ? ((int)0) : ((latch_275 >= ((int)1)) ? ((int)1) : latch_275));
			t_sample triangle_9808 = triangle(saw_188, clamp_9806);
			t_sample sub_12868 = (triangle_9808 - ((int)0));
			t_sample scale_12865 = ((safepow((sub_12868 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_9807 = scale_12865;
			t_sample gen_272 = scale_9807;
			t_sample rsub_243 = (((int)1) - gen_272);
			int change_244 = __m_change_155(gen_272);
			int gt_274 = (change_244 > ((int)0));
			t_sample switch_268 = (gt_274 ? gen_272 : rsub_243);
			t_sample sub_9813 = (switch_268 - m_history_47);
			t_sample add_9809 = (switch_268 + m_history_47);
			t_sample div_9812 = safediv(sub_9813, add_9809);
			t_sample abs_9815 = fabs(div_9812);
			int gt_9817 = (abs_9815 > ((t_sample)0.5));
			int change_9811 = __m_change_156(gt_9817);
			int gt_9810 = (change_9811 > ((int)0));
			int gen_267 = gt_9810;
			t_sample history_233_next_9814 = fixdenorm(switch_268);
			__m_latch_157 = ((gen_267 != 0) ? m_history_3 : __m_latch_157);
			t_sample latch_277 = __m_latch_157;
			t_sample sub_9824 = (switch_268 - m_history_46);
			t_sample add_9820 = (switch_268 + m_history_46);
			t_sample div_9823 = safediv(sub_9824, add_9820);
			t_sample abs_9825 = fabs(div_9823);
			int gt_9827 = (abs_9825 > ((t_sample)0.5));
			int change_9822 = __m_change_158(gt_9827);
			int gt_9821 = (change_9822 > ((int)0));
			int gen_239 = gt_9821;
			t_sample history_233_next_9819 = fixdenorm(switch_268);
			__m_latch_159 = ((gen_239 != 0) ? m_history_1 : __m_latch_159);
			t_sample latch_241 = __m_latch_159;
			t_sample mix_12869 = (gt_274 + (latch_246 * (abs_265 - gt_274)));
			t_sample mix_249 = mix_12869;
			t_sample orange_12872 = (((int)1) - latch_247);
			t_sample sub_12873 = (mix_249 - ((int)0));
			t_sample scale_12870 = ((safepow((sub_12873 * ((t_sample)1)), ((int)1)) * orange_12872) + latch_247);
			t_sample scale_248 = scale_12870;
			__m_latch_160 = ((gen_267 != 0) ? scale_248 : __m_latch_160);
			t_sample latch_278 = __m_latch_160;
			__m_latch_161 = ((gen_239 != 0) ? scale_248 : __m_latch_161);
			t_sample latch_242 = __m_latch_161;
			int gte_214 = (latch_241 >= latch_242);
			int and_251 = (gte_214 && latch_250);
			t_sample switch_253 = (and_251 ? latch_254 : rsub_252);
			t_sample clamp_9835 = ((switch_268 <= ((int)0)) ? ((int)0) : ((switch_268 >= ((int)1)) ? ((int)1) : switch_268));
			t_sample round_9836 = round(clamp_9835);
			t_sample triangle_9838 = triangle(clamp_9835, ((t_sample)0.5));
			t_sample clamp_9848 = ((switch_253 <= ((int)0)) ? ((int)0) : ((switch_253 >= ((int)1)) ? ((int)1) : switch_253));
			t_sample sub_12877 = (clamp_9848 - ((int)1));
			t_sample scale_12874 = ((safepow((sub_12877 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_9837 = scale_12874;
			t_sample clamp_9840 = ((triangle_9838 <= ((int)0)) ? ((int)0) : ((triangle_9838 >= ((int)1)) ? ((int)1) : triangle_9838));
			t_sample clamp_9833 = ((scale_9837 <= ((int)0)) ? ((int)0) : ((scale_9837 >= ((int)1)) ? ((int)1) : scale_9837));
			int lt_9839 = (clamp_9833 < ((t_sample)0.5));
			int not_9842 = (!lt_9839);
			t_sample sub_12881 = (clamp_9833 - ((int)1));
			t_sample scale_12878 = ((safepow((sub_12881 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_9831 = scale_12878;
			t_sample tan_9834 = tan(scale_9831);
			t_sample rdiv_9830 = safediv(((int)1), tan_9834);
			t_sample switch_9845 = (lt_9839 ? rdiv_9830 : tan_9834);
			t_sample switch_9844 = (lt_9839 ? tan_9834 : rdiv_9830);
			int irange_12883 = (lt_9839 - not_9842);
			t_sample sub_12885 = (clamp_9840 - not_9842);
			t_sample scale_12882 = ((safepow(safediv(sub_12885, irange_12883), switch_9844) * ((int)-1)) + ((int)1));
			t_sample scale_9843 = scale_12882;
			int orange_12888 = (not_9842 - lt_9839);
			t_sample sub_12889 = (scale_9843 - ((int)0));
			t_sample scale_12886 = ((safepow((sub_12889 * ((t_sample)1)), switch_9845) * orange_12888) + lt_9839);
			t_sample scale_9846 = scale_12886;
			t_sample gen_9832 = scale_9846;
			t_sample mix_12890 = (round_9836 + (gen_9832 * (clamp_9835 - round_9836)));
			t_sample mix_9841 = mix_12890;
			t_sample gen_262 = mix_9841;
			t_sample mix_12891 = (latch_277 + (gen_262 * (latch_278 - latch_277)));
			t_sample mix_266 = mix_12891;
			__m_latch_162 = ((trig_497 != 0) ? mix_266 : __m_latch_162);
			t_sample latch_498 = __m_latch_162;
			t_sample clamp_9855 = ((switch_268 <= ((int)0)) ? ((int)0) : ((switch_268 >= ((int)1)) ? ((int)1) : switch_268));
			t_sample clamp_9852 = ((switch_253 <= ((int)0)) ? ((int)0) : ((switch_253 >= ((int)1)) ? ((int)1) : switch_253));
			int lt_9854 = (clamp_9852 < ((t_sample)0.5));
			int not_9856 = (!lt_9854);
			t_sample sub_12895 = (clamp_9852 - ((int)1));
			t_sample scale_12892 = ((safepow((sub_12895 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_9851 = scale_12892;
			t_sample tan_9853 = tan(scale_9851);
			t_sample rdiv_9850 = safediv(((int)1), tan_9853);
			t_sample switch_9859 = (lt_9854 ? rdiv_9850 : tan_9853);
			t_sample switch_9858 = (lt_9854 ? tan_9853 : rdiv_9850);
			int irange_12897 = (lt_9854 - not_9856);
			t_sample sub_12899 = (clamp_9855 - not_9856);
			t_sample scale_12896 = ((safepow(safediv(sub_12899, irange_12897), switch_9858) * ((int)-1)) + ((int)1));
			t_sample scale_9857 = scale_12896;
			int orange_12902 = (not_9856 - lt_9854);
			t_sample sub_12903 = (scale_9857 - ((int)0));
			t_sample scale_12900 = ((safepow((sub_12903 * ((t_sample)1)), switch_9859) * orange_12902) + lt_9854);
			t_sample scale_9860 = scale_12900;
			t_sample gen_228 = scale_9860;
			t_sample mix_12904 = (latch_241 + (gen_228 * (latch_242 - latch_241)));
			t_sample mix_229 = mix_12904;
			t_sample pitch_2 = pitch_1;
			t_sample mul_198 = (pitch_2 * ((int)12));
			int int_194 = int(mul_198);
			t_sample mul_196 = (int_194 * div_438);
			t_sample round_197 = round(mul_196);
			t_sample div_195 = safediv(round_197, div_438);
			t_sample add_200 = (div_195 + ((int)60));
			t_sample mtof_199 = mtof(add_200, ((int)440));
			__m_cycle_163.freq(mtof_199);
			t_sample cycle_192 = __m_cycle_163(__sinedata);
			t_sample cycleindex_193 = __m_cycle_163.phase();
			t_sample mix_12905 = (((int)1) + (m_cvin_78 * (cycle_192 - ((int)1))));
			t_sample mix_191 = mix_12905;
			t_sample floor_409 = floor(mix_353);
			t_sample sub_401 = (mix_353 - floor_409);
			t_sample add_408 = (floor_409 + ((int)1));
			t_sample mul_404 = (mtof_449 * ((t_sample)6.2831853071796));
			t_sample mul_406 = (floor_409 * mul_404);
			t_sample sin_403 = sin((mix_191 + mul_406));
			t_sample mul_405 = (add_408 * mul_404);
			t_sample sin_402 = sin((mix_191 + mul_405));
			t_sample mix_12906 = (sin_403 + (sub_401 * (sin_402 - sin_403)));
			t_sample mix_407 = mix_12906;
			t_sample gen_410 = mix_407;
			t_sample mul_448 = (gen_410 * mix_428);
			t_sample mul_213 = (mul_448 * switch_212);
			t_sample mul_446 = (mul_213 * ((int)2));
			t_sample tanh_447 = tanh(mul_446);
			t_sample div_445 = (tanh_447 * ((t_sample)0.5));
			t_sample mul_310 = (m_history_45 * gen_303);
			t_sample mul_311 = (m_history_43 * ((int)0));
			t_sample mul_312 = (div_445 * gen_301);
			t_sample mul_313 = (m_history_44 * gen_305);
			t_sample mul_314 = (m_history_42 * gen_304);
			t_sample sub_307 = (((mul_312 + mul_311) + mul_310) - (mul_314 + mul_313));
			t_sample gen_321 = sub_307;
			t_sample history_308_next_317 = fixdenorm(m_history_43);
			t_sample history_315_next_318 = fixdenorm(m_history_42);
			t_sample history_309_next_319 = fixdenorm(div_445);
			t_sample history_316_next_320 = fixdenorm(sub_307);
			t_sample clamp_306 = ((gen_321 <= min_164) ? min_164 : ((gen_321 >= ((int)1)) ? ((int)1) : gen_321));
			t_sample mul_83 = (clamp_306 * ((t_sample)0.015));
			t_sample tap_16 = m_delay_41.read_step(((int)1557));
			t_sample gen_54 = tap_16;
			t_sample mul_14 = (tap_16 * ((t_sample)0.7));
			t_sample mul_12 = (m_history_40 * ((t_sample)0.3));
			t_sample add_13 = (mul_14 + mul_12);
			t_sample mul_10 = (add_13 * ((t_sample)0.2));
			t_sample add_17 = (mul_83 + mul_10);
			t_sample history_11_next_18 = fixdenorm(add_13);
			t_sample tap_659 = m_delay_39.read_step(((int)1617));
			t_sample gen_82 = tap_659;
			t_sample mul_667 = (tap_659 * ((t_sample)0.7));
			t_sample mul_662 = (m_history_38 * ((t_sample)0.3));
			t_sample add_666 = (mul_667 + mul_662);
			t_sample mul_664 = (add_666 * ((t_sample)0.2));
			t_sample add_660 = (mul_83 + mul_664);
			t_sample history_11_next_665 = fixdenorm(add_666);
			t_sample tap_671 = m_delay_37.read_step(((int)1491));
			t_sample gen_53 = tap_671;
			t_sample mul_678 = (tap_671 * ((t_sample)0.7));
			t_sample mul_674 = (m_history_36 * ((t_sample)0.3));
			t_sample add_679 = (mul_678 + mul_674);
			t_sample mul_676 = (add_679 * ((t_sample)0.2));
			t_sample add_672 = (mul_83 + mul_676);
			t_sample history_11_next_677 = fixdenorm(add_679);
			t_sample tap_683 = m_delay_35.read_step(((int)1422));
			t_sample gen_52 = tap_683;
			t_sample mul_690 = (tap_683 * ((t_sample)0.7));
			t_sample mul_691 = (m_history_34 * ((t_sample)0.3));
			t_sample add_689 = (mul_690 + mul_691);
			t_sample mul_688 = (add_689 * ((t_sample)0.2));
			t_sample add_684 = (mul_83 + mul_688);
			t_sample history_11_next_692 = fixdenorm(add_689);
			t_sample tap_695 = m_delay_33.read_step(((int)1356));
			t_sample gen_51 = tap_695;
			t_sample mul_702 = (tap_695 * ((t_sample)0.7));
			t_sample mul_703 = (m_history_32 * ((t_sample)0.3));
			t_sample add_701 = (mul_702 + mul_703);
			t_sample mul_700 = (add_701 * ((t_sample)0.2));
			t_sample add_696 = (mul_83 + mul_700);
			t_sample history_11_next_704 = fixdenorm(add_701);
			t_sample tap_707 = m_delay_31.read_step(((int)1277));
			t_sample gen_50 = tap_707;
			t_sample mul_714 = (tap_707 * ((t_sample)0.7));
			t_sample mul_715 = (m_history_30 * ((t_sample)0.3));
			t_sample add_713 = (mul_714 + mul_715);
			t_sample mul_712 = (add_713 * ((t_sample)0.2));
			t_sample add_708 = (mul_83 + mul_712);
			t_sample history_11_next_716 = fixdenorm(add_713);
			t_sample tap_719 = m_delay_29.read_step(((int)1188));
			t_sample gen_49 = tap_719;
			t_sample mul_726 = (tap_719 * ((t_sample)0.7));
			t_sample mul_727 = (m_history_28 * ((t_sample)0.3));
			t_sample add_725 = (mul_726 + mul_727);
			t_sample mul_724 = (add_725 * ((t_sample)0.2));
			t_sample add_720 = (mul_83 + mul_724);
			t_sample history_11_next_728 = fixdenorm(add_725);
			t_sample tap_731 = m_delay_27.read_step(((int)1116));
			t_sample gen_48 = tap_731;
			t_sample mul_737 = (tap_731 * ((t_sample)0.7));
			t_sample mul_738 = (m_history_26 * ((t_sample)0.3));
			t_sample add_736 = (mul_737 + mul_738);
			t_sample mul_735 = (add_736 * ((t_sample)0.2));
			t_sample add_732 = (mul_83 + mul_735);
			t_sample history_11_next_739 = fixdenorm(add_736);
			t_sample add_71 = ((((((((gen_48 + gen_49) + gen_50) + gen_51) + gen_52) + gen_53) + gen_82) + gen_54) + ((int)0));
			t_sample tap_7 = m_delay_25.read_step(((int)556));
			t_sample sub_3 = (add_71 - tap_7);
			t_sample mul_5 = (tap_7 * ((t_sample)0.45));
			t_sample add_4 = (add_71 + mul_5);
			t_sample tap_744 = m_delay_24.read_step(((int)441));
			t_sample sub_747 = (sub_3 - tap_744);
			t_sample mul_746 = (tap_744 * ((t_sample)0.45));
			t_sample add_743 = (sub_3 + mul_746);
			t_sample tap_750 = m_delay_23.read_step(((int)341));
			t_sample sub_753 = (sub_747 - tap_750);
			t_sample mul_752 = (tap_750 * ((t_sample)0.45));
			t_sample add_749 = (sub_747 + mul_752);
			t_sample tap_756 = m_delay_22.read_step(((int)225));
			t_sample sub_759 = (sub_753 - tap_756);
			t_sample mul_758 = (tap_756 * ((t_sample)0.45));
			t_sample add_755 = (sub_753 + mul_758);
			t_sample mix_12907 = (((t_sample)0.7) + (clamp_306 * (sub_759 - ((t_sample)0.7))));
			t_sample add_364 = (mix_12907 + in2);
			t_sample out2 = add_364;
			t_sample add_365 = (mix_12907 + in1);
			t_sample out1 = add_365;
			t_sample history_368_next_9862 = fixdenorm(wrap_371);
			t_sample history_388_next_9863 = fixdenorm(latch_391);
			t_sample history_386_next_9864 = fixdenorm(latch_389);
			t_sample history_397_next_9865 = fixdenorm(latch_400);
			t_sample history_390_next_9866 = fixdenorm(latch_392);
			t_sample history_393_next_9867 = fixdenorm(latch_396);
			t_sample history_385_next_9868 = fixdenorm(latch_394);
			t_sample history_395_next_9869 = fixdenorm(latch_398);
			t_sample history_483_next_9870 = fixdenorm(latch_492);
			t_sample history_486_next_9871 = fixdenorm(latch_489);
			t_sample history_484_next_9872 = fixdenorm(latch_487);
			t_sample history_493_next_9873 = fixdenorm(latch_496);
			t_sample history_491_next_9874 = fixdenorm(latch_494);
			t_sample history_488_next_9875 = fixdenorm(latch_490);
			t_sample history_429_next_9876 = fixdenorm(clamp_423);
			t_sample history_427_next_9877 = fixdenorm(mix_428);
			t_sample history_360_next_9878 = fixdenorm(mix_353);
			t_sample history_334_next_9879 = fixdenorm(mix_332);
			t_sample history_276_next_9880 = fixdenorm(mix_266);
			t_sample history_495_next_9881 = fixdenorm(latch_498);
			t_sample history_240_next_9882 = fixdenorm(mix_229);
			m_history_62 = history_233_next_238;
			m_history_57 = history_378_next_381;
			m_history_56 = history_6202_next_6204;
			m_history_54 = history_6198_next_6206;
			m_history_55 = history_6200_next_6205;
			m_history_53 = history_233_next_9733;
			m_history_52 = history_233_next_9743;
			m_history_51 = history_233_next_9759;
			m_history_50 = history_233_next_9765;
			m_history_49 = history_233_next_9776;
			m_history_48 = history_233_next_9783;
			m_history_47 = history_233_next_9814;
			m_history_46 = history_233_next_9819;
			m_history_45 = history_308_next_317;
			m_history_42 = history_316_next_320;
			m_history_43 = history_309_next_319;
			m_history_44 = history_315_next_318;
			m_delay_41.write(add_17);
			m_delay_22.write(add_755);
			m_delay_23.write(add_749);
			m_delay_24.write(add_743);
			m_delay_25.write(add_4);
			m_history_26 = history_11_next_739;
			m_delay_27.write(add_732);
			m_history_28 = history_11_next_728;
			m_delay_29.write(add_720);
			m_history_30 = history_11_next_716;
			m_delay_31.write(add_708);
			m_history_32 = history_11_next_704;
			m_delay_33.write(add_696);
			m_history_34 = history_11_next_692;
			m_delay_35.write(add_684);
			m_history_36 = history_11_next_677;
			m_delay_37.write(add_672);
			m_history_38 = history_11_next_665;
			m_delay_39.write(add_660);
			m_history_40 = history_11_next_18;
			m_history_21 = history_368_next_9862;
			m_history_20 = history_388_next_9863;
			m_history_19 = history_386_next_9864;
			m_history_18 = history_397_next_9865;
			m_history_17 = history_390_next_9866;
			m_history_16 = history_393_next_9867;
			m_history_15 = history_385_next_9868;
			m_history_14 = history_395_next_9869;
			m_history_13 = history_483_next_9870;
			m_history_12 = history_486_next_9871;
			m_history_11 = history_484_next_9872;
			m_history_10 = history_493_next_9873;
			m_history_9 = history_491_next_9874;
			m_history_8 = history_488_next_9875;
			m_history_7 = history_429_next_9876;
			m_history_6 = history_427_next_9877;
			m_history_5 = history_360_next_9878;
			m_history_4 = history_334_next_9879;
			m_history_3 = history_276_next_9880;
			m_history_2 = history_495_next_9881;
			m_history_1 = history_240_next_9882;
			m_delay_22.step();
			m_delay_23.step();
			m_delay_24.step();
			m_delay_25.step();
			m_delay_27.step();
			m_delay_29.step();
			m_delay_31.step();
			m_delay_33.step();
			m_delay_35.step();
			m_delay_37.step();
			m_delay_39.step();
			m_delay_41.step();
			(elapsed++);
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
	inline void set_sw2(t_param _value) {
		m_sw_63 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_symmetry(t_param _value) {
		m_symmetry_64 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_filter(t_param _value) {
		m_knob6_filter_65 = (_value < 100 ? 100 : (_value > 1400 ? 1400 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_66 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_67 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_envelopeLength(t_param _value) {
		m_knob2_envelopeLength_68 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_random(t_param _value) {
		m_random_69 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_70 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_71 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_skew(t_param _value) {
		m_skew_72 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_shiftVar(t_param _value) {
		m_knob4_shiftVar_73 = (_value < 0 ? 0 : (_value > 0.5 ? 0.5 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_74 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_numer(t_param _value) {
		m_numer_75 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_denom(t_param _value) {
		m_denom_76 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_shape(t_param _value) {
		m_shape_77 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin2(t_param _value) {
		m_cvin_78 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_euclidP(t_param _value) {
		m_knob3_euclidP_79 = (_value < 0 ? 0 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_80 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_81 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bipolar(t_param _value) {
		m_bipolar_82 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_bpm(t_param _value) {
		m_knob1_bpm_83 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_84 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_timbre(t_param _value) {
		m_knob5_timbre_85 = (_value < 0.01 ? 0.01 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_euclidean_patterns(void * _value) {
		m_euclidean_patterns_86.setbuffer(_value);
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
int num_params() { return 24; }

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
		case 1: self->set_cvin2(value); break;
		case 2: self->set_denom(value); break;
		case 3: self->set_euclidean_patterns(ref); break;
		case 4: self->set_gatein1(value); break;
		case 5: self->set_knob1_bpm(value); break;
		case 6: self->set_knob2_envelopeLength(value); break;
		case 7: self->set_knob3_euclidP(value); break;
		case 8: self->set_knob4_shiftVar(value); break;
		case 9: self->set_knob5_timbre(value); break;
		case 10: self->set_knob6_filter(value); break;
		case 11: self->set_numer(value); break;
		case 12: self->set_random(value); break;
		case 13: self->set_shape(value); break;
		case 14: self->set_skew(value); break;
		case 15: self->set_sw1(value); break;
		case 16: self->set_sw2(value); break;
		case 17: self->set_sw3(value); break;
		case 18: self->set_sw4(value); break;
		case 19: self->set_sw5(value); break;
		case 20: self->set_sw6(value); break;
		case 21: self->set_sw7(value); break;
		case 22: self->set_sw8(value); break;
		case 23: self->set_symmetry(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_bipolar_82; break;
		case 1: *value = self->m_cvin_78; break;
		case 2: *value = self->m_denom_76; break;
		
		case 4: *value = self->m_gatein_67; break;
		case 5: *value = self->m_knob1_bpm_83; break;
		case 6: *value = self->m_knob2_envelopeLength_68; break;
		case 7: *value = self->m_knob3_euclidP_79; break;
		case 8: *value = self->m_knob4_shiftVar_73; break;
		case 9: *value = self->m_knob5_timbre_85; break;
		case 10: *value = self->m_knob6_filter_65; break;
		case 11: *value = self->m_numer_75; break;
		case 12: *value = self->m_random_69; break;
		case 13: *value = self->m_shape_77; break;
		case 14: *value = self->m_skew_72; break;
		case 15: *value = self->m_sw_74; break;
		case 16: *value = self->m_sw_63; break;
		case 17: *value = self->m_sw_84; break;
		case 18: *value = self->m_sw_66; break;
		case 19: *value = self->m_sw_71; break;
		case 20: *value = self->m_sw_70; break;
		case 21: *value = self->m_sw_80; break;
		case 22: *value = self->m_sw_81; break;
		case 23: *value = self->m_symmetry_64; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(24 * sizeof(ParamInfo));
	self->__commonstate.numparams = 24;
	// initialize parameter 0 ("m_bipolar_82")
	pi = self->__commonstate.params + 0;
	pi->name = "bipolar";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bipolar_82;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cvin_78")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_78;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_denom_76")
	pi = self->__commonstate.params + 2;
	pi->name = "denom";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_denom_76;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 24;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_euclidean_patterns_86")
	pi = self->__commonstate.params + 3;
	pi->name = "euclidean_patterns";
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
	// initialize parameter 4 ("m_gatein_67")
	pi = self->__commonstate.params + 4;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_67;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob1_bpm_83")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1_bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_bpm_83;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob2_envelopeLength_68")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2_envelopeLength";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_envelopeLength_68;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob3_euclidP_79")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_euclidP";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_euclidP_79;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_shiftVar_73")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_shiftVar";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_shiftVar_73;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_timbre_85")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_timbre";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_timbre_85;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_filter_65")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_filter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_filter_65;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 100;
	pi->outputmax = 1400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_numer_75")
	pi = self->__commonstate.params + 11;
	pi->name = "numer";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_numer_75;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 24;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_random_69")
	pi = self->__commonstate.params + 12;
	pi->name = "random";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_random_69;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_shape_77")
	pi = self->__commonstate.params + 13;
	pi->name = "shape";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_shape_77;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_skew_72")
	pi = self->__commonstate.params + 14;
	pi->name = "skew";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_skew_72;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_74")
	pi = self->__commonstate.params + 15;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_74;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_sw_63")
	pi = self->__commonstate.params + 16;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_63;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_84")
	pi = self->__commonstate.params + 17;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_84;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_66")
	pi = self->__commonstate.params + 18;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_66;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_71")
	pi = self->__commonstate.params + 19;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_71;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_70")
	pi = self->__commonstate.params + 20;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_70;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_sw_80")
	pi = self->__commonstate.params + 21;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_80;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_sw_81")
	pi = self->__commonstate.params + 22;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_81;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_symmetry_64")
	pi = self->__commonstate.params + 23;
	pi->name = "symmetry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_symmetry_64;
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


} // POCKET_CALCULATOR::
