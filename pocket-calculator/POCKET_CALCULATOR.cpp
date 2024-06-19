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
	Change __m_change_121;
	Change __m_change_117;
	Change __m_change_136;
	Change __m_change_85;
	Change __m_change_108;
	Change __m_change_145;
	Change __m_change_139;
	Change __m_change_105;
	Change __m_change_153;
	Change __m_change_155;
	Change __m_change_146;
	Change __m_change_152;
	Change __m_change_148;
	Data m_euclidean_patterns_83;
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
	Phasor __m_phasor_84;
	Phasor __m_phasor_138;
	Phasor __m_phasor_116;
	Phasor __m_phasor_107;
	SineCycle __m_cycle_160;
	SineData __sinedata;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample __m_latch_124;
	t_sample m_history_32;
	t_sample __m_latch_123;
	t_sample m_history_8;
	t_sample __m_latch_122;
	t_sample __m_latch_125;
	t_sample __m_latch_126;
	t_sample __m_latch_127;
	t_sample __m_latch_130;
	t_sample __m_latch_120;
	t_sample __m_latch_129;
	t_sample __m_latch_128;
	t_sample __m_latch_119;
	t_sample __m_latch_118;
	t_sample m_history_9;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample __m_latch_106;
	t_sample m_history_13;
	t_sample __m_latch_131;
	t_sample __m_latch_109;
	t_sample __m_latch_111;
	t_sample m_history_10;
	t_sample __m_latch_110;
	t_sample __m_latch_113;
	t_sample __m_latch_112;
	t_sample __m_latch_132;
	t_sample __m_latch_133;
	t_sample __m_latch_134;
	t_sample __m_latch_151;
	t_sample m_history_1;
	t_sample __m_latch_150;
	t_sample __m_latch_149;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample __m_latch_156;
	t_sample __m_latch_159;
	t_sample __m_latch_154;
	t_sample __m_latch_158;
	t_sample __m_latch_157;
	t_sample m_history_14;
	t_sample __m_latch_147;
	t_sample m_history_4;
	t_sample __m_latch_137;
	t_sample m_history_6;
	t_sample m_history_7;
	t_sample __m_latch_135;
	t_sample m_history_3;
	t_sample m_history_5;
	t_sample __m_latch_141;
	t_sample __m_latch_144;
	t_sample __m_latch_140;
	t_sample __m_latch_143;
	t_sample __m_latch_142;
	t_sample m_history_30;
	t_sample elapsed;
	t_sample m_history_15;
	t_sample m_history_50;
	t_sample m_history_51;
	t_sample m_history_49;
	t_sample m_history_47;
	t_sample m_history_48;
	t_sample m_history_46;
	t_sample m_history_52;
	t_sample m_history_54;
	t_sample m_events_57;
	t_sample m_history_53;
	t_sample m_hits_56;
	t_sample m_shift_55;
	t_sample m_beats_58;
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
	t_sample __m_latch_86;
	t_sample m_history_59;
	t_sample m_sw_61;
	t_sample m_numer_78;
	t_sample m_sw_79;
	t_sample m_knob6_filter_77;
	t_sample m_knob2_envelopeLength_76;
	t_sample m_cv_75;
	t_sample m_denom_80;
	t_sample m_bipolar_82;
	t_sample m_history_16;
	t_sample m_skew_81;
	t_sample samples_to_seconds;
	t_sample m_history_17;
	t_sample m_shape_60;
	t_sample m_gatein_74;
	t_sample m_random_72;
	t_sample m_knob4_shiftVar_64;
	t_sample m_sw_65;
	t_sample m_sw_63;
	t_sample m_sw_62;
	t_sample m_symmetry_73;
	t_sample m_knob3_euclidP_66;
	t_sample m_sw_68;
	t_sample m_history_18;
	t_sample m_sw_67;
	t_sample m_knob1_bpm_70;
	t_sample m_knob5_timbre_69;
	t_sample m_sw_71;
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
		m_shift_55 = ((int)0);
		m_hits_56 = ((int)0);
		m_events_57 = ((int)0);
		m_beats_58 = ((int)0);
		m_history_59 = ((int)0);
		m_shape_60 = ((t_sample)0.5);
		m_sw_61 = ((int)0);
		m_sw_62 = ((int)0);
		m_sw_63 = ((int)0);
		m_knob4_shiftVar_64 = ((t_sample)0.5);
		m_sw_65 = ((int)0);
		m_knob3_euclidP_66 = ((int)0);
		m_sw_67 = ((int)0);
		m_sw_68 = ((int)0);
		m_knob5_timbre_69 = ((int)0);
		m_knob1_bpm_70 = ((int)0);
		m_sw_71 = ((int)0);
		m_random_72 = ((int)0);
		m_symmetry_73 = ((int)0);
		m_gatein_74 = ((int)0);
		m_cv_75 = ((int)0);
		m_knob2_envelopeLength_76 = ((int)0);
		m_knob6_filter_77 = ((int)220);
		m_numer_78 = ((int)5);
		m_sw_79 = ((int)0);
		m_denom_80 = ((int)12);
		m_skew_81 = ((t_sample)0.5);
		m_bipolar_82 = ((int)0);
		m_euclidean_patterns_83.reset("euclidean_patterns", ((int)64), ((int)4));
		samples_to_seconds = (1 / samplerate);
		__m_phasor_84.reset(0);
		__m_change_85.reset(0);
		__m_latch_86 = 0;
		elapsed = 0;
		__m_change_105.reset(0);
		__m_latch_106 = 11025;
		__m_phasor_107.reset(0);
		__m_change_108.reset(0);
		__m_latch_109 = 0;
		__m_latch_110 = 0;
		__m_latch_111 = 0;
		__m_latch_112 = 0;
		__m_latch_113 = 0;
		__m_phasor_116.reset(0);
		__m_change_117.reset(0);
		__m_latch_118 = 0;
		__m_latch_119 = 0;
		__m_latch_120 = 0;
		__m_change_121.reset(0);
		__m_latch_122 = 0;
		__m_latch_123 = 0;
		__m_latch_124 = 0;
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
		__m_change_136.reset(0);
		__m_latch_137 = 0;
		__m_phasor_138.reset(0);
		__m_change_139.reset(0);
		__m_latch_140 = 0;
		__m_latch_141 = 0;
		__m_latch_142 = 0;
		__m_latch_143 = 0;
		__m_latch_144 = 0;
		__m_change_145.reset(0);
		__m_change_146.reset(0);
		__m_latch_147 = 0;
		__m_change_148.reset(0);
		__m_latch_149 = 0;
		__m_latch_150 = 0;
		__m_latch_151 = 0;
		__m_change_152.reset(0);
		__m_change_153.reset(0);
		__m_latch_154 = 0;
		__m_change_155.reset(0);
		__m_latch_156 = 0;
		__m_latch_157 = 0;
		__m_latch_158 = 0;
		__m_latch_159 = 0;
		__m_cycle_160.reset(samplerate, 0);
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
		int euclidean_patterns_dim = m_euclidean_patterns_83.dim;
		int euclidean_patterns_channels = m_euclidean_patterns_83.channels;
		bool chan_ignore_98 = ((1 < 0) || (1 >= euclidean_patterns_channels));
		bool chan_ignore_101 = ((2 < 0) || (2 >= euclidean_patterns_channels));
		bool chan_ignore_104 = ((3 < 0) || (3 >= euclidean_patterns_channels));
		int gt_191 = (m_gatein_74 > ((int)0));
		t_sample rsub_138 = (((int)1) - m_knob5_timbre_69);
		t_sample neg_57 = (-m_bipolar_82);
		t_sample mul_248 = (samplerate * m_knob2_envelopeLength_76);
		t_sample t_249 = exp(safediv(-6.9077552789821, mul_248));
		int min_114 = ((-samplerate) * ((t_sample)0.5));
		int max_115 = (samplerate * ((t_sample)0.5));
		t_sample clamp_111 = ((m_knob6_filter_77 <= min_114) ? min_114 : ((m_knob6_filter_77 >= max_115) ? max_115 : m_knob6_filter_77));
		t_sample abs_110 = fabs(clamp_111);
		t_sample mul_109 = (abs_110 * safediv(6.2831853071796, samplerate));
		t_sample sin_106 = sin(mul_109);
		t_sample mul_105 = (sin_106 * ((t_sample)0.5));
		t_sample div_104 = (mul_105 * ((t_sample)0.5));
		t_sample rsub_96 = (((int)1) - div_104);
		t_sample neg_95 = (-div_104);
		t_sample add_103 = (div_104 + ((int)1));
		t_sample rdiv_102 = safediv(((int)1), add_103);
		t_sample mul_98 = (rsub_96 * rdiv_102);
		t_sample gen_117 = mul_98;
		t_sample mul_100 = (neg_95 * rdiv_102);
		t_sample gen_115 = mul_100;
		t_sample mul_101 = (div_104 * rdiv_102);
		t_sample gen_113 = mul_101;
		t_sample cos_108 = cos(mul_109);
		t_sample neg_107 = (-cos_108);
		t_sample mul_97 = (neg_107 * ((int)2));
		t_sample mul_99 = (mul_97 * rdiv_102);
		t_sample gen_116 = mul_99;
		int gt_136 = (m_knob5_timbre_69 > ((t_sample)0.5));
		t_sample sub_15638 = (m_knob5_timbre_69 - ((int)0));
		t_sample scale_15635 = ((safepow((sub_15638 * ((t_sample)1)), ((int)1)) * ((t_sample)0.3)) + ((int)0));
		t_sample scale_134 = scale_15635;
		t_sample switch_135 = (gt_136 ? scale_134 : ((int)0));
		int lt_23 = (m_knob4_shiftVar_64 < ((t_sample)0.1));
		int gt_181 = (m_knob1_bpm_70 > ((t_sample)0.99));
		int int_330 = int(m_numer_78);
		int int_328 = int(m_denom_80);
		t_sample div_327 = safediv(int_330, int_328);
		t_sample sub_15642 = (m_knob1_bpm_70 - ((int)0));
		t_sample scale_15639 = ((safepow((sub_15642 * ((t_sample)1)), ((int)1)) * ((int)160)) + ((int)40));
		t_sample scale_251 = scale_15639;
		t_sample div_250 = (scale_251 * ((t_sample)0.016666666666667));
		int min_161 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample phasor_229 = __m_phasor_84(((int)10), samples_to_seconds);
			t_sample sub_48 = (phasor_229 - m_history_59);
			t_sample add_49 = (phasor_229 + m_history_59);
			t_sample div_47 = safediv(sub_48, add_49);
			t_sample abs_46 = fabs(div_47);
			int gt_44 = (abs_46 > ((t_sample)0.5));
			int change_43 = __m_change_85(gt_44);
			int gt_42 = (change_43 > ((int)0));
			int gen_228 = gt_42;
			t_sample history_45_next_50 = fixdenorm(phasor_229);
			__m_latch_86 = ((gen_228 != 0) ? m_knob3_euclidP_66 : __m_latch_86);
			t_sample latch_230 = __m_latch_86;
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				int euclidean_patterns_dim = m_euclidean_patterns_83.dim;
				int euclidean_patterns_channels = m_euclidean_patterns_83.channels;
				while ((i < euclidean_patterns_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample n2 = noise();
					t_sample n3 = noise();
					t_sample sub_15626 = (n2 - (-1));
					t_sample scale_15623 = ((safepow((sub_15626 * ((t_sample)0.5)), ((int)1)) * ((int)0)) + ((int)16));
					t_sample b = round(scale_15623);
					t_sample sub_15630 = (n3 - (-1));
					t_sample scale_15627 = ((safepow((sub_15630 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)1));
					t_sample c = round(scale_15627);
					bool index_ignore_87 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!index_ignore_87)) {
						m_euclidean_patterns_83.write(((int)8), i, 0);
						
					};
					bool chan_ignore_88 = ((((int)1) < 0) || (((int)1) >= euclidean_patterns_channels));
					bool index_ignore_89 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_88 || index_ignore_89))) {
						m_euclidean_patterns_83.write(b, i, ((int)1));
						
					};
					bool chan_ignore_90 = ((((int)2) < 0) || (((int)2) >= euclidean_patterns_channels));
					bool index_ignore_91 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_90 || index_ignore_91))) {
						m_euclidean_patterns_83.write(c, i, ((int)2));
						
					};
					bool chan_ignore_92 = ((((int)3) < 0) || (((int)3) >= euclidean_patterns_channels));
					bool index_ignore_93 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_92 || index_ignore_93))) {
						m_euclidean_patterns_83.write(((int)0), i, ((int)3));
						
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
			t_sample sub_15634 = (latch_230 - ((int)0));
			t_sample scale_15631 = ((safepow((sub_15634 * ((t_sample)1)), ((int)1)) * ((int)63)) + ((int)1));
			t_sample selection = round(scale_15631);
			int index_trunc_94 = fixnan(floor(selection));
			bool index_ignore_95 = ((index_trunc_94 >= euclidean_patterns_dim) || (index_trunc_94 < 0));
			// samples euclidean_patterns channel 1;
			m_beats_58 = (index_ignore_95 ? 0 : m_euclidean_patterns_83.read(index_trunc_94, 0));
			int index_trunc_96 = fixnan(floor(selection));
			bool index_ignore_97 = ((index_trunc_96 >= euclidean_patterns_dim) || (index_trunc_96 < 0));
			// samples euclidean_patterns channel 1;
			m_events_57 = ((chan_ignore_98 || index_ignore_97) ? 0 : m_euclidean_patterns_83.read(index_trunc_96, 1));
			int index_trunc_99 = fixnan(floor(selection));
			bool index_ignore_100 = ((index_trunc_99 >= euclidean_patterns_dim) || (index_trunc_99 < 0));
			// samples euclidean_patterns channel 1;
			m_hits_56 = ((chan_ignore_101 || index_ignore_100) ? 0 : m_euclidean_patterns_83.read(index_trunc_99, 2));
			int index_trunc_102 = fixnan(floor(selection));
			bool index_ignore_103 = ((index_trunc_102 >= euclidean_patterns_dim) || (index_trunc_102 < 0));
			// samples euclidean_patterns channel 1;
			m_shift_55 = ((chan_ignore_104 || index_ignore_103) ? 0 : m_euclidean_patterns_83.read(index_trunc_102, 3));
			int change_190 = __m_change_105(gt_191);
			int gt_189 = (change_190 > ((int)0));
			int gen_192 = gt_189;
			t_sample noise_201 = noise();
			int gt_200 = (noise_201 > m_knob4_shiftVar_64);
			t_sample add_197 = (m_history_54 + ((int)1));
			__m_latch_106 = ((gen_192 != 0) ? add_197 : __m_latch_106);
			t_sample latch_196 = __m_latch_106;
			t_sample gen_199 = latch_196;
			t_sample switch_194 = (gen_192 ? ((int)0) : add_197);
			t_sample history_195_next_198 = fixdenorm(switch_194);
			t_sample rdiv_186 = safediv(((int)1), gen_199);
			t_sample add_188 = (m_history_21 + rdiv_186);
			t_sample switch_185 = (gen_192 ? ((int)0) : add_188);
			t_sample wrap_187 = wrap(switch_185, ((int)0), ((int)1));
			t_sample noise_165 = noise();
			t_sample abs_166 = fabs(noise_165);
			t_sample noise_76 = noise();
			t_sample abs_77 = fabs(noise_76);
			t_sample phasor_331 = __m_phasor_107(((int)1), samples_to_seconds);
			t_sample sub_15122 = (phasor_331 - m_history_53);
			t_sample add_15127 = (phasor_331 + m_history_53);
			t_sample div_15123 = safediv(sub_15122, add_15127);
			t_sample abs_15119 = fabs(div_15123);
			int gt_15121 = (abs_15119 > ((t_sample)0.5));
			int change_15125 = __m_change_108(gt_15121);
			int gt_15120 = (change_15125 > ((int)0));
			int gen_75 = gt_15120;
			t_sample history_45_next_15124 = fixdenorm(phasor_331);
			__m_latch_109 = ((gen_75 != 0) ? neg_57 : __m_latch_109);
			t_sample latch_59 = __m_latch_109;
			__m_latch_110 = ((gen_75 != 0) ? m_shape_60 : __m_latch_110);
			t_sample latch_66 = __m_latch_110;
			t_sample rsub_64 = (((int)1) - latch_66);
			__m_latch_111 = ((gen_75 != 0) ? ((int)0) : __m_latch_111);
			int latch_58 = __m_latch_111;
			__m_latch_112 = ((gen_75 != 0) ? m_skew_81 : __m_latch_112);
			t_sample latch_87 = __m_latch_112;
			__m_latch_113 = ((gen_75 != 0) ? m_symmetry_73 : __m_latch_113);
			t_sample latch_62 = __m_latch_113;
			t_sample floor_353 = floor(m_shift_55);
			t_sample floor_354 = floor(m_events_57);
			t_sample floor_355 = floor(m_hits_56);
			t_sample phasor_372 = __m_phasor_116(div_250, samples_to_seconds);
			t_sample switch_180 = (gt_181 ? wrap_187 : phasor_372);
			t_sample mul_358 = (switch_180 * m_beats_58);
			t_sample wrap_357 = wrap(mul_358, ((int)0), ((int)1));
			t_sample sub_15129 = (wrap_357 - m_history_52);
			t_sample add_15137 = (wrap_357 + m_history_52);
			t_sample div_15136 = safediv(sub_15129, add_15137);
			t_sample abs_15131 = fabs(div_15136);
			int gt_15134 = (abs_15131 > ((t_sample)0.5));
			int change_15135 = __m_change_117(gt_15134);
			int gt_15133 = (change_15135 > ((int)0));
			int gen_360 = gt_15133;
			t_sample history_45_next_15130 = fixdenorm(wrap_357);
			__m_latch_118 = ((gen_360 != 0) ? floor_353 : __m_latch_118);
			t_sample latch_361 = __m_latch_118;
			t_sample sub_370 = (mul_358 - latch_361);
			__m_latch_119 = ((gen_360 != 0) ? floor_354 : __m_latch_119);
			t_sample latch_363 = __m_latch_119;
			t_sample abs_345 = fabs(latch_363);
			__m_latch_120 = ((gen_360 != 0) ? floor_355 : __m_latch_120);
			t_sample latch_362 = __m_latch_120;
			t_sample abs_344 = fabs(latch_362);
			t_sample max_343 = ((abs_345 < abs_344) ? abs_344 : abs_345);
			t_sample min_342 = ((abs_344 < abs_345) ? abs_344 : abs_345);
			t_sample div_346 = safediv(min_342, max_343);
			t_sample mul_341 = (latch_363 * latch_362);
			int sign_348 = ((mul_341 > 0) ? 1 : ((mul_341 < 0) ? -1 : 0));
			t_sample mul_347 = (sub_370 * sign_348);
			t_sample wrap_364 = wrap(mul_347, ((int)0), max_343);
			t_sample floor_371 = floor(wrap_364);
			t_sample mul_366 = (floor_371 * div_346);
			t_sample floor_369 = floor(mul_366);
			t_sample div_368 = safediv(floor_369, div_346);
			t_sample ceil_367 = ceil(div_368);
			t_sample sub_365 = (wrap_364 - ceil_367);
			t_sample add_350 = (floor_369 + ((int)1));
			t_sample div_352 = safediv(add_350, div_346);
			t_sample ceil_351 = ceil(div_352);
			t_sample sub_349 = (ceil_351 - ceil_367);
			t_sample div_359 = safediv(sub_365, sub_349);
			t_sample sub_15139 = (div_359 - m_history_51);
			t_sample add_15147 = (div_359 + m_history_51);
			t_sample div_15145 = safediv(sub_15139, add_15147);
			t_sample abs_15140 = fabs(div_15145);
			int gt_15146 = (abs_15140 > ((t_sample)0.5));
			int change_15142 = __m_change_121(gt_15146);
			int gt_15144 = (change_15142 > ((int)0));
			int gen_332 = gt_15144;
			t_sample history_45_next_15143 = fixdenorm(div_359);
			int trig_216 = gen_332;
			__m_latch_122 = ((trig_216 != 0) ? m_history_16 : __m_latch_122);
			t_sample latch_215 = __m_latch_122;
			int not_20 = (!latch_215);
			t_sample out4 = not_20;
			__m_latch_123 = ((trig_216 != 0) ? m_history_20 : __m_latch_123);
			t_sample latch_213 = __m_latch_123;
			int not_19 = (!latch_213);
			t_sample out5 = not_19;
			__m_latch_124 = ((trig_216 != 0) ? m_history_14 : __m_latch_124);
			t_sample latch_206 = __m_latch_124;
			int not_15 = (!latch_206);
			t_sample out9 = not_15;
			__m_latch_125 = ((trig_216 != 0) ? m_history_19 : __m_latch_125);
			t_sample latch_211 = __m_latch_125;
			int not_18 = (!latch_211);
			t_sample out6 = not_18;
			__m_latch_126 = ((trig_216 != 0) ? gt_200 : __m_latch_126);
			int latch_217 = __m_latch_126;
			int not_21 = (!latch_217);
			t_sample out3 = not_21;
			__m_latch_127 = ((trig_216 != 0) ? m_history_17 : __m_latch_127);
			t_sample latch_209 = __m_latch_127;
			int not_17 = (!latch_209);
			t_sample out7 = not_17;
			__m_latch_128 = ((trig_216 != 0) ? m_history_15 : __m_latch_128);
			t_sample latch_208 = __m_latch_128;
			int not_16 = (!latch_208);
			t_sample out8 = not_16;
			int trig_387 = trig_216;
			__m_latch_129 = ((trig_387 != 0) ? m_history_12 : __m_latch_129);
			t_sample latch_382 = __m_latch_129;
			__m_latch_130 = ((trig_387 != 0) ? m_history_11 : __m_latch_130);
			t_sample latch_384 = __m_latch_130;
			__m_latch_131 = ((trig_387 != 0) ? m_history_1 : __m_latch_131);
			t_sample latch_386 = __m_latch_131;
			__m_latch_132 = ((trig_387 != 0) ? m_history_13 : __m_latch_132);
			t_sample latch_380 = __m_latch_132;
			__m_latch_133 = ((trig_387 != 0) ? m_history_10 : __m_latch_133);
			t_sample latch_379 = __m_latch_133;
			__m_latch_134 = ((trig_387 != 0) ? m_history_9 : __m_latch_134);
			t_sample latch_377 = __m_latch_134;
			__m_latch_135 = ((trig_216 != 0) ? m_history_18 : __m_latch_135);
			t_sample latch_204 = __m_latch_135;
			int not_14 = (!latch_204);
			t_sample out10 = not_14;
			t_sample switch_24 = (lt_23 ? ((int)1) : latch_204);
			int neq_243 = (gen_332 != ((int)0));
			int change_242 = __m_change_136(neq_243);
			int gt_241 = (change_242 > ((int)0));
			t_sample mul_247 = ((m_history_7 + gt_241) * t_249);
			t_sample clamp_240 = ((mul_247 <= ((int)0)) ? ((int)0) : ((mul_247 >= ((int)1)) ? ((int)1) : mul_247));
			t_sample mix_15643 = (clamp_240 + (((t_sample)0.97) * (m_history_6 - clamp_240)));
			t_sample mix_245 = mix_15643;
			__m_latch_137 = ((trig_387 != 0) ? m_history_8 : __m_latch_137);
			t_sample latch_375 = __m_latch_137;
			t_sample pitch_13539 = latch_375;
			t_sample mul_333 = (pitch_13539 * ((int)12));
			int int_324 = int(mul_333);
			t_sample mul_326 = (int_324 * div_327);
			t_sample round_329 = round(mul_326);
			t_sample div_325 = safediv(round_329, div_327);
			t_sample add_340 = (div_325 + ((int)36));
			t_sample mtof_339 = mtof(add_340, ((int)440));
			t_sample phasor_177 = __m_phasor_138(mtof_339, samples_to_seconds);
			t_sample saw_4274 = phasor_177;
			t_sample sub_15149 = (saw_4274 - m_history_50);
			t_sample add_15157 = (saw_4274 + m_history_50);
			t_sample div_15156 = safediv(sub_15149, add_15157);
			t_sample abs_15150 = fabs(div_15156);
			int gt_15155 = (abs_15150 > ((t_sample)0.5));
			int change_15152 = __m_change_139(gt_15155);
			int gt_15154 = (change_15152 > ((int)0));
			int gen_164 = gt_15154;
			t_sample history_45_next_15153 = fixdenorm(saw_4274);
			__m_latch_140 = ((gen_164 != 0) ? ((int)-1) : __m_latch_140);
			int latch_155 = __m_latch_140;
			__m_latch_141 = ((gen_164 != 0) ? rsub_138 : __m_latch_141);
			t_sample latch_162 = __m_latch_141;
			t_sample rsub_160 = (((int)1) - latch_162);
			__m_latch_142 = ((gen_164 != 0) ? switch_135 : __m_latch_142);
			t_sample latch_154 = __m_latch_142;
			__m_latch_143 = ((gen_164 != 0) ? ((t_sample)0.5) : __m_latch_143);
			t_sample latch_173 = __m_latch_143;
			__m_latch_144 = ((gen_164 != 0) ? ((int)1) : __m_latch_144);
			int latch_158 = __m_latch_144;
			t_sample saw_5312 = saw_4274;
			t_sample clamp_83 = ((latch_173 <= ((int)0)) ? ((int)0) : ((latch_173 >= ((int)1)) ? ((int)1) : latch_173));
			t_sample triangle_82 = triangle(saw_5312, clamp_83);
			t_sample sub_15647 = (triangle_82 - ((int)0));
			t_sample scale_15644 = ((safepow((sub_15647 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_81 = scale_15644;
			t_sample gen_170 = scale_81;
			t_sample rsub_151 = (((int)1) - gen_170);
			int change_152 = __m_change_145(gen_170);
			int gt_172 = (change_152 > ((int)0));
			t_sample switch_169 = (gt_172 ? gen_170 : rsub_151);
			t_sample sub_15159 = (switch_169 - m_history_49);
			t_sample add_15167 = (switch_169 + m_history_49);
			t_sample div_15166 = safediv(sub_15159, add_15167);
			t_sample abs_15160 = fabs(div_15166);
			int gt_15165 = (abs_15160 > ((t_sample)0.5));
			int change_15162 = __m_change_146(gt_15165);
			int gt_15164 = (change_15162 > ((int)0));
			int gen_168 = gt_15164;
			t_sample history_45_next_15163 = fixdenorm(switch_169);
			__m_latch_147 = ((gen_168 != 0) ? m_history_5 : __m_latch_147);
			t_sample latch_175 = __m_latch_147;
			t_sample sub_15169 = (switch_169 - m_history_48);
			t_sample add_15177 = (switch_169 + m_history_48);
			t_sample div_15174 = safediv(sub_15169, add_15177);
			t_sample abs_15170 = fabs(div_15174);
			int gt_15176 = (abs_15170 > ((t_sample)0.5));
			int change_15172 = __m_change_148(gt_15176);
			int gt_15175 = (change_15172 > ((int)0));
			int gen_147 = gt_15175;
			t_sample history_45_next_15173 = fixdenorm(switch_169);
			__m_latch_149 = ((gen_147 != 0) ? m_history_4 : __m_latch_149);
			t_sample latch_149 = __m_latch_149;
			t_sample mix_15648 = (gt_172 + (latch_154 * (abs_166 - gt_172)));
			t_sample mix_157 = mix_15648;
			int orange_15651 = (((int)1) - latch_155);
			t_sample sub_15652 = (mix_157 - ((int)0));
			t_sample scale_15649 = ((safepow((sub_15652 * ((t_sample)1)), ((int)1)) * orange_15651) + latch_155);
			t_sample scale_156 = scale_15649;
			__m_latch_150 = ((gen_168 != 0) ? scale_156 : __m_latch_150);
			t_sample latch_176 = __m_latch_150;
			__m_latch_151 = ((gen_147 != 0) ? scale_156 : __m_latch_151);
			t_sample latch_150 = __m_latch_151;
			int gte_144 = (latch_149 >= latch_150);
			int and_159 = (gte_144 && latch_158);
			t_sample switch_161 = (and_159 ? latch_162 : rsub_160);
			t_sample clamp_67 = ((switch_169 <= ((int)0)) ? ((int)0) : ((switch_169 >= ((int)1)) ? ((int)1) : switch_169));
			t_sample round_73 = round(clamp_67);
			t_sample triangle_68 = triangle(clamp_67, ((t_sample)0.5));
			t_sample clamp_71 = ((switch_161 <= ((int)0)) ? ((int)0) : ((switch_161 >= ((int)1)) ? ((int)1) : switch_161));
			t_sample sub_15656 = (clamp_71 - ((int)1));
			t_sample scale_15653 = ((safepow((sub_15656 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_69 = scale_15653;
			t_sample clamp_35 = ((triangle_68 <= ((int)0)) ? ((int)0) : ((triangle_68 >= ((int)1)) ? ((int)1) : triangle_68));
			t_sample clamp_29 = ((scale_69 <= ((int)0)) ? ((int)0) : ((scale_69 >= ((int)1)) ? ((int)1) : scale_69));
			int lt_38 = (clamp_29 < ((t_sample)0.5));
			int not_34 = (!lt_38);
			t_sample sub_15660 = (clamp_29 - ((int)1));
			t_sample scale_15657 = ((safepow((sub_15660 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_39 = scale_15657;
			t_sample tan_37 = tan(scale_39);
			t_sample rdiv_36 = safediv(((int)1), tan_37);
			t_sample switch_33 = (lt_38 ? rdiv_36 : tan_37);
			t_sample switch_32 = (lt_38 ? tan_37 : rdiv_36);
			int irange_15662 = (lt_38 - not_34);
			t_sample sub_15664 = (clamp_35 - not_34);
			t_sample scale_15661 = ((safepow(safediv(sub_15664, irange_15662), switch_32) * ((int)-1)) + ((int)1));
			t_sample scale_31 = scale_15661;
			int orange_15667 = (not_34 - lt_38);
			t_sample sub_15668 = (scale_31 - ((int)0));
			t_sample scale_15665 = ((safepow((sub_15668 * ((t_sample)1)), switch_33) * orange_15667) + lt_38);
			t_sample scale_30 = scale_15665;
			t_sample gen_70 = scale_30;
			t_sample mix_15669 = (round_73 + (gen_70 * (clamp_67 - round_73)));
			t_sample mix_72 = mix_15669;
			t_sample gen_163 = mix_72;
			t_sample mix_15670 = (latch_175 + (gen_163 * (latch_176 - latch_175)));
			t_sample mix_167 = mix_15670;
			t_sample out11 = mix_167;
			t_sample clamp_15182 = ((switch_169 <= ((int)0)) ? ((int)0) : ((switch_169 >= ((int)1)) ? ((int)1) : switch_169));
			t_sample clamp_15179 = ((switch_161 <= ((int)0)) ? ((int)0) : ((switch_161 >= ((int)1)) ? ((int)1) : switch_161));
			int lt_15191 = (clamp_15179 < ((t_sample)0.5));
			int not_15187 = (!lt_15191);
			t_sample sub_15674 = (clamp_15179 - ((int)1));
			t_sample scale_15671 = ((safepow((sub_15674 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_15190 = scale_15671;
			t_sample tan_15186 = tan(scale_15190);
			t_sample rdiv_15180 = safediv(((int)1), tan_15186);
			t_sample switch_15185 = (lt_15191 ? rdiv_15180 : tan_15186);
			t_sample switch_15181 = (lt_15191 ? tan_15186 : rdiv_15180);
			int irange_15676 = (lt_15191 - not_15187);
			t_sample sub_15678 = (clamp_15182 - not_15187);
			t_sample scale_15675 = ((safepow(safediv(sub_15678, irange_15676), switch_15181) * ((int)-1)) + ((int)1));
			t_sample scale_15184 = scale_15675;
			int orange_15681 = (not_15187 - lt_15191);
			t_sample sub_15682 = (scale_15184 - ((int)0));
			t_sample scale_15679 = ((safepow((sub_15682 * ((t_sample)1)), switch_15185) * orange_15681) + lt_15191);
			t_sample scale_15183 = scale_15679;
			t_sample gen_145 = scale_15183;
			t_sample mix_15683 = (latch_149 + (gen_145 * (latch_150 - latch_149)));
			t_sample mix_146 = mix_15683;
			t_sample out12 = mix_146;
			t_sample saw_5052 = saw_4274;
			t_sample clamp_15193 = ((latch_87 <= ((int)0)) ? ((int)0) : ((latch_87 >= ((int)1)) ? ((int)1) : latch_87));
			t_sample triangle_15192 = triangle(saw_5052, clamp_15193);
			t_sample sub_15687 = (triangle_15192 - ((int)0));
			t_sample scale_15684 = ((safepow((sub_15687 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_15194 = scale_15684;
			t_sample gen_84 = scale_15194;
			t_sample rsub_55 = (((int)1) - gen_84);
			int change_56 = __m_change_152(gen_84);
			int gt_86 = (change_56 > ((int)0));
			t_sample switch_80 = (gt_86 ? gen_84 : rsub_55);
			t_sample sub_15198 = (switch_80 - m_history_47);
			t_sample add_15203 = (switch_80 + m_history_47);
			t_sample div_15202 = safediv(sub_15198, add_15203);
			t_sample abs_15199 = fabs(div_15202);
			int gt_15197 = (abs_15199 > ((t_sample)0.5));
			int change_15201 = __m_change_153(gt_15197);
			int gt_15196 = (change_15201 > ((int)0));
			int gen_51 = gt_15196;
			t_sample history_45_next_15195 = fixdenorm(switch_80);
			__m_latch_154 = ((gen_51 != 0) ? m_history_3 : __m_latch_154);
			t_sample latch_53 = __m_latch_154;
			t_sample sub_15208 = (switch_80 - m_history_46);
			t_sample add_15213 = (switch_80 + m_history_46);
			t_sample div_15211 = safediv(sub_15208, add_15213);
			t_sample abs_15209 = fabs(div_15211);
			int gt_15207 = (abs_15209 > ((t_sample)0.5));
			int change_15212 = __m_change_155(gt_15207);
			int gt_15206 = (change_15212 > ((int)0));
			int gen_79 = gt_15206;
			t_sample history_45_next_15205 = fixdenorm(switch_80);
			__m_latch_156 = ((gen_79 != 0) ? m_history_2 : __m_latch_156);
			t_sample latch_89 = __m_latch_156;
			t_sample mix_15688 = (gt_86 + (latch_58 * (abs_77 - gt_86)));
			t_sample mix_61 = mix_15688;
			t_sample orange_15691 = (((int)1) - latch_59);
			t_sample sub_15692 = (mix_61 - ((int)0));
			t_sample scale_15689 = ((safepow((sub_15692 * ((t_sample)1)), ((int)1)) * orange_15691) + latch_59);
			t_sample scale_60 = scale_15689;
			__m_latch_157 = ((gen_51 != 0) ? scale_60 : __m_latch_157);
			t_sample latch_54 = __m_latch_157;
			int gte_26 = (latch_53 >= latch_54);
			int and_63 = (gte_26 && latch_62);
			t_sample switch_65 = (and_63 ? latch_66 : rsub_64);
			t_sample clamp_15219 = ((switch_80 <= ((int)0)) ? ((int)0) : ((switch_80 >= ((int)1)) ? ((int)1) : switch_80));
			t_sample clamp_15215 = ((switch_65 <= ((int)0)) ? ((int)0) : ((switch_65 >= ((int)1)) ? ((int)1) : switch_65));
			int lt_15227 = (clamp_15215 < ((t_sample)0.5));
			int not_15223 = (!lt_15227);
			t_sample sub_15696 = (clamp_15215 - ((int)1));
			t_sample scale_15693 = ((safepow((sub_15696 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_15226 = scale_15693;
			t_sample tan_15218 = tan(scale_15226);
			t_sample rdiv_15216 = safediv(((int)1), tan_15218);
			t_sample switch_15222 = (lt_15227 ? rdiv_15216 : tan_15218);
			t_sample switch_15217 = (lt_15227 ? tan_15218 : rdiv_15216);
			int irange_15698 = (lt_15227 - not_15223);
			t_sample sub_15700 = (clamp_15219 - not_15223);
			t_sample scale_15697 = ((safepow(safediv(sub_15700, irange_15698), switch_15217) * ((int)-1)) + ((int)1));
			t_sample scale_15221 = scale_15697;
			int orange_15703 = (not_15223 - lt_15227);
			t_sample sub_15704 = (scale_15221 - ((int)0));
			t_sample scale_15701 = ((safepow((sub_15704 * ((t_sample)1)), switch_15222) * orange_15703) + lt_15227);
			t_sample scale_15220 = scale_15701;
			t_sample gen_40 = scale_15220;
			t_sample mix_15705 = (latch_53 + (gen_40 * (latch_54 - latch_53)));
			t_sample mix_41 = mix_15705;
			t_sample clamp_15232 = ((switch_80 <= ((int)0)) ? ((int)0) : ((switch_80 >= ((int)1)) ? ((int)1) : switch_80));
			t_sample round_15229 = round(clamp_15232);
			t_sample triangle_15239 = triangle(clamp_15232, ((t_sample)0.5));
			t_sample clamp_15231 = ((switch_65 <= ((int)0)) ? ((int)0) : ((switch_65 >= ((int)1)) ? ((int)1) : switch_65));
			t_sample sub_15709 = (clamp_15231 - ((int)1));
			t_sample scale_15706 = ((safepow((sub_15709 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_15247 = scale_15706;
			t_sample clamp_15238 = ((triangle_15239 <= ((int)0)) ? ((int)0) : ((triangle_15239 >= ((int)1)) ? ((int)1) : triangle_15239));
			t_sample clamp_15230 = ((scale_15247 <= ((int)0)) ? ((int)0) : ((scale_15247 >= ((int)1)) ? ((int)1) : scale_15247));
			int lt_15246 = (clamp_15230 < ((t_sample)0.5));
			int not_15242 = (!lt_15246);
			t_sample sub_15713 = (clamp_15230 - ((int)1));
			t_sample scale_15710 = ((safepow((sub_15713 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_15245 = scale_15710;
			t_sample tan_15237 = tan(scale_15245);
			t_sample rdiv_15234 = safediv(((int)1), tan_15237);
			t_sample switch_15241 = (lt_15246 ? rdiv_15234 : tan_15237);
			t_sample switch_15235 = (lt_15246 ? tan_15237 : rdiv_15234);
			int irange_15715 = (lt_15246 - not_15242);
			t_sample sub_15717 = (clamp_15238 - not_15242);
			t_sample scale_15714 = ((safepow(safediv(sub_15717, irange_15715), switch_15235) * ((int)-1)) + ((int)1));
			t_sample scale_15236 = scale_15714;
			int orange_15720 = (not_15242 - lt_15246);
			t_sample sub_15721 = (scale_15236 - ((int)0));
			t_sample scale_15718 = ((safepow((sub_15721 * ((t_sample)1)), switch_15241) * orange_15720) + lt_15246);
			t_sample scale_15240 = scale_15718;
			t_sample gen_15228 = scale_15240;
			t_sample mix_15722 = (round_15229 + (gen_15228 * (clamp_15232 - round_15229)));
			t_sample mix_15233 = mix_15722;
			t_sample gen_74 = mix_15233;
			__m_latch_158 = ((gen_79 != 0) ? scale_60 : __m_latch_158);
			t_sample latch_90 = __m_latch_158;
			t_sample mix_15723 = (latch_89 + (gen_74 * (latch_90 - latch_89)));
			t_sample mix_78 = mix_15723;
			__m_latch_159 = ((trig_387 != 0) ? mix_78 : __m_latch_159);
			t_sample latch_388 = __m_latch_159;
			t_sample pitch_12359 = pitch_13539;
			t_sample mul_9 = (pitch_12359 * ((int)12));
			int int_5 = int(mul_9);
			int mul_7 = (int_5 * ((int)1));
			int round_8 = round(mul_7);
			t_sample div_6 = (round_8 * ((t_sample)1));
			t_sample add_11 = (div_6 + ((int)60));
			t_sample mtof_10 = mtof(add_11, ((int)440));
			__m_cycle_160.freq(mtof_10);
			t_sample cycle_3 = __m_cycle_160(__sinedata);
			t_sample cycleindex_4 = __m_cycle_160.phase();
			t_sample mix_15724 = (((int)1) + (m_cv_75 * (cycle_3 - ((int)1))));
			t_sample mix_2 = mix_15724;
			t_sample floor_226 = floor(mix_167);
			t_sample sub_218 = (mix_167 - floor_226);
			t_sample add_225 = (floor_226 + ((int)1));
			t_sample mul_221 = (mtof_339 * ((t_sample)6.2831853071796));
			t_sample mul_223 = (floor_226 * mul_221);
			t_sample sin_220 = sin((mix_2 + mul_223));
			t_sample mul_222 = (add_225 * mul_221);
			t_sample sin_219 = sin((mix_2 + mul_222));
			t_sample mix_15725 = (sin_220 + (sub_218 * (sin_219 - sin_220)));
			t_sample mix_224 = mix_15725;
			t_sample gen_227 = mix_224;
			t_sample mul_337 = (gen_227 * mix_245);
			t_sample mul_25 = (mul_337 * switch_24);
			t_sample mul_335 = (mul_25 * ((int)2));
			t_sample tanh_336 = tanh(mul_335);
			t_sample div_334 = (tanh_336 * ((t_sample)0.5));
			t_sample mul_122 = (m_history_45 * gen_115);
			t_sample mul_123 = (m_history_43 * ((int)0));
			t_sample mul_124 = (div_334 * gen_113);
			t_sample mul_125 = (m_history_44 * gen_117);
			t_sample mul_126 = (m_history_42 * gen_116);
			t_sample sub_119 = (((mul_124 + mul_123) + mul_122) - (mul_126 + mul_125));
			t_sample gen_133 = sub_119;
			t_sample history_120_next_129 = fixdenorm(m_history_43);
			t_sample history_127_next_130 = fixdenorm(m_history_42);
			t_sample history_121_next_131 = fixdenorm(div_334);
			t_sample history_128_next_132 = fixdenorm(sub_119);
			t_sample clamp_118 = ((gen_133 <= min_161) ? min_161 : ((gen_133 >= ((int)1)) ? ((int)1) : gen_133));
			t_sample mul_9257 = (clamp_118 * ((t_sample)0.015));
			t_sample tap_265 = m_delay_41.read_step(((int)1557));
			t_sample gen_9228 = tap_265;
			t_sample mul_263 = (tap_265 * ((t_sample)0.7));
			t_sample mul_261 = (m_history_40 * ((t_sample)0.3));
			t_sample add_262 = (mul_263 + mul_261);
			t_sample mul_259 = (add_262 * ((t_sample)0.2));
			t_sample add_266 = (mul_9257 + mul_259);
			t_sample history_260_next_267 = fixdenorm(add_262);
			t_sample tap_9260 = m_delay_39.read_step(((int)1617));
			t_sample gen_9256 = tap_9260;
			t_sample mul_9266 = (tap_9260 * ((t_sample)0.7));
			t_sample mul_9263 = (m_history_38 * ((t_sample)0.3));
			t_sample add_9264 = (mul_9266 + mul_9263);
			t_sample mul_9267 = (add_9264 * ((t_sample)0.2));
			t_sample add_9261 = (mul_9257 + mul_9267);
			t_sample history_260_next_9262 = fixdenorm(add_9264);
			t_sample tap_9272 = m_delay_37.read_step(((int)1491));
			t_sample gen_9227 = tap_9272;
			t_sample mul_9273 = (tap_9272 * ((t_sample)0.7));
			t_sample mul_9277 = (m_history_36 * ((t_sample)0.3));
			t_sample add_9276 = (mul_9273 + mul_9277);
			t_sample mul_9279 = (add_9276 * ((t_sample)0.2));
			t_sample add_9274 = (mul_9257 + mul_9279);
			t_sample history_260_next_9275 = fixdenorm(add_9276);
			t_sample tap_9286 = m_delay_35.read_step(((int)1422));
			t_sample gen_9226 = tap_9286;
			t_sample mul_9282 = (tap_9286 * ((t_sample)0.7));
			t_sample mul_9288 = (m_history_34 * ((t_sample)0.3));
			t_sample add_9283 = (mul_9282 + mul_9288);
			t_sample mul_9289 = (add_9283 * ((t_sample)0.2));
			t_sample add_9287 = (mul_9257 + mul_9289);
			t_sample history_260_next_9290 = fixdenorm(add_9283);
			t_sample tap_9299 = m_delay_33.read_step(((int)1356));
			t_sample gen_9225 = tap_9299;
			t_sample mul_9294 = (tap_9299 * ((t_sample)0.7));
			t_sample mul_9302 = (m_history_32 * ((t_sample)0.3));
			t_sample add_9296 = (mul_9294 + mul_9302);
			t_sample mul_9303 = (add_9296 * ((t_sample)0.2));
			t_sample add_9300 = (mul_9257 + mul_9303);
			t_sample history_260_next_9301 = fixdenorm(add_9296);
			t_sample tap_9311 = m_delay_31.read_step(((int)1277));
			t_sample gen_9224 = tap_9311;
			t_sample mul_9306 = (tap_9311 * ((t_sample)0.7));
			t_sample mul_9315 = (m_history_30 * ((t_sample)0.3));
			t_sample add_9307 = (mul_9306 + mul_9315);
			t_sample mul_9313 = (add_9307 * ((t_sample)0.2));
			t_sample add_9312 = (mul_9257 + mul_9313);
			t_sample history_260_next_9308 = fixdenorm(add_9307);
			t_sample tap_9322 = m_delay_29.read_step(((int)1188));
			t_sample gen_9223 = tap_9322;
			t_sample mul_9318 = (tap_9322 * ((t_sample)0.7));
			t_sample mul_9326 = (m_history_28 * ((t_sample)0.3));
			t_sample add_9319 = (mul_9318 + mul_9326);
			t_sample mul_9324 = (add_9319 * ((t_sample)0.2));
			t_sample add_9323 = (mul_9257 + mul_9324);
			t_sample history_260_next_9325 = fixdenorm(add_9319);
			t_sample tap_9335 = m_delay_27.read_step(((int)1116));
			t_sample gen_9222 = tap_9335;
			t_sample mul_9330 = (tap_9335 * ((t_sample)0.7));
			t_sample mul_9333 = (m_history_26 * ((t_sample)0.3));
			t_sample add_9331 = (mul_9330 + mul_9333);
			t_sample mul_9337 = (add_9331 * ((t_sample)0.2));
			t_sample add_9336 = (mul_9257 + mul_9337);
			t_sample history_260_next_9339 = fixdenorm(add_9331);
			t_sample add_9245 = ((((((((gen_9222 + gen_9223) + gen_9224) + gen_9225) + gen_9226) + gen_9227) + gen_9256) + gen_9228) + ((int)0));
			t_sample tap_256 = m_delay_25.read_step(((int)556));
			t_sample sub_252 = (add_9245 - tap_256);
			t_sample mul_254 = (tap_256 * ((t_sample)0.45));
			t_sample add_253 = (add_9245 + mul_254);
			t_sample tap_9342 = m_delay_24.read_step(((int)441));
			t_sample sub_9345 = (sub_252 - tap_9342);
			t_sample mul_9343 = (tap_9342 * ((t_sample)0.45));
			t_sample add_9344 = (sub_252 + mul_9343);
			t_sample tap_9348 = m_delay_23.read_step(((int)341));
			t_sample sub_9352 = (sub_9345 - tap_9348);
			t_sample mul_9350 = (tap_9348 * ((t_sample)0.45));
			t_sample add_9351 = (sub_9345 + mul_9350);
			t_sample tap_9354 = m_delay_22.read_step(((int)225));
			t_sample sub_9358 = (sub_9352 - tap_9354);
			t_sample mul_9356 = (tap_9354 * ((t_sample)0.45));
			t_sample add_9357 = (sub_9352 + mul_9356);
			t_sample mix_15726 = (((t_sample)0.7) + (clamp_118 * (sub_9358 - ((t_sample)0.7))));
			t_sample add_178 = (mix_15726 + in2);
			t_sample out2 = add_178;
			t_sample add_179 = (mix_15726 + in1);
			t_sample out1 = add_179;
			t_sample history_184_next_15248 = fixdenorm(wrap_187);
			t_sample history_212_next_15249 = fixdenorm(latch_215);
			t_sample history_210_next_15250 = fixdenorm(latch_213);
			t_sample history_203_next_15251 = fixdenorm(latch_206);
			t_sample history_202_next_15252 = fixdenorm(latch_211);
			t_sample history_214_next_15253 = fixdenorm(latch_217);
			t_sample history_207_next_15254 = fixdenorm(latch_209);
			t_sample history_205_next_15255 = fixdenorm(latch_208);
			t_sample history_373_next_15256 = fixdenorm(latch_382);
			t_sample history_381_next_15257 = fixdenorm(latch_384);
			t_sample history_383_next_15258 = fixdenorm(latch_386);
			t_sample history_378_next_15259 = fixdenorm(latch_380);
			t_sample history_376_next_15260 = fixdenorm(latch_379);
			t_sample history_374_next_15261 = fixdenorm(latch_377);
			t_sample history_246_next_15262 = fixdenorm(clamp_240);
			t_sample history_244_next_15263 = fixdenorm(mix_245);
			t_sample history_174_next_15264 = fixdenorm(mix_167);
			t_sample history_148_next_15265 = fixdenorm(mix_146);
			t_sample history_52_next_15266 = fixdenorm(mix_41);
			t_sample history_88_next_15267 = fixdenorm(mix_78);
			t_sample history_385_next_15268 = fixdenorm(latch_388);
			m_history_59 = history_45_next_50;
			m_history_54 = history_195_next_198;
			m_history_53 = history_45_next_15124;
			m_history_52 = history_45_next_15130;
			m_history_51 = history_45_next_15143;
			m_history_50 = history_45_next_15153;
			m_history_49 = history_45_next_15163;
			m_history_48 = history_45_next_15173;
			m_history_47 = history_45_next_15195;
			m_history_46 = history_45_next_15205;
			m_history_45 = history_120_next_129;
			m_history_42 = history_128_next_132;
			m_history_43 = history_121_next_131;
			m_history_44 = history_127_next_130;
			m_delay_41.write(add_266);
			m_delay_22.write(add_9357);
			m_delay_23.write(add_9351);
			m_delay_24.write(add_9344);
			m_delay_25.write(add_253);
			m_history_26 = history_260_next_9339;
			m_delay_27.write(add_9336);
			m_history_28 = history_260_next_9325;
			m_delay_29.write(add_9323);
			m_history_30 = history_260_next_9308;
			m_delay_31.write(add_9312);
			m_history_32 = history_260_next_9301;
			m_delay_33.write(add_9300);
			m_history_34 = history_260_next_9290;
			m_delay_35.write(add_9287);
			m_history_36 = history_260_next_9275;
			m_delay_37.write(add_9274);
			m_history_38 = history_260_next_9262;
			m_delay_39.write(add_9261);
			m_history_40 = history_260_next_267;
			m_history_21 = history_184_next_15248;
			m_history_20 = history_212_next_15249;
			m_history_19 = history_210_next_15250;
			m_history_18 = history_203_next_15251;
			m_history_17 = history_202_next_15252;
			m_history_16 = history_214_next_15253;
			m_history_15 = history_207_next_15254;
			m_history_14 = history_205_next_15255;
			m_history_13 = history_373_next_15256;
			m_history_12 = history_381_next_15257;
			m_history_11 = history_383_next_15258;
			m_history_10 = history_378_next_15259;
			m_history_9 = history_376_next_15260;
			m_history_8 = history_374_next_15261;
			m_history_7 = history_246_next_15262;
			m_history_6 = history_244_next_15263;
			m_history_5 = history_174_next_15264;
			m_history_4 = history_148_next_15265;
			m_history_3 = history_52_next_15266;
			m_history_2 = history_88_next_15267;
			m_history_1 = history_385_next_15268;
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
	inline void set_shape(t_param _value) {
		m_shape_60 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_61 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_62 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_63 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_shiftVar(t_param _value) {
		m_knob4_shiftVar_64 = (_value < 0 ? 0 : (_value > 0.5 ? 0.5 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_65 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_euclidP(t_param _value) {
		m_knob3_euclidP_66 = (_value < 0 ? 0 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_67 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_68 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_timbre(t_param _value) {
		m_knob5_timbre_69 = (_value < 0.01 ? 0.01 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_knob1_bpm(t_param _value) {
		m_knob1_bpm_70 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_71 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_random(t_param _value) {
		m_random_72 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_symmetry(t_param _value) {
		m_symmetry_73 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_74 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cv1(t_param _value) {
		m_cv_75 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_envelopeLength(t_param _value) {
		m_knob2_envelopeLength_76 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_filter(t_param _value) {
		m_knob6_filter_77 = (_value < 100 ? 100 : (_value > 1400 ? 1400 : _value));
	};
	inline void set_numer(t_param _value) {
		m_numer_78 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_79 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_denom(t_param _value) {
		m_denom_80 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_skew(t_param _value) {
		m_skew_81 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bipolar(t_param _value) {
		m_bipolar_82 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_euclidean_patterns(void * _value) {
		m_euclidean_patterns_83.setbuffer(_value);
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
		case 1: self->set_cv1(value); break;
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
		case 1: *value = self->m_cv_75; break;
		case 2: *value = self->m_denom_80; break;
		
		case 4: *value = self->m_gatein_74; break;
		case 5: *value = self->m_knob1_bpm_70; break;
		case 6: *value = self->m_knob2_envelopeLength_76; break;
		case 7: *value = self->m_knob3_euclidP_66; break;
		case 8: *value = self->m_knob4_shiftVar_64; break;
		case 9: *value = self->m_knob5_timbre_69; break;
		case 10: *value = self->m_knob6_filter_77; break;
		case 11: *value = self->m_numer_78; break;
		case 12: *value = self->m_random_72; break;
		case 13: *value = self->m_shape_60; break;
		case 14: *value = self->m_skew_81; break;
		case 15: *value = self->m_sw_68; break;
		case 16: *value = self->m_sw_65; break;
		case 17: *value = self->m_sw_61; break;
		case 18: *value = self->m_sw_71; break;
		case 19: *value = self->m_sw_79; break;
		case 20: *value = self->m_sw_62; break;
		case 21: *value = self->m_sw_63; break;
		case 22: *value = self->m_sw_67; break;
		case 23: *value = self->m_symmetry_73; break;
		
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
	// initialize parameter 1 ("m_cv_75")
	pi = self->__commonstate.params + 1;
	pi->name = "cv1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv_75;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_denom_80")
	pi = self->__commonstate.params + 2;
	pi->name = "denom";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_denom_80;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 24;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_euclidean_patterns_83")
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
	// initialize parameter 4 ("m_gatein_74")
	pi = self->__commonstate.params + 4;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_74;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob1_bpm_70")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1_bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_bpm_70;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob2_envelopeLength_76")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2_envelopeLength";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_envelopeLength_76;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob3_euclidP_66")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_euclidP";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_euclidP_66;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_shiftVar_64")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_shiftVar";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_shiftVar_64;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_timbre_69")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_timbre";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_timbre_69;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_filter_77")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_filter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_filter_77;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 100;
	pi->outputmax = 1400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_numer_78")
	pi = self->__commonstate.params + 11;
	pi->name = "numer";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_numer_78;
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
	// initialize parameter 13 ("m_shape_60")
	pi = self->__commonstate.params + 13;
	pi->name = "shape";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_shape_60;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_skew_81")
	pi = self->__commonstate.params + 14;
	pi->name = "skew";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_skew_81;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_68")
	pi = self->__commonstate.params + 15;
	pi->name = "sw1";
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
	// initialize parameter 16 ("m_sw_65")
	pi = self->__commonstate.params + 16;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_65;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_61")
	pi = self->__commonstate.params + 17;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_61;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_71")
	pi = self->__commonstate.params + 18;
	pi->name = "sw4";
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
	// initialize parameter 19 ("m_sw_79")
	pi = self->__commonstate.params + 19;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_79;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_62")
	pi = self->__commonstate.params + 20;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_62;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_sw_63")
	pi = self->__commonstate.params + 21;
	pi->name = "sw7";
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
	// initialize parameter 22 ("m_sw_67")
	pi = self->__commonstate.params + 22;
	pi->name = "sw8";
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
	// initialize parameter 23 ("m_symmetry_73")
	pi = self->__commonstate.params + 23;
	pi->name = "symmetry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_symmetry_73;
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
