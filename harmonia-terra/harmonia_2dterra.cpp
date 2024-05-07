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
	Change __m_change_74;
	Change __m_change_100;
	Change __m_change_102;
	Change __m_change_98;
	Change __m_change_84;
	Change __m_change_79;
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
	Data m_offsets_48;
	Delta __m_delta_103;
	PlusEquals __m_pluseq_70;
	PlusEquals __m_pluseq_71;
	PlusEquals __m_pluseq_89;
	PlusEquals __m_pluseq_90;
	PlusEquals __m_pluseq_61;
	PlusEquals __m_pluseq_65;
	PlusEquals __m_pluseq_60;
	PlusEquals __m_pluseq_75;
	PlusEquals __m_pluseq_99;
	PlusEquals __m_pluseq_95;
	PlusEquals __m_pluseq_85;
	PlusEquals __m_pluseq_86;
	PlusEquals __m_pluseq_76;
	PlusEquals __m_pluseq_94;
	PlusEquals __m_pluseq_66;
	PlusEquals __m_pluseq_81;
	PlusEquals __m_pluseq_80;
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
	t_sample m_sw_51;
	t_sample m_sw_50;
	t_sample m_sw_49;
	t_sample m_chancetwo_54;
	t_sample m_sw_56;
	t_sample m_n_55;
	t_sample m_chanceone_58;
	t_sample m_sw_57;
	t_sample m_history_34;
	t_sample m_history_35;
	t_sample m_chancethree_46;
	t_sample m_history_40;
	t_sample m_history_39;
	t_sample m_history_38;
	t_sample m_gate_47;
	t_sample m_history_41;
	t_sample m_bpm_43;
	t_sample m_history_42;
	t_sample m_sw_45;
	t_sample m_k_44;
	t_sample m_history_15;
	t_sample m_history_33;
	t_sample __m_latch_62;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample __m_latch_77;
	t_sample __m_latch_82;
	t_sample m_history_18;
	t_sample m_history_19;
	t_sample __m_latch_87;
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
		m_bpm_43 = ((int)0);
		m_k_44 = ((int)0);
		m_sw_45 = ((int)0);
		m_chancethree_46 = ((int)0);
		m_gate_47 = ((int)0);
		m_offsets_48.reset("offsets", ((int)512), ((int)1));
		m_sw_49 = ((int)0);
		m_sw_50 = ((int)0);
		m_sw_51 = ((int)0);
		m_sw_52 = ((int)0);
		m_sw_53 = ((int)0);
		m_chancetwo_54 = ((int)0);
		m_n_55 = ((int)0);
		m_sw_56 = ((int)0);
		m_sw_57 = ((int)0);
		m_chanceone_58 = ((int)0);
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
		__m_change_74.reset(0);
		__m_pluseq_75.reset(0);
		__m_pluseq_76.reset(0);
		__m_latch_77 = 0;
		__m_change_79.reset(0);
		__m_pluseq_80.reset(0);
		__m_pluseq_81.reset(0);
		__m_latch_82 = 0;
		__m_change_84.reset(0);
		__m_pluseq_85.reset(0);
		__m_pluseq_86.reset(0);
		__m_latch_87 = 0;
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
		int int_48634 = int(m_sw_51);
		int offsets_dim = m_offsets_48.dim;
		int offsets_channels = m_offsets_48.channels;
		bool chan_ignore_63 = ((((int)6) < 0) || (((int)6) >= offsets_channels));
		int int_54054 = int(m_sw_49);
		bool chan_ignore_68 = ((((int)4) < 0) || (((int)4) >= offsets_channels));
		int int_54065 = int(m_sw_57);
		bool chan_ignore_73 = ((((int)1) < 0) || (((int)1) >= offsets_channels));
		int int_54079 = int(m_sw_50);
		bool chan_ignore_78 = ((((int)7) < 0) || (((int)7) >= offsets_channels));
		int int_54091 = int(m_sw_56);
		bool chan_ignore_83 = ((((int)3) < 0) || (((int)3) >= offsets_channels));
		int int_54104 = int(m_sw_45);
		int int_54117 = int(m_sw_53);
		bool chan_ignore_92 = ((((int)2) < 0) || (((int)2) >= offsets_channels));
		int int_54130 = int(m_sw_52);
		bool chan_ignore_97 = ((((int)5) < 0) || (((int)5) >= offsets_channels));
		t_sample mstosamps_52032 = (((int)0) * (samplerate * 0.001));
		t_sample max_52033 = ((mstosamps_52032 < vectorsize) ? vectorsize : mstosamps_52032);
		int gt_52038 = (m_gate_47 > ((int)0));
		t_sample history_48481_next_48517 = fixdenorm(((int)8));
		t_sample floor_48745 = floor(m_k_44);
		t_sample floor_48746 = floor(m_n_55);
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
			t_sample out11 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out10 = ((int)0);
			t_sample out3 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out12 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out8 = ((int)0);
			int change_48635 = __m_change_59(int_48634);
			int eqp_48636 = ((int_48634 == change_48635) ? int_48634 : 0);
			int plusequals_48625 = __m_pluseq_60.post(((int)1), ((int)0), 0);
			int lt_48623 = (plusequals_48625 < ((int)100));
			int plusequals_48617 = __m_pluseq_61.post(eqp_48636, ((int)0), 0);
			int wrap_48616 = wrap(plusequals_48617, (-12), ((int)12));
			t_sample noise_48621 = noise();
			__m_latch_62 = ((lt_48623 != 0) ? noise_48621 : __m_latch_62);
			t_sample latch_48622 = __m_latch_62;
			t_sample sub_54467 = (latch_48622 - (-1));
			t_sample scale_54464 = ((safepow((sub_54467 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_48619 = floor(scale_54464);
			t_sample switch_48618 = (lt_48623 ? floor_48619 : wrap_48616);
			if ((!chan_ignore_63)) {
				m_offsets_48.write(switch_48618, 0, ((int)6));
				
			};
			int change_54053 = __m_change_64(int_54054);
			int eqp_54052 = ((int_54054 == change_54053) ? int_54054 : 0);
			int plusequals_54064 = __m_pluseq_65.post(((int)1), ((int)0), 0);
			int lt_54060 = (plusequals_54064 < ((int)100));
			int plusequals_54055 = __m_pluseq_66.post(eqp_54052, ((int)0), 0);
			int wrap_54062 = wrap(plusequals_54055, (-12), ((int)12));
			t_sample noise_54057 = noise();
			__m_latch_67 = ((lt_54060 != 0) ? noise_54057 : __m_latch_67);
			t_sample latch_54059 = __m_latch_67;
			t_sample sub_54471 = (latch_54059 - (-1));
			t_sample scale_54468 = ((safepow((sub_54471 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_54056 = floor(scale_54468);
			t_sample switch_54058 = (lt_54060 ? floor_54056 : wrap_54062);
			if ((!chan_ignore_68)) {
				m_offsets_48.write(switch_54058, 0, ((int)4));
				
			};
			int change_54067 = __m_change_69(int_54065);
			int eqp_54066 = ((int_54065 == change_54067) ? int_54065 : 0);
			int plusequals_54077 = __m_pluseq_70.post(((int)1), ((int)0), 0);
			int lt_54073 = (plusequals_54077 < ((int)100));
			int plusequals_54068 = __m_pluseq_71.post(eqp_54066, ((int)0), 0);
			int wrap_54075 = wrap(plusequals_54068, (-12), ((int)12));
			t_sample noise_54074 = noise();
			__m_latch_72 = ((lt_54073 != 0) ? noise_54074 : __m_latch_72);
			t_sample latch_54076 = __m_latch_72;
			t_sample sub_54475 = (latch_54076 - (-1));
			t_sample scale_54472 = ((safepow((sub_54475 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_54069 = floor(scale_54472);
			t_sample switch_54071 = (lt_54073 ? floor_54069 : wrap_54075);
			if ((!chan_ignore_73)) {
				m_offsets_48.write(switch_54071, 0, ((int)1));
				
			};
			int change_54078 = __m_change_74(int_54079);
			int eqp_54080 = ((int_54079 == change_54078) ? int_54079 : 0);
			int plusequals_54090 = __m_pluseq_75.post(((int)1), ((int)0), 0);
			int lt_54086 = (plusequals_54090 < ((int)100));
			int plusequals_54081 = __m_pluseq_76.post(eqp_54080, ((int)0), 0);
			int wrap_54088 = wrap(plusequals_54081, (-12), ((int)12));
			t_sample noise_54087 = noise();
			__m_latch_77 = ((lt_54086 != 0) ? noise_54087 : __m_latch_77);
			t_sample latch_54089 = __m_latch_77;
			t_sample sub_54479 = (latch_54089 - (-1));
			t_sample scale_54476 = ((safepow((sub_54479 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_54082 = floor(scale_54476);
			t_sample switch_54084 = (lt_54086 ? floor_54082 : wrap_54088);
			if ((!chan_ignore_78)) {
				m_offsets_48.write(switch_54084, 0, ((int)7));
				
			};
			int change_54093 = __m_change_79(int_54091);
			int eqp_54092 = ((int_54091 == change_54093) ? int_54091 : 0);
			int plusequals_54103 = __m_pluseq_80.post(((int)1), ((int)0), 0);
			int lt_54102 = (plusequals_54103 < ((int)100));
			int plusequals_54094 = __m_pluseq_81.post(eqp_54092, ((int)0), 0);
			int wrap_54101 = wrap(plusequals_54094, (-12), ((int)12));
			t_sample noise_54096 = noise();
			__m_latch_82 = ((lt_54102 != 0) ? noise_54096 : __m_latch_82);
			t_sample latch_54097 = __m_latch_82;
			t_sample sub_54483 = (latch_54097 - (-1));
			t_sample scale_54480 = ((safepow((sub_54483 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_54098 = floor(scale_54480);
			t_sample switch_54095 = (lt_54102 ? floor_54098 : wrap_54101);
			if ((!chan_ignore_83)) {
				m_offsets_48.write(switch_54095, 0, ((int)3));
				
			};
			int change_54106 = __m_change_84(int_54104);
			int eqp_54105 = ((int_54104 == change_54106) ? int_54104 : 0);
			int plusequals_54116 = __m_pluseq_85.post(((int)1), ((int)0), 0);
			int lt_54115 = (plusequals_54116 < ((int)100));
			int plusequals_54107 = __m_pluseq_86.post(eqp_54105, ((int)0), 0);
			int wrap_54114 = wrap(plusequals_54107, (-12), ((int)12));
			t_sample noise_54109 = noise();
			__m_latch_87 = ((lt_54115 != 0) ? noise_54109 : __m_latch_87);
			t_sample latch_54110 = __m_latch_87;
			t_sample sub_54487 = (latch_54110 - (-1));
			t_sample scale_54484 = ((safepow((sub_54487 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_54111 = floor(scale_54484);
			t_sample switch_54108 = (lt_54115 ? floor_54111 : wrap_54114);
			m_offsets_48.write(switch_54108, 0, 0);
			int change_54119 = __m_change_88(int_54117);
			int eqp_54118 = ((int_54117 == change_54119) ? int_54117 : 0);
			int plusequals_54129 = __m_pluseq_89.post(((int)1), ((int)0), 0);
			int lt_54128 = (plusequals_54129 < ((int)100));
			int plusequals_54120 = __m_pluseq_90.post(eqp_54118, ((int)0), 0);
			int wrap_54127 = wrap(plusequals_54120, (-12), ((int)12));
			t_sample noise_54122 = noise();
			__m_latch_91 = ((lt_54128 != 0) ? noise_54122 : __m_latch_91);
			t_sample latch_54123 = __m_latch_91;
			t_sample sub_54491 = (latch_54123 - (-1));
			t_sample scale_54488 = ((safepow((sub_54491 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_54124 = floor(scale_54488);
			t_sample switch_54121 = (lt_54128 ? floor_54124 : wrap_54127);
			if ((!chan_ignore_92)) {
				m_offsets_48.write(switch_54121, 0, ((int)2));
				
			};
			int change_54132 = __m_change_93(int_54130);
			int eqp_54131 = ((int_54130 == change_54132) ? int_54130 : 0);
			int plusequals_54142 = __m_pluseq_94.post(((int)1), ((int)0), 0);
			int lt_54141 = (plusequals_54142 < ((int)100));
			int plusequals_54133 = __m_pluseq_95.post(eqp_54131, ((int)0), 0);
			int wrap_54140 = wrap(plusequals_54133, (-12), ((int)12));
			t_sample noise_54135 = noise();
			__m_latch_96 = ((lt_54141 != 0) ? noise_54135 : __m_latch_96);
			t_sample latch_54136 = __m_latch_96;
			t_sample sub_54495 = (latch_54136 - (-1));
			t_sample scale_54492 = ((safepow((sub_54495 * ((t_sample)0.5)), ((int)1)) * ((int)24)) + (-12));
			t_sample floor_54137 = floor(scale_54492);
			t_sample switch_54134 = (lt_54141 ? floor_54137 : wrap_54140);
			if ((!chan_ignore_97)) {
				m_offsets_48.write(switch_54134, 0, ((int)5));
				
			};
			int change_52037 = __m_change_98(gt_52038);
			int gt_52036 = (change_52037 > ((int)0));
			int plusequals_52035 = __m_pluseq_99.post(((int)1), gt_52036, 0);
			int lte_52034 = (plusequals_52035 <= max_52033);
			int gen_52039 = lte_52034;
			int gt_50934 = (gen_52039 > ((int)0));
			int change_50933 = __m_change_100(gt_50934);
			int gt_50932 = (change_50933 > ((int)0));
			int gen_50935 = gt_50932;
			t_sample add_50940 = (m_history_42 + ((int)1));
			__m_latch_101 = ((gen_50935 != 0) ? add_50940 : __m_latch_101);
			t_sample latch_50939 = __m_latch_101;
			t_sample gen_50942 = latch_50939;
			t_sample switch_50937 = (gen_50935 ? ((int)0) : add_50940);
			t_sample history_50938_next_50941 = fixdenorm(switch_50937);
			t_sample rdiv_50929 = safediv(((int)1), gen_50942);
			t_sample add_50931 = (m_history_41 + rdiv_50929);
			t_sample switch_50928 = (gen_50935 ? ((int)0) : add_50931);
			t_sample wrap_50930 = wrap(switch_50928, ((int)0), ((int)1));
			t_sample gen_50945 = wrap_50930;
			t_sample history_50927_next_50943 = fixdenorm(wrap_50930);
			t_sample mul_48486 = (gen_50945 * ((t_sample)0.125));
			t_sample sub_48502 = (gen_50945 - m_history_40);
			t_sample add_48503 = (gen_50945 + m_history_40);
			t_sample div_48501 = safediv(sub_48502, add_48503);
			t_sample abs_48500 = fabs(div_48501);
			int gt_48498 = (abs_48500 > ((t_sample)0.5));
			int change_48497 = __m_change_102(gt_48498);
			int gt_48496 = (change_48497 > ((int)0));
			int gen_48505 = gt_48496;
			t_sample history_48499_next_48504 = fixdenorm(gen_50945);
			t_sample delta_48511 = __m_delta_103(gen_50945);
			t_sample wrap_48512 = wrap(delta_48511, (-0.5), ((t_sample)0.5));
			t_sample gen_48513 = wrap_48512;
			t_sample mul_48508 = (gen_48513 * ((t_sample)0.125));
			t_sample add_48506 = (mul_48508 + m_history_37);
			t_sample sub_48484 = (add_48506 - mul_48486);
			t_sample round_48495 = (trunc((sub_48484 * ((t_sample)8))) * ((t_sample)0.125));
			t_sample add_48485 = (round_48495 + mul_48486);
			t_sample sub_48515 = (m_history_38 - ((int)8));
			t_sample add_48516 = (m_history_38 + ((int)8));
			t_sample div_48514 = safediv(sub_48515, add_48516);
			t_sample abs_48479 = fabs(div_48514);
			int gt_48480 = (abs_48479 > ((t_sample)0.015625));
			int and_48483 = (gt_48480 && ((int)1));
			t_sample switch_48487 = (and_48483 ? and_48483 : m_history_39);
			t_sample switch_48490 = (gen_48505 ? switch_48487 : ((int)0));
			t_sample gen_48493 = switch_48490;
			t_sample switch_48489 = (switch_48490 ? ((int)0) : switch_48487);
			t_sample history_48491_next_48492 = fixdenorm(switch_48489);
			int or_48482 = (gen_48493 || ((int)0));
			t_sample switch_48510 = (or_48482 ? add_48485 : add_48506);
			t_sample wrap_48507 = wrap(switch_48510, ((int)0), ((int)1));
			t_sample gen_48770 = wrap_48507;
			t_sample history_48509_next_48518 = fixdenorm(wrap_48507);
			t_sample sub_54143 = (gen_48770 - m_history_36);
			t_sample add_54145 = (gen_48770 + m_history_36);
			t_sample div_54148 = safediv(sub_54143, add_54145);
			t_sample abs_54149 = fabs(div_54148);
			int gt_54147 = (abs_54149 > ((t_sample)0.5));
			int change_54144 = __m_change_104(gt_54147);
			int gt_54150 = (change_54144 > ((int)0));
			int gen_48768 = gt_54150;
			t_sample history_48499_next_54151 = fixdenorm(gen_48770);
			t_sample mul_48749 = (gen_48770 * ((int)16));
			t_sample wrap_48748 = wrap(mul_48749, ((int)0), ((int)1));
			t_sample sub_54153 = (wrap_48748 - m_history_35);
			t_sample add_54155 = (wrap_48748 + m_history_35);
			t_sample div_54158 = safediv(sub_54153, add_54155);
			t_sample abs_54159 = fabs(div_54158);
			int gt_54154 = (abs_54159 > ((t_sample)0.5));
			int change_54157 = __m_change_105(gt_54154);
			int gt_54160 = (change_54157 > ((int)0));
			int gen_48751 = gt_54160;
			t_sample history_48499_next_54161 = fixdenorm(wrap_48748);
			__m_latch_106 = ((gen_48751 != 0) ? floor_48745 : __m_latch_106);
			t_sample latch_48754 = __m_latch_106;
			t_sample abs_48736 = fabs(latch_48754);
			__m_latch_107 = ((gen_48751 != 0) ? floor_48746 : __m_latch_107);
			t_sample latch_48753 = __m_latch_107;
			t_sample abs_48735 = fabs(latch_48753);
			t_sample min_48733 = ((abs_48735 < abs_48736) ? abs_48735 : abs_48736);
			t_sample max_48734 = ((abs_48736 < abs_48735) ? abs_48735 : abs_48736);
			t_sample div_48737 = safediv(min_48733, max_48734);
			t_sample mul_48732 = (latch_48754 * latch_48753);
			int sign_48739 = ((mul_48732 > 0) ? 1 : ((mul_48732 < 0) ? -1 : 0));
			__m_latch_108 = ((gen_48751 != 0) ? ((int)0) : __m_latch_108);
			int latch_48752 = __m_latch_108;
			t_sample sub_48761 = (mul_48749 - latch_48752);
			t_sample mul_48738 = (sub_48761 * sign_48739);
			t_sample wrap_48755 = wrap(mul_48738, ((int)0), max_48734);
			t_sample floor_48762 = floor(wrap_48755);
			t_sample mul_48757 = (floor_48762 * div_48737);
			t_sample floor_48760 = floor(mul_48757);
			t_sample div_48759 = safediv(floor_48760, div_48737);
			t_sample ceil_48758 = ceil(div_48759);
			t_sample add_48741 = (floor_48760 + ((int)1));
			t_sample div_48743 = safediv(add_48741, div_48737);
			t_sample ceil_48742 = ceil(div_48743);
			t_sample sub_48740 = (ceil_48742 - ceil_48758);
			t_sample sub_48756 = (wrap_48755 - ceil_48758);
			t_sample div_48750 = safediv(sub_48756, sub_48740);
			t_sample gen_48764 = div_48750;
			t_sample sub_54167 = (gen_48764 - m_history_34);
			t_sample add_54168 = (gen_48764 + m_history_34);
			t_sample div_54163 = safediv(sub_54167, add_54168);
			t_sample abs_54169 = fabs(div_54163);
			int gt_54164 = (abs_54169 > ((t_sample)0.5));
			int change_54165 = __m_change_109(gt_54164);
			int gt_54166 = (change_54165 > ((int)0));
			int gen_48778 = gt_54166;
			t_sample history_48499_next_54171 = fixdenorm(gen_48764);
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_48680 = m_offsets_48.read(0, 0);
			t_sample sample_offsets_48681 = (chan_ignore_110 ? 0 : m_offsets_48.read(0, 1));
			t_sample sample_offsets_48682 = (chan_ignore_111 ? 0 : m_offsets_48.read(0, 2));
			t_sample sample_offsets_48683 = (chan_ignore_112 ? 0 : m_offsets_48.read(0, 3));
			t_sample sample_offsets_48684 = (chan_ignore_113 ? 0 : m_offsets_48.read(0, 4));
			t_sample sample_offsets_48685 = (chan_ignore_114 ? 0 : m_offsets_48.read(0, 5));
			t_sample sample_offsets_48686 = (chan_ignore_115 ? 0 : m_offsets_48.read(0, 6));
			t_sample sample_offsets_48687 = (chan_ignore_116 ? 0 : m_offsets_48.read(0, 7));
			t_sample index_offsets_48688 = ((int)0);
			t_sample noise_48676 = noise();
			t_sample abs_48675 = fabs(noise_48676);
			int lt_48677 = (abs_48675 < m_chanceone_58);
			t_sample switch_48678 = (((int)0) ? m_history_23 : lt_48677);
			__m_latch_117 = ((gen_48768 != 0) ? m_history_29 : __m_latch_117);
			t_sample latch_48695 = __m_latch_117;
			t_sample gen_48716 = latch_48695;
			__m_latch_118 = ((gen_48768 != 0) ? m_history_33 : __m_latch_118);
			t_sample latch_48693 = __m_latch_118;
			t_sample gen_48717 = latch_48693;
			__m_latch_119 = ((gen_48768 != 0) ? m_history_28 : __m_latch_119);
			t_sample latch_48698 = __m_latch_119;
			t_sample gen_48714 = latch_48698;
			__m_latch_120 = ((gen_48768 != 0) ? m_history_27 : __m_latch_120);
			t_sample latch_48702 = __m_latch_120;
			t_sample gen_48712 = latch_48702;
			__m_latch_121 = ((gen_48768 != 0) ? m_history_31 : __m_latch_121);
			t_sample latch_48696 = __m_latch_121;
			t_sample gen_48715 = latch_48696;
			__m_latch_122 = ((gen_48768 != 0) ? m_history_30 : __m_latch_122);
			t_sample latch_48700 = __m_latch_122;
			t_sample gen_48713 = latch_48700;
			__m_latch_123 = ((gen_48768 != 0) ? m_history_32 : __m_latch_123);
			t_sample latch_48691 = __m_latch_123;
			t_sample gen_48718 = latch_48691;
			__m_latch_124 = ((gen_48768 != 0) ? switch_48678 : __m_latch_124);
			t_sample latch_48703 = __m_latch_124;
			t_sample gen_48711 = latch_48703;
			t_sample history_48692_next_48704 = fixdenorm(latch_48695);
			t_sample history_48690_next_48705 = fixdenorm(latch_48693);
			t_sample history_48689_next_48706 = fixdenorm(latch_48698);
			t_sample history_48699_next_48707 = fixdenorm(latch_48702);
			t_sample history_48694_next_48708 = fixdenorm(latch_48696);
			t_sample history_48697_next_48709 = fixdenorm(latch_48700);
			t_sample history_48701_next_48710 = fixdenorm(latch_48703);
			t_sample mul_48719 = (gen_48718 * sample_offsets_48687);
			t_sample mul_48720 = (gen_48717 * sample_offsets_48686);
			t_sample mul_48721 = (gen_48716 * sample_offsets_48685);
			t_sample mul_48722 = (gen_48715 * sample_offsets_48684);
			t_sample mul_48723 = (gen_48714 * sample_offsets_48683);
			t_sample mul_48724 = (gen_48713 * sample_offsets_48682);
			t_sample mul_48725 = (gen_48712 * sample_offsets_48681);
			t_sample mul_48726 = (gen_48711 * sample_offsets_48680);
			t_sample pass_48727 = (((((((mul_48726 + mul_48725) + mul_48724) + mul_48723) + mul_48722) + mul_48721) + mul_48720) + mul_48719);
			int change_48672 = __m_change_125(gen_48778);
			int neq_48671 = (change_48672 != ((int)0));
			t_sample switch_48662 = (neq_48671 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_54496 = (m_history_26 + (switch_48662 * (neq_48671 - m_history_26)));
			t_sample mix_48661 = mix_54496;
			t_sample mix_54497 = (m_history_25 + (((t_sample)0.04) * (mix_48661 - m_history_25)));
			t_sample mix_48659 = mix_54497;
			t_sample gen_48665 = mix_48659;
			t_sample history_48660_next_48663 = fixdenorm(mix_48661);
			t_sample history_48658_next_48664 = fixdenorm(mix_48659);
			t_sample mul_48654 = (gen_48665 * ((int)100));
			t_sample add_48666 = (pass_48727 + ((int)60));
			t_sample mtof_48667 = mtof(add_48666, ((int)440));
			__m_cycle_126.freq((m_history_24 + mtof_48667));
			t_sample cycle_48668 = __m_cycle_126(__sinedata);
			t_sample cycleindex_48669 = __m_cycle_126.phase();
			t_sample clamp_48656 = ((cycle_48668 <= min_127) ? min_127 : ((cycle_48668 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_48668));
			t_sample mul_48655 = (clamp_48656 * mul_48654);
			t_sample mul_48670 = (clamp_48656 * gen_48665);
			t_sample history_48657_next_48673 = fixdenorm(mul_48655);
			t_sample history_48679_next_48728 = fixdenorm(gen_48718);
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_54176 = m_offsets_48.read(0, 0);
			t_sample sample_offsets_54200 = (chan_ignore_128 ? 0 : m_offsets_48.read(0, 1));
			t_sample sample_offsets_54204 = (chan_ignore_129 ? 0 : m_offsets_48.read(0, 2));
			t_sample sample_offsets_54175 = (chan_ignore_130 ? 0 : m_offsets_48.read(0, 3));
			t_sample sample_offsets_54235 = (chan_ignore_131 ? 0 : m_offsets_48.read(0, 4));
			t_sample sample_offsets_54234 = (chan_ignore_132 ? 0 : m_offsets_48.read(0, 5));
			t_sample sample_offsets_54205 = (chan_ignore_133 ? 0 : m_offsets_48.read(0, 6));
			t_sample sample_offsets_54233 = (chan_ignore_134 ? 0 : m_offsets_48.read(0, 7));
			t_sample index_offsets_54232 = ((int)0);
			t_sample noise_54228 = noise();
			t_sample abs_54186 = fabs(noise_54228);
			int lt_54209 = (abs_54186 < m_chancetwo_54);
			t_sample switch_54208 = (((int)0) ? m_history_12 : lt_54209);
			__m_latch_135 = ((gen_48768 != 0) ? m_history_18 : __m_latch_135);
			t_sample latch_54231 = __m_latch_135;
			t_sample gen_54230 = latch_54231;
			__m_latch_136 = ((gen_48768 != 0) ? m_history_22 : __m_latch_136);
			t_sample latch_54229 = __m_latch_136;
			t_sample gen_54238 = latch_54229;
			__m_latch_137 = ((gen_48768 != 0) ? m_history_17 : __m_latch_137);
			t_sample latch_54199 = __m_latch_137;
			t_sample gen_54180 = latch_54199;
			__m_latch_138 = ((gen_48768 != 0) ? m_history_16 : __m_latch_138);
			t_sample latch_54227 = __m_latch_138;
			t_sample gen_54226 = latch_54227;
			__m_latch_139 = ((gen_48768 != 0) ? m_history_20 : __m_latch_139);
			t_sample latch_54225 = __m_latch_139;
			t_sample gen_54242 = latch_54225;
			__m_latch_140 = ((gen_48768 != 0) ? m_history_19 : __m_latch_140);
			t_sample latch_54184 = __m_latch_140;
			t_sample gen_54224 = latch_54184;
			__m_latch_141 = ((gen_48768 != 0) ? m_history_21 : __m_latch_141);
			t_sample latch_54192 = __m_latch_141;
			t_sample gen_54247 = latch_54192;
			__m_latch_142 = ((gen_48768 != 0) ? switch_54208 : __m_latch_142);
			t_sample latch_54191 = __m_latch_142;
			t_sample gen_54201 = latch_54191;
			t_sample history_48692_next_54236 = fixdenorm(latch_54231);
			t_sample history_48690_next_54188 = fixdenorm(latch_54229);
			t_sample history_48689_next_54198 = fixdenorm(latch_54199);
			t_sample history_48699_next_54185 = fixdenorm(latch_54227);
			t_sample history_48694_next_54223 = fixdenorm(latch_54225);
			t_sample history_48697_next_54181 = fixdenorm(latch_54184);
			t_sample history_48701_next_54178 = fixdenorm(latch_54191);
			t_sample mul_54182 = (gen_54247 * sample_offsets_54233);
			t_sample mul_54214 = (gen_54238 * sample_offsets_54205);
			t_sample mul_54221 = (gen_54230 * sample_offsets_54234);
			t_sample mul_54203 = (gen_54242 * sample_offsets_54235);
			t_sample mul_54220 = (gen_54180 * sample_offsets_54175);
			t_sample mul_54193 = (gen_54224 * sample_offsets_54204);
			t_sample mul_54219 = (gen_54226 * sample_offsets_54200);
			t_sample mul_54218 = (gen_54201 * sample_offsets_54176);
			t_sample pass_54179 = (((((((mul_54218 + mul_54219) + mul_54193) + mul_54220) + mul_54203) + mul_54221) + mul_54214) + mul_54182);
			int change_54173 = __m_change_143(gen_48778);
			int neq_54217 = (change_54173 != ((int)0));
			t_sample switch_54240 = (neq_54217 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_54498 = (m_history_15 + (switch_54240 * (neq_54217 - m_history_15)));
			t_sample mix_54196 = mix_54498;
			t_sample mix_54499 = (m_history_14 + (((t_sample)0.04) * (mix_54196 - m_history_14)));
			t_sample mix_54216 = mix_54499;
			t_sample gen_54215 = mix_54216;
			t_sample history_48660_next_54222 = fixdenorm(mix_54196);
			t_sample history_48658_next_54195 = fixdenorm(mix_54216);
			t_sample mul_54183 = (gen_54215 * ((int)100));
			t_sample add_54190 = (pass_54179 + ((int)60));
			t_sample mtof_54213 = mtof(add_54190, ((int)440));
			__m_cycle_144.freq((m_history_13 + mtof_54213));
			t_sample cycle_54246 = __m_cycle_144(__sinedata);
			t_sample cycleindex_54212 = __m_cycle_144.phase();
			t_sample clamp_54211 = ((cycle_54246 <= min_145) ? min_145 : ((cycle_54246 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_54246));
			t_sample mul_54197 = (clamp_54211 * mul_54183);
			t_sample mul_54245 = (clamp_54211 * gen_54215);
			t_sample history_48657_next_54177 = fixdenorm(mul_54197);
			t_sample history_48679_next_54206 = fixdenorm(gen_54247);
			t_sample mix_54500 = (mul_48670 + (((t_sample)0.25) * (mul_54245 - mul_48670)));
			// samples offsets channel 1;
			// samples offsets channel 2;
			// samples offsets channel 3;
			// samples offsets channel 4;
			// samples offsets channel 5;
			// samples offsets channel 6;
			// samples offsets channel 7;
			// samples offsets channel 8;
			t_sample sample_offsets_49141 = m_offsets_48.read(0, 0);
			t_sample sample_offsets_49142 = (chan_ignore_146 ? 0 : m_offsets_48.read(0, 1));
			t_sample sample_offsets_49143 = (chan_ignore_147 ? 0 : m_offsets_48.read(0, 2));
			t_sample sample_offsets_49144 = (chan_ignore_148 ? 0 : m_offsets_48.read(0, 3));
			t_sample sample_offsets_49145 = (chan_ignore_149 ? 0 : m_offsets_48.read(0, 4));
			t_sample sample_offsets_49146 = (chan_ignore_150 ? 0 : m_offsets_48.read(0, 5));
			t_sample sample_offsets_49147 = (chan_ignore_151 ? 0 : m_offsets_48.read(0, 6));
			t_sample sample_offsets_49148 = (chan_ignore_152 ? 0 : m_offsets_48.read(0, 7));
			t_sample index_offsets_49149 = ((int)0);
			t_sample noise_49137 = noise();
			t_sample abs_49136 = fabs(noise_49137);
			int lt_49138 = (abs_49136 < m_chancethree_46);
			t_sample switch_49139 = (((int)0) ? m_history_1 : lt_49138);
			__m_latch_153 = ((gen_48768 != 0) ? m_history_7 : __m_latch_153);
			t_sample latch_54292 = __m_latch_153;
			t_sample gen_49155 = latch_54292;
			__m_latch_154 = ((gen_48768 != 0) ? m_history_11 : __m_latch_154);
			t_sample latch_54291 = __m_latch_154;
			t_sample gen_49156 = latch_54291;
			__m_latch_155 = ((gen_48768 != 0) ? m_history_6 : __m_latch_155);
			t_sample latch_54278 = __m_latch_155;
			t_sample gen_49153 = latch_54278;
			__m_latch_156 = ((gen_48768 != 0) ? m_history_5 : __m_latch_156);
			t_sample latch_54289 = __m_latch_156;
			t_sample gen_49151 = latch_54289;
			__m_latch_157 = ((gen_48768 != 0) ? m_history_9 : __m_latch_157);
			t_sample latch_54288 = __m_latch_157;
			t_sample gen_49154 = latch_54288;
			__m_latch_158 = ((gen_48768 != 0) ? m_history_8 : __m_latch_158);
			t_sample latch_54266 = __m_latch_158;
			t_sample gen_49152 = latch_54266;
			__m_latch_159 = ((gen_48768 != 0) ? m_history_10 : __m_latch_159);
			t_sample latch_54272 = __m_latch_159;
			t_sample gen_49157 = latch_54272;
			__m_latch_160 = ((gen_48768 != 0) ? switch_49139 : __m_latch_160);
			t_sample latch_54271 = __m_latch_160;
			t_sample gen_49150 = latch_54271;
			t_sample history_48692_next_54294 = fixdenorm(latch_54292);
			t_sample history_48690_next_54268 = fixdenorm(latch_54291);
			t_sample history_48689_next_54277 = fixdenorm(latch_54278);
			t_sample history_48699_next_54267 = fixdenorm(latch_54289);
			t_sample history_48694_next_54287 = fixdenorm(latch_54288);
			t_sample history_48697_next_54263 = fixdenorm(latch_54266);
			t_sample history_48701_next_54262 = fixdenorm(latch_54271);
			t_sample mul_49158 = (gen_49157 * sample_offsets_49148);
			t_sample mul_49159 = (gen_49156 * sample_offsets_49147);
			t_sample mul_49160 = (gen_49155 * sample_offsets_49146);
			t_sample mul_49161 = (gen_49154 * sample_offsets_49145);
			t_sample mul_49162 = (gen_49153 * sample_offsets_49144);
			t_sample mul_49163 = (gen_49152 * sample_offsets_49143);
			t_sample mul_49164 = (gen_49151 * sample_offsets_49142);
			t_sample mul_49165 = (gen_49150 * sample_offsets_49141);
			t_sample pass_49166 = (((((((mul_49165 + mul_49164) + mul_49163) + mul_49162) + mul_49161) + mul_49160) + mul_49159) + mul_49158);
			int change_54259 = __m_change_161(gen_48778);
			int neq_54286 = (change_54259 != ((int)0));
			t_sample switch_54296 = (neq_54286 ? ((int)1) : ((t_sample)0.0004));
			t_sample mix_54501 = (m_history_4 + (switch_54296 * (neq_54286 - m_history_4)));
			t_sample mix_54275 = mix_54501;
			t_sample mix_54502 = (m_history_3 + (((t_sample)0.04) * (mix_54275 - m_history_3)));
			t_sample mix_54285 = mix_54502;
			t_sample gen_54284 = mix_54285;
			t_sample history_48660_next_54290 = fixdenorm(mix_54275);
			t_sample history_48658_next_54274 = fixdenorm(mix_54285);
			t_sample mul_54265 = (gen_54284 * ((int)100));
			t_sample add_54270 = (pass_49166 + ((int)60));
			t_sample mtof_54283 = mtof(add_54270, ((int)440));
			__m_cycle_162.freq((m_history_2 + mtof_54283));
			t_sample cycle_54300 = __m_cycle_162(__sinedata);
			t_sample cycleindex_54282 = __m_cycle_162.phase();
			t_sample clamp_54281 = ((cycle_54300 <= min_163) ? min_163 : ((cycle_54300 >= ((t_sample)0.25)) ? ((t_sample)0.25) : cycle_54300));
			t_sample mul_54276 = (clamp_54281 * mul_54265);
			t_sample mul_54299 = (clamp_54281 * gen_54284);
			t_sample history_48657_next_54261 = fixdenorm(mul_54276);
			t_sample history_49140_next_49532 = fixdenorm(gen_49157);
			t_sample mix_54503 = (mul_54245 + (((t_sample)0.75) * (mul_54299 - mul_54245)));
			t_sample mix_54504 = (mix_54500 + (((t_sample)0.25) * (mix_54503 - mix_54500)));
			t_sample mul_48615 = (mix_54504 * ((t_sample)0.3));
			t_sample mix_54505 = (mul_48615 + (((t_sample)0.7) * (in1 - mul_48615)));
			t_sample out1 = mix_54505;
			t_sample mix_54506 = (mix_54503 + (((t_sample)0.25) * (mix_54500 - mix_54503)));
			t_sample mul_48614 = (mix_54506 * ((t_sample)0.3));
			t_sample mix_54507 = (mul_48614 + (((t_sample)0.7) * (in2 - mul_48614)));
			t_sample out2 = mix_54507;
			m_history_42 = history_50938_next_50941;
			m_history_41 = history_50927_next_50943;
			m_history_40 = history_48499_next_48504;
			m_history_37 = history_48509_next_48518;
			m_history_38 = history_48481_next_48517;
			m_history_39 = history_48491_next_48492;
			m_history_36 = history_48499_next_54151;
			m_history_35 = history_48499_next_54161;
			m_history_34 = history_48499_next_54171;
			m_history_33 = history_48692_next_48704;
			m_history_23 = history_48679_next_48728;
			m_history_25 = history_48658_next_48664;
			m_history_24 = history_48657_next_48673;
			m_history_26 = history_48660_next_48663;
			m_history_32 = history_48690_next_48705;
			m_history_31 = history_48689_next_48706;
			m_history_30 = history_48699_next_48707;
			m_history_29 = history_48694_next_48708;
			m_history_28 = history_48697_next_48709;
			m_history_27 = history_48701_next_48710;
			m_history_22 = history_48692_next_54236;
			m_history_12 = history_48679_next_54206;
			m_history_14 = history_48658_next_54195;
			m_history_13 = history_48657_next_54177;
			m_history_15 = history_48660_next_54222;
			m_history_21 = history_48690_next_54188;
			m_history_20 = history_48689_next_54198;
			m_history_19 = history_48699_next_54185;
			m_history_18 = history_48694_next_54223;
			m_history_17 = history_48697_next_54181;
			m_history_16 = history_48701_next_54178;
			m_history_11 = history_48692_next_54294;
			m_history_1 = history_49140_next_49532;
			m_history_3 = history_48658_next_54274;
			m_history_2 = history_48657_next_54261;
			m_history_4 = history_48660_next_54290;
			m_history_10 = history_48690_next_54268;
			m_history_9 = history_48689_next_54277;
			m_history_8 = history_48699_next_54267;
			m_history_7 = history_48694_next_54287;
			m_history_6 = history_48697_next_54263;
			m_history_5 = history_48701_next_54262;
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
	inline void set_bpm(t_param _value) {
		m_bpm_43 = (_value < 40 ? 40 : (_value > 200 ? 200 : _value));
	};
	inline void set_k(t_param _value) {
		m_k_44 = (_value < 1 ? 1 : (_value > 16 ? 16 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_45 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_chancethree(t_param _value) {
		m_chancethree_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_offsets(void * _value) {
		m_offsets_48.setbuffer(_value);
	};
	inline void set_sw5(t_param _value) {
		m_sw_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_50 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_51 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_chancetwo(t_param _value) {
		m_chancetwo_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_n(t_param _value) {
		m_n_55 = (_value < 1 ? 1 : (_value > 16 ? 16 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_56 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_chanceone(t_param _value) {
		m_chanceone_58 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_bpm_43; break;
		case 1: *value = self->m_chanceone_58; break;
		case 2: *value = self->m_chancethree_46; break;
		case 3: *value = self->m_chancetwo_54; break;
		case 4: *value = self->m_gate_47; break;
		case 5: *value = self->m_k_44; break;
		case 6: *value = self->m_n_55; break;
		
		case 8: *value = self->m_sw_45; break;
		case 9: *value = self->m_sw_57; break;
		case 10: *value = self->m_sw_53; break;
		case 11: *value = self->m_sw_56; break;
		case 12: *value = self->m_sw_49; break;
		case 13: *value = self->m_sw_52; break;
		case 14: *value = self->m_sw_51; break;
		case 15: *value = self->m_sw_50; break;
		
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
	// initialize parameter 0 ("m_bpm_43")
	pi = self->__commonstate.params + 0;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_43;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 40;
	pi->outputmax = 200;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_chanceone_58")
	pi = self->__commonstate.params + 1;
	pi->name = "chanceone";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chanceone_58;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_chancethree_46")
	pi = self->__commonstate.params + 2;
	pi->name = "chancethree";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chancethree_46;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_chancetwo_54")
	pi = self->__commonstate.params + 3;
	pi->name = "chancetwo";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chancetwo_54;
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
	// initialize parameter 5 ("m_k_44")
	pi = self->__commonstate.params + 5;
	pi->name = "k";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_k_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_n_55")
	pi = self->__commonstate.params + 6;
	pi->name = "n";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_n_55;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_offsets_48")
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
	// initialize parameter 8 ("m_sw_45")
	pi = self->__commonstate.params + 8;
	pi->name = "sw1";
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
	// initialize parameter 9 ("m_sw_57")
	pi = self->__commonstate.params + 9;
	pi->name = "sw2";
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
	// initialize parameter 10 ("m_sw_53")
	pi = self->__commonstate.params + 10;
	pi->name = "sw3";
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
	// initialize parameter 11 ("m_sw_56")
	pi = self->__commonstate.params + 11;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_56;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_49")
	pi = self->__commonstate.params + 12;
	pi->name = "sw5";
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
	// initialize parameter 13 ("m_sw_52")
	pi = self->__commonstate.params + 13;
	pi->name = "sw6";
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
	// initialize parameter 14 ("m_sw_51")
	pi = self->__commonstate.params + 14;
	pi->name = "sw7";
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
	// initialize parameter 15 ("m_sw_50")
	pi = self->__commonstate.params + 15;
	pi->name = "sw8";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // harmonia_2dterra::
