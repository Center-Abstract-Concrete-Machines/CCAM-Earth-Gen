#include "harmonia_2dterra.h"

namespace harmonia_2dterra {

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
	Change __m_change_78;
	Change __m_change_57;
	Change __m_change_105;
	Change __m_change_85;
	Change __m_change_98;
	Change __m_change_92;
	Change __m_change_71;
	Change __m_change_115;
	Change __m_change_113;
	Change __m_change_172;
	Change __m_change_64;
	Change __m_change_136;
	Change __m_change_154;
	Change __m_change_120;
	Change __m_change_116;
	Data m_offsets_56;
	Delta __m_delta_114;
	Phasor __m_phasor_112;
	PlusEquals __m_pluseq_69;
	PlusEquals __m_pluseq_62;
	PlusEquals __m_pluseq_76;
	PlusEquals __m_pluseq_103;
	PlusEquals __m_pluseq_90;
	PlusEquals __m_pluseq_83;
	PlusEquals __m_pluseq_110;
	PlusEquals __m_pluseq_97;
	SineCycle __m_cycle_155;
	SineCycle __m_cycle_173;
	SineCycle __m_cycle_137;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_5;
	t_sample __m_latch_117;
	t_sample m_history_29;
	t_sample m_history_6;
	t_sample m_history_7;
	t_sample __m_latch_118;
	t_sample m_history_4;
	t_sample __m_latch_130;
	t_sample __m_latch_119;
	t_sample __m_latch_129;
	t_sample __m_latch_128;
	t_sample __m_latch_131;
	t_sample m_history_8;
	t_sample samples_to_seconds;
	t_sample __m_carry_101;
	t_sample __m_count_99;
	t_sample m_history_13;
	t_sample m_history_9;
	t_sample m_history_12;
	t_sample __m_count_106;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample __m_carry_108;
	t_sample __m_latch_132;
	t_sample __m_latch_133;
	t_sample __m_latch_134;
	t_sample __m_latch_165;
	t_sample __m_latch_166;
	t_sample __m_latch_164;
	t_sample samplerate;
	t_sample __m_latch_153;
	t_sample __m_latch_167;
	t_sample __m_latch_169;
	t_sample __m_latch_168;
	t_sample __m_latch_171;
	t_sample __m_latch_170;
	t_sample m_history_14;
	t_sample __m_latch_152;
	t_sample __m_latch_150;
	t_sample m_history_2;
	t_sample m_history_3;
	t_sample __m_latch_135;
	t_sample __m_latch_151;
	t_sample m_history_1;
	t_sample __m_latch_147;
	t_sample __m_latch_146;
	t_sample __m_latch_149;
	t_sample __m_latch_148;
	t_sample m_history_28;
	t_sample __m_carry_95;
	t_sample m_history_15;
	t_sample m_sw_45;
	t_sample m_sw_46;
	t_sample m_sw_44;
	t_sample m_sw_43;
	t_sample m_k_42;
	t_sample m_sw_47;
	t_sample m_bpm_49;
	t_sample m_n_48;
	t_sample m_gate_51;
	t_sample m_sw_50;
	t_sample m_sw_52;
	t_sample m_chancetwo_41;
	t_sample m_history_39;
	t_sample m_history_32;
	t_sample m_history_33;
	t_sample m_history_31;
	t_sample m_history_30;
	t_sample m_history_40;
	t_sample m_history_34;
	t_sample m_history_36;
	t_sample m_history_35;
	t_sample m_history_38;
	t_sample m_history_37;
	t_sample __m_count_93;
	t_sample m_chanceone_53;
	t_sample m_sw_55;
	t_sample __m_count_79;
	t_sample __m_carry_81;
	t_sample m_history_19;
	t_sample m_history_20;
	t_sample __m_carry_74;
	t_sample m_history_18;
	t_sample __m_count_86;
	t_sample m_history_17;
	t_sample m_history_16;
	t_sample __m_carry_88;
	t_sample m_chancethree_54;
	t_sample __m_count_72;
	t_sample m_history_22;
	t_sample __m_count_58;
	t_sample m_history_26;
	t_sample m_history_27;
	t_sample m_history_21;
	t_sample __m_carry_60;
	t_sample m_history_24;
	t_sample m_history_25;
	t_sample m_history_23;
	t_sample __m_count_65;
	t_sample __m_carry_67;
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
		m_history_34 = ((int)0);
		m_history_35 = ((int)0);
		m_history_36 = ((int)0);
		m_history_37 = ((int)0);
		m_history_38 = ((int)0);
		m_history_39 = ((int)0);
		m_history_40 = ((int)0);
		m_chancetwo_41 = ((int)0);
		m_k_42 = ((int)0);
		m_sw_43 = ((int)0);
		m_sw_44 = ((int)0);
		m_sw_45 = ((int)0);
		m_sw_46 = ((int)0);
		m_sw_47 = ((int)0);
		m_n_48 = ((int)0);
		m_bpm_49 = ((int)0);
		m_sw_50 = ((int)0);
		m_gate_51 = ((int)0);
		m_sw_52 = ((int)0);
		m_chanceone_53 = ((int)0);
		m_chancethree_54 = ((int)0);
		m_sw_55 = ((int)0);
		m_offsets_56.reset("offsets", ((int)512), ((int)1));
		__m_change_57.reset(0);
		__m_count_58 = 0;
		__m_carry_60 = 0;
		__m_pluseq_62.reset(0);
		__m_change_64.reset(0);
		__m_count_65 = 0;
		__m_carry_67 = 0;
		__m_pluseq_69.reset(0);
		__m_change_71.reset(0);
		__m_count_72 = 0;
		__m_carry_74 = 0;
		__m_pluseq_76.reset(0);
		__m_change_78.reset(0);
		__m_count_79 = 0;
		__m_carry_81 = 0;
		__m_pluseq_83.reset(0);
		__m_change_85.reset(0);
		__m_count_86 = 0;
		__m_carry_88 = 0;
		__m_pluseq_90.reset(0);
		__m_change_92.reset(0);
		__m_count_93 = 0;
		__m_carry_95 = 0;
		__m_pluseq_97.reset(0);
		__m_change_98.reset(0);
		__m_count_99 = 0;
		__m_carry_101 = 0;
		__m_pluseq_103.reset(0);
		__m_change_105.reset(0);
		__m_count_106 = 0;
		__m_carry_108 = 0;
		__m_pluseq_110.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_112.reset(0);
		__m_change_113.reset(0);
		__m_delta_114.reset(0);
		__m_change_115.reset(0);
		__m_change_116.reset(0);
		__m_latch_117 = 0;
		__m_latch_118 = 0;
		__m_latch_119 = 0;
		__m_change_120.reset(0);
		__m_latch_128 = 0;
		__m_latch_129 = 0;
		__m_latch_130 = 0;
		__m_latch_131 = 0;
		__m_latch_132 = 0;
		__m_latch_133 = 0;
		__m_latch_134 = 0;
		__m_latch_135 = 0;
		__m_change_136.reset(0);
		__m_cycle_137.reset(samplerate, 0);
		__m_latch_146 = 0;
		__m_latch_147 = 0;
		__m_latch_148 = 0;
		__m_latch_149 = 0;
		__m_latch_150 = 0;
		__m_latch_151 = 0;
		__m_latch_152 = 0;
		__m_latch_153 = 0;
		__m_change_154.reset(0);
		__m_cycle_155.reset(samplerate, 0);
		__m_latch_164 = 0;
		__m_latch_165 = 0;
		__m_latch_166 = 0;
		__m_latch_167 = 0;
		__m_latch_168 = 0;
		__m_latch_169 = 0;
		__m_latch_170 = 0;
		__m_latch_171 = 0;
		__m_change_172.reset(0);
		__m_cycle_173.reset(samplerate, 0);
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
		int int_24303 = int(m_sw_46);
		int offsets_dim = m_offsets_56.dim;
		int offsets_channels = m_offsets_56.channels;
		bool chan_ignore_63 = ((((int)7) < 0) || (((int)7) >= offsets_channels));
		int int_28298 = int(m_sw_44);
		bool chan_ignore_70 = ((((int)4) < 0) || (((int)4) >= offsets_channels));
		int int_28321 = int(m_sw_50);
		bool chan_ignore_77 = ((((int)6) < 0) || (((int)6) >= offsets_channels));
		int int_28346 = int(m_sw_55);
		bool chan_ignore_84 = ((((int)3) < 0) || (((int)3) >= offsets_channels));
		int int_28369 = int(m_sw_45);
		bool chan_ignore_91 = ((((int)2) < 0) || (((int)2) >= offsets_channels));
		int int_28392 = int(m_sw_47);
		int int_28415 = int(m_sw_43);
		bool chan_ignore_104 = ((((int)5) < 0) || (((int)5) >= offsets_channels));
		int int_28438 = int(m_sw_52);
		bool chan_ignore_111 = ((((int)1) < 0) || (((int)1) >= offsets_channels));
		t_sample div_20896 = (m_bpm_49 * ((t_sample)0.016666666666667));
		t_sample mul_20898 = (div_20896 * ((int)1));
		t_sample div_20893 = (mul_20898 * ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample history_21071_next_21098 = fixdenorm(((int)8));
		t_sample floor_21035 = floor(m_k_42);
		t_sample floor_21036 = floor(m_n_48);
		bool chan_ignore_121 = ((1 < 0) || (1 >= offsets_channels));
		bool chan_ignore_122 = ((2 < 0) || (2 >= offsets_channels));
		bool chan_ignore_123 = ((3 < 0) || (3 >= offsets_channels));
		bool chan_ignore_124 = ((4 < 0) || (4 >= offsets_channels));
		bool chan_ignore_125 = ((5 < 0) || (5 >= offsets_channels));
		bool chan_ignore_126 = ((6 < 0) || (6 >= offsets_channels));
		bool chan_ignore_127 = ((7 < 0) || (7 >= offsets_channels));
		t_sample min_138 = (-0.25);
		bool chan_ignore_139 = ((1 < 0) || (1 >= offsets_channels));
		bool chan_ignore_140 = ((2 < 0) || (2 >= offsets_channels));
		bool chan_ignore_141 = ((3 < 0) || (3 >= offsets_channels));
		bool chan_ignore_142 = ((4 < 0) || (4 >= offsets_channels));
		bool chan_ignore_143 = ((5 < 0) || (5 >= offsets_channels));
		bool chan_ignore_144 = ((6 < 0) || (6 >= offsets_channels));
		bool chan_ignore_145 = ((7 < 0) || (7 >= offsets_channels));
		t_sample min_156 = (-0.25);
		bool chan_ignore_157 = ((1 < 0) || (1 >= offsets_channels));
		bool chan_ignore_158 = ((2 < 0) || (2 >= offsets_channels));
		bool chan_ignore_159 = ((3 < 0) || (3 >= offsets_channels));
		bool chan_ignore_160 = ((4 < 0) || (4 >= offsets_channels));
		bool chan_ignore_161 = ((5 < 0) || (5 >= offsets_channels));
		bool chan_ignore_162 = ((6 < 0) || (6 >= offsets_channels));
		bool chan_ignore_163 = ((7 < 0) || (7 >= offsets_channels));
		t_sample min_174 = (-0.25);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out12 = ((int)0);
			t_sample out11 = ((int)0);
			int change_24304 = __m_change_57(int_24303);
			int eqp_24305 = ((int_24303 == change_24304) ? int_24303 : 0);
			__m_count_58 = (((int)0) ? 0 : (fixdenorm(__m_count_58 + eqp_24305)));
			int carry_59 = 0;
			if ((((int)0) != 0)) {
				__m_count_58 = 0;
				__m_carry_60 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_58 >= ((int)14)))) {
				int wraps_61 = (__m_count_58 / ((int)14));
				__m_carry_60 = (__m_carry_60 + wraps_61);
				__m_count_58 = (__m_count_58 - (wraps_61 * ((int)14)));
				carry_59 = 1;
				
			};
			int counter_24278 = __m_count_58;
			int counter_24279 = carry_59;
			int counter_24280 = __m_carry_60;
			t_sample div_24267 = (counter_24278 * ((t_sample)0.071428571428571));
			t_sample div_24268 = (counter_24278 * ((t_sample)0.14285714285714));
			int plusequals_24286 = __m_pluseq_62.post(((int)1), ((int)0), 0);
			int lt_24284 = (plusequals_24286 < ((int)100));
			t_sample noise_24283 = noise();
			t_sample add_24269 = (noise_24283 + ((int)1));
			t_sample floor_24282 = floor(add_24269);
			t_sample switch_24281 = (lt_24284 ? floor_24282 : div_24268);
			t_sample mul_24276 = (switch_24281 * ((int)7));
			t_sample add_24274 = (mul_24276 + ((int)12));
			t_sample round_24272 = round(add_24274);
			t_sample div_24273 = (round_24272 * ((t_sample)0.14285714285714));
			if ((!chan_ignore_63)) {
				m_offsets_56.write(div_24273, 0, ((int)7));
				
			};
			t_sample out10 = div_24267;
			int change_28299 = __m_change_64(int_28298);
			int eqp_28300 = ((int_28298 == change_28299) ? int_28298 : 0);
			__m_count_65 = (((int)0) ? 0 : (fixdenorm(__m_count_65 + eqp_28300)));
			int carry_66 = 0;
			if ((((int)0) != 0)) {
				__m_count_65 = 0;
				__m_carry_67 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_65 >= ((int)14)))) {
				int wraps_68 = (__m_count_65 / ((int)14));
				__m_carry_67 = (__m_carry_67 + wraps_68);
				__m_count_65 = (__m_count_65 - (wraps_68 * ((int)14)));
				carry_66 = 1;
				
			};
			int counter_28318 = __m_count_65;
			int counter_28304 = carry_66;
			int counter_28315 = __m_carry_67;
			t_sample div_28305 = (counter_28318 * ((t_sample)0.071428571428571));
			t_sample div_28319 = (counter_28318 * ((t_sample)0.14285714285714));
			int plusequals_28308 = __m_pluseq_69.post(((int)1), ((int)0), 0);
			int lt_28303 = (plusequals_28308 < ((int)100));
			t_sample noise_28302 = noise();
			t_sample add_28309 = (noise_28302 + ((int)1));
			t_sample floor_28316 = floor(add_28309);
			t_sample switch_28311 = (lt_28303 ? floor_28316 : div_28319);
			t_sample mul_28301 = (switch_28311 * ((int)7));
			t_sample add_28320 = (mul_28301 + ((int)12));
			t_sample round_28306 = round(add_28320);
			t_sample div_28314 = (round_28306 * ((t_sample)0.14285714285714));
			t_sample out7 = div_28305;
			if ((!chan_ignore_70)) {
				m_offsets_56.write(div_28314, 0, ((int)4));
				
			};
			int change_28322 = __m_change_71(int_28321);
			int eqp_28323 = ((int_28321 == change_28322) ? int_28321 : 0);
			__m_count_72 = (((int)0) ? 0 : (fixdenorm(__m_count_72 + eqp_28323)));
			int carry_73 = 0;
			if ((((int)0) != 0)) {
				__m_count_72 = 0;
				__m_carry_74 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_72 >= ((int)14)))) {
				int wraps_75 = (__m_count_72 / ((int)14));
				__m_carry_74 = (__m_carry_74 + wraps_75);
				__m_count_72 = (__m_count_72 - (wraps_75 * ((int)14)));
				carry_73 = 1;
				
			};
			int counter_28341 = __m_count_72;
			int counter_28327 = carry_73;
			int counter_28339 = __m_carry_74;
			t_sample div_28328 = (counter_28341 * ((t_sample)0.071428571428571));
			t_sample div_28342 = (counter_28341 * ((t_sample)0.14285714285714));
			int plusequals_28331 = __m_pluseq_76.post(((int)1), ((int)0), 0);
			int lt_28326 = (plusequals_28331 < ((int)100));
			t_sample noise_28325 = noise();
			t_sample add_28332 = (noise_28325 + ((int)1));
			t_sample floor_28340 = floor(add_28332);
			t_sample switch_28334 = (lt_28326 ? floor_28340 : div_28342);
			t_sample mul_28324 = (switch_28334 * ((int)7));
			t_sample add_28343 = (mul_28324 + ((int)12));
			t_sample round_28329 = round(add_28343);
			t_sample div_28338 = (round_28329 * ((t_sample)0.14285714285714));
			t_sample out9 = div_28328;
			if ((!chan_ignore_77)) {
				m_offsets_56.write(div_28338, 0, ((int)6));
				
			};
			int change_28345 = __m_change_78(int_28346);
			int eqp_28344 = ((int_28346 == change_28345) ? int_28346 : 0);
			__m_count_79 = (((int)0) ? 0 : (fixdenorm(__m_count_79 + eqp_28344)));
			int carry_80 = 0;
			if ((((int)0) != 0)) {
				__m_count_79 = 0;
				__m_carry_81 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_79 >= ((int)14)))) {
				int wraps_82 = (__m_count_79 / ((int)14));
				__m_carry_81 = (__m_carry_81 + wraps_82);
				__m_count_79 = (__m_count_79 - (wraps_82 * ((int)14)));
				carry_80 = 1;
				
			};
			int counter_28366 = __m_count_79;
			int counter_28347 = carry_80;
			int counter_28351 = __m_carry_81;
			t_sample div_28354 = (counter_28366 * ((t_sample)0.071428571428571));
			t_sample div_28353 = (counter_28366 * ((t_sample)0.14285714285714));
			int plusequals_28357 = __m_pluseq_83.post(((int)1), ((int)0), 0);
			int lt_28365 = (plusequals_28357 < ((int)100));
			t_sample noise_28359 = noise();
			t_sample add_28349 = (noise_28359 + ((int)1));
			t_sample floor_28352 = floor(add_28349);
			t_sample switch_28362 = (lt_28365 ? floor_28352 : div_28353);
			t_sample mul_28358 = (switch_28362 * ((int)7));
			t_sample add_28360 = (mul_28358 + ((int)12));
			t_sample round_28355 = round(add_28360);
			t_sample div_28364 = (round_28355 * ((t_sample)0.14285714285714));
			if ((!chan_ignore_84)) {
				m_offsets_56.write(div_28364, 0, ((int)3));
				
			};
			t_sample out6 = div_28354;
			int change_28368 = __m_change_85(int_28369);
			int eqp_28367 = ((int_28369 == change_28368) ? int_28369 : 0);
			__m_count_86 = (((int)0) ? 0 : (fixdenorm(__m_count_86 + eqp_28367)));
			int carry_87 = 0;
			if ((((int)0) != 0)) {
				__m_count_86 = 0;
				__m_carry_88 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_86 >= ((int)14)))) {
				int wraps_89 = (__m_count_86 / ((int)14));
				__m_carry_88 = (__m_carry_88 + wraps_89);
				__m_count_86 = (__m_count_86 - (wraps_89 * ((int)14)));
				carry_87 = 1;
				
			};
			int counter_28389 = __m_count_86;
			int counter_28370 = carry_87;
			int counter_28374 = __m_carry_88;
			t_sample div_28377 = (counter_28389 * ((t_sample)0.071428571428571));
			t_sample div_28376 = (counter_28389 * ((t_sample)0.14285714285714));
			int plusequals_28380 = __m_pluseq_90.post(((int)1), ((int)0), 0);
			int lt_28388 = (plusequals_28380 < ((int)100));
			t_sample noise_28382 = noise();
			t_sample add_28372 = (noise_28382 + ((int)1));
			t_sample floor_28375 = floor(add_28372);
			t_sample switch_28385 = (lt_28388 ? floor_28375 : div_28376);
			t_sample mul_28381 = (switch_28385 * ((int)7));
			t_sample add_28383 = (mul_28381 + ((int)12));
			t_sample round_28378 = round(add_28383);
			t_sample div_28387 = (round_28378 * ((t_sample)0.14285714285714));
			t_sample out5 = div_28377;
			if ((!chan_ignore_91)) {
				m_offsets_56.write(div_28387, 0, ((int)2));
				
			};
			int change_28391 = __m_change_92(int_28392);
			int eqp_28390 = ((int_28392 == change_28391) ? int_28392 : 0);
			__m_count_93 = (((int)0) ? 0 : (fixdenorm(__m_count_93 + eqp_28390)));
			int carry_94 = 0;
			if ((((int)0) != 0)) {
				__m_count_93 = 0;
				__m_carry_95 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_93 >= ((int)14)))) {
				int wraps_96 = (__m_count_93 / ((int)14));
				__m_carry_95 = (__m_carry_95 + wraps_96);
				__m_count_93 = (__m_count_93 - (wraps_96 * ((int)14)));
				carry_94 = 1;
				
			};
			int counter_28396 = __m_count_93;
			int counter_28400 = carry_94;
			int counter_28394 = __m_carry_95;
			t_sample div_28403 = (counter_28396 * ((t_sample)0.071428571428571));
			t_sample div_28408 = (counter_28396 * ((t_sample)0.14285714285714));
			int plusequals_28406 = __m_pluseq_97.post(((int)1), ((int)0), 0);
			int lt_28402 = (plusequals_28406 < ((int)100));
			t_sample noise_28393 = noise();
			t_sample add_28405 = (noise_28393 + ((int)1));
			t_sample floor_28395 = floor(add_28405);
			t_sample switch_28410 = (lt_28402 ? floor_28395 : div_28408);
			t_sample mul_28399 = (switch_28410 * ((int)7));
			t_sample add_28412 = (mul_28399 + ((int)12));
			t_sample round_28411 = round(add_28412);
			t_sample div_28398 = (round_28411 * ((t_sample)0.14285714285714));
			t_sample out3 = div_28403;
			m_offsets_56.write(div_28398, 0, 0);
			int change_28414 = __m_change_98(int_28415);
			int eqp_28413 = ((int_28415 == change_28414) ? int_28415 : 0);
			__m_count_99 = (((int)0) ? 0 : (fixdenorm(__m_count_99 + eqp_28413)));
			int carry_100 = 0;
			if ((((int)0) != 0)) {
				__m_count_99 = 0;
				__m_carry_101 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_99 >= ((int)14)))) {
				int wraps_102 = (__m_count_99 / ((int)14));
				__m_carry_101 = (__m_carry_101 + wraps_102);
				__m_count_99 = (__m_count_99 - (wraps_102 * ((int)14)));
				carry_100 = 1;
				
			};
			int counter_28419 = __m_count_99;
			int counter_28423 = carry_100;
			int counter_28417 = __m_carry_101;
			t_sample div_28426 = (counter_28419 * ((t_sample)0.071428571428571));
			t_sample div_28431 = (counter_28419 * ((t_sample)0.14285714285714));
			int plusequals_28429 = __m_pluseq_103.post(((int)1), ((int)0), 0);
			int lt_28425 = (plusequals_28429 < ((int)100));
			t_sample noise_28416 = noise();
			t_sample add_28428 = (noise_28416 + ((int)1));
			t_sample floor_28418 = floor(add_28428);
			t_sample switch_28433 = (lt_28425 ? floor_28418 : div_28431);
			t_sample mul_28422 = (switch_28433 * ((int)7));
			t_sample add_28435 = (mul_28422 + ((int)12));
			t_sample round_28434 = round(add_28435);
			t_sample div_28421 = (round_28434 * ((t_sample)0.14285714285714));
			if ((!chan_ignore_104)) {
				m_offsets_56.write(div_28421, 0, ((int)5));
				
			};
			t_sample out8 = div_28426;
			int change_28437 = __m_change_105(int_28438);
			int eqp_28436 = ((int_28438 == change_28437) ? int_28438 : 0);
			__m_count_106 = (((int)0) ? 0 : (fixdenorm(__m_count_106 + eqp_28436)));
			int carry_107 = 0;
			if ((((int)0) != 0)) {
				__m_count_106 = 0;
				__m_carry_108 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_106 >= ((int)14)))) {
				int wraps_109 = (__m_count_106 / ((int)14));
				__m_carry_108 = (__m_carry_108 + wraps_109);
				__m_count_106 = (__m_count_106 - (wraps_109 * ((int)14)));
				carry_107 = 1;
				
			};
			int counter_28442 = __m_count_106;
			int counter_28447 = carry_107;
			int counter_28440 = __m_carry_108;
			t_sample div_28450 = (counter_28442 * ((t_sample)0.071428571428571));
			t_sample div_28454 = (counter_28442 * ((t_sample)0.14285714285714));
			int plusequals_28452 = __m_pluseq_110.post(((int)1), ((int)0), 0);
			int lt_28449 = (plusequals_28452 < ((int)100));
			t_sample noise_28439 = noise();
			t_sample add_28445 = (noise_28439 + ((int)1));
			t_sample floor_28441 = floor(add_28445);
			t_sample switch_28456 = (lt_28449 ? floor_28441 : div_28454);
			t_sample mul_28446 = (switch_28456 * ((int)7));
			t_sample add_28458 = (mul_28446 + ((int)12));
			t_sample round_28457 = round(add_28458);
			t_sample div_28444 = (round_28457 * ((t_sample)0.14285714285714));
			if ((!chan_ignore_111)) {
				m_offsets_56.write(div_28444, 0, ((int)1));
				
			};
			t_sample out4 = div_28450;
			t_sample phasor_20894 = __m_phasor_112(div_20893, samples_to_seconds);
			t_sample mul_20892 = (phasor_20894 * ((int)4));
			t_sample wrap_20891 = wrap(mul_20892, ((int)0), ((int)1));
			t_sample gen_20899 = wrap_20891;
			t_sample mul_21076 = (gen_20899 * ((t_sample)0.125));
			t_sample sub_21047 = (gen_20899 - m_history_40);
			t_sample add_21048 = (gen_20899 + m_history_40);
			t_sample div_21046 = safediv(sub_21047, add_21048);
			t_sample abs_21045 = fabs(div_21046);
			int gt_21043 = (abs_21045 > ((t_sample)0.5));
			int change_21042 = __m_change_113(gt_21043);
			int gt_21041 = (change_21042 > ((int)0));
			int gen_21086 = gt_21041;
			t_sample history_21044_next_21049 = fixdenorm(gen_20899);
			t_sample delta_21092 = __m_delta_114(gen_20899);
			t_sample wrap_21093 = wrap(delta_21092, (-0.5), ((t_sample)0.5));
			t_sample gen_21094 = wrap_21093;
			t_sample mul_21089 = (gen_21094 * ((t_sample)0.125));
			t_sample add_21087 = (mul_21089 + m_history_37);
			t_sample sub_21074 = (add_21087 - mul_21076);
			t_sample round_21085 = (trunc((sub_21074 * ((t_sample)8))) * ((t_sample)0.125));
			t_sample add_21075 = (round_21085 + mul_21076);
			t_sample sub_21096 = (m_history_38 - ((int)8));
			t_sample add_21097 = (m_history_38 + ((int)8));
			t_sample div_21095 = safediv(sub_21096, add_21097);
			t_sample abs_21069 = fabs(div_21095);
			int gt_21070 = (abs_21069 > ((t_sample)0.015625));
			int and_21073 = (gt_21070 && ((int)1));
			t_sample switch_21077 = (and_21073 ? and_21073 : m_history_39);
			t_sample switch_21080 = (gen_21086 ? switch_21077 : ((int)0));
			t_sample gen_21083 = switch_21080;
			t_sample switch_21079 = (switch_21080 ? ((int)0) : switch_21077);
			t_sample history_21081_next_21082 = fixdenorm(switch_21079);
			int or_21072 = (gen_21083 || ((int)0));
			t_sample switch_21091 = (or_21072 ? add_21075 : add_21087);
			t_sample wrap_21088 = wrap(switch_21091, ((int)0), ((int)1));
			t_sample gen_21100 = wrap_21088;
			t_sample history_21090_next_21099 = fixdenorm(wrap_21088);
			t_sample sub_28467 = (gen_21100 - m_history_36);
			t_sample add_28462 = (gen_21100 + m_history_36);
			t_sample div_28466 = safediv(sub_28467, add_28462);
			t_sample abs_28461 = fabs(div_28466);
			int gt_28459 = (abs_28461 > ((t_sample)0.5));
			int change_28465 = __m_change_115(gt_28459);
			int gt_28464 = (change_28465 > ((int)0));
			int gen_21067 = gt_28464;
			t_sample history_21044_next_28460 = fixdenorm(gen_21100);
			t_sample mul_21039 = (gen_21100 * ((int)16));
			t_sample wrap_21038 = wrap(mul_21039, ((int)0), ((int)1));
			t_sample sub_28477 = (wrap_21038 - m_history_35);
			t_sample add_28473 = (wrap_21038 + m_history_35);
			t_sample div_28476 = safediv(sub_28477, add_28473);
			t_sample abs_28471 = fabs(div_28476);
			int gt_28469 = (abs_28471 > ((t_sample)0.5));
			int change_28475 = __m_change_116(gt_28469);
			int gt_28474 = (change_28475 > ((int)0));
			int gen_21050 = gt_28474;
			t_sample history_21044_next_28470 = fixdenorm(wrap_21038);
			__m_latch_117 = ((gen_21050 != 0) ? floor_21035 : __m_latch_117);
			t_sample latch_21053 = __m_latch_117;
			t_sample abs_21026 = fabs(latch_21053);
			__m_latch_118 = ((gen_21050 != 0) ? floor_21036 : __m_latch_118);
			t_sample latch_21052 = __m_latch_118;
			t_sample abs_21025 = fabs(latch_21052);
			t_sample min_21023 = ((abs_21025 < abs_21026) ? abs_21025 : abs_21026);
			t_sample max_21024 = ((abs_21026 < abs_21025) ? abs_21025 : abs_21026);
			t_sample div_21027 = safediv(min_21023, max_21024);
			t_sample mul_21022 = (latch_21053 * latch_21052);
			int sign_21029 = ((mul_21022 > 0) ? 1 : ((mul_21022 < 0) ? -1 : 0));
			__m_latch_119 = ((gen_21050 != 0) ? ((int)0) : __m_latch_119);
			int latch_21051 = __m_latch_119;
			t_sample sub_21060 = (mul_21039 - latch_21051);
			t_sample mul_21028 = (sub_21060 * sign_21029);
			t_sample wrap_21054 = wrap(mul_21028, ((int)0), max_21024);
			t_sample floor_21061 = floor(wrap_21054);
			t_sample mul_21056 = (floor_21061 * div_21027);
			t_sample floor_21059 = floor(mul_21056);
			t_sample div_21058 = safediv(floor_21059, div_21027);
			t_sample ceil_21057 = ceil(div_21058);
			t_sample add_21031 = (floor_21059 + ((int)1));
			t_sample div_21033 = safediv(add_21031, div_21027);
			t_sample ceil_21032 = ceil(div_21033);
			t_sample sub_21030 = (ceil_21032 - ceil_21057);
			t_sample sub_21055 = (wrap_21054 - ceil_21057);
			t_sample div_21040 = safediv(sub_21055, sub_21030);
			t_sample gen_21063 = div_21040;
			t_sample sub_28487 = (gen_21063 - m_history_34);
			t_sample add_28483 = (gen_21063 + m_history_34);
			t_sample div_28484 = safediv(sub_28487, add_28483);
			t_sample abs_28481 = fabs(div_28484);
			int gt_28479 = (abs_28481 > ((t_sample)0.5));
			int change_28486 = __m_change_120(gt_28479);
			int gt_28485 = (change_28486 > ((int)0));
			int gen_21108 = gt_28485;
			t_sample history_21044_next_28480 = fixdenorm(gen_21063);
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_20970 = m_offsets_56.read(0, 0);
			t_sample sample_offsets_20971 = (chan_ignore_121 ? 0 : m_offsets_56.read(0, 1));
			t_sample sample_offsets_20972 = (chan_ignore_122 ? 0 : m_offsets_56.read(0, 2));
			t_sample sample_offsets_20973 = (chan_ignore_123 ? 0 : m_offsets_56.read(0, 3));
			t_sample sample_offsets_20974 = (chan_ignore_124 ? 0 : m_offsets_56.read(0, 4));
			t_sample sample_offsets_20975 = (chan_ignore_125 ? 0 : m_offsets_56.read(0, 5));
			t_sample sample_offsets_20976 = (chan_ignore_126 ? 0 : m_offsets_56.read(0, 6));
			t_sample sample_offsets_20977 = (chan_ignore_127 ? 0 : m_offsets_56.read(0, 7));
			t_sample index_offsets_20978 = ((int)0);
			t_sample noise_20966 = noise();
			t_sample abs_20965 = fabs(noise_20966);
			int lt_20967 = (abs_20965 < m_chancetwo_41);
			t_sample switch_20968 = (((int)0) ? m_history_23 : lt_20967);
			__m_latch_128 = ((gen_21067 != 0) ? m_history_29 : __m_latch_128);
			t_sample latch_20988 = __m_latch_128;
			t_sample gen_21004 = latch_20988;
			__m_latch_129 = ((gen_21067 != 0) ? m_history_30 : __m_latch_129);
			t_sample latch_20983 = __m_latch_129;
			t_sample gen_21007 = latch_20983;
			__m_latch_130 = ((gen_21067 != 0) ? m_history_33 : __m_latch_130);
			t_sample latch_20986 = __m_latch_130;
			t_sample gen_21005 = latch_20986;
			__m_latch_131 = ((gen_21067 != 0) ? m_history_31 : __m_latch_131);
			t_sample latch_20985 = __m_latch_131;
			t_sample gen_21006 = latch_20985;
			__m_latch_132 = ((gen_21067 != 0) ? m_history_28 : __m_latch_132);
			t_sample latch_20990 = __m_latch_132;
			t_sample gen_21003 = latch_20990;
			__m_latch_133 = ((gen_21067 != 0) ? m_history_32 : __m_latch_133);
			t_sample latch_20981 = __m_latch_133;
			t_sample gen_21008 = latch_20981;
			__m_latch_134 = ((gen_21067 != 0) ? m_history_27 : __m_latch_134);
			t_sample latch_20992 = __m_latch_134;
			t_sample gen_21002 = latch_20992;
			__m_latch_135 = ((gen_21067 != 0) ? switch_20968 : __m_latch_135);
			t_sample latch_20993 = __m_latch_135;
			t_sample gen_21001 = latch_20993;
			t_sample history_20979_next_20994 = fixdenorm(latch_20988);
			t_sample history_20980_next_20995 = fixdenorm(latch_20983);
			t_sample history_20984_next_20996 = fixdenorm(latch_20986);
			t_sample history_20982_next_20997 = fixdenorm(latch_20985);
			t_sample history_20987_next_20998 = fixdenorm(latch_20990);
			t_sample history_20989_next_20999 = fixdenorm(latch_20992);
			t_sample history_20991_next_21000 = fixdenorm(latch_20993);
			t_sample mul_21009 = (gen_21008 * sample_offsets_20977);
			t_sample mul_21010 = (gen_21007 * sample_offsets_20976);
			t_sample mul_21011 = (gen_21006 * sample_offsets_20975);
			t_sample mul_21012 = (gen_21005 * sample_offsets_20974);
			t_sample mul_21013 = (gen_21004 * sample_offsets_20973);
			t_sample mul_21014 = (gen_21003 * sample_offsets_20972);
			t_sample mul_21015 = (gen_21002 * sample_offsets_20971);
			t_sample mul_21016 = (gen_21001 * sample_offsets_20970);
			t_sample pass_21017 = (((((((mul_21016 + mul_21015) + mul_21014) + mul_21013) + mul_21012) + mul_21011) + mul_21010) + mul_21009);
			int change_20962 = __m_change_136(gen_21108);
			int neq_20961 = (change_20962 != ((int)0));
			t_sample switch_20952 = (neq_20961 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_28680 = (m_history_26 + (switch_20952 * (neq_20961 - m_history_26)));
			t_sample mix_20951 = mix_28680;
			t_sample mix_28681 = (m_history_25 + (((t_sample)0.04) * (mix_20951 - m_history_25)));
			t_sample mix_20949 = mix_28681;
			t_sample gen_20955 = mix_20949;
			t_sample history_20950_next_20953 = fixdenorm(mix_20951);
			t_sample history_20948_next_20954 = fixdenorm(mix_20949);
			t_sample mul_20944 = (gen_20955 * ((int)100));
			t_sample add_20956 = (pass_21017 + ((int)60));
			t_sample mtof_20957 = mtof(add_20956, ((int)440));
			__m_cycle_137.freq((m_history_24 + mtof_20957));
			t_sample cycle_20958 = __m_cycle_137(__sinedata);
			t_sample cycleindex_20959 = __m_cycle_137.phase();
			t_sample clamp_20946 = ((cycle_20958 <= min_138) ? min_138 : ((cycle_20958 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_20958));
			t_sample mul_20960 = (clamp_20946 * gen_20955);
			t_sample mul_20945 = (clamp_20946 * mul_20944);
			t_sample history_20947_next_20963 = fixdenorm(mul_20945);
			t_sample history_20969_next_21018 = fixdenorm(gen_21008);
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_28543 = m_offsets_56.read(0, 0);
			t_sample sample_offsets_28520 = (chan_ignore_139 ? 0 : m_offsets_56.read(0, 1));
			t_sample sample_offsets_28522 = (chan_ignore_140 ? 0 : m_offsets_56.read(0, 2));
			t_sample sample_offsets_28542 = (chan_ignore_141 ? 0 : m_offsets_56.read(0, 3));
			t_sample sample_offsets_28497 = (chan_ignore_142 ? 0 : m_offsets_56.read(0, 4));
			t_sample sample_offsets_28554 = (chan_ignore_143 ? 0 : m_offsets_56.read(0, 5));
			t_sample sample_offsets_28490 = (chan_ignore_144 ? 0 : m_offsets_56.read(0, 6));
			t_sample sample_offsets_28510 = (chan_ignore_145 ? 0 : m_offsets_56.read(0, 7));
			t_sample index_offsets_28531 = ((int)0);
			t_sample noise_28548 = noise();
			t_sample abs_28489 = fabs(noise_28548);
			int lt_28540 = (abs_28489 < m_chancethree_54);
			t_sample switch_28552 = (((int)0) ? m_history_12 : lt_28540);
			__m_latch_146 = ((gen_21067 != 0) ? m_history_18 : __m_latch_146);
			t_sample latch_28539 = __m_latch_146;
			t_sample gen_28555 = latch_28539;
			__m_latch_147 = ((gen_21067 != 0) ? m_history_19 : __m_latch_147);
			t_sample latch_28538 = __m_latch_147;
			t_sample gen_28546 = latch_28538;
			__m_latch_148 = ((gen_21067 != 0) ? m_history_22 : __m_latch_148);
			t_sample latch_28501 = __m_latch_148;
			t_sample gen_28550 = latch_28501;
			__m_latch_149 = ((gen_21067 != 0) ? m_history_20 : __m_latch_149);
			t_sample latch_28556 = __m_latch_149;
			t_sample gen_28536 = latch_28556;
			__m_latch_150 = ((gen_21067 != 0) ? m_history_17 : __m_latch_150);
			t_sample latch_28535 = __m_latch_150;
			t_sample gen_28505 = latch_28535;
			__m_latch_151 = ((gen_21067 != 0) ? m_history_21 : __m_latch_151);
			t_sample latch_28533 = __m_latch_151;
			t_sample gen_28544 = latch_28533;
			__m_latch_152 = ((gen_21067 != 0) ? m_history_16 : __m_latch_152);
			t_sample latch_28495 = __m_latch_152;
			t_sample gen_28500 = latch_28495;
			__m_latch_153 = ((gen_21067 != 0) ? switch_28552 : __m_latch_153);
			t_sample latch_28492 = __m_latch_153;
			t_sample gen_28532 = latch_28492;
			t_sample history_20979_next_28511 = fixdenorm(latch_28539);
			t_sample history_20980_next_28529 = fixdenorm(latch_28538);
			t_sample history_20984_next_28528 = fixdenorm(latch_28501);
			t_sample history_20982_next_28526 = fixdenorm(latch_28556);
			t_sample history_20987_next_28525 = fixdenorm(latch_28535);
			t_sample history_20989_next_28541 = fixdenorm(latch_28495);
			t_sample history_20991_next_28524 = fixdenorm(latch_28492);
			t_sample mul_28523 = (gen_28544 * sample_offsets_28510);
			t_sample mul_28557 = (gen_28546 * sample_offsets_28490);
			t_sample mul_28553 = (gen_28536 * sample_offsets_28554);
			t_sample mul_28502 = (gen_28550 * sample_offsets_28497);
			t_sample mul_28549 = (gen_28555 * sample_offsets_28542);
			t_sample mul_28518 = (gen_28505 * sample_offsets_28522);
			t_sample mul_28560 = (gen_28500 * sample_offsets_28520);
			t_sample mul_28517 = (gen_28532 * sample_offsets_28543);
			t_sample pass_28516 = (((((((mul_28517 + mul_28560) + mul_28518) + mul_28549) + mul_28502) + mul_28553) + mul_28557) + mul_28523);
			int change_28515 = __m_change_154(gen_21108);
			int neq_28514 = (change_28515 != ((int)0));
			t_sample switch_28513 = (neq_28514 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_28682 = (m_history_15 + (switch_28513 * (neq_28514 - m_history_15)));
			t_sample mix_28512 = mix_28682;
			t_sample mix_28683 = (m_history_14 + (((t_sample)0.04) * (mix_28512 - m_history_14)));
			t_sample mix_28530 = mix_28683;
			t_sample gen_28509 = mix_28530;
			t_sample history_20950_next_28545 = fixdenorm(mix_28512);
			t_sample history_20948_next_28537 = fixdenorm(mix_28530);
			t_sample mul_28519 = (gen_28509 * ((int)100));
			t_sample add_28508 = (pass_28516 + ((int)60));
			t_sample mtof_28507 = mtof(add_28508, ((int)440));
			__m_cycle_155.freq((m_history_13 + mtof_28507));
			t_sample cycle_28506 = __m_cycle_155(__sinedata);
			t_sample cycleindex_28499 = __m_cycle_155.phase();
			t_sample clamp_28559 = ((cycle_28506 <= min_156) ? min_156 : ((cycle_28506 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_28506));
			t_sample mul_28534 = (clamp_28559 * gen_28509);
			t_sample mul_28496 = (clamp_28559 * mul_28519);
			t_sample history_20947_next_28503 = fixdenorm(mul_28496);
			t_sample history_20969_next_28498 = fixdenorm(gen_28544);
			t_sample mix_28684 = (mul_20960 + (((t_sample)0.75) * (mul_28534 - mul_20960)));
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_28579 = m_offsets_56.read(0, 0);
			t_sample sample_offsets_28616 = (chan_ignore_157 ? 0 : m_offsets_56.read(0, 1));
			t_sample sample_offsets_28619 = (chan_ignore_158 ? 0 : m_offsets_56.read(0, 2));
			t_sample sample_offsets_28629 = (chan_ignore_159 ? 0 : m_offsets_56.read(0, 3));
			t_sample sample_offsets_28587 = (chan_ignore_160 ? 0 : m_offsets_56.read(0, 4));
			t_sample sample_offsets_28640 = (chan_ignore_161 ? 0 : m_offsets_56.read(0, 5));
			t_sample sample_offsets_28576 = (chan_ignore_162 ? 0 : m_offsets_56.read(0, 6));
			t_sample sample_offsets_28608 = (chan_ignore_163 ? 0 : m_offsets_56.read(0, 7));
			t_sample index_offsets_28624 = ((int)0);
			t_sample noise_28634 = noise();
			t_sample abs_28575 = fabs(noise_28634);
			int lt_28628 = (abs_28575 < m_chanceone_53);
			t_sample switch_28638 = (((int)0) ? m_history_1 : lt_28628);
			__m_latch_164 = ((gen_21067 != 0) ? m_history_7 : __m_latch_164);
			t_sample latch_28626 = __m_latch_164;
			t_sample gen_28641 = latch_28626;
			__m_latch_165 = ((gen_21067 != 0) ? m_history_8 : __m_latch_165);
			t_sample latch_28590 = __m_latch_165;
			t_sample gen_28633 = latch_28590;
			__m_latch_166 = ((gen_21067 != 0) ? m_history_11 : __m_latch_166);
			t_sample latch_28597 = __m_latch_166;
			t_sample gen_28636 = latch_28597;
			__m_latch_167 = ((gen_21067 != 0) ? m_history_9 : __m_latch_167);
			t_sample latch_28642 = __m_latch_167;
			t_sample gen_28582 = latch_28642;
			__m_latch_168 = ((gen_21067 != 0) ? m_history_6 : __m_latch_168);
			t_sample latch_28622 = __m_latch_168;
			t_sample gen_28621 = latch_28622;
			__m_latch_169 = ((gen_21067 != 0) ? m_history_10 : __m_latch_169);
			t_sample latch_28620 = __m_latch_169;
			t_sample gen_28631 = latch_28620;
			__m_latch_170 = ((gen_21067 != 0) ? m_history_5 : __m_latch_170);
			t_sample latch_28585 = __m_latch_170;
			t_sample gen_28596 = latch_28585;
			__m_latch_171 = ((gen_21067 != 0) ? switch_28638 : __m_latch_171);
			t_sample latch_28580 = __m_latch_171;
			t_sample gen_28618 = latch_28580;
			t_sample history_20979_next_28594 = fixdenorm(latch_28626);
			t_sample history_20980_next_28614 = fixdenorm(latch_28590);
			t_sample history_20984_next_28613 = fixdenorm(latch_28597);
			t_sample history_20982_next_28612 = fixdenorm(latch_28642);
			t_sample history_20987_next_28611 = fixdenorm(latch_28622);
			t_sample history_20989_next_28630 = fixdenorm(latch_28585);
			t_sample history_20991_next_28610 = fixdenorm(latch_28580);
			t_sample mul_28609 = (gen_28631 * sample_offsets_28608);
			t_sample mul_28643 = (gen_28633 * sample_offsets_28576);
			t_sample mul_28639 = (gen_28582 * sample_offsets_28640);
			t_sample mul_28598 = (gen_28636 * sample_offsets_28587);
			t_sample mul_28635 = (gen_28641 * sample_offsets_28629);
			t_sample mul_28607 = (gen_28621 * sample_offsets_28619);
			t_sample mul_28646 = (gen_28596 * sample_offsets_28616);
			t_sample mul_28606 = (gen_28618 * sample_offsets_28579);
			t_sample pass_28605 = (((((((mul_28606 + mul_28646) + mul_28607) + mul_28635) + mul_28598) + mul_28639) + mul_28643) + mul_28609);
			int change_28604 = __m_change_172(gen_21108);
			int neq_28603 = (change_28604 != ((int)0));
			t_sample switch_28602 = (neq_28603 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_28685 = (m_history_4 + (switch_28602 * (neq_28603 - m_history_4)));
			t_sample mix_28601 = mix_28685;
			t_sample mix_28686 = (m_history_3 + (((t_sample)0.04) * (mix_28601 - m_history_3)));
			t_sample mix_28600 = mix_28686;
			t_sample gen_28599 = mix_28600;
			t_sample history_20950_next_28632 = fixdenorm(mix_28601);
			t_sample history_20948_next_28627 = fixdenorm(mix_28600);
			t_sample mul_28615 = (gen_28599 * ((int)100));
			t_sample add_28593 = (pass_28605 + ((int)60));
			t_sample mtof_28592 = mtof(add_28593, ((int)440));
			__m_cycle_173.freq((m_history_2 + mtof_28592));
			t_sample cycle_28591 = __m_cycle_173(__sinedata);
			t_sample cycleindex_28595 = __m_cycle_173.phase();
			t_sample clamp_28645 = ((cycle_28591 <= min_174) ? min_174 : ((cycle_28591 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_28591));
			t_sample mul_28625 = (clamp_28645 * gen_28599);
			t_sample mul_28586 = (clamp_28645 * mul_28615);
			t_sample history_20947_next_28588 = fixdenorm(mul_28586);
			t_sample history_20969_next_28584 = fixdenorm(gen_28631);
			t_sample mix_28687 = (mul_28625 + (((t_sample)0.25) * (mul_20960 - mul_28625)));
			t_sample mix_28688 = (mix_28684 + (((t_sample)0.25) * (mix_28687 - mix_28684)));
			t_sample mul_20903 = (mix_28688 * ((t_sample)0.3));
			t_sample mix_28689 = (mul_20903 + (((t_sample)0.7) * (in2 - mul_20903)));
			t_sample out2 = mix_28689;
			t_sample mix_28690 = (mix_28687 + (((t_sample)0.25) * (mix_28684 - mix_28687)));
			t_sample mul_20904 = (mix_28690 * ((t_sample)0.3));
			t_sample mix_28691 = (mul_20904 + (((t_sample)0.7) * (in1 - mul_20904)));
			t_sample out1 = mix_28691;
			m_history_40 = history_21044_next_21049;
			m_history_37 = history_21090_next_21099;
			m_history_38 = history_21071_next_21098;
			m_history_39 = history_21081_next_21082;
			m_history_36 = history_21044_next_28460;
			m_history_35 = history_21044_next_28470;
			m_history_34 = history_21044_next_28480;
			m_history_33 = history_20979_next_20994;
			m_history_23 = history_20969_next_21018;
			m_history_25 = history_20948_next_20954;
			m_history_24 = history_20947_next_20963;
			m_history_26 = history_20950_next_20953;
			m_history_32 = history_20980_next_20995;
			m_history_31 = history_20984_next_20996;
			m_history_30 = history_20982_next_20997;
			m_history_29 = history_20987_next_20998;
			m_history_28 = history_20989_next_20999;
			m_history_27 = history_20991_next_21000;
			m_history_22 = history_20979_next_28511;
			m_history_12 = history_20969_next_28498;
			m_history_14 = history_20948_next_28537;
			m_history_13 = history_20947_next_28503;
			m_history_15 = history_20950_next_28545;
			m_history_21 = history_20980_next_28529;
			m_history_20 = history_20984_next_28528;
			m_history_19 = history_20982_next_28526;
			m_history_18 = history_20987_next_28525;
			m_history_17 = history_20989_next_28541;
			m_history_16 = history_20991_next_28524;
			m_history_11 = history_20979_next_28594;
			m_history_1 = history_20969_next_28584;
			m_history_3 = history_20948_next_28627;
			m_history_2 = history_20947_next_28588;
			m_history_4 = history_20950_next_28632;
			m_history_10 = history_20980_next_28614;
			m_history_9 = history_20984_next_28613;
			m_history_8 = history_20982_next_28612;
			m_history_7 = history_20987_next_28611;
			m_history_6 = history_20989_next_28630;
			m_history_5 = history_20991_next_28610;
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
	inline void set_chancetwo(t_param _value) {
		m_chancetwo_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k(t_param _value) {
		m_k_42 = (_value < 1 ? 1 : (_value > 16 ? 16 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_43 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_45 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_n(t_param _value) {
		m_n_48 = (_value < 1 ? 1 : (_value > 16 ? 16 : _value));
	};
	inline void set_bpm(t_param _value) {
		m_bpm_49 = (_value < 40 ? 40 : (_value > 200 ? 200 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_50 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_51 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_chanceone(t_param _value) {
		m_chanceone_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_chancethree(t_param _value) {
		m_chancethree_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_offsets(void * _value) {
		m_offsets_56.setbuffer(_value);
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
		case 0: self->set_bpm(value); break;
		case 1: self->set_chanceone(value); break;
		case 2: self->set_chancethree(value); break;
		case 3: self->set_chancetwo(value); break;
		case 4: self->set_gate1(value); break;
		case 5: self->set_k(value); break;
		case 6: self->set_n(value); break;
		case 7: self->set_offsets(ref); break;
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
		case 0: *value = self->m_bpm_49; break;
		case 1: *value = self->m_chanceone_53; break;
		case 2: *value = self->m_chancethree_54; break;
		case 3: *value = self->m_chancetwo_41; break;
		case 4: *value = self->m_gate_51; break;
		case 5: *value = self->m_k_42; break;
		case 6: *value = self->m_n_48; break;
		
		case 8: *value = self->m_sw_47; break;
		case 9: *value = self->m_sw_52; break;
		case 10: *value = self->m_sw_45; break;
		case 11: *value = self->m_sw_55; break;
		case 12: *value = self->m_sw_44; break;
		case 13: *value = self->m_sw_43; break;
		case 14: *value = self->m_sw_50; break;
		case 15: *value = self->m_sw_46; break;
		
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
	// initialize parameter 0 ("m_bpm_49")
	pi = self->__commonstate.params + 0;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 40;
	pi->outputmax = 200;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_chanceone_53")
	pi = self->__commonstate.params + 1;
	pi->name = "chanceone";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chanceone_53;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_chancethree_54")
	pi = self->__commonstate.params + 2;
	pi->name = "chancethree";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chancethree_54;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_chancetwo_41")
	pi = self->__commonstate.params + 3;
	pi->name = "chancetwo";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chancetwo_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_gate_51")
	pi = self->__commonstate.params + 4;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_51;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_k_42")
	pi = self->__commonstate.params + 5;
	pi->name = "k";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_42;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_n_48")
	pi = self->__commonstate.params + 6;
	pi->name = "n";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_offsets_56")
	pi = self->__commonstate.params + 7;
	pi->name = "offsets";
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
	// initialize parameter 8 ("m_sw_47")
	pi = self->__commonstate.params + 8;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_52")
	pi = self->__commonstate.params + 9;
	pi->name = "sw2";
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
	// initialize parameter 10 ("m_sw_45")
	pi = self->__commonstate.params + 10;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_45;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_sw_55")
	pi = self->__commonstate.params + 11;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_55;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_44")
	pi = self->__commonstate.params + 12;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_43")
	pi = self->__commonstate.params + 13;
	pi->name = "sw6";
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
	// initialize parameter 14 ("m_sw_50")
	pi = self->__commonstate.params + 14;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_50;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_46")
	pi = self->__commonstate.params + 15;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_46;
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


} // harmonia_2dterra::
