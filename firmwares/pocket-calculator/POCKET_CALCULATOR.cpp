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
	Change __m_change_88;
	Change __m_change_125;
	Change __m_change_143;
	Change __m_change_121;
	Change __m_change_111;
	Change __m_change_118;
	Change __m_change_144;
	Change __m_change_140;
	Change __m_change_157;
	Change __m_change_159;
	Change __m_change_146;
	Change __m_change_156;
	Change __m_change_151;
	Data m_euclidean_patterns_86;
	Delay m_delay_24;
	Delay m_delay_21;
	Delay m_delay_38;
	Delay m_delay_40;
	Delay m_delay_32;
	Delay m_delay_28;
	Delay m_delay_30;
	Delay m_delay_34;
	Delay m_delay_26;
	Delay m_delay_22;
	Delay m_delay_36;
	Delay m_delay_23;
	Phasor __m_phasor_110;
	Phasor __m_phasor_87;
	Phasor __m_phasor_142;
	Phasor __m_phasor_119;
	PlusEquals __m_pluseq_117;
	SineCycle __m_cycle_164;
	SineData __sinedata;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample __m_latch_126;
	t_sample m_history_33;
	t_sample __m_latch_127;
	t_sample m_history_8;
	t_sample __m_latch_123;
	t_sample __m_latch_124;
	t_sample __m_latch_122;
	t_sample __m_latch_128;
	t_sample __m_latch_130;
	t_sample __m_latch_133;
	t_sample __m_latch_129;
	t_sample __m_latch_132;
	t_sample __m_latch_131;
	t_sample __m_latch_134;
	t_sample m_history_9;
	t_sample m_history_10;
	t_sample m_history_13;
	t_sample __m_latch_112;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample __m_latch_120;
	t_sample __m_latch_113;
	t_sample __m_latch_115;
	t_sample m_history_11;
	t_sample __m_latch_114;
	t_sample m_history_12;
	t_sample __m_latch_116;
	t_sample __m_latch_135;
	t_sample __m_latch_136;
	t_sample __m_latch_137;
	t_sample __m_latch_155;
	t_sample m_history_1;
	t_sample __m_latch_154;
	t_sample __m_latch_152;
	t_sample __m_latch_153;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample __m_latch_160;
	t_sample __m_latch_163;
	t_sample __m_latch_158;
	t_sample __m_latch_162;
	t_sample __m_latch_161;
	t_sample elapsed;
	t_sample __m_latch_150;
	t_sample __m_latch_148;
	t_sample m_history_7;
	t_sample __m_latch_141;
	t_sample __m_latch_139;
	t_sample __m_latch_138;
	t_sample __m_latch_149;
	t_sample m_history_6;
	t_sample m_history_4;
	t_sample __m_latch_147;
	t_sample m_history_5;
	t_sample m_history_3;
	t_sample __m_latch_145;
	t_sample m_history_31;
	t_sample __m_latch_89;
	t_sample m_history_17;
	t_sample m_history_51;
	t_sample m_history_52;
	t_sample m_history_50;
	t_sample m_history_48;
	t_sample m_history_49;
	t_sample m_history_47;
	t_sample m_history_53;
	t_sample m_history_55;
	t_sample m_shift_58;
	t_sample m_history_54;
	t_sample m_history_57;
	t_sample m_history_56;
	t_sample m_hits_59;
	t_sample m_history_46;
	t_sample m_history_44;
	t_sample m_history_27;
	t_sample m_history_37;
	t_sample m_history_35;
	t_sample m_history_29;
	t_sample m_history_45;
	t_sample m_history_25;
	t_sample m_history_20;
	t_sample m_history_43;
	t_sample m_history_39;
	t_sample m_history_42;
	t_sample m_history_41;
	t_sample m_history_16;
	t_sample m_events_60;
	t_sample m_history_62;
	t_sample m_sw_80;
	t_sample m_sw_81;
	t_sample m_knob4_shiftVar_79;
	t_sample m_skew_77;
	t_sample m_sw_78;
	t_sample m_symmetry_76;
	t_sample m_sw_82;
	t_sample m_shape_84;
	t_sample samples_to_seconds;
	t_sample m_knob6_filter_83;
	t_sample m_history_18;
	t_sample m_bipolar_85;
	t_sample m_beats_61;
	t_sample m_knob2_envelopeLength_75;
	t_sample m_history_19;
	t_sample m_knob1_bpm_65;
	t_sample m_numer_66;
	t_sample m_knob3_euclidP_64;
	t_sample m_sw_63;
	t_sample m_denom_74;
	t_sample m_sw_67;
	t_sample m_cvin_69;
	t_sample m_random_72;
	t_sample m_sw_68;
	t_sample m_gatein_71;
	t_sample m_knob5_timbre_70;
	t_sample m_sw_73;
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
		m_delay_21.reset("m_delay_21", ((int)2000));
		m_delay_22.reset("m_delay_22", ((int)2000));
		m_delay_23.reset("m_delay_23", ((int)2000));
		m_delay_24.reset("m_delay_24", ((int)2000));
		m_history_25 = ((int)0);
		m_delay_26.reset("m_delay_26", ((int)2000));
		m_history_27 = ((int)0);
		m_delay_28.reset("m_delay_28", ((int)2000));
		m_history_29 = ((int)0);
		m_delay_30.reset("m_delay_30", ((int)2000));
		m_history_31 = ((int)0);
		m_delay_32.reset("m_delay_32", ((int)2000));
		m_history_33 = ((int)0);
		m_delay_34.reset("m_delay_34", ((int)2000));
		m_history_35 = ((int)0);
		m_delay_36.reset("m_delay_36", ((int)2000));
		m_history_37 = ((int)0);
		m_delay_38.reset("m_delay_38", ((int)2000));
		m_history_39 = ((int)0);
		m_delay_40.reset("m_delay_40", ((int)2000));
		m_history_41 = ((int)0);
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
		m_knob3_euclidP_64 = ((int)0);
		m_knob1_bpm_65 = ((int)0);
		m_numer_66 = ((int)5);
		m_sw_67 = ((int)0);
		m_sw_68 = ((int)0);
		m_cvin_69 = ((int)0);
		m_knob5_timbre_70 = ((int)0);
		m_gatein_71 = ((int)0);
		m_random_72 = ((int)0);
		m_sw_73 = ((int)0);
		m_denom_74 = ((int)12);
		m_knob2_envelopeLength_75 = ((int)0);
		m_symmetry_76 = ((int)0);
		m_skew_77 = ((t_sample)0.5);
		m_sw_78 = ((int)0);
		m_knob4_shiftVar_79 = ((t_sample)0.5);
		m_sw_80 = ((int)0);
		m_sw_81 = ((int)0);
		m_sw_82 = ((int)0);
		m_knob6_filter_83 = ((int)220);
		m_shape_84 = ((t_sample)0.5);
		m_bipolar_85 = ((int)0);
		m_euclidean_patterns_86.reset("euclidean_patterns", ((int)64), ((int)4));
		samples_to_seconds = (1 / samplerate);
		__m_phasor_87.reset(0);
		__m_change_88.reset(0);
		__m_latch_89 = 0;
		elapsed = 0;
		__m_phasor_110.reset(0);
		__m_change_111.reset(0);
		__m_latch_112 = 0;
		__m_latch_113 = 0;
		__m_latch_114 = 0;
		__m_latch_115 = 0;
		__m_latch_116 = 0;
		__m_pluseq_117.reset(0);
		__m_change_118.reset(0);
		__m_phasor_119.reset(0);
		__m_latch_120 = 11025;
		__m_change_121.reset(0);
		__m_latch_122 = 0;
		__m_latch_123 = 0;
		__m_latch_124 = 0;
		__m_change_125.reset(0);
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
		__m_latch_139 = 0;
		__m_change_140.reset(0);
		__m_latch_141 = 0;
		__m_phasor_142.reset(0);
		__m_change_143.reset(0);
		__m_change_144.reset(0);
		__m_latch_145 = 0;
		__m_change_146.reset(0);
		__m_latch_147 = 0;
		__m_latch_148 = 0;
		__m_latch_149 = 0;
		__m_latch_150 = 0;
		__m_change_151.reset(0);
		__m_latch_152 = 0;
		__m_latch_153 = 0;
		__m_latch_154 = 0;
		__m_latch_155 = 0;
		__m_change_156.reset(0);
		__m_change_157.reset(0);
		__m_latch_158 = 0;
		__m_change_159.reset(0);
		__m_latch_160 = 0;
		__m_latch_161 = 0;
		__m_latch_162 = 0;
		__m_latch_163 = 0;
		__m_cycle_164.reset(samplerate, 0);
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
		t_sample neg_279 = (-m_bipolar_85);
		t_sample mul_464 = (samplerate * m_knob2_envelopeLength_75);
		t_sample t_465 = exp(safediv(-6.9077552789821, mul_464));
		int min_108 = ((-samplerate) * ((t_sample)0.5));
		int max_109 = (samplerate * ((t_sample)0.5));
		t_sample clamp_333 = ((m_knob6_filter_83 <= min_108) ? min_108 : ((m_knob6_filter_83 >= max_109) ? max_109 : m_knob6_filter_83));
		t_sample abs_332 = fabs(clamp_333);
		t_sample mul_331 = (abs_332 * safediv(6.2831853071796, samplerate));
		t_sample sin_328 = sin(mul_331);
		t_sample mul_327 = (sin_328 * ((t_sample)0.5));
		t_sample div_326 = (mul_327 * ((t_sample)0.5));
		t_sample neg_317 = (-div_326);
		t_sample rsub_318 = (((int)1) - div_326);
		t_sample add_325 = (div_326 + ((int)1));
		t_sample rdiv_324 = safediv(((int)1), add_325);
		t_sample mul_323 = (div_326 * rdiv_324);
		t_sample gen_335 = mul_323;
		t_sample mul_322 = (neg_317 * rdiv_324);
		t_sample gen_337 = mul_322;
		t_sample mul_320 = (rsub_318 * rdiv_324);
		t_sample gen_339 = mul_320;
		t_sample cos_330 = cos(mul_331);
		t_sample neg_329 = (-cos_330);
		t_sample mul_319 = (neg_329 * ((int)2));
		t_sample mul_321 = (mul_319 * rdiv_324);
		t_sample gen_338 = mul_321;
		int lt_245 = (m_knob4_shiftVar_79 < ((t_sample)0.1));
		t_sample sub_23827 = (m_knob1_bpm_65 - ((int)0));
		t_sample scale_23824 = ((safepow((sub_23827 * ((t_sample)1)), ((int)1)) * ((int)-260)) + ((int)320));
		t_sample scale_467 = scale_23824;
		int gt_20771 = (m_gatein_71 > ((int)0));
		t_sample div_1684 = (scale_467 * ((t_sample)0.016666666666667));
		t_sample mul_1686 = (div_1684 * ((int)1));
		t_sample div_1681 = (mul_1686 * ((t_sample)0.25));
		int mul_20783 = (((int)1) * samplerate);
		int int_474 = int(m_numer_66);
		int int_472 = int(m_denom_74);
		t_sample div_471 = safediv(int_474, int_472);
		int min_165 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample phasor_445 = __m_phasor_87(((int)10), samples_to_seconds);
			t_sample sub_270 = (phasor_445 - m_history_62);
			t_sample add_271 = (phasor_445 + m_history_62);
			t_sample div_269 = safediv(sub_270, add_271);
			t_sample abs_268 = fabs(div_269);
			int gt_266 = (abs_268 > ((t_sample)0.5));
			int change_265 = __m_change_88(gt_266);
			int gt_264 = (change_265 > ((int)0));
			int gen_444 = gt_264;
			t_sample history_267_next_272 = fixdenorm(phasor_445);
			__m_latch_89 = ((gen_444 != 0) ? m_knob3_euclidP_64 : __m_latch_89);
			t_sample latch_446 = __m_latch_89;
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
					t_sample sub_23812 = (n2 - (-1));
					t_sample scale_23809 = ((safepow((sub_23812 * ((t_sample)0.5)), ((int)1)) * ((int)0)) + ((int)16));
					t_sample b = round(scale_23809);
					t_sample sub_23816 = (n3 - (-1));
					t_sample scale_23813 = ((safepow((sub_23816 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)1));
					t_sample c = round(scale_23813);
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
			t_sample sub_23820 = (latch_446 - ((int)0));
			t_sample scale_23817 = ((safepow((sub_23820 * ((t_sample)1)), ((int)1)) * ((int)63)) + ((int)1));
			t_sample selection = round(scale_23817);
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
			t_sample noise_417 = noise();
			int gt_416 = (noise_417 > m_knob4_shiftVar_79);
			t_sample noise_384 = noise();
			t_sample abs_385 = fabs(noise_384);
			t_sample mix_23821 = (m_history_57 + (((t_sample)0.0042742627044161) * (m_knob5_timbre_70 - m_history_57)));
			t_sample mix_6 = mix_23821;
			t_sample mix_23822 = (m_history_56 + (((t_sample)0.0042742627044161) * (mix_6 - m_history_56)));
			t_sample mix_4 = mix_23822;
			t_sample mix_23823 = (m_history_55 + (((t_sample)0.0042742627044161) * (mix_4 - m_history_55)));
			t_sample mix_2 = mix_23823;
			t_sample gen_12 = mix_2;
			t_sample history_7_next_9 = fixdenorm(mix_6);
			t_sample history_5_next_10 = fixdenorm(mix_4);
			t_sample history_3_next_11 = fixdenorm(mix_2);
			t_sample rsub_360 = (((int)1) - gen_12);
			t_sample noise_298 = noise();
			t_sample abs_299 = fabs(noise_298);
			t_sample phasor_475 = __m_phasor_110(((int)1), samples_to_seconds);
			t_sample sub_23545 = (phasor_475 - m_history_54);
			t_sample add_23547 = (phasor_475 + m_history_54);
			t_sample div_23549 = safediv(sub_23545, add_23547);
			t_sample abs_23550 = fabs(div_23549);
			int gt_23544 = (abs_23550 > ((t_sample)0.5));
			int change_23548 = __m_change_111(gt_23544);
			int gt_23542 = (change_23548 > ((int)0));
			int gen_297 = gt_23542;
			t_sample history_267_next_23546 = fixdenorm(phasor_475);
			__m_latch_112 = ((gen_297 != 0) ? neg_279 : __m_latch_112);
			t_sample latch_281 = __m_latch_112;
			__m_latch_113 = ((gen_297 != 0) ? m_shape_84 : __m_latch_113);
			t_sample latch_288 = __m_latch_113;
			t_sample rsub_286 = (((int)1) - latch_288);
			__m_latch_114 = ((gen_297 != 0) ? ((int)0) : __m_latch_114);
			int latch_280 = __m_latch_114;
			__m_latch_115 = ((gen_297 != 0) ? m_skew_77 : __m_latch_115);
			t_sample latch_309 = __m_latch_115;
			__m_latch_116 = ((gen_297 != 0) ? m_symmetry_76 : __m_latch_116);
			t_sample latch_284 = __m_latch_116;
			t_sample floor_496 = floor(m_shift_58);
			t_sample floor_497 = floor(m_events_60);
			t_sample floor_498 = floor(m_hits_59);
			t_sample plusequals_20782 = __m_pluseq_117.post(((int)1), m_gatein_71, 0);
			int change_20770 = __m_change_118(gt_20771);
			int gt_20769 = (change_20770 > ((int)0));
			int gen_20772 = gt_20769;
			t_sample phasor_1682 = __m_phasor_119(div_1681, samples_to_seconds);
			t_sample mul_1680 = (phasor_1682 * ((int)4));
			t_sample wrap_1679 = wrap(mul_1680, ((int)0), ((int)1));
			t_sample gen_20762 = wrap_1679;
			int gt_20779 = (plusequals_20782 > mul_20783);
			t_sample add_20776 = (m_history_53 + ((int)1));
			t_sample switch_20773 = (gen_20772 ? ((int)0) : add_20776);
			__m_latch_120 = ((gen_20772 != 0) ? add_20776 : __m_latch_120);
			t_sample latch_20775 = __m_latch_120;
			t_sample gen_20778 = latch_20775;
			t_sample history_20774_next_20777 = fixdenorm(switch_20773);
			t_sample rdiv_20766 = safediv(((int)1), gen_20778);
			t_sample add_20768 = (m_history_52 + rdiv_20766);
			t_sample switch_20765 = (gen_20772 ? ((int)0) : add_20768);
			t_sample wrap_20767 = wrap(switch_20765, ((int)0), ((int)1));
			t_sample switch_20781 = (gt_20779 ? gen_20762 : wrap_20767);
			t_sample gen_20786 = switch_20781;
			t_sample history_20764_next_20785 = fixdenorm(wrap_20767);
			t_sample mul_501 = (gen_20786 * m_beats_61);
			t_sample wrap_500 = wrap(mul_501, ((int)0), ((int)1));
			t_sample sub_23556 = (wrap_500 - m_history_51);
			t_sample add_23559 = (wrap_500 + m_history_51);
			t_sample div_23562 = safediv(sub_23556, add_23559);
			t_sample abs_23558 = fabs(div_23562);
			int gt_23555 = (abs_23558 > ((t_sample)0.5));
			int change_23557 = __m_change_121(gt_23555);
			int gt_23560 = (change_23557 > ((int)0));
			int gen_503 = gt_23560;
			t_sample history_267_next_23561 = fixdenorm(wrap_500);
			__m_latch_122 = ((gen_503 != 0) ? floor_496 : __m_latch_122);
			t_sample latch_504 = __m_latch_122;
			t_sample sub_513 = (mul_501 - latch_504);
			__m_latch_123 = ((gen_503 != 0) ? floor_497 : __m_latch_123);
			t_sample latch_506 = __m_latch_123;
			t_sample abs_488 = fabs(latch_506);
			__m_latch_124 = ((gen_503 != 0) ? floor_498 : __m_latch_124);
			t_sample latch_505 = __m_latch_124;
			t_sample abs_487 = fabs(latch_505);
			t_sample max_486 = ((abs_488 < abs_487) ? abs_487 : abs_488);
			t_sample min_485 = ((abs_487 < abs_488) ? abs_487 : abs_488);
			t_sample div_489 = safediv(min_485, max_486);
			t_sample mul_484 = (latch_506 * latch_505);
			int sign_491 = ((mul_484 > 0) ? 1 : ((mul_484 < 0) ? -1 : 0));
			t_sample mul_490 = (sub_513 * sign_491);
			t_sample wrap_507 = wrap(mul_490, ((int)0), max_486);
			t_sample floor_514 = floor(wrap_507);
			t_sample mul_509 = (floor_514 * div_489);
			t_sample floor_512 = floor(mul_509);
			t_sample div_511 = safediv(floor_512, div_489);
			t_sample ceil_510 = ceil(div_511);
			t_sample sub_508 = (wrap_507 - ceil_510);
			t_sample add_493 = (floor_512 + ((int)1));
			t_sample div_495 = safediv(add_493, div_489);
			t_sample ceil_494 = ceil(div_495);
			t_sample sub_492 = (ceil_494 - ceil_510);
			t_sample div_502 = safediv(sub_508, sub_492);
			t_sample sub_23566 = (div_502 - m_history_50);
			t_sample add_23567 = (div_502 + m_history_50);
			t_sample div_23569 = safediv(sub_23566, add_23567);
			t_sample abs_23570 = fabs(div_23569);
			int gt_23565 = (abs_23570 > ((t_sample)0.5));
			int change_23568 = __m_change_125(gt_23565);
			int gt_23571 = (change_23568 > ((int)0));
			int gen_476 = gt_23571;
			t_sample history_267_next_23572 = fixdenorm(div_502);
			int trig_432 = gen_476;
			__m_latch_126 = ((trig_432 != 0) ? m_history_19 : __m_latch_126);
			t_sample latch_427 = __m_latch_126;
			int not_240 = (!latch_427);
			t_sample out6 = not_240;
			__m_latch_127 = ((trig_432 != 0) ? m_history_14 : __m_latch_127);
			t_sample latch_429 = __m_latch_127;
			int not_241 = (!latch_429);
			t_sample out5 = not_241;
			__m_latch_128 = ((trig_432 != 0) ? m_history_20 : __m_latch_128);
			t_sample latch_425 = __m_latch_128;
			int not_239 = (!latch_425);
			t_sample out7 = not_239;
			__m_latch_129 = ((trig_432 != 0) ? m_history_18 : __m_latch_129);
			t_sample latch_424 = __m_latch_129;
			int not_238 = (!latch_424);
			t_sample out8 = not_238;
			__m_latch_130 = ((trig_432 != 0) ? m_history_17 : __m_latch_130);
			t_sample latch_422 = __m_latch_130;
			int not_237 = (!latch_422);
			t_sample out9 = not_237;
			__m_latch_131 = ((trig_432 != 0) ? gt_416 : __m_latch_131);
			int latch_433 = __m_latch_131;
			int not_243 = (!latch_433);
			t_sample out3 = not_243;
			__m_latch_132 = ((trig_432 != 0) ? m_history_15 : __m_latch_132);
			t_sample latch_431 = __m_latch_132;
			int not_242 = (!latch_431);
			t_sample out4 = not_242;
			int trig_530 = trig_432;
			__m_latch_133 = ((trig_530 != 0) ? m_history_9 : __m_latch_133);
			t_sample latch_520 = __m_latch_133;
			__m_latch_134 = ((trig_530 != 0) ? m_history_8 : __m_latch_134);
			t_sample latch_525 = __m_latch_134;
			__m_latch_135 = ((trig_530 != 0) ? m_history_3 : __m_latch_135);
			t_sample latch_529 = __m_latch_135;
			__m_latch_136 = ((trig_530 != 0) ? m_history_12 : __m_latch_136);
			t_sample latch_523 = __m_latch_136;
			__m_latch_137 = ((trig_530 != 0) ? m_history_10 : __m_latch_137);
			t_sample latch_522 = __m_latch_137;
			__m_latch_138 = ((trig_530 != 0) ? m_history_11 : __m_latch_138);
			t_sample latch_527 = __m_latch_138;
			__m_latch_139 = ((trig_432 != 0) ? m_history_16 : __m_latch_139);
			t_sample latch_420 = __m_latch_139;
			int not_236 = (!latch_420);
			t_sample out10 = not_236;
			t_sample switch_246 = (lt_245 ? ((int)1) : latch_420);
			int neq_459 = (gen_476 != ((int)0));
			int change_458 = __m_change_140(neq_459);
			int gt_457 = (change_458 > ((int)0));
			t_sample mul_463 = ((m_history_7 + gt_457) * t_465);
			t_sample clamp_456 = ((mul_463 <= ((int)0)) ? ((int)0) : ((mul_463 >= ((int)1)) ? ((int)1) : mul_463));
			t_sample mix_23828 = (clamp_456 + (((t_sample)0.97) * (m_history_6 - clamp_456)));
			t_sample mix_461 = mix_23828;
			__m_latch_141 = ((trig_530 != 0) ? m_history_13 : __m_latch_141);
			t_sample latch_518 = __m_latch_141;
			t_sample pitch_35 = latch_518;
			t_sample mul_477 = (pitch_35 * ((int)12));
			int int_468 = int(mul_477);
			t_sample mul_470 = (int_468 * div_471);
			t_sample round_473 = round(mul_470);
			t_sample div_469 = safediv(round_473, div_471);
			t_sample add_483 = (div_469 + ((int)36));
			t_sample mtof_482 = mtof(add_483, ((int)440));
			t_sample phasor_396 = __m_phasor_142(mtof_482, samples_to_seconds);
			t_sample saw_222 = phasor_396;
			t_sample clamp_305 = ((latch_309 <= ((int)0)) ? ((int)0) : ((latch_309 >= ((int)1)) ? ((int)1) : latch_309));
			t_sample triangle_304 = triangle(saw_222, clamp_305);
			t_sample sub_23832 = (triangle_304 - ((int)0));
			t_sample scale_23829 = ((safepow((sub_23832 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_303 = scale_23829;
			t_sample gen_306 = scale_303;
			t_sample rsub_277 = (((int)1) - gen_306);
			int change_278 = __m_change_143(gen_306);
			int gt_308 = (change_278 > ((int)0));
			t_sample switch_302 = (gt_308 ? gen_306 : rsub_277);
			t_sample sub_23577 = (switch_302 - m_history_49);
			t_sample add_23576 = (switch_302 + m_history_49);
			t_sample div_23579 = safediv(sub_23577, add_23576);
			t_sample abs_23580 = fabs(div_23579);
			int gt_23575 = (abs_23580 > ((t_sample)0.5));
			int change_23578 = __m_change_144(gt_23575);
			int gt_23581 = (change_23578 > ((int)0));
			int gen_19687 = gt_23581;
			t_sample history_267_next_19686 = fixdenorm(switch_302);
			__m_latch_145 = ((gen_19687 != 0) ? m_history_5 : __m_latch_145);
			t_sample latch_275 = __m_latch_145;
			t_sample sub_23590 = (switch_302 - m_history_48);
			t_sample add_23588 = (switch_302 + m_history_48);
			t_sample div_23585 = safediv(sub_23590, add_23588);
			t_sample abs_23586 = fabs(div_23585);
			int gt_23587 = (abs_23586 > ((t_sample)0.5));
			int change_23591 = __m_change_146(gt_23587);
			int gt_23584 = (change_23591 > ((int)0));
			int gen_301 = gt_23584;
			t_sample history_267_next_23583 = fixdenorm(switch_302);
			__m_latch_147 = ((gen_301 != 0) ? m_history_4 : __m_latch_147);
			t_sample latch_311 = __m_latch_147;
			t_sample mix_23833 = (gt_308 + (latch_280 * (abs_299 - gt_308)));
			t_sample mix_283 = mix_23833;
			t_sample orange_23836 = (((int)1) - latch_281);
			t_sample sub_23837 = (mix_283 - ((int)0));
			t_sample scale_23834 = ((safepow((sub_23837 * ((t_sample)1)), ((int)1)) * orange_23836) + latch_281);
			t_sample scale_282 = scale_23834;
			__m_latch_148 = ((gen_19687 != 0) ? scale_282 : __m_latch_148);
			t_sample latch_276 = __m_latch_148;
			int gte_248 = (latch_275 >= latch_276);
			int and_285 = (gte_248 && latch_284);
			t_sample switch_287 = (and_285 ? latch_288 : rsub_286);
			t_sample clamp_257 = ((switch_302 <= ((int)0)) ? ((int)0) : ((switch_302 >= ((int)1)) ? ((int)1) : switch_302));
			t_sample clamp_251 = ((switch_287 <= ((int)0)) ? ((int)0) : ((switch_287 >= ((int)1)) ? ((int)1) : switch_287));
			int lt_260 = (clamp_251 < ((t_sample)0.5));
			int not_256 = (!lt_260);
			t_sample sub_23841 = (clamp_251 - ((int)1));
			t_sample scale_23838 = ((safepow((sub_23841 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_261 = scale_23838;
			t_sample tan_259 = tan(scale_261);
			t_sample rdiv_258 = safediv(((int)1), tan_259);
			t_sample switch_255 = (lt_260 ? rdiv_258 : tan_259);
			t_sample switch_254 = (lt_260 ? tan_259 : rdiv_258);
			int irange_23843 = (lt_260 - not_256);
			t_sample sub_23845 = (clamp_257 - not_256);
			t_sample scale_23842 = ((safepow(safediv(sub_23845, irange_23843), switch_254) * ((int)-1)) + ((int)1));
			t_sample scale_253 = scale_23842;
			int orange_23848 = (not_256 - lt_260);
			t_sample sub_23849 = (scale_253 - ((int)0));
			t_sample scale_23846 = ((safepow((sub_23849 * ((t_sample)1)), switch_255) * orange_23848) + lt_260);
			t_sample scale_252 = scale_23846;
			t_sample gen_262 = scale_252;
			t_sample mix_23850 = (latch_275 + (gen_262 * (latch_276 - latch_275)));
			t_sample mix_263 = mix_23850;
			t_sample clamp_289 = ((switch_302 <= ((int)0)) ? ((int)0) : ((switch_302 >= ((int)1)) ? ((int)1) : switch_302));
			t_sample round_295 = round(clamp_289);
			t_sample triangle_290 = triangle(clamp_289, ((t_sample)0.5));
			t_sample clamp_293 = ((switch_287 <= ((int)0)) ? ((int)0) : ((switch_287 >= ((int)1)) ? ((int)1) : switch_287));
			t_sample sub_23854 = (clamp_293 - ((int)1));
			t_sample scale_23851 = ((safepow((sub_23854 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_291 = scale_23851;
			t_sample clamp_23597 = ((triangle_290 <= ((int)0)) ? ((int)0) : ((triangle_290 >= ((int)1)) ? ((int)1) : triangle_290));
			t_sample clamp_23604 = ((scale_291 <= ((int)0)) ? ((int)0) : ((scale_291 >= ((int)1)) ? ((int)1) : scale_291));
			int lt_23595 = (clamp_23604 < ((t_sample)0.5));
			int not_23605 = (!lt_23595);
			t_sample sub_23858 = (clamp_23604 - ((int)1));
			t_sample scale_23855 = ((safepow((sub_23858 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_23602 = scale_23855;
			t_sample tan_23601 = tan(scale_23602);
			t_sample rdiv_23600 = safediv(((int)1), tan_23601);
			t_sample switch_23599 = (lt_23595 ? rdiv_23600 : tan_23601);
			t_sample switch_23596 = (lt_23595 ? tan_23601 : rdiv_23600);
			int irange_23860 = (lt_23595 - not_23605);
			t_sample sub_23862 = (clamp_23597 - not_23605);
			t_sample scale_23859 = ((safepow(safediv(sub_23862, irange_23860), switch_23596) * ((int)-1)) + ((int)1));
			t_sample scale_23594 = scale_23859;
			int orange_23865 = (not_23605 - lt_23595);
			t_sample sub_23866 = (scale_23594 - ((int)0));
			t_sample scale_23863 = ((safepow((sub_23866 * ((t_sample)1)), switch_23599) * orange_23865) + lt_23595);
			t_sample scale_23593 = scale_23863;
			t_sample gen_292 = scale_23593;
			t_sample mix_23867 = (round_295 + (gen_292 * (clamp_289 - round_295)));
			t_sample mix_294 = mix_23867;
			t_sample gen_296 = mix_294;
			__m_latch_149 = ((gen_301 != 0) ? scale_282 : __m_latch_149);
			t_sample latch_312 = __m_latch_149;
			t_sample mix_23868 = (latch_311 + (gen_296 * (latch_312 - latch_311)));
			t_sample mix_300 = mix_23868;
			__m_latch_150 = ((trig_530 != 0) ? mix_300 : __m_latch_150);
			t_sample latch_531 = __m_latch_150;
			t_sample saw_221 = saw_222;
			t_sample saw_223 = saw_222;
			t_sample sub_23613 = (saw_223 - m_history_47);
			t_sample add_23611 = (saw_223 + m_history_47);
			t_sample div_23608 = safediv(sub_23613, add_23611);
			t_sample abs_23609 = fabs(div_23608);
			int gt_23610 = (abs_23609 > ((t_sample)0.5));
			int change_23614 = __m_change_151(gt_23610);
			int gt_23607 = (change_23614 > ((int)0));
			int gen_383 = gt_23607;
			t_sample history_267_next_23606 = fixdenorm(saw_223);
			__m_latch_152 = ((gen_383 != 0) ? ((int)-1) : __m_latch_152);
			int latch_374 = __m_latch_152;
			__m_latch_153 = ((gen_383 != 0) ? rsub_360 : __m_latch_153);
			t_sample latch_381 = __m_latch_153;
			t_sample rsub_379 = (((int)1) - latch_381);
			__m_latch_154 = ((gen_383 != 0) ? ((int)0) : __m_latch_154);
			int latch_373 = __m_latch_154;
			__m_latch_155 = ((gen_383 != 0) ? ((t_sample)0.5) : __m_latch_155);
			t_sample latch_392 = __m_latch_155;
			t_sample clamp_23618 = ((latch_392 <= ((int)0)) ? ((int)0) : ((latch_392 >= ((int)1)) ? ((int)1) : latch_392));
			t_sample triangle_23617 = triangle(saw_221, clamp_23618);
			t_sample sub_23872 = (triangle_23617 - ((int)0));
			t_sample scale_23869 = ((safepow((sub_23872 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_23616 = scale_23869;
			t_sample gen_389 = scale_23616;
			t_sample rsub_370 = (((int)1) - gen_389);
			int change_371 = __m_change_156(gen_389);
			int gt_391 = (change_371 > ((int)0));
			t_sample switch_388 = (gt_391 ? gen_389 : rsub_370);
			t_sample sub_23626 = (switch_388 - m_history_46);
			t_sample add_23624 = (switch_388 + m_history_46);
			t_sample div_23621 = safediv(sub_23626, add_23624);
			t_sample abs_23622 = fabs(div_23621);
			int gt_23623 = (abs_23622 > ((t_sample)0.5));
			int change_23627 = __m_change_157(gt_23623);
			int gt_23620 = (change_23627 > ((int)0));
			int gen_366 = gt_23620;
			t_sample history_267_next_23625 = fixdenorm(switch_388);
			__m_latch_158 = ((gen_366 != 0) ? m_history_2 : __m_latch_158);
			t_sample latch_368 = __m_latch_158;
			t_sample sub_23634 = (switch_388 - m_history_45);
			t_sample add_23636 = (switch_388 + m_history_45);
			t_sample div_23631 = safediv(sub_23634, add_23636);
			t_sample abs_23632 = fabs(div_23631);
			int gt_23633 = (abs_23632 > ((t_sample)0.5));
			int change_23637 = __m_change_159(gt_23633);
			int gt_23630 = (change_23637 > ((int)0));
			int gen_387 = gt_23630;
			t_sample history_267_next_23635 = fixdenorm(switch_388);
			__m_latch_160 = ((gen_387 != 0) ? m_history_1 : __m_latch_160);
			t_sample latch_394 = __m_latch_160;
			t_sample mix_23873 = (gt_391 + (latch_373 * (abs_385 - gt_391)));
			t_sample mix_376 = mix_23873;
			int orange_23876 = (((int)1) - latch_374);
			t_sample sub_23877 = (mix_376 - ((int)0));
			t_sample scale_23874 = ((safepow((sub_23877 * ((t_sample)1)), ((int)1)) * orange_23876) + latch_374);
			t_sample scale_375 = scale_23874;
			__m_latch_161 = ((gen_366 != 0) ? scale_375 : __m_latch_161);
			t_sample latch_369 = __m_latch_161;
			int gte_363 = (latch_368 >= latch_369);
			__m_latch_162 = ((gen_387 != 0) ? scale_375 : __m_latch_162);
			t_sample latch_395 = __m_latch_162;
			__m_latch_163 = ((gen_383 != 0) ? gen_12 : __m_latch_163);
			t_sample latch_377 = __m_latch_163;
			int and_378 = (gte_363 && latch_377);
			t_sample switch_380 = (and_378 ? latch_381 : rsub_379);
			t_sample clamp_23643 = ((switch_388 <= ((int)0)) ? ((int)0) : ((switch_388 >= ((int)1)) ? ((int)1) : switch_388));
			t_sample clamp_23650 = ((switch_380 <= ((int)0)) ? ((int)0) : ((switch_380 >= ((int)1)) ? ((int)1) : switch_380));
			int lt_23641 = (clamp_23650 < ((t_sample)0.5));
			int not_23651 = (!lt_23641);
			t_sample sub_23881 = (clamp_23650 - ((int)1));
			t_sample scale_23878 = ((safepow((sub_23881 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_23648 = scale_23878;
			t_sample tan_23647 = tan(scale_23648);
			t_sample rdiv_23646 = safediv(((int)1), tan_23647);
			t_sample switch_23645 = (lt_23641 ? rdiv_23646 : tan_23647);
			t_sample switch_23642 = (lt_23641 ? tan_23647 : rdiv_23646);
			int irange_23883 = (lt_23641 - not_23651);
			t_sample sub_23885 = (clamp_23643 - not_23651);
			t_sample scale_23882 = ((safepow(safediv(sub_23885, irange_23883), switch_23642) * ((int)-1)) + ((int)1));
			t_sample scale_23640 = scale_23882;
			int orange_23888 = (not_23651 - lt_23641);
			t_sample sub_23889 = (scale_23640 - ((int)0));
			t_sample scale_23886 = ((safepow((sub_23889 * ((t_sample)1)), switch_23645) * orange_23888) + lt_23641);
			t_sample scale_23639 = scale_23886;
			t_sample gen_364 = scale_23639;
			t_sample mix_23890 = (latch_368 + (gen_364 * (latch_369 - latch_368)));
			t_sample mix_365 = mix_23890;
			t_sample out12 = mix_365;
			t_sample clamp_23668 = ((switch_388 <= ((int)0)) ? ((int)0) : ((switch_388 >= ((int)1)) ? ((int)1) : switch_388));
			t_sample round_23660 = round(clamp_23668);
			t_sample triangle_23670 = triangle(clamp_23668, ((t_sample)0.5));
			t_sample clamp_23659 = ((switch_380 <= ((int)0)) ? ((int)0) : ((switch_380 >= ((int)1)) ? ((int)1) : switch_380));
			t_sample sub_23894 = (clamp_23659 - ((int)1));
			t_sample scale_23891 = ((safepow((sub_23894 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_23667 = scale_23891;
			t_sample clamp_23656 = ((triangle_23670 <= ((int)0)) ? ((int)0) : ((triangle_23670 >= ((int)1)) ? ((int)1) : triangle_23670));
			t_sample clamp_23669 = ((scale_23667 <= ((int)0)) ? ((int)0) : ((scale_23667 >= ((int)1)) ? ((int)1) : scale_23667));
			int lt_23654 = (clamp_23669 < ((t_sample)0.5));
			int not_23671 = (!lt_23654);
			t_sample sub_23898 = (clamp_23669 - ((int)1));
			t_sample scale_23895 = ((safepow((sub_23898 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_23665 = scale_23895;
			t_sample tan_23664 = tan(scale_23665);
			t_sample rdiv_23663 = safediv(((int)1), tan_23664);
			t_sample switch_23662 = (lt_23654 ? rdiv_23663 : tan_23664);
			t_sample switch_23655 = (lt_23654 ? tan_23664 : rdiv_23663);
			int irange_23900 = (lt_23654 - not_23671);
			t_sample sub_23902 = (clamp_23656 - not_23671);
			t_sample scale_23899 = ((safepow(safediv(sub_23902, irange_23900), switch_23655) * ((int)-1)) + ((int)1));
			t_sample scale_23653 = scale_23899;
			int orange_23905 = (not_23671 - lt_23654);
			t_sample sub_23906 = (scale_23653 - ((int)0));
			t_sample scale_23903 = ((safepow((sub_23906 * ((t_sample)1)), switch_23662) * orange_23905) + lt_23654);
			t_sample scale_23652 = scale_23903;
			t_sample gen_23658 = scale_23652;
			t_sample mix_23907 = (round_23660 + (gen_23658 * (clamp_23668 - round_23660)));
			t_sample mix_23657 = mix_23907;
			t_sample gen_382 = mix_23657;
			t_sample mix_23908 = (latch_394 + (gen_382 * (latch_395 - latch_394)));
			t_sample mix_386 = mix_23908;
			t_sample out11 = mix_386;
			t_sample pitch_36 = pitch_35;
			t_sample mul_232 = (pitch_36 * ((int)12));
			int int_228 = int(mul_232);
			t_sample mul_230 = (int_228 * div_471);
			t_sample round_231 = round(mul_230);
			t_sample div_229 = safediv(round_231, div_471);
			t_sample add_234 = (div_229 + ((int)60));
			t_sample mtof_233 = mtof(add_234, ((int)440));
			__m_cycle_164.freq(mtof_233);
			t_sample cycle_226 = __m_cycle_164(__sinedata);
			t_sample cycleindex_227 = __m_cycle_164.phase();
			t_sample mix_23909 = (((int)1) + (m_cvin_69 * (cycle_226 - ((int)1))));
			t_sample mix_225 = mix_23909;
			t_sample floor_442 = floor(mix_386);
			t_sample sub_434 = (mix_386 - floor_442);
			t_sample add_441 = (floor_442 + ((int)1));
			t_sample mul_437 = (mtof_482 * ((t_sample)6.2831853071796));
			t_sample mul_439 = (floor_442 * mul_437);
			t_sample sin_436 = sin((mix_225 + mul_439));
			t_sample mul_438 = (add_441 * mul_437);
			t_sample sin_435 = sin((mix_225 + mul_438));
			t_sample mix_23910 = (sin_436 + (sub_434 * (sin_435 - sin_436)));
			t_sample mix_440 = mix_23910;
			t_sample gen_443 = mix_440;
			t_sample mul_481 = (gen_443 * mix_461);
			t_sample mul_247 = (mul_481 * switch_246);
			t_sample mul_479 = (mul_247 * ((int)2));
			t_sample tanh_480 = tanh(mul_479);
			t_sample div_478 = (tanh_480 * ((t_sample)0.5));
			t_sample mul_344 = (m_history_44 * gen_337);
			t_sample mul_345 = (m_history_42 * ((int)0));
			t_sample mul_346 = (div_478 * gen_335);
			t_sample mul_347 = (m_history_43 * gen_339);
			t_sample mul_348 = (m_history_41 * gen_338);
			t_sample sub_341 = (((mul_346 + mul_345) + mul_344) - (mul_348 + mul_347));
			t_sample gen_355 = sub_341;
			t_sample history_342_next_351 = fixdenorm(m_history_42);
			t_sample history_349_next_352 = fixdenorm(m_history_41);
			t_sample history_343_next_353 = fixdenorm(div_478);
			t_sample history_350_next_354 = fixdenorm(sub_341);
			t_sample clamp_340 = ((gen_355 <= min_165) ? min_165 : ((gen_355 >= ((int)1)) ? ((int)1) : gen_355));
			t_sample mul_117 = (clamp_340 * ((t_sample)0.015));
			t_sample tap_50 = m_delay_40.read_step(((int)1557));
			t_sample gen_88 = tap_50;
			t_sample mul_48 = (tap_50 * ((t_sample)0.7));
			t_sample mul_46 = (m_history_39 * ((t_sample)0.3));
			t_sample add_47 = (mul_48 + mul_46);
			t_sample mul_44 = (add_47 * ((t_sample)0.2));
			t_sample add_51 = (mul_117 + mul_44);
			t_sample history_45_next_52 = fixdenorm(add_47);
			t_sample tap_23435 = m_delay_38.read_step(((int)1617));
			t_sample gen_116 = tap_23435;
			t_sample mul_23437 = (tap_23435 * ((t_sample)0.7));
			t_sample mul_23438 = (m_history_37 * ((t_sample)0.3));
			t_sample add_23433 = (mul_23437 + mul_23438);
			t_sample mul_23439 = (add_23433 * ((t_sample)0.2));
			t_sample add_23434 = (mul_117 + mul_23439);
			t_sample history_45_next_23436 = fixdenorm(add_23433);
			t_sample tap_23448 = m_delay_36.read_step(((int)1491));
			t_sample gen_87 = tap_23448;
			t_sample mul_23451 = (tap_23448 * ((t_sample)0.7));
			t_sample mul_23452 = (m_history_35 * ((t_sample)0.3));
			t_sample add_23445 = (mul_23451 + mul_23452);
			t_sample mul_23450 = (add_23445 * ((t_sample)0.2));
			t_sample add_23447 = (mul_117 + mul_23450);
			t_sample history_45_next_23449 = fixdenorm(add_23445);
			t_sample tap_23458 = m_delay_34.read_step(((int)1422));
			t_sample gen_86 = tap_23458;
			t_sample mul_23461 = (tap_23458 * ((t_sample)0.7));
			t_sample mul_23462 = (m_history_33 * ((t_sample)0.3));
			t_sample add_23456 = (mul_23461 + mul_23462);
			t_sample mul_23460 = (add_23456 * ((t_sample)0.2));
			t_sample add_23457 = (mul_117 + mul_23460);
			t_sample history_45_next_23459 = fixdenorm(add_23456);
			t_sample tap_23470 = m_delay_32.read_step(((int)1356));
			t_sample gen_85 = tap_23470;
			t_sample mul_23474 = (tap_23470 * ((t_sample)0.7));
			t_sample mul_23475 = (m_history_31 * ((t_sample)0.3));
			t_sample add_23468 = (mul_23474 + mul_23475);
			t_sample mul_23473 = (add_23468 * ((t_sample)0.2));
			t_sample add_23469 = (mul_117 + mul_23473);
			t_sample history_45_next_23472 = fixdenorm(add_23468);
			t_sample tap_23482 = m_delay_30.read_step(((int)1277));
			t_sample gen_84 = tap_23482;
			t_sample mul_23485 = (tap_23482 * ((t_sample)0.7));
			t_sample mul_23486 = (m_history_29 * ((t_sample)0.3));
			t_sample add_23480 = (mul_23485 + mul_23486);
			t_sample mul_23484 = (add_23480 * ((t_sample)0.2));
			t_sample add_23481 = (mul_117 + mul_23484);
			t_sample history_45_next_23483 = fixdenorm(add_23480);
			t_sample tap_23495 = m_delay_28.read_step(((int)1188));
			t_sample gen_83 = tap_23495;
			t_sample mul_23498 = (tap_23495 * ((t_sample)0.7));
			t_sample mul_23499 = (m_history_27 * ((t_sample)0.3));
			t_sample add_23492 = (mul_23498 + mul_23499);
			t_sample mul_23497 = (add_23492 * ((t_sample)0.2));
			t_sample add_23493 = (mul_117 + mul_23497);
			t_sample history_45_next_23496 = fixdenorm(add_23492);
			t_sample tap_23507 = m_delay_26.read_step(((int)1116));
			t_sample gen_23314 = tap_23507;
			t_sample mul_23510 = (tap_23507 * ((t_sample)0.7));
			t_sample mul_23511 = (m_history_25 * ((t_sample)0.3));
			t_sample add_23504 = (mul_23510 + mul_23511);
			t_sample mul_23509 = (add_23504 * ((t_sample)0.2));
			t_sample add_23505 = (mul_117 + mul_23509);
			t_sample history_45_next_23508 = fixdenorm(add_23504);
			t_sample add_105 = ((((((((gen_23314 + gen_83) + gen_84) + gen_85) + gen_86) + gen_87) + gen_116) + gen_88) + ((int)0));
			t_sample tap_41 = m_delay_24.read_step(((int)556));
			t_sample sub_37 = (add_105 - tap_41);
			t_sample mul_39 = (tap_41 * ((t_sample)0.45));
			t_sample add_38 = (add_105 + mul_39);
			t_sample tap_23520 = m_delay_23.read_step(((int)441));
			t_sample sub_23518 = (sub_37 - tap_23520);
			t_sample mul_23517 = (tap_23520 * ((t_sample)0.45));
			t_sample add_23519 = (sub_37 + mul_23517);
			t_sample tap_23526 = m_delay_22.read_step(((int)341));
			t_sample sub_23524 = (sub_23518 - tap_23526);
			t_sample mul_23523 = (tap_23526 * ((t_sample)0.45));
			t_sample add_23525 = (sub_23518 + mul_23523);
			t_sample tap_23532 = m_delay_21.read_step(((int)225));
			t_sample sub_23530 = (sub_23524 - tap_23532);
			t_sample mul_23529 = (tap_23532 * ((t_sample)0.45));
			t_sample add_23531 = (sub_23524 + mul_23529);
			t_sample mix_23911 = (((t_sample)0.7) + (clamp_340 * (sub_23530 - ((t_sample)0.7))));
			t_sample add_397 = (mix_23911 + in2);
			t_sample out2 = add_397;
			t_sample add_398 = (mix_23911 + in1);
			t_sample out1 = add_398;
			t_sample history_418_next_23672 = fixdenorm(latch_427);
			t_sample history_426_next_23673 = fixdenorm(latch_429);
			t_sample history_423_next_23674 = fixdenorm(latch_425);
			t_sample history_421_next_23675 = fixdenorm(latch_424);
			t_sample history_419_next_23676 = fixdenorm(latch_422);
			t_sample history_430_next_23677 = fixdenorm(latch_433);
			t_sample history_428_next_23678 = fixdenorm(latch_431);
			t_sample history_517_next_23679 = fixdenorm(latch_520);
			t_sample history_516_next_23680 = fixdenorm(latch_525);
			t_sample history_526_next_23681 = fixdenorm(latch_529);
			t_sample history_521_next_23682 = fixdenorm(latch_523);
			t_sample history_519_next_23683 = fixdenorm(latch_522);
			t_sample history_524_next_23684 = fixdenorm(latch_527);
			t_sample history_462_next_23685 = fixdenorm(clamp_456);
			t_sample history_460_next_23686 = fixdenorm(mix_461);
			t_sample history_274_next_23687 = fixdenorm(mix_263);
			t_sample history_310_next_23688 = fixdenorm(mix_300);
			t_sample history_528_next_23689 = fixdenorm(latch_531);
			t_sample history_367_next_23690 = fixdenorm(mix_365);
			t_sample history_393_next_23691 = fixdenorm(mix_386);
			m_history_62 = history_267_next_272;
			m_history_57 = history_7_next_9;
			m_history_55 = history_3_next_11;
			m_history_56 = history_5_next_10;
			m_history_54 = history_267_next_23546;
			m_history_53 = history_20774_next_20777;
			m_history_52 = history_20764_next_20785;
			m_history_51 = history_267_next_23561;
			m_history_50 = history_267_next_23572;
			m_history_49 = history_267_next_19686;
			m_history_48 = history_267_next_23583;
			m_history_47 = history_267_next_23606;
			m_history_46 = history_267_next_23625;
			m_history_45 = history_267_next_23635;
			m_history_44 = history_342_next_351;
			m_history_41 = history_350_next_354;
			m_history_42 = history_343_next_353;
			m_history_43 = history_349_next_352;
			m_delay_40.write(add_51);
			m_delay_21.write(add_23531);
			m_delay_22.write(add_23525);
			m_delay_23.write(add_23519);
			m_delay_24.write(add_38);
			m_history_25 = history_45_next_23508;
			m_delay_26.write(add_23505);
			m_history_27 = history_45_next_23496;
			m_delay_28.write(add_23493);
			m_history_29 = history_45_next_23483;
			m_delay_30.write(add_23481);
			m_history_31 = history_45_next_23472;
			m_delay_32.write(add_23469);
			m_history_33 = history_45_next_23459;
			m_delay_34.write(add_23457);
			m_history_35 = history_45_next_23449;
			m_delay_36.write(add_23447);
			m_history_37 = history_45_next_23436;
			m_delay_38.write(add_23434);
			m_history_39 = history_45_next_52;
			m_history_20 = history_418_next_23672;
			m_history_19 = history_426_next_23673;
			m_history_18 = history_423_next_23674;
			m_history_17 = history_421_next_23675;
			m_history_16 = history_419_next_23676;
			m_history_15 = history_430_next_23677;
			m_history_14 = history_428_next_23678;
			m_history_13 = history_517_next_23679;
			m_history_12 = history_516_next_23680;
			m_history_11 = history_526_next_23681;
			m_history_10 = history_521_next_23682;
			m_history_9 = history_519_next_23683;
			m_history_8 = history_524_next_23684;
			m_history_7 = history_462_next_23685;
			m_history_6 = history_460_next_23686;
			m_history_5 = history_274_next_23687;
			m_history_4 = history_310_next_23688;
			m_history_3 = history_528_next_23689;
			m_history_2 = history_367_next_23690;
			m_history_1 = history_393_next_23691;
			m_delay_21.step();
			m_delay_22.step();
			m_delay_23.step();
			m_delay_24.step();
			m_delay_26.step();
			m_delay_28.step();
			m_delay_30.step();
			m_delay_32.step();
			m_delay_34.step();
			m_delay_36.step();
			m_delay_38.step();
			m_delay_40.step();
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
	inline void set_sw1(t_param _value) {
		m_sw_63 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_euclidP(t_param _value) {
		m_knob3_euclidP_64 = (_value < 0 ? 0 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob1_bpm(t_param _value) {
		m_knob1_bpm_65 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_numer(t_param _value) {
		m_numer_66 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_67 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_68 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin2(t_param _value) {
		m_cvin_69 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_timbre(t_param _value) {
		m_knob5_timbre_70 = (_value < 0.01 ? 0.01 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_71 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_random(t_param _value) {
		m_random_72 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_73 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_denom(t_param _value) {
		m_denom_74 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_knob2_envelopeLength(t_param _value) {
		m_knob2_envelopeLength_75 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_symmetry(t_param _value) {
		m_symmetry_76 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_skew(t_param _value) {
		m_skew_77 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_78 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_shiftVar(t_param _value) {
		m_knob4_shiftVar_79 = (_value < 0 ? 0 : (_value > 0.5 ? 0.5 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_80 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_81 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_82 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_filter(t_param _value) {
		m_knob6_filter_83 = (_value < 100 ? 100 : (_value > 1400 ? 1400 : _value));
	};
	inline void set_shape(t_param _value) {
		m_shape_84 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bipolar(t_param _value) {
		m_bipolar_85 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_bipolar_85; break;
		case 1: *value = self->m_cvin_69; break;
		case 2: *value = self->m_denom_74; break;
		
		case 4: *value = self->m_gatein_71; break;
		case 5: *value = self->m_knob1_bpm_65; break;
		case 6: *value = self->m_knob2_envelopeLength_75; break;
		case 7: *value = self->m_knob3_euclidP_64; break;
		case 8: *value = self->m_knob4_shiftVar_79; break;
		case 9: *value = self->m_knob5_timbre_70; break;
		case 10: *value = self->m_knob6_filter_83; break;
		case 11: *value = self->m_numer_66; break;
		case 12: *value = self->m_random_72; break;
		case 13: *value = self->m_shape_84; break;
		case 14: *value = self->m_skew_77; break;
		case 15: *value = self->m_sw_63; break;
		case 16: *value = self->m_sw_73; break;
		case 17: *value = self->m_sw_78; break;
		case 18: *value = self->m_sw_82; break;
		case 19: *value = self->m_sw_67; break;
		case 20: *value = self->m_sw_80; break;
		case 21: *value = self->m_sw_68; break;
		case 22: *value = self->m_sw_81; break;
		case 23: *value = self->m_symmetry_76; break;
		
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
	// initialize parameter 0 ("m_bipolar_85")
	pi = self->__commonstate.params + 0;
	pi->name = "bipolar";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bipolar_85;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cvin_69")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_69;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_denom_74")
	pi = self->__commonstate.params + 2;
	pi->name = "denom";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_denom_74;
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
	// initialize parameter 4 ("m_gatein_71")
	pi = self->__commonstate.params + 4;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_71;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob1_bpm_65")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1_bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_bpm_65;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob2_envelopeLength_75")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2_envelopeLength";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_envelopeLength_75;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob3_euclidP_64")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_euclidP";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_euclidP_64;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_shiftVar_79")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_shiftVar";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_shiftVar_79;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_timbre_70")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_timbre";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_timbre_70;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_filter_83")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_filter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_filter_83;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 100;
	pi->outputmax = 1400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_numer_66")
	pi = self->__commonstate.params + 11;
	pi->name = "numer";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_numer_66;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 24;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_random_72")
	pi = self->__commonstate.params + 12;
	pi->name = "random";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_random_72;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_shape_84")
	pi = self->__commonstate.params + 13;
	pi->name = "shape";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_shape_84;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_skew_77")
	pi = self->__commonstate.params + 14;
	pi->name = "skew";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_skew_77;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_63")
	pi = self->__commonstate.params + 15;
	pi->name = "sw1";
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
	// initialize parameter 16 ("m_sw_73")
	pi = self->__commonstate.params + 16;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_73;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_78")
	pi = self->__commonstate.params + 17;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_78;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_82")
	pi = self->__commonstate.params + 18;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_82;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_67")
	pi = self->__commonstate.params + 19;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_67;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_80")
	pi = self->__commonstate.params + 20;
	pi->name = "sw6";
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
	// initialize parameter 21 ("m_sw_68")
	pi = self->__commonstate.params + 21;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_68;
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
	// initialize parameter 23 ("m_symmetry_76")
	pi = self->__commonstate.params + 23;
	pi->name = "symmetry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_symmetry_76;
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
