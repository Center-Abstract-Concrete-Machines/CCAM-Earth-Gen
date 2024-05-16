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
	Change __m_change_90;
	Change __m_change_140;
	Change __m_change_143;
	Change __m_change_125;
	Change __m_change_88;
	Change __m_change_112;
	Change __m_change_144;
	Change __m_change_121;
	Change __m_change_157;
	Change __m_change_159;
	Change __m_change_146;
	Change __m_change_156;
	Change __m_change_151;
	Data m_euclidean_patterns_87;
	Delay m_delay_33;
	Delay m_delay_22;
	Delay m_delay_23;
	Delay m_delay_25;
	Delay m_delay_35;
	Delay m_delay_24;
	Delay m_delay_37;
	Delay m_delay_27;
	Delay m_delay_39;
	Delay m_delay_31;
	Delay m_delay_29;
	Delay m_delay_41;
	Phasor __m_phasor_142;
	Phasor __m_phasor_111;
	Phasor __m_phasor_89;
	Phasor __m_phasor_120;
	SineCycle __m_cycle_164;
	SineData __sinedata;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample __m_latch_126;
	t_sample m_history_32;
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
	t_sample __m_latch_117;
	t_sample m_history_13;
	t_sample __m_latch_110;
	t_sample elapsed;
	t_sample __m_latch_91;
	t_sample m_history_10;
	t_sample m_history_12;
	t_sample __m_latch_113;
	t_sample __m_latch_116;
	t_sample m_history_11;
	t_sample __m_latch_115;
	t_sample __m_latch_114;
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
	t_sample m_history_14;
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
	t_sample m_history_30;
	t_sample m_history_15;
	t_sample m_history_16;
	t_sample m_history_51;
	t_sample m_history_52;
	t_sample m_history_50;
	t_sample m_history_48;
	t_sample m_history_49;
	t_sample m_history_47;
	t_sample m_history_53;
	t_sample m_shift_55;
	t_sample m_beats_58;
	t_sample m_history_54;
	t_sample m_events_57;
	t_sample m_hits_56;
	t_sample m_history_59;
	t_sample m_history_46;
	t_sample m_history_44;
	t_sample m_history_36;
	t_sample m_history_21;
	t_sample m_history_26;
	t_sample m_history_28;
	t_sample m_history_34;
	t_sample m_history_45;
	t_sample m_history_38;
	t_sample m_history_40;
	t_sample m_history_43;
	t_sample m_history_20;
	t_sample m_history_42;
	t_sample m_history_19;
	t_sample samples_to_seconds;
	t_sample m_random_60;
	t_sample m_envelope_length_62;
	t_sample m_filter_80;
	t_sample m_sw_81;
	t_sample m_skew_79;
	t_sample m_damp_77;
	t_sample m_sw_78;
	t_sample m_timbre_76;
	t_sample m_symmetry_82;
	t_sample m_denom_84;
	t_sample m_history_17;
	t_sample m_fb_83;
	t_sample m_sw_86;
	t_sample m_sw_85;
	t_sample m_shift_var_61;
	t_sample m_numer_75;
	t_sample m_history_18;
	t_sample m_fb_65;
	t_sample m_spread_66;
	t_sample m_euclid_p_64;
	t_sample m_sw_63;
	t_sample m_sw_74;
	t_sample m_bipolar_67;
	t_sample m_cv_69;
	t_sample m_bpm_72;
	t_sample m_sw_68;
	t_sample m_sw_71;
	t_sample m_gatein_70;
	t_sample m_shape_73;
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
		m_random_60 = ((int)0);
		m_shift_var_61 = ((int)1);
		m_envelope_length_62 = ((int)0);
		m_sw_63 = ((int)0);
		m_euclid_p_64 = ((int)0);
		m_fb_65 = ((t_sample)0.9);
		m_spread_66 = ((int)0);
		m_bipolar_67 = ((int)0);
		m_sw_68 = ((int)0);
		m_cv_69 = ((int)0);
		m_gatein_70 = ((int)0);
		m_sw_71 = ((int)0);
		m_bpm_72 = ((int)0);
		m_shape_73 = ((t_sample)0.5);
		m_sw_74 = ((int)0);
		m_numer_75 = ((int)5);
		m_timbre_76 = ((int)0);
		m_damp_77 = ((t_sample)0.7);
		m_sw_78 = ((int)0);
		m_skew_79 = ((t_sample)0.5);
		m_filter_80 = ((int)220);
		m_sw_81 = ((int)0);
		m_symmetry_82 = ((int)0);
		m_fb_83 = ((t_sample)0.2);
		m_denom_84 = ((int)12);
		m_sw_85 = ((int)0);
		m_sw_86 = ((int)0);
		m_euclidean_patterns_87.reset("euclidean_patterns", ((int)64), ((int)4));
		__m_change_88.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_89.reset(0);
		__m_change_90.reset(0);
		__m_latch_91 = 0;
		elapsed = 0;
		__m_latch_110 = 11025;
		__m_phasor_111.reset(0);
		__m_change_112.reset(0);
		__m_latch_113 = 0;
		__m_latch_114 = 0;
		__m_latch_115 = 0;
		__m_latch_116 = 0;
		__m_latch_117 = 0;
		__m_phasor_120.reset(0);
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
		int gt_72844 = (m_gatein_70 > ((int)0));
		samples_to_seconds = (1 / samplerate);
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		int euclidean_patterns_dim = m_euclidean_patterns_87.dim;
		int euclidean_patterns_channels = m_euclidean_patterns_87.channels;
		bool chan_ignore_103 = ((1 < 0) || (1 >= euclidean_patterns_channels));
		bool chan_ignore_106 = ((2 < 0) || (2 >= euclidean_patterns_channels));
		bool chan_ignore_109 = ((3 < 0) || (3 >= euclidean_patterns_channels));
		t_sample mul_72974 = (m_fb_65 * ((t_sample)0.5));
		t_sample rsub_72791 = (((int)1) - m_timbre_76);
		t_sample neg_72710 = (-m_bipolar_67);
		t_sample add_72960 = (((int)225) + m_spread_66);
		t_sample mul_72901 = (samplerate * m_envelope_length_62);
		t_sample t_72902 = exp(safediv(-6.9077552789821, mul_72901));
		t_sample add_72962 = (((int)341) + m_spread_66);
		int min_118 = ((-samplerate) * ((t_sample)0.5));
		int max_119 = (samplerate * ((t_sample)0.5));
		t_sample clamp_72764 = ((m_filter_80 <= min_118) ? min_118 : ((m_filter_80 >= max_119) ? max_119 : m_filter_80));
		t_sample abs_72763 = fabs(clamp_72764);
		t_sample mul_72762 = (abs_72763 * safediv(6.2831853071796, samplerate));
		t_sample sin_72759 = sin(mul_72762);
		t_sample mul_72758 = (sin_72759 * ((t_sample)0.5));
		t_sample div_72757 = (mul_72758 * ((t_sample)0.5));
		t_sample neg_72748 = (-div_72757);
		t_sample rsub_72749 = (((int)1) - div_72757);
		t_sample add_72756 = (div_72757 + ((int)1));
		t_sample rdiv_72755 = safediv(((int)1), add_72756);
		t_sample mul_72754 = (div_72757 * rdiv_72755);
		t_sample gen_72766 = mul_72754;
		t_sample mul_72753 = (neg_72748 * rdiv_72755);
		t_sample gen_72768 = mul_72753;
		t_sample mul_72751 = (rsub_72749 * rdiv_72755);
		t_sample gen_72770 = mul_72751;
		t_sample cos_72761 = cos(mul_72762);
		t_sample neg_72760 = (-cos_72761);
		t_sample mul_72750 = (neg_72760 * ((int)2));
		t_sample mul_72752 = (mul_72750 * rdiv_72755);
		t_sample gen_72769 = mul_72752;
		int gt_72789 = (m_timbre_76 > ((t_sample)0.5));
		t_sample sub_79366 = (m_timbre_76 - ((int)0));
		t_sample scale_79363 = ((safepow((sub_79366 * ((t_sample)1)), ((int)1)) * ((t_sample)0.3)) + ((int)0));
		t_sample scale_72787 = scale_79363;
		t_sample switch_72788 = (gt_72789 ? scale_72787 : ((int)0));
		t_sample add_72972 = (((int)441) + m_spread_66);
		t_sample add_72958 = (((int)556) + m_spread_66);
		t_sample damp_72947 = m_damp_77;
		t_sample damp_72949 = damp_72947;
		t_sample damp_72948 = damp_72947;
		t_sample damp_72946 = damp_72947;
		t_sample damp_72945 = damp_72947;
		t_sample damp_72944 = damp_72947;
		t_sample damp_72943 = damp_72947;
		t_sample damp_72942 = damp_72947;
		int int_72983 = int(m_numer_75);
		int int_72981 = int(m_denom_84);
		t_sample div_72980 = safediv(int_72983, int_72981);
		t_sample add_72971 = (((int)1116) + m_spread_66);
		t_sample add_72970 = (((int)1188) + m_spread_66);
		t_sample add_72969 = (((int)1277) + m_spread_66);
		t_sample add_72968 = (((int)1356) + m_spread_66);
		t_sample add_72967 = (((int)1422) + m_spread_66);
		t_sample add_72966 = (((int)1491) + m_spread_66);
		t_sample add_72965 = (((int)1557) + m_spread_66);
		t_sample add_72964 = (((int)1617) + m_spread_66);
		int lt_72685 = (m_shift_var_61 < ((t_sample)0.1));
		int gt_72834 = (m_bpm_72 > ((t_sample)0.99));
		t_sample sub_79370 = (m_bpm_72 - ((int)0));
		t_sample scale_79367 = ((safepow((sub_79370 * ((t_sample)1)), ((int)1)) * ((int)160)) + ((int)40));
		t_sample scale_73797 = scale_79367;
		t_sample div_72903 = (scale_73797 * ((t_sample)0.016666666666667));
		int min_165 = (-1);
		t_sample rsub_72911 = (((int)1) - damp_72949);
		t_sample rsub_73940 = (((int)1) - damp_72948);
		t_sample rsub_73952 = (((int)1) - damp_72947);
		t_sample rsub_73964 = (((int)1) - damp_72946);
		t_sample rsub_73976 = (((int)1) - damp_72945);
		t_sample rsub_73984 = (((int)1) - damp_72944);
		t_sample rsub_73996 = (((int)1) - damp_72943);
		t_sample rsub_74008 = (((int)1) - damp_72942);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			int change_72843 = __m_change_88(gt_72844);
			int gt_72842 = (change_72843 > ((int)0));
			int gen_72845 = gt_72842;
			t_sample phasor_72882 = __m_phasor_89(((int)10), samples_to_seconds);
			t_sample sub_197 = (phasor_72882 - m_history_59);
			t_sample add_198 = (phasor_72882 + m_history_59);
			t_sample div_196 = safediv(sub_197, add_198);
			t_sample abs_195 = fabs(div_196);
			int gt_193 = (abs_195 > ((t_sample)0.5));
			int change_192 = __m_change_90(gt_193);
			int gt_191 = (change_192 > ((int)0));
			int gen_72881 = gt_191;
			t_sample history_194_next_199 = fixdenorm(phasor_72882);
			__m_latch_91 = ((gen_72881 != 0) ? m_euclid_p_64 : __m_latch_91);
			t_sample latch_72883 = __m_latch_91;
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				int euclidean_patterns_dim = m_euclidean_patterns_87.dim;
				int euclidean_patterns_channels = m_euclidean_patterns_87.channels;
				while ((i < euclidean_patterns_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample n2 = noise();
					t_sample n3 = noise();
					t_sample sub_79354 = (n2 - (-1));
					t_sample scale_79351 = ((safepow((sub_79354 * ((t_sample)0.5)), ((int)1)) * ((int)0)) + ((int)16));
					t_sample b = round(scale_79351);
					t_sample sub_79358 = (n3 - (-1));
					t_sample scale_79355 = ((safepow((sub_79358 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)1));
					t_sample c = round(scale_79355);
					bool index_ignore_92 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!index_ignore_92)) {
						m_euclidean_patterns_87.write(((int)8), i, 0);
						
					};
					bool chan_ignore_93 = ((((int)1) < 0) || (((int)1) >= euclidean_patterns_channels));
					bool index_ignore_94 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_93 || index_ignore_94))) {
						m_euclidean_patterns_87.write(b, i, ((int)1));
						
					};
					bool chan_ignore_95 = ((((int)2) < 0) || (((int)2) >= euclidean_patterns_channels));
					bool index_ignore_96 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_95 || index_ignore_96))) {
						m_euclidean_patterns_87.write(c, i, ((int)2));
						
					};
					bool chan_ignore_97 = ((((int)3) < 0) || (((int)3) >= euclidean_patterns_channels));
					bool index_ignore_98 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_97 || index_ignore_98))) {
						m_euclidean_patterns_87.write(((int)0), i, ((int)3));
						
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
			t_sample sub_79362 = (latch_72883 - ((int)0));
			t_sample scale_79359 = ((safepow((sub_79362 * ((t_sample)1)), ((int)1)) * ((int)63)) + ((int)1));
			t_sample selection = round(scale_79359);
			int index_trunc_99 = fixnan(floor(selection));
			bool index_ignore_100 = ((index_trunc_99 >= euclidean_patterns_dim) || (index_trunc_99 < 0));
			// samples euclidean_patterns channel 1;
			m_beats_58 = (index_ignore_100 ? 0 : m_euclidean_patterns_87.read(index_trunc_99, 0));
			int index_trunc_101 = fixnan(floor(selection));
			bool index_ignore_102 = ((index_trunc_101 >= euclidean_patterns_dim) || (index_trunc_101 < 0));
			// samples euclidean_patterns channel 1;
			m_events_57 = ((chan_ignore_103 || index_ignore_102) ? 0 : m_euclidean_patterns_87.read(index_trunc_101, 1));
			int index_trunc_104 = fixnan(floor(selection));
			bool index_ignore_105 = ((index_trunc_104 >= euclidean_patterns_dim) || (index_trunc_104 < 0));
			// samples euclidean_patterns channel 1;
			m_hits_56 = ((chan_ignore_106 || index_ignore_105) ? 0 : m_euclidean_patterns_87.read(index_trunc_104, 2));
			int index_trunc_107 = fixnan(floor(selection));
			bool index_ignore_108 = ((index_trunc_107 >= euclidean_patterns_dim) || (index_trunc_107 < 0));
			// samples euclidean_patterns channel 1;
			m_shift_55 = ((chan_ignore_109 || index_ignore_108) ? 0 : m_euclidean_patterns_87.read(index_trunc_107, 3));
			t_sample noise_72854 = noise();
			int gt_72853 = (noise_72854 > m_shift_var_61);
			t_sample add_72850 = (m_history_54 + ((int)1));
			t_sample switch_72847 = (gen_72845 ? ((int)0) : add_72850);
			__m_latch_110 = ((gen_72845 != 0) ? add_72850 : __m_latch_110);
			t_sample latch_72849 = __m_latch_110;
			t_sample gen_72852 = latch_72849;
			t_sample history_72848_next_72851 = fixdenorm(switch_72847);
			t_sample rdiv_72839 = safediv(((int)1), gen_72852);
			t_sample add_72841 = (m_history_21 + rdiv_72839);
			t_sample switch_72838 = (gen_72845 ? ((int)0) : add_72841);
			t_sample wrap_72840 = wrap(switch_72838, ((int)0), ((int)1));
			t_sample noise_72818 = noise();
			t_sample abs_72819 = fabs(noise_72818);
			t_sample noise_72729 = noise();
			t_sample abs_72730 = fabs(noise_72729);
			t_sample phasor_72984 = __m_phasor_111(((int)1), samples_to_seconds);
			t_sample sub_73809 = (phasor_72984 - m_history_53);
			t_sample add_73808 = (phasor_72984 + m_history_53);
			t_sample div_73812 = safediv(sub_73809, add_73808);
			t_sample abs_73813 = fabs(div_73812);
			int gt_73807 = (abs_73813 > ((t_sample)0.5));
			int change_73806 = __m_change_112(gt_73807);
			int gt_73810 = (change_73806 > ((int)0));
			int gen_72728 = gt_73810;
			t_sample history_194_next_73805 = fixdenorm(phasor_72984);
			__m_latch_113 = ((gen_72728 != 0) ? neg_72710 : __m_latch_113);
			t_sample latch_72712 = __m_latch_113;
			__m_latch_114 = ((gen_72728 != 0) ? m_shape_73 : __m_latch_114);
			t_sample latch_72719 = __m_latch_114;
			t_sample rsub_72717 = (((int)1) - latch_72719);
			__m_latch_115 = ((gen_72728 != 0) ? ((int)0) : __m_latch_115);
			int latch_72711 = __m_latch_115;
			__m_latch_116 = ((gen_72728 != 0) ? m_skew_79 : __m_latch_116);
			t_sample latch_72740 = __m_latch_116;
			__m_latch_117 = ((gen_72728 != 0) ? m_symmetry_82 : __m_latch_117);
			t_sample latch_72715 = __m_latch_117;
			t_sample floor_73006 = floor(m_shift_55);
			t_sample floor_73007 = floor(m_events_57);
			t_sample floor_73008 = floor(m_hits_56);
			t_sample phasor_73025 = __m_phasor_120(div_72903, samples_to_seconds);
			t_sample switch_72833 = (gt_72834 ? wrap_72840 : phasor_73025);
			t_sample mul_73011 = (switch_72833 * m_beats_58);
			t_sample wrap_73010 = wrap(mul_73011, ((int)0), ((int)1));
			t_sample sub_73822 = (wrap_73010 - m_history_52);
			t_sample add_73819 = (wrap_73010 + m_history_52);
			t_sample div_73818 = safediv(sub_73822, add_73819);
			t_sample abs_73821 = fabs(div_73818);
			int gt_73817 = (abs_73821 > ((t_sample)0.5));
			int change_73816 = __m_change_121(gt_73817);
			int gt_73815 = (change_73816 > ((int)0));
			int gen_73013 = gt_73815;
			t_sample history_194_next_73820 = fixdenorm(wrap_73010);
			__m_latch_122 = ((gen_73013 != 0) ? floor_73006 : __m_latch_122);
			t_sample latch_73014 = __m_latch_122;
			t_sample sub_73023 = (mul_73011 - latch_73014);
			__m_latch_123 = ((gen_73013 != 0) ? floor_73007 : __m_latch_123);
			t_sample latch_73016 = __m_latch_123;
			t_sample abs_72998 = fabs(latch_73016);
			__m_latch_124 = ((gen_73013 != 0) ? floor_73008 : __m_latch_124);
			t_sample latch_73015 = __m_latch_124;
			t_sample abs_72997 = fabs(latch_73015);
			t_sample max_72996 = ((abs_72998 < abs_72997) ? abs_72997 : abs_72998);
			t_sample min_72995 = ((abs_72997 < abs_72998) ? abs_72997 : abs_72998);
			t_sample div_72999 = safediv(min_72995, max_72996);
			t_sample mul_72994 = (latch_73016 * latch_73015);
			int sign_73001 = ((mul_72994 > 0) ? 1 : ((mul_72994 < 0) ? -1 : 0));
			t_sample mul_73000 = (sub_73023 * sign_73001);
			t_sample wrap_73017 = wrap(mul_73000, ((int)0), max_72996);
			t_sample floor_73024 = floor(wrap_73017);
			t_sample mul_73019 = (floor_73024 * div_72999);
			t_sample floor_73022 = floor(mul_73019);
			t_sample div_73021 = safediv(floor_73022, div_72999);
			t_sample ceil_73020 = ceil(div_73021);
			t_sample sub_73018 = (wrap_73017 - ceil_73020);
			t_sample add_73003 = (floor_73022 + ((int)1));
			t_sample div_73005 = safediv(add_73003, div_72999);
			t_sample ceil_73004 = ceil(div_73005);
			t_sample sub_73002 = (ceil_73004 - ceil_73020);
			t_sample div_73012 = safediv(sub_73018, sub_73002);
			t_sample sub_73831 = (div_73012 - m_history_51);
			t_sample add_73830 = (div_73012 + m_history_51);
			t_sample div_73829 = safediv(sub_73831, add_73830);
			t_sample abs_73828 = fabs(div_73829);
			int gt_73827 = (abs_73828 > ((t_sample)0.5));
			int change_73826 = __m_change_125(gt_73827);
			int gt_73825 = (change_73826 > ((int)0));
			int gen_72985 = gt_73825;
			t_sample history_194_next_73832 = fixdenorm(div_73012);
			int trig_72869 = gen_72985;
			__m_latch_126 = ((trig_72869 != 0) ? m_history_19 : __m_latch_126);
			t_sample latch_72864 = __m_latch_126;
			int not_72680 = (!latch_72864);
			t_sample out6 = not_72680;
			__m_latch_127 = ((trig_72869 != 0) ? m_history_15 : __m_latch_127);
			t_sample latch_72866 = __m_latch_127;
			int not_72681 = (!latch_72866);
			t_sample out5 = not_72681;
			__m_latch_128 = ((trig_72869 != 0) ? gt_72853 : __m_latch_128);
			int latch_72870 = __m_latch_128;
			int not_72683 = (!latch_72870);
			t_sample out3 = not_72683;
			__m_latch_129 = ((trig_72869 != 0) ? m_history_20 : __m_latch_129);
			t_sample latch_72862 = __m_latch_129;
			int not_72679 = (!latch_72862);
			t_sample out7 = not_72679;
			__m_latch_130 = ((trig_72869 != 0) ? m_history_17 : __m_latch_130);
			t_sample latch_72861 = __m_latch_130;
			int not_72678 = (!latch_72861);
			t_sample out8 = not_72678;
			__m_latch_131 = ((trig_72869 != 0) ? m_history_18 : __m_latch_131);
			t_sample latch_72868 = __m_latch_131;
			int not_72682 = (!latch_72868);
			t_sample out4 = not_72682;
			__m_latch_132 = ((trig_72869 != 0) ? m_history_16 : __m_latch_132);
			t_sample latch_72859 = __m_latch_132;
			int not_72677 = (!latch_72859);
			t_sample out9 = not_72677;
			int trig_73040 = trig_72869;
			__m_latch_133 = ((trig_73040 != 0) ? m_history_4 : __m_latch_133);
			t_sample latch_73039 = __m_latch_133;
			__m_latch_134 = ((trig_73040 != 0) ? m_history_13 : __m_latch_134);
			t_sample latch_73037 = __m_latch_134;
			__m_latch_135 = ((trig_73040 != 0) ? m_history_12 : __m_latch_135);
			t_sample latch_73035 = __m_latch_135;
			__m_latch_136 = ((trig_73040 != 0) ? m_history_9 : __m_latch_136);
			t_sample latch_73030 = __m_latch_136;
			__m_latch_137 = ((trig_73040 != 0) ? m_history_8 : __m_latch_137);
			t_sample latch_73032 = __m_latch_137;
			__m_latch_138 = ((trig_73040 != 0) ? m_history_11 : __m_latch_138);
			t_sample latch_73033 = __m_latch_138;
			__m_latch_139 = ((trig_72869 != 0) ? m_history_14 : __m_latch_139);
			t_sample latch_72857 = __m_latch_139;
			int not_72676 = (!latch_72857);
			t_sample out10 = not_72676;
			t_sample switch_72686 = (lt_72685 ? ((int)1) : latch_72857);
			int neq_72896 = (gen_72985 != ((int)0));
			int change_72895 = __m_change_140(neq_72896);
			int gt_72894 = (change_72895 > ((int)0));
			t_sample mul_72900 = ((m_history_7 + gt_72894) * t_72902);
			t_sample clamp_72893 = ((mul_72900 <= ((int)0)) ? ((int)0) : ((mul_72900 >= ((int)1)) ? ((int)1) : mul_72900));
			t_sample mix_79371 = (clamp_72893 + (((t_sample)0.97) * (m_history_6 - clamp_72893)));
			t_sample mix_72898 = mix_79371;
			__m_latch_141 = ((trig_73040 != 0) ? m_history_10 : __m_latch_141);
			t_sample latch_73028 = __m_latch_141;
			t_sample mul_72986 = (latch_73028 * ((int)12));
			int int_72977 = int(mul_72986);
			t_sample mul_72979 = (int_72977 * div_72980);
			t_sample round_72982 = round(mul_72979);
			t_sample div_72978 = safediv(round_72982, div_72980);
			t_sample add_72993 = (div_72978 + ((int)36));
			t_sample mtof_72992 = mtof(add_72993, ((int)440));
			t_sample phasor_72830 = __m_phasor_142(mtof_72992, samples_to_seconds);
			t_sample clamp_72736 = ((latch_72740 <= ((int)0)) ? ((int)0) : ((latch_72740 >= ((int)1)) ? ((int)1) : latch_72740));
			t_sample triangle_72735 = triangle(phasor_72830, clamp_72736);
			t_sample sub_79375 = (triangle_72735 - ((int)0));
			t_sample scale_79372 = ((safepow((sub_79375 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_72734 = scale_79372;
			t_sample gen_72737 = scale_72734;
			t_sample rsub_72708 = (((int)1) - gen_72737);
			int change_72709 = __m_change_143(gen_72737);
			int gt_72739 = (change_72709 > ((int)0));
			t_sample switch_72733 = (gt_72739 ? gen_72737 : rsub_72708);
			t_sample sub_73838 = (switch_72733 - m_history_50);
			t_sample add_73842 = (switch_72733 + m_history_50);
			t_sample div_73837 = safediv(sub_73838, add_73842);
			t_sample abs_73841 = fabs(div_73837);
			int gt_73843 = (abs_73841 > ((t_sample)0.5));
			int change_73836 = __m_change_144(gt_73843);
			int gt_73835 = (change_73836 > ((int)0));
			int gen_72732 = gt_73835;
			t_sample history_194_next_73839 = fixdenorm(switch_72733);
			__m_latch_145 = ((gen_72732 != 0) ? m_history_5 : __m_latch_145);
			t_sample latch_72742 = __m_latch_145;
			t_sample sub_73848 = (switch_72733 - m_history_49);
			t_sample add_73852 = (switch_72733 + m_history_49);
			t_sample div_73847 = safediv(sub_73848, add_73852);
			t_sample abs_73851 = fabs(div_73847);
			int gt_73853 = (abs_73851 > ((t_sample)0.5));
			int change_73846 = __m_change_146(gt_73853);
			int gt_73845 = (change_73846 > ((int)0));
			int gen_72704 = gt_73845;
			t_sample history_194_next_73849 = fixdenorm(switch_72733);
			__m_latch_147 = ((gen_72704 != 0) ? m_history_3 : __m_latch_147);
			t_sample latch_72706 = __m_latch_147;
			t_sample mix_79376 = (gt_72739 + (latch_72711 * (abs_72730 - gt_72739)));
			t_sample mix_72714 = mix_79376;
			t_sample orange_79379 = (((int)1) - latch_72712);
			t_sample sub_79380 = (mix_72714 - ((int)0));
			t_sample scale_79377 = ((safepow((sub_79380 * ((t_sample)1)), ((int)1)) * orange_79379) + latch_72712);
			t_sample scale_72713 = scale_79377;
			__m_latch_148 = ((gen_72732 != 0) ? scale_72713 : __m_latch_148);
			t_sample latch_72743 = __m_latch_148;
			__m_latch_149 = ((gen_72704 != 0) ? scale_72713 : __m_latch_149);
			t_sample latch_72707 = __m_latch_149;
			int gte_72688 = (latch_72706 >= latch_72707);
			int and_72716 = (gte_72688 && latch_72715);
			t_sample switch_72718 = (and_72716 ? latch_72719 : rsub_72717);
			t_sample clamp_72720 = ((switch_72733 <= ((int)0)) ? ((int)0) : ((switch_72733 >= ((int)1)) ? ((int)1) : switch_72733));
			t_sample round_72726 = round(clamp_72720);
			t_sample triangle_72721 = triangle(clamp_72720, ((t_sample)0.5));
			t_sample clamp_72724 = ((switch_72718 <= ((int)0)) ? ((int)0) : ((switch_72718 >= ((int)1)) ? ((int)1) : switch_72718));
			t_sample sub_79384 = (clamp_72724 - ((int)1));
			t_sample scale_79381 = ((safepow((sub_79384 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_72722 = scale_79381;
			t_sample clamp_72697 = ((triangle_72721 <= ((int)0)) ? ((int)0) : ((triangle_72721 >= ((int)1)) ? ((int)1) : triangle_72721));
			t_sample clamp_72691 = ((scale_72722 <= ((int)0)) ? ((int)0) : ((scale_72722 >= ((int)1)) ? ((int)1) : scale_72722));
			int lt_72700 = (clamp_72691 < ((t_sample)0.5));
			int not_72696 = (!lt_72700);
			t_sample sub_79388 = (clamp_72691 - ((int)1));
			t_sample scale_79385 = ((safepow((sub_79388 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_72701 = scale_79385;
			t_sample tan_72699 = tan(scale_72701);
			t_sample rdiv_72698 = safediv(((int)1), tan_72699);
			t_sample switch_72695 = (lt_72700 ? rdiv_72698 : tan_72699);
			t_sample switch_72694 = (lt_72700 ? tan_72699 : rdiv_72698);
			int irange_79390 = (lt_72700 - not_72696);
			t_sample sub_79392 = (clamp_72697 - not_72696);
			t_sample scale_79389 = ((safepow(safediv(sub_79392, irange_79390), switch_72694) * ((int)-1)) + ((int)1));
			t_sample scale_72693 = scale_79389;
			int orange_79395 = (not_72696 - lt_72700);
			t_sample sub_79396 = (scale_72693 - ((int)0));
			t_sample scale_79393 = ((safepow((sub_79396 * ((t_sample)1)), switch_72695) * orange_79395) + lt_72700);
			t_sample scale_72692 = scale_79393;
			t_sample gen_72723 = scale_72692;
			t_sample mix_79397 = (round_72726 + (gen_72723 * (clamp_72720 - round_72726)));
			t_sample mix_72725 = mix_79397;
			t_sample gen_72727 = mix_72725;
			t_sample mix_79398 = (latch_72742 + (gen_72727 * (latch_72743 - latch_72742)));
			t_sample mix_72731 = mix_79398;
			__m_latch_150 = ((trig_73040 != 0) ? mix_72731 : __m_latch_150);
			t_sample latch_73041 = __m_latch_150;
			t_sample clamp_73859 = ((switch_72733 <= ((int)0)) ? ((int)0) : ((switch_72733 >= ((int)1)) ? ((int)1) : switch_72733));
			t_sample clamp_73860 = ((switch_72718 <= ((int)0)) ? ((int)0) : ((switch_72718 >= ((int)1)) ? ((int)1) : switch_72718));
			int lt_73856 = (clamp_73860 < ((t_sample)0.5));
			int not_73866 = (!lt_73856);
			t_sample sub_79402 = (clamp_73860 - ((int)1));
			t_sample scale_79399 = ((safepow((sub_79402 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_73862 = scale_79399;
			t_sample tan_73861 = tan(scale_73862);
			t_sample rdiv_73855 = safediv(((int)1), tan_73861);
			t_sample switch_73864 = (lt_73856 ? rdiv_73855 : tan_73861);
			t_sample switch_73863 = (lt_73856 ? tan_73861 : rdiv_73855);
			int irange_79404 = (lt_73856 - not_73866);
			t_sample sub_79406 = (clamp_73859 - not_73866);
			t_sample scale_79403 = ((safepow(safediv(sub_79406, irange_79404), switch_73863) * ((int)-1)) + ((int)1));
			t_sample scale_73857 = scale_79403;
			int orange_79409 = (not_73866 - lt_73856);
			t_sample sub_79410 = (scale_73857 - ((int)0));
			t_sample scale_79407 = ((safepow((sub_79410 * ((t_sample)1)), switch_73864) * orange_79409) + lt_73856);
			t_sample scale_73865 = scale_79407;
			t_sample gen_72702 = scale_73865;
			t_sample mix_79411 = (latch_72706 + (gen_72702 * (latch_72707 - latch_72706)));
			t_sample mix_72703 = mix_79411;
			t_sample sub_73871 = (phasor_72830 - m_history_48);
			t_sample add_73875 = (phasor_72830 + m_history_48);
			t_sample div_73870 = safediv(sub_73871, add_73875);
			t_sample abs_73874 = fabs(div_73870);
			int gt_73876 = (abs_73874 > ((t_sample)0.5));
			int change_73869 = __m_change_151(gt_73876);
			int gt_73868 = (change_73869 > ((int)0));
			int gen_72817 = gt_73868;
			t_sample history_194_next_73872 = fixdenorm(phasor_72830);
			__m_latch_152 = ((gen_72817 != 0) ? ((int)-1) : __m_latch_152);
			int latch_72808 = __m_latch_152;
			__m_latch_153 = ((gen_72817 != 0) ? rsub_72791 : __m_latch_153);
			t_sample latch_72815 = __m_latch_153;
			t_sample rsub_72813 = (((int)1) - latch_72815);
			__m_latch_154 = ((gen_72817 != 0) ? switch_72788 : __m_latch_154);
			t_sample latch_72807 = __m_latch_154;
			__m_latch_155 = ((gen_72817 != 0) ? ((t_sample)0.5) : __m_latch_155);
			t_sample latch_72826 = __m_latch_155;
			t_sample clamp_73880 = ((latch_72826 <= ((int)0)) ? ((int)0) : ((latch_72826 >= ((int)1)) ? ((int)1) : latch_72826));
			t_sample triangle_73879 = triangle(phasor_72830, clamp_73880);
			t_sample sub_79415 = (triangle_73879 - ((int)0));
			t_sample scale_79412 = ((safepow((sub_79415 * ((t_sample)1)), ((int)1)) * ((int)-1)) + ((int)1));
			t_sample scale_73878 = scale_79412;
			t_sample gen_72823 = scale_73878;
			t_sample rsub_72804 = (((int)1) - gen_72823);
			int change_72805 = __m_change_156(gen_72823);
			int gt_72825 = (change_72805 > ((int)0));
			t_sample switch_72822 = (gt_72825 ? gen_72823 : rsub_72804);
			t_sample sub_73884 = (switch_72822 - m_history_47);
			t_sample add_73888 = (switch_72822 + m_history_47);
			t_sample div_73883 = safediv(sub_73884, add_73888);
			t_sample abs_73887 = fabs(div_73883);
			int gt_73889 = (abs_73887 > ((t_sample)0.5));
			int change_73882 = __m_change_157(gt_73889);
			int gt_73881 = (change_73882 > ((int)0));
			int gen_72800 = gt_73881;
			t_sample history_194_next_73885 = fixdenorm(switch_72822);
			__m_latch_158 = ((gen_72800 != 0) ? m_history_2 : __m_latch_158);
			t_sample latch_72802 = __m_latch_158;
			t_sample sub_73899 = (switch_72822 - m_history_46);
			t_sample add_73897 = (switch_72822 + m_history_46);
			t_sample div_73893 = safediv(sub_73899, add_73897);
			t_sample abs_73896 = fabs(div_73893);
			int gt_73898 = (abs_73896 > ((t_sample)0.5));
			int change_73892 = __m_change_159(gt_73898);
			int gt_73891 = (change_73892 > ((int)0));
			int gen_72821 = gt_73891;
			t_sample history_194_next_73894 = fixdenorm(switch_72822);
			__m_latch_160 = ((gen_72821 != 0) ? m_history_1 : __m_latch_160);
			t_sample latch_72828 = __m_latch_160;
			t_sample mix_79416 = (gt_72825 + (latch_72807 * (abs_72819 - gt_72825)));
			t_sample mix_72810 = mix_79416;
			int orange_79419 = (((int)1) - latch_72808);
			t_sample sub_79420 = (mix_72810 - ((int)0));
			t_sample scale_79417 = ((safepow((sub_79420 * ((t_sample)1)), ((int)1)) * orange_79419) + latch_72808);
			t_sample scale_72809 = scale_79417;
			__m_latch_161 = ((gen_72800 != 0) ? scale_72809 : __m_latch_161);
			t_sample latch_72803 = __m_latch_161;
			int gte_72797 = (latch_72802 >= latch_72803);
			__m_latch_162 = ((gen_72821 != 0) ? scale_72809 : __m_latch_162);
			t_sample latch_72829 = __m_latch_162;
			__m_latch_163 = ((gen_72817 != 0) ? ((int)1) : __m_latch_163);
			int latch_72811 = __m_latch_163;
			int and_72812 = (gte_72797 && latch_72811);
			t_sample switch_72814 = (and_72812 ? latch_72815 : rsub_72813);
			t_sample clamp_73906 = ((switch_72822 <= ((int)0)) ? ((int)0) : ((switch_72822 >= ((int)1)) ? ((int)1) : switch_72822));
			t_sample clamp_73908 = ((switch_72814 <= ((int)0)) ? ((int)0) : ((switch_72814 >= ((int)1)) ? ((int)1) : switch_72814));
			int lt_73902 = (clamp_73908 < ((t_sample)0.5));
			int not_73911 = (!lt_73902);
			t_sample sub_79424 = (clamp_73908 - ((int)1));
			t_sample scale_79421 = ((safepow((sub_79424 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_73910 = scale_79421;
			t_sample tan_73909 = tan(scale_73910);
			t_sample rdiv_73901 = safediv(((int)1), tan_73909);
			t_sample switch_73904 = (lt_73902 ? rdiv_73901 : tan_73909);
			t_sample switch_73907 = (lt_73902 ? tan_73909 : rdiv_73901);
			int irange_79426 = (lt_73902 - not_73911);
			t_sample sub_79428 = (clamp_73906 - not_73911);
			t_sample scale_79425 = ((safepow(safediv(sub_79428, irange_79426), switch_73907) * ((int)-1)) + ((int)1));
			t_sample scale_73903 = scale_79425;
			int orange_79431 = (not_73911 - lt_73902);
			t_sample sub_79432 = (scale_73903 - ((int)0));
			t_sample scale_79429 = ((safepow((sub_79432 * ((t_sample)1)), switch_73904) * orange_79431) + lt_73902);
			t_sample scale_73912 = scale_79429;
			t_sample gen_72798 = scale_73912;
			t_sample mix_79433 = (latch_72802 + (gen_72798 * (latch_72803 - latch_72802)));
			t_sample mix_72799 = mix_79433;
			t_sample out12 = mix_72799;
			t_sample clamp_73933 = ((switch_72822 <= ((int)0)) ? ((int)0) : ((switch_72822 >= ((int)1)) ? ((int)1) : switch_72822));
			t_sample round_73914 = round(clamp_73933);
			t_sample triangle_73918 = triangle(clamp_73933, ((t_sample)0.5));
			t_sample clamp_73931 = ((switch_72814 <= ((int)0)) ? ((int)0) : ((switch_72814 >= ((int)1)) ? ((int)1) : switch_72814));
			t_sample sub_79437 = (clamp_73931 - ((int)1));
			t_sample scale_79434 = ((safepow((sub_79437 * ((t_sample)-1)), ((t_sample)0.884)) * ((int)1)) + ((int)0));
			t_sample scale_73920 = scale_79434;
			t_sample clamp_73923 = ((triangle_73918 <= ((int)0)) ? ((int)0) : ((triangle_73918 >= ((int)1)) ? ((int)1) : triangle_73918));
			t_sample clamp_73925 = ((scale_73920 <= ((int)0)) ? ((int)0) : ((scale_73920 >= ((int)1)) ? ((int)1) : scale_73920));
			int lt_73916 = (clamp_73925 < ((t_sample)0.5));
			int not_73929 = (!lt_73916);
			t_sample sub_79441 = (clamp_73925 - ((int)1));
			t_sample scale_79438 = ((safepow((sub_79441 * ((t_sample)-1)), ((int)1)) * ((t_sample)1.5707963267949)) + ((int)0));
			t_sample scale_73928 = scale_79438;
			t_sample tan_73926 = tan(scale_73928);
			t_sample rdiv_73915 = safediv(((int)1), tan_73926);
			t_sample switch_73919 = (lt_73916 ? rdiv_73915 : tan_73926);
			t_sample switch_73924 = (lt_73916 ? tan_73926 : rdiv_73915);
			int irange_79443 = (lt_73916 - not_73929);
			t_sample sub_79445 = (clamp_73923 - not_73929);
			t_sample scale_79442 = ((safepow(safediv(sub_79445, irange_79443), switch_73924) * ((int)-1)) + ((int)1));
			t_sample scale_73917 = scale_79442;
			int orange_79448 = (not_73929 - lt_73916);
			t_sample sub_79449 = (scale_73917 - ((int)0));
			t_sample scale_79446 = ((safepow((sub_79449 * ((t_sample)1)), switch_73919) * orange_79448) + lt_73916);
			t_sample scale_73930 = scale_79446;
			t_sample gen_73927 = scale_73930;
			t_sample mix_79450 = (round_73914 + (gen_73927 * (clamp_73933 - round_73914)));
			t_sample mix_73921 = mix_79450;
			t_sample gen_72816 = mix_73921;
			t_sample mix_79451 = (latch_72828 + (gen_72816 * (latch_72829 - latch_72828)));
			t_sample mix_72820 = mix_79451;
			t_sample out11 = mix_72820;
			t_sample mul_72671 = (latch_73028 * ((int)12));
			int int_72667 = int(mul_72671);
			int mul_72669 = (int_72667 * ((int)1));
			int round_72670 = round(mul_72669);
			t_sample div_72668 = (round_72670 * ((t_sample)1));
			t_sample add_72673 = (div_72668 + ((int)60));
			t_sample mtof_72672 = mtof(add_72673, ((int)440));
			__m_cycle_164.freq(mtof_72672);
			t_sample cycle_72665 = __m_cycle_164(__sinedata);
			t_sample cycleindex_72666 = __m_cycle_164.phase();
			t_sample mix_79452 = (((int)1) + (m_cv_69 * (cycle_72665 - ((int)1))));
			t_sample mix_72664 = mix_79452;
			t_sample floor_72879 = floor(mix_72820);
			t_sample sub_72871 = (mix_72820 - floor_72879);
			t_sample add_72878 = (floor_72879 + ((int)1));
			t_sample mul_72874 = (mtof_72992 * ((t_sample)6.2831853071796));
			t_sample mul_72876 = (floor_72879 * mul_72874);
			t_sample sin_72873 = sin((mix_72664 + mul_72876));
			t_sample mul_72875 = (add_72878 * mul_72874);
			t_sample sin_72872 = sin((mix_72664 + mul_72875));
			t_sample mix_79453 = (sin_72873 + (sub_72871 * (sin_72872 - sin_72873)));
			t_sample mix_72877 = mix_79453;
			t_sample gen_72880 = mix_72877;
			t_sample mul_72990 = (gen_72880 * mix_72898);
			t_sample mul_72687 = (mul_72990 * switch_72686);
			t_sample mul_72988 = (mul_72687 * ((int)2));
			t_sample tanh_72989 = tanh(mul_72988);
			t_sample div_72987 = (tanh_72989 * ((t_sample)0.5));
			t_sample mul_72775 = (m_history_45 * gen_72768);
			t_sample mul_72776 = (m_history_43 * ((int)0));
			t_sample mul_72777 = (div_72987 * gen_72766);
			t_sample mul_72778 = (m_history_44 * gen_72770);
			t_sample mul_72779 = (m_history_42 * gen_72769);
			t_sample sub_72772 = (((mul_72777 + mul_72776) + mul_72775) - (mul_72779 + mul_72778));
			t_sample gen_72786 = sub_72772;
			t_sample history_72773_next_72782 = fixdenorm(m_history_43);
			t_sample history_72780_next_72783 = fixdenorm(m_history_42);
			t_sample history_72774_next_72784 = fixdenorm(div_72987);
			t_sample history_72781_next_72785 = fixdenorm(sub_72772);
			t_sample clamp_72771 = ((gen_72786 <= min_165) ? min_165 : ((gen_72786 >= ((int)1)) ? ((int)1) : gen_72786));
			t_sample mul_72976 = (clamp_72771 * ((t_sample)0.015));
			t_sample tap_72918 = m_delay_41.read_linear(add_72971);
			t_sample gen_72950 = tap_72918;
			t_sample mul_72916 = (tap_72918 * damp_72949);
			t_sample mul_72914 = (m_history_40 * rsub_72911);
			t_sample add_72915 = (mul_72916 + mul_72914);
			t_sample mul_72912 = (add_72915 * m_fb_83);
			t_sample add_72919 = (mul_72976 + mul_72912);
			t_sample history_72913_next_72920 = fixdenorm(add_72915);
			t_sample tap_73938 = m_delay_39.read_linear(add_72970);
			t_sample gen_72951 = tap_73938;
			t_sample mul_73941 = (tap_73938 * damp_72948);
			t_sample mul_73937 = (m_history_38 * rsub_73940);
			t_sample add_73936 = (mul_73941 + mul_73937);
			t_sample mul_73939 = (add_73936 * m_fb_83);
			t_sample add_73942 = (mul_72976 + mul_73939);
			t_sample history_72913_next_73935 = fixdenorm(add_73936);
			t_sample tap_73950 = m_delay_37.read_linear(add_72969);
			t_sample gen_72952 = tap_73950;
			t_sample mul_73953 = (tap_73950 * damp_72947);
			t_sample mul_73949 = (m_history_36 * rsub_73952);
			t_sample add_73948 = (mul_73953 + mul_73949);
			t_sample mul_73951 = (add_73948 * m_fb_83);
			t_sample add_73954 = (mul_72976 + mul_73951);
			t_sample history_72913_next_73947 = fixdenorm(add_73948);
			t_sample tap_73962 = m_delay_35.read_linear(add_72968);
			t_sample gen_72953 = tap_73962;
			t_sample mul_73965 = (tap_73962 * damp_72946);
			t_sample mul_73961 = (m_history_34 * rsub_73964);
			t_sample add_73960 = (mul_73965 + mul_73961);
			t_sample mul_73963 = (add_73960 * m_fb_83);
			t_sample add_73966 = (mul_72976 + mul_73963);
			t_sample history_72913_next_73959 = fixdenorm(add_73960);
			t_sample tap_73974 = m_delay_33.read_linear(add_72967);
			t_sample gen_72954 = tap_73974;
			t_sample mul_73977 = (tap_73974 * damp_72945);
			t_sample mul_73973 = (m_history_32 * rsub_73976);
			t_sample add_73972 = (mul_73977 + mul_73973);
			t_sample mul_73975 = (add_73972 * m_fb_83);
			t_sample add_73978 = (mul_72976 + mul_73975);
			t_sample history_72913_next_73971 = fixdenorm(add_73972);
			t_sample tap_73983 = m_delay_31.read_linear(add_72966);
			t_sample gen_72955 = tap_73983;
			t_sample mul_73990 = (tap_73983 * damp_72944);
			t_sample mul_73986 = (m_history_30 * rsub_73984);
			t_sample add_73989 = (mul_73990 + mul_73986);
			t_sample mul_73988 = (add_73989 * m_fb_83);
			t_sample add_73985 = (mul_72976 + mul_73988);
			t_sample history_72913_next_73987 = fixdenorm(add_73989);
			t_sample tap_73995 = m_delay_29.read_linear(add_72965);
			t_sample gen_72956 = tap_73995;
			t_sample mul_74002 = (tap_73995 * damp_72943);
			t_sample mul_73998 = (m_history_28 * rsub_73996);
			t_sample add_74001 = (mul_74002 + mul_73998);
			t_sample mul_74000 = (add_74001 * m_fb_83);
			t_sample add_73997 = (mul_72976 + mul_74000);
			t_sample history_72913_next_73999 = fixdenorm(add_74001);
			t_sample tap_74007 = m_delay_27.read_linear(add_72964);
			t_sample gen_72975 = tap_74007;
			t_sample mul_74014 = (tap_74007 * damp_72942);
			t_sample mul_74010 = (m_history_26 * rsub_74008);
			t_sample add_74013 = (mul_74014 + mul_74010);
			t_sample mul_74012 = (add_74013 * m_fb_83);
			t_sample add_74009 = (mul_72976 + mul_74012);
			t_sample history_72913_next_74011 = fixdenorm(add_74013);
			t_sample add_72973 = ((((((((gen_72975 + gen_72956) + gen_72955) + gen_72954) + gen_72953) + gen_72952) + gen_72951) + gen_72950) + ((int)0));
			t_sample tap_72909 = m_delay_25.read_linear(add_72958);
			t_sample sub_72905 = (add_72973 - tap_72909);
			t_sample mul_72907 = (tap_72909 * mul_72974);
			t_sample add_72906 = (add_72973 + mul_72907);
			t_sample tap_74018 = m_delay_24.read_linear(add_72972);
			t_sample sub_74022 = (sub_72905 - tap_74018);
			t_sample mul_74019 = (tap_74018 * mul_72974);
			t_sample add_74020 = (sub_72905 + mul_74019);
			t_sample tap_74024 = m_delay_23.read_linear(add_72962);
			t_sample sub_74028 = (sub_74022 - tap_74024);
			t_sample mul_74025 = (tap_74024 * mul_72974);
			t_sample add_74026 = (sub_74022 + mul_74025);
			t_sample tap_74030 = m_delay_22.read_linear(add_72960);
			t_sample sub_74034 = (sub_74028 - tap_74030);
			t_sample mul_74031 = (tap_74030 * mul_72974);
			t_sample add_74032 = (sub_74028 + mul_74031);
			t_sample mix_79454 = (((t_sample)0.7) + (clamp_72771 * (sub_74034 - ((t_sample)0.7))));
			t_sample add_72831 = (mix_79454 + in2);
			t_sample out2 = add_72831;
			t_sample add_72832 = (mix_79454 + in1);
			t_sample out1 = add_72832;
			t_sample history_72837_next_74036 = fixdenorm(wrap_72840);
			t_sample history_72855_next_74037 = fixdenorm(latch_72864);
			t_sample history_72863_next_74038 = fixdenorm(latch_72866);
			t_sample history_72867_next_74039 = fixdenorm(latch_72870);
			t_sample history_72860_next_74040 = fixdenorm(latch_72862);
			t_sample history_72858_next_74041 = fixdenorm(latch_72861);
			t_sample history_72865_next_74042 = fixdenorm(latch_72868);
			t_sample history_72856_next_74043 = fixdenorm(latch_72859);
			t_sample history_73036_next_74044 = fixdenorm(latch_73039);
			t_sample history_73034_next_74045 = fixdenorm(latch_73037);
			t_sample history_73026_next_74046 = fixdenorm(latch_73035);
			t_sample history_73027_next_74047 = fixdenorm(latch_73030);
			t_sample history_73029_next_74048 = fixdenorm(latch_73032);
			t_sample history_73031_next_74049 = fixdenorm(latch_73033);
			t_sample history_72899_next_74050 = fixdenorm(clamp_72893);
			t_sample history_72897_next_74051 = fixdenorm(mix_72898);
			t_sample history_72741_next_74052 = fixdenorm(mix_72731);
			t_sample history_73038_next_74053 = fixdenorm(latch_73041);
			t_sample history_72705_next_74054 = fixdenorm(mix_72703);
			t_sample history_72801_next_74055 = fixdenorm(mix_72799);
			t_sample history_72827_next_74056 = fixdenorm(mix_72820);
			m_history_59 = history_194_next_199;
			m_history_54 = history_72848_next_72851;
			m_history_53 = history_194_next_73805;
			m_history_52 = history_194_next_73820;
			m_history_51 = history_194_next_73832;
			m_history_50 = history_194_next_73839;
			m_history_49 = history_194_next_73849;
			m_history_48 = history_194_next_73872;
			m_history_47 = history_194_next_73885;
			m_history_46 = history_194_next_73894;
			m_history_45 = history_72773_next_72782;
			m_history_42 = history_72781_next_72785;
			m_history_43 = history_72774_next_72784;
			m_history_44 = history_72780_next_72783;
			m_delay_41.write(add_72919);
			m_history_40 = history_72913_next_72920;
			m_delay_39.write(add_73942);
			m_history_38 = history_72913_next_73935;
			m_delay_37.write(add_73954);
			m_history_36 = history_72913_next_73947;
			m_delay_35.write(add_73966);
			m_history_34 = history_72913_next_73959;
			m_delay_33.write(add_73978);
			m_history_32 = history_72913_next_73971;
			m_delay_31.write(add_73985);
			m_history_30 = history_72913_next_73987;
			m_delay_29.write(add_73997);
			m_history_28 = history_72913_next_73999;
			m_delay_27.write(add_74009);
			m_history_26 = history_72913_next_74011;
			m_delay_25.write(add_72906);
			m_delay_24.write(add_74020);
			m_delay_23.write(add_74026);
			m_delay_22.write(add_74032);
			m_history_21 = history_72837_next_74036;
			m_history_20 = history_72855_next_74037;
			m_history_19 = history_72863_next_74038;
			m_history_18 = history_72867_next_74039;
			m_history_17 = history_72860_next_74040;
			m_history_16 = history_72858_next_74041;
			m_history_15 = history_72865_next_74042;
			m_history_14 = history_72856_next_74043;
			m_history_13 = history_73036_next_74044;
			m_history_12 = history_73034_next_74045;
			m_history_11 = history_73026_next_74046;
			m_history_10 = history_73027_next_74047;
			m_history_9 = history_73029_next_74048;
			m_history_8 = history_73031_next_74049;
			m_history_7 = history_72899_next_74050;
			m_history_6 = history_72897_next_74051;
			m_history_5 = history_72741_next_74052;
			m_history_4 = history_73038_next_74053;
			m_history_3 = history_72705_next_74054;
			m_history_2 = history_72801_next_74055;
			m_history_1 = history_72827_next_74056;
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
	inline void set_random(t_param _value) {
		m_random_60 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_shift_var(t_param _value) {
		m_shift_var_61 = (_value < 0 ? 0 : (_value > 0.5 ? 0.5 : _value));
	};
	inline void set_envelope_length(t_param _value) {
		m_envelope_length_62 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_63 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_euclid_p(t_param _value) {
		m_euclid_p_64 = (_value < 0 ? 0 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_fb2(t_param _value) {
		m_fb_65 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_spread(t_param _value) {
		m_spread_66 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_bipolar(t_param _value) {
		m_bipolar_67 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_68 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cv1(t_param _value) {
		m_cv_69 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_70 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_71 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bpm(t_param _value) {
		m_bpm_72 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_shape(t_param _value) {
		m_shape_73 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_74 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_numer(t_param _value) {
		m_numer_75 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_timbre(t_param _value) {
		m_timbre_76 = (_value < 0.01 ? 0.01 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_damp(t_param _value) {
		m_damp_77 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_78 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_skew(t_param _value) {
		m_skew_79 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_filter(t_param _value) {
		m_filter_80 = (_value < 100 ? 100 : (_value > 1400 ? 1400 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_81 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_symmetry(t_param _value) {
		m_symmetry_82 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_fb1(t_param _value) {
		m_fb_83 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_denom(t_param _value) {
		m_denom_84 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_85 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_86 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_euclidean_patterns(void * _value) {
		m_euclidean_patterns_87.setbuffer(_value);
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
int num_params() { return 28; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "out11", "out12" };

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
		case 1: self->set_bpm(value); break;
		case 2: self->set_cv1(value); break;
		case 3: self->set_damp(value); break;
		case 4: self->set_denom(value); break;
		case 5: self->set_envelope_length(value); break;
		case 6: self->set_euclid_p(value); break;
		case 7: self->set_euclidean_patterns(ref); break;
		case 8: self->set_fb1(value); break;
		case 9: self->set_fb2(value); break;
		case 10: self->set_filter(value); break;
		case 11: self->set_gatein1(value); break;
		case 12: self->set_numer(value); break;
		case 13: self->set_random(value); break;
		case 14: self->set_shape(value); break;
		case 15: self->set_shift_var(value); break;
		case 16: self->set_skew(value); break;
		case 17: self->set_spread(value); break;
		case 18: self->set_sw1(value); break;
		case 19: self->set_sw2(value); break;
		case 20: self->set_sw3(value); break;
		case 21: self->set_sw4(value); break;
		case 22: self->set_sw5(value); break;
		case 23: self->set_sw6(value); break;
		case 24: self->set_sw7(value); break;
		case 25: self->set_sw8(value); break;
		case 26: self->set_symmetry(value); break;
		case 27: self->set_timbre(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_bipolar_67; break;
		case 1: *value = self->m_bpm_72; break;
		case 2: *value = self->m_cv_69; break;
		case 3: *value = self->m_damp_77; break;
		case 4: *value = self->m_denom_84; break;
		case 5: *value = self->m_envelope_length_62; break;
		case 6: *value = self->m_euclid_p_64; break;
		
		case 8: *value = self->m_fb_83; break;
		case 9: *value = self->m_fb_65; break;
		case 10: *value = self->m_filter_80; break;
		case 11: *value = self->m_gatein_70; break;
		case 12: *value = self->m_numer_75; break;
		case 13: *value = self->m_random_60; break;
		case 14: *value = self->m_shape_73; break;
		case 15: *value = self->m_shift_var_61; break;
		case 16: *value = self->m_skew_79; break;
		case 17: *value = self->m_spread_66; break;
		case 18: *value = self->m_sw_81; break;
		case 19: *value = self->m_sw_86; break;
		case 20: *value = self->m_sw_85; break;
		case 21: *value = self->m_sw_71; break;
		case 22: *value = self->m_sw_63; break;
		case 23: *value = self->m_sw_74; break;
		case 24: *value = self->m_sw_68; break;
		case 25: *value = self->m_sw_78; break;
		case 26: *value = self->m_symmetry_82; break;
		case 27: *value = self->m_timbre_76; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(28 * sizeof(ParamInfo));
	self->__commonstate.numparams = 28;
	// initialize parameter 0 ("m_bipolar_67")
	pi = self->__commonstate.params + 0;
	pi->name = "bipolar";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bipolar_67;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_bpm_72")
	pi = self->__commonstate.params + 1;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_72;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_cv_69")
	pi = self->__commonstate.params + 2;
	pi->name = "cv1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv_69;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_damp_77")
	pi = self->__commonstate.params + 3;
	pi->name = "damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_damp_77;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_denom_84")
	pi = self->__commonstate.params + 4;
	pi->name = "denom";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_denom_84;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 24;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_envelope_length_62")
	pi = self->__commonstate.params + 5;
	pi->name = "envelope_length";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_envelope_length_62;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_euclid_p_64")
	pi = self->__commonstate.params + 6;
	pi->name = "euclid_p";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_euclid_p_64;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_euclidean_patterns_87")
	pi = self->__commonstate.params + 7;
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
	// initialize parameter 8 ("m_fb_83")
	pi = self->__commonstate.params + 8;
	pi->name = "fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_fb_83;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_fb_65")
	pi = self->__commonstate.params + 9;
	pi->name = "fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_fb_65;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_filter_80")
	pi = self->__commonstate.params + 10;
	pi->name = "filter";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_filter_80;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 100;
	pi->outputmax = 1400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_gatein_70")
	pi = self->__commonstate.params + 11;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_70;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_numer_75")
	pi = self->__commonstate.params + 12;
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
	// initialize parameter 13 ("m_random_60")
	pi = self->__commonstate.params + 13;
	pi->name = "random";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_random_60;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_shape_73")
	pi = self->__commonstate.params + 14;
	pi->name = "shape";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_shape_73;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_shift_var_61")
	pi = self->__commonstate.params + 15;
	pi->name = "shift_var";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_shift_var_61;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_skew_79")
	pi = self->__commonstate.params + 16;
	pi->name = "skew";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_skew_79;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_spread_66")
	pi = self->__commonstate.params + 17;
	pi->name = "spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_spread_66;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_81")
	pi = self->__commonstate.params + 18;
	pi->name = "sw1";
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
	// initialize parameter 19 ("m_sw_86")
	pi = self->__commonstate.params + 19;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_86;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_85")
	pi = self->__commonstate.params + 20;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_85;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_sw_71")
	pi = self->__commonstate.params + 21;
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
	// initialize parameter 22 ("m_sw_63")
	pi = self->__commonstate.params + 22;
	pi->name = "sw5";
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
	// initialize parameter 23 ("m_sw_74")
	pi = self->__commonstate.params + 23;
	pi->name = "sw6";
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
	// initialize parameter 24 ("m_sw_68")
	pi = self->__commonstate.params + 24;
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
	// initialize parameter 25 ("m_sw_78")
	pi = self->__commonstate.params + 25;
	pi->name = "sw8";
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
	// initialize parameter 26 ("m_symmetry_82")
	pi = self->__commonstate.params + 26;
	pi->name = "symmetry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_symmetry_82;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 27 ("m_timbre_76")
	pi = self->__commonstate.params + 27;
	pi->name = "timbre";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_timbre_76;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 0.99;
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
