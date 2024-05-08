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
	Change __m_change_88;
	Change __m_change_73;
	Change __m_change_100;
	Change __m_change_102;
	Change __m_change_98;
	Change __m_change_83;
	Change __m_change_78;
	Change __m_change_93;
	Change __m_change_69;
	Change __m_change_105;
	Change __m_change_143;
	Change __m_change_64;
	Change __m_change_104;
	Change __m_change_161;
	Change __m_change_109;
	Change __m_change_125;
	Change __m_change_59;
	Data m_offsets_50;
	Delta __m_delta_103;
	PlusEquals __m_pluseq_70;
	PlusEquals __m_pluseq_71;
	PlusEquals __m_pluseq_89;
	PlusEquals __m_pluseq_90;
	PlusEquals __m_pluseq_61;
	PlusEquals __m_pluseq_65;
	PlusEquals __m_pluseq_60;
	PlusEquals __m_pluseq_74;
	PlusEquals __m_pluseq_99;
	PlusEquals __m_pluseq_95;
	PlusEquals __m_pluseq_84;
	PlusEquals __m_pluseq_85;
	PlusEquals __m_pluseq_75;
	PlusEquals __m_pluseq_94;
	PlusEquals __m_pluseq_66;
	PlusEquals __m_pluseq_80;
	PlusEquals __m_pluseq_79;
	SineCycle __m_cycle_126;
	SineCycle __m_cycle_144;
	SineCycle __m_cycle_162;
	SineData __sinedata;
	int vectorsize;
	int __exception;
	t_sample __m_latch_108;
	t_sample __m_latch_106;
	t_sample __m_latch_107;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample __m_latch_118;
	t_sample __m_latch_117;
	t_sample __m_latch_120;
	t_sample __m_latch_119;
	t_sample __m_latch_121;
	t_sample m_history_5;
	t_sample m_history_7;
	t_sample m_history_11;
	t_sample m_history_12;
	t_sample m_history_13;
	t_sample m_history_6;
	t_sample __m_latch_96;
	t_sample m_history_9;
	t_sample m_history_10;
	t_sample __m_latch_101;
	t_sample m_history_8;
	t_sample __m_latch_122;
	t_sample __m_latch_123;
	t_sample __m_latch_124;
	t_sample __m_latch_155;
	t_sample __m_latch_154;
	t_sample __m_latch_153;
	t_sample samplerate;
	t_sample __m_latch_156;
	t_sample __m_latch_158;
	t_sample __m_latch_157;
	t_sample __m_latch_160;
	t_sample __m_latch_159;
	t_sample __m_latch_91;
	t_sample __m_latch_142;
	t_sample __m_latch_140;
	t_sample __m_latch_135;
	t_sample m_history_1;
	t_sample m_history_2;
	t_sample __m_latch_141;
	t_sample __m_latch_136;
	t_sample __m_latch_138;
	t_sample __m_latch_137;
	t_sample __m_latch_139;
	t_sample m_history_36;
	t_sample m_history_14;
	t_sample m_history_16;
	t_sample m_sw_52;
	t_sample m_sw_53;
	t_sample m_chanceone_51;
	t_sample m_history_35;
	t_sample m_chancetwo_49;
	t_sample m_sw_54;
	t_sample m_k_56;
	t_sample m_sw_55;
	t_sample m_n_58;
	t_sample m_sw_57;
	t_sample m_history_34;
	t_sample m_chancethree_48;
	t_sample m_bpm_46;
	t_sample m_history_40;
	t_sample m_history_39;
	t_sample m_history_38;
	t_sample m_gate_47;
	t_sample m_history_41;
	t_sample m_sw_43;
	t_sample m_history_42;
	t_sample m_sw_45;
	t_sample m_sw_44;
	t_sample m_history_15;
	t_sample m_history_33;
	t_sample __m_latch_62;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample __m_latch_76;
	t_sample __m_latch_81;
	t_sample m_history_18;
	t_sample m_history_19;
	t_sample __m_latch_86;
	t_sample m_history_17;
	t_sample m_history_32;
	t_sample m_history_23;
	t_sample m_history_25;
	t_sample m_history_29;
	t_sample m_history_30;
	t_sample m_history_31;
	t_sample m_history_24;
	t_sample __m_latch_67;
	t_sample m_history_27;
	t_sample m_history_28;
	t_sample __m_latch_72;
	t_sample m_history_26;
	t_sample m_history_37;
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
		m_history_41 = ((int)0);
		m_history_42 = ((int)0);
		m_sw_43 = ((int)0);
		m_sw_44 = ((int)0);
		m_sw_45 = ((int)0);
		m_bpm_46 = ((int)0);
		m_gate_47 = ((int)0);
		m_chancethree_48 = ((int)0);
		m_chancetwo_49 = ((int)0);
		m_offsets_50.reset("offsets", ((int)512), ((int)1));
		m_chanceone_51 = ((int)0);
		m_sw_52 = ((int)0);
		m_sw_53 = ((int)0);
		m_sw_54 = ((int)0);
		m_sw_55 = ((int)0);
		m_k_56 = ((int)0);
		m_sw_57 = ((int)0);
		m_n_58 = ((int)0);
		__m_change_59.reset(0);
		__m_pluseq_60.reset(0);
		__m_pluseq_61.reset(0);
		__m_latch_62 = 0;
		__m_change_64.reset(0);
		__m_pluseq_65.reset(0);
		__m_pluseq_66.reset(0);
		__m_latch_67 = 0;
		__m_change_69.reset(0);
		__m_pluseq_70.reset(0);
		__m_pluseq_71.reset(0);
		__m_latch_72 = 0;
		__m_change_73.reset(0);
		__m_pluseq_74.reset(0);
		__m_pluseq_75.reset(0);
		__m_latch_76 = 0;
		__m_change_78.reset(0);
		__m_pluseq_79.reset(0);
		__m_pluseq_80.reset(0);
		__m_latch_81 = 0;
		__m_change_83.reset(0);
		__m_pluseq_84.reset(0);
		__m_pluseq_85.reset(0);
		__m_latch_86 = 0;
		__m_change_88.reset(0);
		__m_pluseq_89.reset(0);
		__m_pluseq_90.reset(0);
		__m_latch_91 = 0;
		__m_change_93.reset(0);
		__m_pluseq_94.reset(0);
		__m_pluseq_95.reset(0);
		__m_latch_96 = 0;
		__m_change_98.reset(0);
		__m_pluseq_99.reset(0);
		__m_change_100.reset(0);
		__m_latch_101 = 11025;
		__m_change_102.reset(0);
		__m_delta_103.reset(0);
		__m_change_104.reset(0);
		__m_change_105.reset(0);
		__m_latch_106 = 0;
		__m_latch_107 = 0;
		__m_latch_108 = 0;
		__m_change_109.reset(0);
		__m_latch_117 = 0;
		__m_latch_118 = 0;
		__m_latch_119 = 0;
		__m_latch_120 = 0;
		__m_latch_121 = 0;
		__m_latch_122 = 0;
		__m_latch_123 = 0;
		__m_latch_124 = 0;
		__m_change_125.reset(0);
		__m_cycle_126.reset(samplerate, 0);
		__m_latch_135 = 0;
		__m_latch_136 = 0;
		__m_latch_137 = 0;
		__m_latch_138 = 0;
		__m_latch_139 = 0;
		__m_latch_140 = 0;
		__m_latch_141 = 0;
		__m_latch_142 = 0;
		__m_change_143.reset(0);
		__m_cycle_144.reset(samplerate, 0);
		__m_latch_153 = 0;
		__m_latch_154 = 0;
		__m_latch_155 = 0;
		__m_latch_156 = 0;
		__m_latch_157 = 0;
		__m_latch_158 = 0;
		__m_latch_159 = 0;
		__m_latch_160 = 0;
		__m_change_161.reset(0);
		__m_cycle_162.reset(samplerate, 0);
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
		int int_1910 = int(m_sw_43);
		int offsets_dim = m_offsets_50.dim;
		int offsets_channels = m_offsets_50.channels;
		bool chan_ignore_63 = ((((int)5) < 0) || (((int)5) >= offsets_channels));
		int int_2096 = int(m_sw_44);
		bool chan_ignore_68 = ((((int)4) < 0) || (((int)4) >= offsets_channels));
		int int_2108 = int(m_sw_55);
		int int_2121 = int(m_sw_52);
		bool chan_ignore_77 = ((((int)2) < 0) || (((int)2) >= offsets_channels));
		int int_2135 = int(m_sw_45);
		bool chan_ignore_82 = ((((int)1) < 0) || (((int)1) >= offsets_channels));
		int int_2148 = int(m_sw_57);
		bool chan_ignore_87 = ((((int)3) < 0) || (((int)3) >= offsets_channels));
		int int_2161 = int(m_sw_54);
		bool chan_ignore_92 = ((((int)7) < 0) || (((int)7) >= offsets_channels));
		int int_2174 = int(m_sw_53);
		bool chan_ignore_97 = ((((int)6) < 0) || (((int)6) >= offsets_channels));
		t_sample mstosamps_1847 = (((int)0) * (samplerate * 0.001));
		t_sample max_1848 = ((mstosamps_1847 < vectorsize) ? vectorsize : mstosamps_1847);
		int gt_1853 = (m_gate_47 > ((int)0));
		t_sample history_2057_next_2084 = fixdenorm(((int)8));
		t_sample floor_2021 = floor(m_k_56);
		t_sample floor_2022 = floor(m_n_58);
		bool chan_ignore_110 = ((1 < 0) || (1 >= offsets_channels));
		bool chan_ignore_111 = ((2 < 0) || (2 >= offsets_channels));
		bool chan_ignore_112 = ((3 < 0) || (3 >= offsets_channels));
		bool chan_ignore_113 = ((4 < 0) || (4 >= offsets_channels));
		bool chan_ignore_114 = ((5 < 0) || (5 >= offsets_channels));
		bool chan_ignore_115 = ((6 < 0) || (6 >= offsets_channels));
		bool chan_ignore_116 = ((7 < 0) || (7 >= offsets_channels));
		t_sample min_127 = (-0.25);
		bool chan_ignore_128 = ((1 < 0) || (1 >= offsets_channels));
		bool chan_ignore_129 = ((2 < 0) || (2 >= offsets_channels));
		bool chan_ignore_130 = ((3 < 0) || (3 >= offsets_channels));
		bool chan_ignore_131 = ((4 < 0) || (4 >= offsets_channels));
		bool chan_ignore_132 = ((5 < 0) || (5 >= offsets_channels));
		bool chan_ignore_133 = ((6 < 0) || (6 >= offsets_channels));
		bool chan_ignore_134 = ((7 < 0) || (7 >= offsets_channels));
		t_sample min_145 = (-0.25);
		bool chan_ignore_146 = ((1 < 0) || (1 >= offsets_channels));
		bool chan_ignore_147 = ((2 < 0) || (2 >= offsets_channels));
		bool chan_ignore_148 = ((3 < 0) || (3 >= offsets_channels));
		bool chan_ignore_149 = ((4 < 0) || (4 >= offsets_channels));
		bool chan_ignore_150 = ((5 < 0) || (5 >= offsets_channels));
		bool chan_ignore_151 = ((6 < 0) || (6 >= offsets_channels));
		bool chan_ignore_152 = ((7 < 0) || (7 >= offsets_channels));
		t_sample min_163 = (-0.25);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out12 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out3 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out11 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out10 = ((int)0);
			t_sample out8 = ((int)0);
			t_sample out5 = ((int)0);
			int change_1911 = __m_change_59(int_1910);
			int eqp_1912 = ((int_1910 == change_1911) ? int_1910 : 0);
			int plusequals_1901 = __m_pluseq_60.post(((int)1), ((int)0), 0);
			int lt_1899 = (plusequals_1901 < ((int)100));
			int plusequals_1893 = __m_pluseq_61.post(eqp_1912, ((int)0), 0);
			int wrap_1892 = wrap(plusequals_1893, (-12), ((int)12));
			t_sample noise_1897 = noise();
			__m_latch_62 = ((lt_1899 != 0) ? noise_1897 : __m_latch_62);
			t_sample latch_1898 = __m_latch_62;
			t_sample sub_2544 = (latch_1898 - (-1));
			t_sample scale_2541 = ((safepow((sub_2544 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_1895 = floor(scale_2541);
			t_sample switch_1894 = (lt_1899 ? floor_1895 : wrap_1892);
			if ((!chan_ignore_63)) {
				m_offsets_50.write(switch_1894, 0, ((int)5));
				
			};
			int change_2097 = __m_change_64(int_2096);
			int eqp_2095 = ((int_2096 == change_2097) ? int_2096 : 0);
			int plusequals_2098 = __m_pluseq_65.post(((int)1), ((int)0), 0);
			int lt_2105 = (plusequals_2098 < ((int)100));
			int plusequals_2107 = __m_pluseq_66.post(eqp_2095, ((int)0), 0);
			int wrap_2102 = wrap(plusequals_2107, (-12), ((int)12));
			t_sample noise_2104 = noise();
			__m_latch_67 = ((lt_2105 != 0) ? noise_2104 : __m_latch_67);
			t_sample latch_2103 = __m_latch_67;
			t_sample sub_2548 = (latch_2103 - (-1));
			t_sample scale_2545 = ((safepow((sub_2548 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_2100 = floor(scale_2545);
			t_sample switch_2101 = (lt_2105 ? floor_2100 : wrap_2102);
			if ((!chan_ignore_68)) {
				m_offsets_50.write(switch_2101, 0, ((int)4));
				
			};
			int change_2110 = __m_change_69(int_2108);
			int eqp_2109 = ((int_2108 == change_2110) ? int_2108 : 0);
			int plusequals_2115 = __m_pluseq_70.post(((int)1), ((int)0), 0);
			int lt_2117 = (plusequals_2115 < ((int)100));
			int plusequals_2120 = __m_pluseq_71.post(eqp_2109, ((int)0), 0);
			int wrap_2118 = wrap(plusequals_2120, (-12), ((int)12));
			t_sample noise_2116 = noise();
			__m_latch_72 = ((lt_2117 != 0) ? noise_2116 : __m_latch_72);
			t_sample latch_2119 = __m_latch_72;
			t_sample sub_2552 = (latch_2119 - (-1));
			t_sample scale_2549 = ((safepow((sub_2552 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_2112 = floor(scale_2549);
			t_sample switch_2114 = (lt_2117 ? floor_2112 : wrap_2118);
			m_offsets_50.write(switch_2114, 0, 0);
			int change_2123 = __m_change_73(int_2121);
			int eqp_2122 = ((int_2121 == change_2123) ? int_2121 : 0);
			int plusequals_2128 = __m_pluseq_74.post(((int)1), ((int)0), 0);
			int lt_2130 = (plusequals_2128 < ((int)100));
			int plusequals_2133 = __m_pluseq_75.post(eqp_2122, ((int)0), 0);
			int wrap_2131 = wrap(plusequals_2133, (-12), ((int)12));
			t_sample noise_2129 = noise();
			__m_latch_76 = ((lt_2130 != 0) ? noise_2129 : __m_latch_76);
			t_sample latch_2132 = __m_latch_76;
			t_sample sub_2556 = (latch_2132 - (-1));
			t_sample scale_2553 = ((safepow((sub_2556 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_2125 = floor(scale_2553);
			t_sample switch_2127 = (lt_2130 ? floor_2125 : wrap_2131);
			if ((!chan_ignore_77)) {
				m_offsets_50.write(switch_2127, 0, ((int)2));
				
			};
			int change_2134 = __m_change_78(int_2135);
			int eqp_2136 = ((int_2135 == change_2134) ? int_2135 : 0);
			int plusequals_2138 = __m_pluseq_79.post(((int)1), ((int)0), 0);
			int lt_2137 = (plusequals_2138 < ((int)100));
			int plusequals_2145 = __m_pluseq_80.post(eqp_2136, ((int)0), 0);
			int wrap_2143 = wrap(plusequals_2145, (-12), ((int)12));
			t_sample noise_2146 = noise();
			__m_latch_81 = ((lt_2137 != 0) ? noise_2146 : __m_latch_81);
			t_sample latch_2142 = __m_latch_81;
			t_sample sub_2560 = (latch_2142 - (-1));
			t_sample scale_2557 = ((safepow((sub_2560 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_2140 = floor(scale_2557);
			t_sample switch_2144 = (lt_2137 ? floor_2140 : wrap_2143);
			if ((!chan_ignore_82)) {
				m_offsets_50.write(switch_2144, 0, ((int)1));
				
			};
			int change_2147 = __m_change_83(int_2148);
			int eqp_2149 = ((int_2148 == change_2147) ? int_2148 : 0);
			int plusequals_2151 = __m_pluseq_84.post(((int)1), ((int)0), 0);
			int lt_2150 = (plusequals_2151 < ((int)100));
			int plusequals_2158 = __m_pluseq_85.post(eqp_2149, ((int)0), 0);
			int wrap_2156 = wrap(plusequals_2158, (-12), ((int)12));
			t_sample noise_2159 = noise();
			__m_latch_86 = ((lt_2150 != 0) ? noise_2159 : __m_latch_86);
			t_sample latch_2155 = __m_latch_86;
			t_sample sub_2564 = (latch_2155 - (-1));
			t_sample scale_2561 = ((safepow((sub_2564 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_2153 = floor(scale_2561);
			t_sample switch_2157 = (lt_2150 ? floor_2153 : wrap_2156);
			if ((!chan_ignore_87)) {
				m_offsets_50.write(switch_2157, 0, ((int)3));
				
			};
			int change_2160 = __m_change_88(int_2161);
			int eqp_2162 = ((int_2161 == change_2160) ? int_2161 : 0);
			int plusequals_2164 = __m_pluseq_89.post(((int)1), ((int)0), 0);
			int lt_2163 = (plusequals_2164 < ((int)100));
			int plusequals_2171 = __m_pluseq_90.post(eqp_2162, ((int)0), 0);
			int wrap_2169 = wrap(plusequals_2171, (-12), ((int)12));
			t_sample noise_2172 = noise();
			__m_latch_91 = ((lt_2163 != 0) ? noise_2172 : __m_latch_91);
			t_sample latch_2168 = __m_latch_91;
			t_sample sub_2568 = (latch_2168 - (-1));
			t_sample scale_2565 = ((safepow((sub_2568 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_2166 = floor(scale_2565);
			t_sample switch_2170 = (lt_2163 ? floor_2166 : wrap_2169);
			if ((!chan_ignore_92)) {
				m_offsets_50.write(switch_2170, 0, ((int)7));
				
			};
			int change_2173 = __m_change_93(int_2174);
			int eqp_2175 = ((int_2174 == change_2173) ? int_2174 : 0);
			int plusequals_2177 = __m_pluseq_94.post(((int)1), ((int)0), 0);
			int lt_2176 = (plusequals_2177 < ((int)100));
			int plusequals_2184 = __m_pluseq_95.post(eqp_2175, ((int)0), 0);
			int wrap_2182 = wrap(plusequals_2184, (-12), ((int)12));
			t_sample noise_2185 = noise();
			__m_latch_96 = ((lt_2176 != 0) ? noise_2185 : __m_latch_96);
			t_sample latch_2181 = __m_latch_96;
			t_sample sub_2572 = (latch_2181 - (-1));
			t_sample scale_2569 = ((safepow((sub_2572 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_2179 = floor(scale_2569);
			t_sample switch_2183 = (lt_2176 ? floor_2179 : wrap_2182);
			if ((!chan_ignore_97)) {
				m_offsets_50.write(switch_2183, 0, ((int)6));
				
			};
			int change_1852 = __m_change_98(gt_1853);
			int gt_1851 = (change_1852 > ((int)0));
			int plusequals_1850 = __m_pluseq_99.post(((int)1), gt_1851, 0);
			int lte_1849 = (plusequals_1850 <= max_1848);
			int gen_1854 = lte_1849;
			int gt_1863 = (gen_1854 > ((int)0));
			int change_1862 = __m_change_100(gt_1863);
			int gt_1861 = (change_1862 > ((int)0));
			int gen_1864 = gt_1861;
			t_sample add_1869 = (m_history_42 + ((int)1));
			t_sample switch_1866 = (gen_1864 ? ((int)0) : add_1869);
			__m_latch_101 = ((gen_1864 != 0) ? add_1869 : __m_latch_101);
			t_sample latch_1868 = __m_latch_101;
			t_sample gen_1871 = latch_1868;
			t_sample history_1867_next_1870 = fixdenorm(switch_1866);
			t_sample rdiv_1858 = safediv(((int)1), gen_1871);
			t_sample add_1860 = (m_history_41 + rdiv_1858);
			t_sample switch_1857 = (gen_1864 ? ((int)0) : add_1860);
			t_sample wrap_1859 = wrap(switch_1857, ((int)0), ((int)1));
			t_sample gen_1874 = wrap_1859;
			t_sample history_1856_next_1872 = fixdenorm(wrap_1859);
			t_sample mul_2062 = (gen_1874 * ((t_sample)0.125));
			t_sample sub_2033 = (gen_1874 - m_history_40);
			t_sample add_2034 = (gen_1874 + m_history_40);
			t_sample div_2032 = safediv(sub_2033, add_2034);
			t_sample abs_2031 = fabs(div_2032);
			int gt_2029 = (abs_2031 > ((t_sample)0.5));
			int change_2028 = __m_change_102(gt_2029);
			int gt_2027 = (change_2028 > ((int)0));
			int gen_2072 = gt_2027;
			t_sample history_2030_next_2035 = fixdenorm(gen_1874);
			t_sample delta_2078 = __m_delta_103(gen_1874);
			t_sample wrap_2079 = wrap(delta_2078, (-0.5), ((t_sample)0.5));
			t_sample gen_2080 = wrap_2079;
			t_sample mul_2075 = (gen_2080 * ((t_sample)0.125));
			t_sample add_2073 = (mul_2075 + m_history_37);
			t_sample sub_2060 = (add_2073 - mul_2062);
			t_sample round_2071 = (trunc((sub_2060 * ((t_sample)8))) * ((t_sample)0.125));
			t_sample add_2061 = (round_2071 + mul_2062);
			t_sample sub_2082 = (m_history_38 - ((int)8));
			t_sample add_2083 = (m_history_38 + ((int)8));
			t_sample div_2081 = safediv(sub_2082, add_2083);
			t_sample abs_2055 = fabs(div_2081);
			int gt_2056 = (abs_2055 > ((t_sample)0.015625));
			int and_2059 = (gt_2056 && ((int)1));
			t_sample switch_2063 = (and_2059 ? and_2059 : m_history_39);
			t_sample switch_2066 = (gen_2072 ? switch_2063 : ((int)0));
			t_sample gen_2069 = switch_2066;
			t_sample switch_2065 = (switch_2066 ? ((int)0) : switch_2063);
			t_sample history_2067_next_2068 = fixdenorm(switch_2065);
			int or_2058 = (gen_2069 || ((int)0));
			t_sample switch_2077 = (or_2058 ? add_2061 : add_2073);
			t_sample wrap_2074 = wrap(switch_2077, ((int)0), ((int)1));
			t_sample gen_2086 = wrap_2074;
			t_sample history_2076_next_2085 = fixdenorm(wrap_2074);
			t_sample sub_2189 = (gen_2086 - m_history_36);
			t_sample add_2191 = (gen_2086 + m_history_36);
			t_sample div_2188 = safediv(sub_2189, add_2191);
			t_sample abs_2190 = fabs(div_2188);
			int gt_2194 = (abs_2190 > ((t_sample)0.5));
			int change_2187 = __m_change_104(gt_2194);
			int gt_2186 = (change_2187 > ((int)0));
			int gen_2053 = gt_2186;
			t_sample history_2030_next_2193 = fixdenorm(gen_2086);
			t_sample mul_2025 = (gen_2086 * ((int)16));
			t_sample wrap_2024 = wrap(mul_2025, ((int)0), ((int)1));
			t_sample sub_2199 = (wrap_2024 - m_history_35);
			t_sample add_2201 = (wrap_2024 + m_history_35);
			t_sample div_2198 = safediv(sub_2199, add_2201);
			t_sample abs_2200 = fabs(div_2198);
			int gt_2204 = (abs_2200 > ((t_sample)0.5));
			int change_2197 = __m_change_105(gt_2204);
			int gt_2196 = (change_2197 > ((int)0));
			int gen_2036 = gt_2196;
			t_sample history_2030_next_2203 = fixdenorm(wrap_2024);
			__m_latch_106 = ((gen_2036 != 0) ? floor_2021 : __m_latch_106);
			t_sample latch_2039 = __m_latch_106;
			t_sample abs_2012 = fabs(latch_2039);
			__m_latch_107 = ((gen_2036 != 0) ? floor_2022 : __m_latch_107);
			t_sample latch_2038 = __m_latch_107;
			t_sample abs_2011 = fabs(latch_2038);
			t_sample min_2009 = ((abs_2011 < abs_2012) ? abs_2011 : abs_2012);
			t_sample max_2010 = ((abs_2012 < abs_2011) ? abs_2011 : abs_2012);
			t_sample div_2013 = safediv(min_2009, max_2010);
			t_sample mul_2008 = (latch_2039 * latch_2038);
			int sign_2015 = ((mul_2008 > 0) ? 1 : ((mul_2008 < 0) ? -1 : 0));
			__m_latch_108 = ((gen_2036 != 0) ? ((int)0) : __m_latch_108);
			int latch_2037 = __m_latch_108;
			t_sample sub_2046 = (mul_2025 - latch_2037);
			t_sample mul_2014 = (sub_2046 * sign_2015);
			t_sample wrap_2040 = wrap(mul_2014, ((int)0), max_2010);
			t_sample floor_2047 = floor(wrap_2040);
			t_sample mul_2042 = (floor_2047 * div_2013);
			t_sample floor_2045 = floor(mul_2042);
			t_sample div_2044 = safediv(floor_2045, div_2013);
			t_sample ceil_2043 = ceil(div_2044);
			t_sample add_2017 = (floor_2045 + ((int)1));
			t_sample div_2019 = safediv(add_2017, div_2013);
			t_sample ceil_2018 = ceil(div_2019);
			t_sample sub_2016 = (ceil_2018 - ceil_2043);
			t_sample sub_2041 = (wrap_2040 - ceil_2043);
			t_sample div_2026 = safediv(sub_2041, sub_2016);
			t_sample gen_2049 = div_2026;
			t_sample sub_2213 = (gen_2049 - m_history_34);
			t_sample add_2209 = (gen_2049 + m_history_34);
			t_sample div_2208 = safediv(sub_2213, add_2209);
			t_sample abs_2214 = fabs(div_2208);
			int gt_2211 = (abs_2214 > ((t_sample)0.5));
			int change_2207 = __m_change_109(gt_2211);
			int gt_2212 = (change_2207 > ((int)0));
			int gen_2094 = gt_2212;
			t_sample history_2030_next_2210 = fixdenorm(gen_2049);
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_1956 = m_offsets_50.read(0, 0);
			t_sample sample_offsets_1957 = (chan_ignore_110 ? 0 : m_offsets_50.read(0, 1));
			t_sample sample_offsets_1958 = (chan_ignore_111 ? 0 : m_offsets_50.read(0, 2));
			t_sample sample_offsets_1959 = (chan_ignore_112 ? 0 : m_offsets_50.read(0, 3));
			t_sample sample_offsets_1960 = (chan_ignore_113 ? 0 : m_offsets_50.read(0, 4));
			t_sample sample_offsets_1961 = (chan_ignore_114 ? 0 : m_offsets_50.read(0, 5));
			t_sample sample_offsets_1962 = (chan_ignore_115 ? 0 : m_offsets_50.read(0, 6));
			t_sample sample_offsets_1963 = (chan_ignore_116 ? 0 : m_offsets_50.read(0, 7));
			t_sample index_offsets_1964 = ((int)0);
			t_sample noise_1952 = noise();
			t_sample abs_1951 = fabs(noise_1952);
			int lt_1953 = (abs_1951 < m_chancetwo_49);
			t_sample switch_1954 = (((int)0) ? m_history_23 : lt_1953);
			__m_latch_117 = ((gen_2053 != 0) ? switch_1954 : __m_latch_117);
			t_sample latch_1979 = __m_latch_117;
			t_sample gen_1987 = latch_1979;
			__m_latch_118 = ((gen_2053 != 0) ? m_history_28 : __m_latch_118);
			t_sample latch_1971 = __m_latch_118;
			t_sample gen_1992 = latch_1971;
			__m_latch_119 = ((gen_2053 != 0) ? m_history_32 : __m_latch_119);
			t_sample latch_1969 = __m_latch_119;
			t_sample gen_1993 = latch_1969;
			__m_latch_120 = ((gen_2053 != 0) ? m_history_29 : __m_latch_120);
			t_sample latch_1974 = __m_latch_120;
			t_sample gen_1990 = latch_1974;
			__m_latch_121 = ((gen_2053 != 0) ? m_history_27 : __m_latch_121);
			t_sample latch_1976 = __m_latch_121;
			t_sample gen_1989 = latch_1976;
			__m_latch_122 = ((gen_2053 != 0) ? m_history_30 : __m_latch_122);
			t_sample latch_1972 = __m_latch_122;
			t_sample gen_1991 = latch_1972;
			__m_latch_123 = ((gen_2053 != 0) ? m_history_33 : __m_latch_123);
			t_sample latch_1978 = __m_latch_123;
			t_sample gen_1988 = latch_1978;
			__m_latch_124 = ((gen_2053 != 0) ? m_history_31 : __m_latch_124);
			t_sample latch_1967 = __m_latch_124;
			t_sample gen_1994 = latch_1967;
			t_sample history_1977_next_1980 = fixdenorm(latch_1979);
			t_sample history_1968_next_1981 = fixdenorm(latch_1971);
			t_sample history_1966_next_1982 = fixdenorm(latch_1969);
			t_sample history_1965_next_1983 = fixdenorm(latch_1974);
			t_sample history_1973_next_1984 = fixdenorm(latch_1976);
			t_sample history_1970_next_1985 = fixdenorm(latch_1972);
			t_sample history_1975_next_1986 = fixdenorm(latch_1978);
			t_sample mul_1995 = (gen_1994 * sample_offsets_1963);
			t_sample mul_1996 = (gen_1993 * sample_offsets_1962);
			t_sample mul_1997 = (gen_1992 * sample_offsets_1961);
			t_sample mul_1998 = (gen_1991 * sample_offsets_1960);
			t_sample mul_1999 = (gen_1990 * sample_offsets_1959);
			t_sample mul_2000 = (gen_1989 * sample_offsets_1958);
			t_sample mul_2001 = (gen_1988 * sample_offsets_1957);
			t_sample mul_2002 = (gen_1987 * sample_offsets_1956);
			t_sample pass_2003 = (((((((mul_2002 + mul_2001) + mul_2000) + mul_1999) + mul_1998) + mul_1997) + mul_1996) + mul_1995);
			int change_1948 = __m_change_125(gen_2094);
			int neq_1947 = (change_1948 != ((int)0));
			t_sample switch_1938 = (neq_1947 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_2573 = (m_history_26 + (switch_1938 * (neq_1947 - m_history_26)));
			t_sample mix_1937 = mix_2573;
			t_sample mix_2574 = (m_history_25 + (((t_sample)0.04) * (mix_1937 - m_history_25)));
			t_sample mix_1935 = mix_2574;
			t_sample gen_1941 = mix_1935;
			t_sample history_1936_next_1939 = fixdenorm(mix_1937);
			t_sample history_1934_next_1940 = fixdenorm(mix_1935);
			t_sample mul_1930 = (gen_1941 * ((int)100));
			t_sample add_1942 = (pass_2003 + ((int)60));
			t_sample mtof_1943 = mtof(add_1942, ((int)440));
			__m_cycle_126.freq((m_history_24 + mtof_1943));
			t_sample cycle_1944 = __m_cycle_126(__sinedata);
			t_sample cycleindex_1945 = __m_cycle_126.phase();
			t_sample clamp_1932 = ((cycle_1944 <= min_127) ? min_127 : ((cycle_1944 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_1944));
			t_sample mul_1946 = (clamp_1932 * gen_1941);
			t_sample mul_1931 = (clamp_1932 * mul_1930);
			t_sample history_1933_next_1949 = fixdenorm(mul_1931);
			t_sample history_1955_next_2004 = fixdenorm(gen_1994);
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_2285 = m_offsets_50.read(0, 0);
			t_sample sample_offsets_2279 = (chan_ignore_128 ? 0 : m_offsets_50.read(0, 1));
			t_sample sample_offsets_2257 = (chan_ignore_129 ? 0 : m_offsets_50.read(0, 2));
			t_sample sample_offsets_2238 = (chan_ignore_130 ? 0 : m_offsets_50.read(0, 3));
			t_sample sample_offsets_2226 = (chan_ignore_131 ? 0 : m_offsets_50.read(0, 4));
			t_sample sample_offsets_2284 = (chan_ignore_132 ? 0 : m_offsets_50.read(0, 5));
			t_sample sample_offsets_2271 = (chan_ignore_133 ? 0 : m_offsets_50.read(0, 6));
			t_sample sample_offsets_2232 = (chan_ignore_134 ? 0 : m_offsets_50.read(0, 7));
			t_sample index_offsets_2222 = ((int)0);
			t_sample noise_2276 = noise();
			t_sample abs_2216 = fabs(noise_2276);
			int lt_2275 = (abs_2216 < m_chancethree_48);
			t_sample switch_2274 = (((int)0) ? m_history_12 : lt_2275);
			__m_latch_135 = ((gen_2053 != 0) ? switch_2274 : __m_latch_135);
			t_sample latch_2233 = __m_latch_135;
			t_sample gen_2273 = latch_2233;
			__m_latch_136 = ((gen_2053 != 0) ? m_history_17 : __m_latch_136);
			t_sample latch_2218 = __m_latch_136;
			t_sample gen_2272 = latch_2218;
			__m_latch_137 = ((gen_2053 != 0) ? m_history_21 : __m_latch_137);
			t_sample latch_2277 = __m_latch_137;
			t_sample gen_2234 = latch_2277;
			__m_latch_138 = ((gen_2053 != 0) ? m_history_18 : __m_latch_138);
			t_sample latch_2270 = __m_latch_138;
			t_sample gen_2250 = latch_2270;
			__m_latch_139 = ((gen_2053 != 0) ? m_history_16 : __m_latch_139);
			t_sample latch_2267 = __m_latch_139;
			t_sample gen_2217 = latch_2267;
			__m_latch_140 = ((gen_2053 != 0) ? m_history_19 : __m_latch_140);
			t_sample latch_2237 = __m_latch_140;
			t_sample gen_2278 = latch_2237;
			__m_latch_141 = ((gen_2053 != 0) ? m_history_22 : __m_latch_141);
			t_sample latch_2229 = __m_latch_141;
			t_sample gen_2266 = latch_2229;
			__m_latch_142 = ((gen_2053 != 0) ? m_history_20 : __m_latch_142);
			t_sample latch_2290 = __m_latch_142;
			t_sample gen_2231 = latch_2290;
			t_sample history_1977_next_2235 = fixdenorm(latch_2233);
			t_sample history_1968_next_2264 = fixdenorm(latch_2218);
			t_sample history_1966_next_2282 = fixdenorm(latch_2277);
			t_sample history_1965_next_2263 = fixdenorm(latch_2270);
			t_sample history_1973_next_2262 = fixdenorm(latch_2267);
			t_sample history_1970_next_2261 = fixdenorm(latch_2237);
			t_sample history_1975_next_2260 = fixdenorm(latch_2229);
			t_sample mul_2258 = (gen_2231 * sample_offsets_2232);
			t_sample mul_2259 = (gen_2234 * sample_offsets_2271);
			t_sample mul_2256 = (gen_2272 * sample_offsets_2284);
			t_sample mul_2236 = (gen_2278 * sample_offsets_2226);
			t_sample mul_2255 = (gen_2250 * sample_offsets_2238);
			t_sample mul_2281 = (gen_2217 * sample_offsets_2257);
			t_sample mul_2254 = (gen_2266 * sample_offsets_2279);
			t_sample mul_2253 = (gen_2273 * sample_offsets_2285);
			t_sample pass_2252 = (((((((mul_2253 + mul_2254) + mul_2281) + mul_2255) + mul_2236) + mul_2256) + mul_2259) + mul_2258);
			int change_2251 = __m_change_143(gen_2094);
			int neq_2269 = (change_2251 != ((int)0));
			t_sample switch_2249 = (neq_2269 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_2575 = (m_history_15 + (switch_2249 * (neq_2269 - m_history_15)));
			t_sample mix_2228 = mix_2575;
			t_sample mix_2576 = (m_history_14 + (((t_sample)0.04) * (mix_2228 - m_history_14)));
			t_sample mix_2248 = mix_2576;
			t_sample gen_2230 = mix_2248;
			t_sample history_1936_next_2247 = fixdenorm(mix_2228);
			t_sample history_1934_next_2246 = fixdenorm(mix_2248);
			t_sample mul_2286 = (gen_2230 * ((int)100));
			t_sample add_2283 = (pass_2252 + ((int)60));
			t_sample mtof_2245 = mtof(add_2283, ((int)440));
			__m_cycle_144.freq((m_history_13 + mtof_2245));
			t_sample cycle_2244 = __m_cycle_144(__sinedata);
			t_sample cycleindex_2243 = __m_cycle_144.phase();
			t_sample clamp_2219 = ((cycle_2244 <= min_145) ? min_145 : ((cycle_2244 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_2244));
			t_sample mul_2242 = (clamp_2219 * gen_2230);
			t_sample mul_2241 = (clamp_2219 * mul_2286);
			t_sample history_1933_next_2225 = fixdenorm(mul_2241);
			t_sample history_1955_next_2240 = fixdenorm(gen_2231);
			t_sample mix_2577 = (mul_1946 + (((t_sample)0.75) * (mul_2242 - mul_1946)));
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_2371 = m_offsets_50.read(0, 0);
			t_sample sample_offsets_2362 = (chan_ignore_146 ? 0 : m_offsets_50.read(0, 1));
			t_sample sample_offsets_2348 = (chan_ignore_147 ? 0 : m_offsets_50.read(0, 2));
			t_sample sample_offsets_2327 = (chan_ignore_148 ? 0 : m_offsets_50.read(0, 3));
			t_sample sample_offsets_2311 = (chan_ignore_149 ? 0 : m_offsets_50.read(0, 4));
			t_sample sample_offsets_2370 = (chan_ignore_150 ? 0 : m_offsets_50.read(0, 5));
			t_sample sample_offsets_2322 = (chan_ignore_151 ? 0 : m_offsets_50.read(0, 6));
			t_sample sample_offsets_2317 = (chan_ignore_152 ? 0 : m_offsets_50.read(0, 7));
			t_sample index_offsets_2307 = ((int)0);
			t_sample noise_2360 = noise();
			t_sample abs_2302 = fabs(noise_2360);
			int lt_2359 = (abs_2302 < m_chanceone_51);
			t_sample switch_2338 = (((int)0) ? m_history_1 : lt_2359);
			__m_latch_153 = ((gen_2053 != 0) ? switch_2338 : __m_latch_153);
			t_sample latch_2318 = __m_latch_153;
			t_sample gen_2356 = latch_2318;
			__m_latch_154 = ((gen_2053 != 0) ? m_history_6 : __m_latch_154);
			t_sample latch_2304 = __m_latch_154;
			t_sample gen_2355 = latch_2304;
			__m_latch_155 = ((gen_2053 != 0) ? m_history_10 : __m_latch_155);
			t_sample latch_2363 = __m_latch_155;
			t_sample gen_2320 = latch_2363;
			__m_latch_156 = ((gen_2053 != 0) ? m_history_7 : __m_latch_156);
			t_sample latch_2354 = __m_latch_156;
			t_sample gen_2353 = latch_2354;
			__m_latch_157 = ((gen_2053 != 0) ? m_history_5 : __m_latch_157);
			t_sample latch_2352 = __m_latch_157;
			t_sample gen_2303 = latch_2352;
			__m_latch_158 = ((gen_2053 != 0) ? m_history_8 : __m_latch_158);
			t_sample latch_2326 = __m_latch_158;
			t_sample gen_2364 = latch_2326;
			__m_latch_159 = ((gen_2053 != 0) ? m_history_11 : __m_latch_159);
			t_sample latch_2314 = __m_latch_159;
			t_sample gen_2351 = latch_2314;
			__m_latch_160 = ((gen_2053 != 0) ? m_history_9 : __m_latch_160);
			t_sample latch_2376 = __m_latch_160;
			t_sample gen_2316 = latch_2376;
			t_sample history_1977_next_2321 = fixdenorm(latch_2318);
			t_sample history_1968_next_2350 = fixdenorm(latch_2304);
			t_sample history_1966_next_2368 = fixdenorm(latch_2363);
			t_sample history_1965_next_2319 = fixdenorm(latch_2354);
			t_sample history_1973_next_2347 = fixdenorm(latch_2352);
			t_sample history_1970_next_2346 = fixdenorm(latch_2326);
			t_sample history_1975_next_2345 = fixdenorm(latch_2314);
			t_sample mul_2324 = (gen_2316 * sample_offsets_2317);
			t_sample mul_2349 = (gen_2320 * sample_offsets_2322);
			t_sample mul_2344 = (gen_2355 * sample_offsets_2370);
			t_sample mul_2325 = (gen_2364 * sample_offsets_2311);
			t_sample mul_2343 = (gen_2353 * sample_offsets_2327);
			t_sample mul_2366 = (gen_2303 * sample_offsets_2348);
			t_sample mul_2342 = (gen_2351 * sample_offsets_2362);
			t_sample mul_2341 = (gen_2356 * sample_offsets_2371);
			t_sample pass_2340 = (((((((mul_2341 + mul_2342) + mul_2366) + mul_2343) + mul_2325) + mul_2344) + mul_2349) + mul_2324);
			int change_2339 = __m_change_161(gen_2094);
			int neq_2358 = (change_2339 != ((int)0));
			t_sample switch_2337 = (neq_2358 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_2578 = (m_history_4 + (switch_2337 * (neq_2358 - m_history_4)));
			t_sample mix_2313 = mix_2578;
			t_sample mix_2579 = (m_history_3 + (((t_sample)0.04) * (mix_2313 - m_history_3)));
			t_sample mix_2336 = mix_2579;
			t_sample gen_2315 = mix_2336;
			t_sample history_1936_next_2335 = fixdenorm(mix_2313);
			t_sample history_1934_next_2334 = fixdenorm(mix_2336);
			t_sample mul_2372 = (gen_2315 * ((int)100));
			t_sample add_2369 = (pass_2340 + ((int)60));
			t_sample mtof_2333 = mtof(add_2369, ((int)440));
			__m_cycle_162.freq((m_history_2 + mtof_2333));
			t_sample cycle_2332 = __m_cycle_162(__sinedata);
			t_sample cycleindex_2331 = __m_cycle_162.phase();
			t_sample clamp_2305 = ((cycle_2332 <= min_163) ? min_163 : ((cycle_2332 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_2332));
			t_sample mul_2323 = (clamp_2305 * gen_2315);
			t_sample mul_2329 = (clamp_2305 * mul_2372);
			t_sample history_1933_next_2310 = fixdenorm(mul_2329);
			t_sample history_1955_next_2328 = fixdenorm(gen_2316);
			t_sample mix_2580 = (mul_2323 + (((t_sample)0.25) * (mul_1946 - mul_2323)));
			t_sample mix_2581 = (mix_2577 + (((t_sample)0.25) * (mix_2580 - mix_2577)));
			t_sample mul_1890 = (mix_2581 * ((t_sample)0.3));
			t_sample mix_2582 = (mul_1890 + (((t_sample)0.7) * (in2 - mul_1890)));
			t_sample out2 = mix_2582;
			t_sample mix_2583 = (mix_2580 + (((t_sample)0.25) * (mix_2577 - mix_2580)));
			t_sample mul_1891 = (mix_2583 * ((t_sample)0.3));
			t_sample mix_2584 = (mul_1891 + (((t_sample)0.7) * (in1 - mul_1891)));
			t_sample out1 = mix_2584;
			m_history_42 = history_1867_next_1870;
			m_history_41 = history_1856_next_1872;
			m_history_40 = history_2030_next_2035;
			m_history_37 = history_2076_next_2085;
			m_history_38 = history_2057_next_2084;
			m_history_39 = history_2067_next_2068;
			m_history_36 = history_2030_next_2193;
			m_history_35 = history_2030_next_2203;
			m_history_34 = history_2030_next_2210;
			m_history_33 = history_1977_next_1980;
			m_history_23 = history_1955_next_2004;
			m_history_25 = history_1934_next_1940;
			m_history_24 = history_1933_next_1949;
			m_history_26 = history_1936_next_1939;
			m_history_32 = history_1968_next_1981;
			m_history_31 = history_1966_next_1982;
			m_history_30 = history_1965_next_1983;
			m_history_29 = history_1973_next_1984;
			m_history_28 = history_1970_next_1985;
			m_history_27 = history_1975_next_1986;
			m_history_22 = history_1977_next_2235;
			m_history_12 = history_1955_next_2240;
			m_history_14 = history_1934_next_2246;
			m_history_13 = history_1933_next_2225;
			m_history_15 = history_1936_next_2247;
			m_history_21 = history_1968_next_2264;
			m_history_20 = history_1966_next_2282;
			m_history_19 = history_1965_next_2263;
			m_history_18 = history_1973_next_2262;
			m_history_17 = history_1970_next_2261;
			m_history_16 = history_1975_next_2260;
			m_history_11 = history_1977_next_2321;
			m_history_1 = history_1955_next_2328;
			m_history_3 = history_1934_next_2334;
			m_history_2 = history_1933_next_2310;
			m_history_4 = history_1936_next_2335;
			m_history_10 = history_1968_next_2350;
			m_history_9 = history_1966_next_2368;
			m_history_8 = history_1965_next_2319;
			m_history_7 = history_1973_next_2347;
			m_history_6 = history_1970_next_2346;
			m_history_5 = history_1975_next_2345;
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
	inline void set_sw6(t_param _value) {
		m_sw_43 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_45 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bpm(t_param _value) {
		m_bpm_46 = (_value < 40 ? 40 : (_value > 200 ? 200 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_chancethree(t_param _value) {
		m_chancethree_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_chancetwo(t_param _value) {
		m_chancetwo_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_offsets(void * _value) {
		m_offsets_50.setbuffer(_value);
	};
	inline void set_chanceone(t_param _value) {
		m_chanceone_51 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_k(t_param _value) {
		m_k_56 = (_value < 1 ? 1 : (_value > 16 ? 16 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_n(t_param _value) {
		m_n_58 = (_value < 1 ? 1 : (_value > 16 ? 16 : _value));
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
		case 0: *value = self->m_bpm_46; break;
		case 1: *value = self->m_chanceone_51; break;
		case 2: *value = self->m_chancethree_48; break;
		case 3: *value = self->m_chancetwo_49; break;
		case 4: *value = self->m_gate_47; break;
		case 5: *value = self->m_k_56; break;
		case 6: *value = self->m_n_58; break;
		
		case 8: *value = self->m_sw_55; break;
		case 9: *value = self->m_sw_45; break;
		case 10: *value = self->m_sw_52; break;
		case 11: *value = self->m_sw_57; break;
		case 12: *value = self->m_sw_44; break;
		case 13: *value = self->m_sw_43; break;
		case 14: *value = self->m_sw_53; break;
		case 15: *value = self->m_sw_54; break;
		
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
	// initialize parameter 0 ("m_bpm_46")
	pi = self->__commonstate.params + 0;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_46;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 40;
	pi->outputmax = 200;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_chanceone_51")
	pi = self->__commonstate.params + 1;
	pi->name = "chanceone";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chanceone_51;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_chancethree_48")
	pi = self->__commonstate.params + 2;
	pi->name = "chancethree";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chancethree_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_chancetwo_49")
	pi = self->__commonstate.params + 3;
	pi->name = "chancetwo";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chancetwo_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_gate_47")
	pi = self->__commonstate.params + 4;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_k_56")
	pi = self->__commonstate.params + 5;
	pi->name = "k";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_56;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_n_58")
	pi = self->__commonstate.params + 6;
	pi->name = "n";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_58;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_offsets_50")
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
	// initialize parameter 8 ("m_sw_55")
	pi = self->__commonstate.params + 8;
	pi->name = "sw1";
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
	// initialize parameter 9 ("m_sw_45")
	pi = self->__commonstate.params + 9;
	pi->name = "sw2";
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
	// initialize parameter 10 ("m_sw_52")
	pi = self->__commonstate.params + 10;
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
	// initialize parameter 11 ("m_sw_57")
	pi = self->__commonstate.params + 11;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_57;
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
	// initialize parameter 14 ("m_sw_53")
	pi = self->__commonstate.params + 14;
	pi->name = "sw7";
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
	// initialize parameter 15 ("m_sw_54")
	pi = self->__commonstate.params + 15;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_54;
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
