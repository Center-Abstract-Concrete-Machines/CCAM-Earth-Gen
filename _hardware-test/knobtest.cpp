#include "knobtest.h"

namespace knobtest {

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
	Change __m_change_106;
	Change __m_change_62;
	Change __m_change_61;
	Change __m_change_38;
	Change __m_change_69;
	Change __m_change_70;
	Change __m_change_54;
	Change __m_change_46;
	Change __m_change_30;
	Change __m_change_53;
	Change __m_change_29;
	Change __m_change_45;
	Change __m_change_77;
	Change __m_change_37;
	Change __m_change_101;
	Change __m_change_85;
	Change __m_change_103;
	Change __m_change_84;
	Change __m_change_104;
	Change __m_change_78;
	Data m_gates_16;
	Data m_notes_25;
	Delta __m_delta_102;
	Delta __m_delta_31;
	Delta __m_delta_39;
	Delta __m_delta_71;
	Delta __m_delta_47;
	Delta __m_delta_63;
	Delta __m_delta_86;
	Delta __m_delta_79;
	Delta __m_delta_55;
	Phasor __m_phasor_92;
	PlusEquals __m_pluseq_105;
	PlusEquals __m_pluseq_26;
	SineCycle __m_cycle_100;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample __m_count_32;
	t_sample m_history_8;
	t_sample m_history_7;
	t_sample __m_carry_82;
	t_sample m_history_6;
	t_sample __m_count_80;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_knob_11;
	t_sample __m_carry_74;
	t_sample __m_count_87;
	t_sample samples_to_seconds;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample __m_carry_89;
	t_sample m_history_2;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample m_history_5;
	t_sample __m_carry_34;
	t_sample __m_count_72;
	t_sample m_knob_13;
	t_sample m_button_22;
	t_sample __m_count_48;
	t_sample __m_carry_50;
	t_sample m_knob_21;
	t_sample m_button_23;
	t_sample __m_latch_27;
	t_sample m_knob_24;
	t_sample __m_count_40;
	t_sample m_button_12;
	t_sample m_button_20;
	t_sample __m_count_56;
	t_sample __m_count_64;
	t_sample __m_carry_66;
	t_sample m_button_14;
	t_sample m_knob_19;
	t_sample m_button_15;
	t_sample m_button_18;
	t_sample m_button_17;
	t_sample __m_carry_58;
	t_sample __m_carry_42;
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
		m_knob_11 = ((int)0);
		m_button_12 = ((int)0);
		m_knob_13 = ((int)0);
		m_button_14 = ((int)0);
		m_button_15 = ((int)0);
		m_gates_16.reset("gates", ((int)512), ((int)1));
		m_button_17 = ((int)0);
		m_button_18 = ((int)0);
		m_knob_19 = ((int)0);
		m_button_20 = ((int)0);
		m_knob_21 = ((int)0);
		m_button_22 = ((int)0);
		m_button_23 = ((int)0);
		m_knob_24 = ((int)0);
		m_notes_25.reset("notes", ((int)512), ((int)1));
		__m_pluseq_26.reset(0);
		__m_latch_27 = 0;
		__m_change_29.reset(0);
		__m_change_30.reset(0);
		__m_delta_31.reset(0);
		__m_count_32 = 0;
		__m_carry_34 = 0;
		__m_change_37.reset(0);
		__m_change_38.reset(0);
		__m_delta_39.reset(0);
		__m_count_40 = 0;
		__m_carry_42 = 0;
		__m_change_45.reset(0);
		__m_change_46.reset(0);
		__m_delta_47.reset(0);
		__m_count_48 = 0;
		__m_carry_50 = 0;
		__m_change_53.reset(0);
		__m_change_54.reset(0);
		__m_delta_55.reset(0);
		__m_count_56 = 0;
		__m_carry_58 = 0;
		__m_change_61.reset(0);
		__m_change_62.reset(0);
		__m_delta_63.reset(0);
		__m_count_64 = 0;
		__m_carry_66 = 0;
		__m_change_69.reset(0);
		__m_change_70.reset(0);
		__m_delta_71.reset(0);
		__m_count_72 = 0;
		__m_carry_74 = 0;
		__m_change_77.reset(0);
		__m_change_78.reset(0);
		__m_delta_79.reset(0);
		__m_count_80 = 0;
		__m_carry_82 = 0;
		__m_change_84.reset(0);
		__m_change_85.reset(0);
		__m_delta_86.reset(0);
		__m_count_87 = 0;
		__m_carry_89 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_92.reset(0);
		__m_cycle_100.reset(samplerate, 0);
		__m_change_101.reset(0);
		__m_delta_102.reset(0);
		__m_change_103.reset(0);
		__m_change_104.reset(0);
		__m_pluseq_105.reset(0);
		__m_change_106.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
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
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int notes_dim = m_notes_25.dim;
		int notes_channels = m_notes_25.channels;
		int int_87 = int(m_button_15);
		int gates_dim = m_gates_16.dim;
		int gates_channels = m_gates_16.channels;
		bool index_ignore_36 = (((int)2) >= gates_dim);
		int int_2952 = int(m_button_23);
		bool index_ignore_44 = (((int)8) >= gates_dim);
		int int_2953 = int(m_button_14);
		bool index_ignore_52 = (((int)1) >= gates_dim);
		int int_2956 = int(m_button_17);
		bool index_ignore_60 = (((int)3) >= gates_dim);
		int int_2959 = int(m_button_18);
		bool index_ignore_68 = (((int)4) >= gates_dim);
		int int_2962 = int(m_button_22);
		bool index_ignore_76 = (((int)5) >= gates_dim);
		int int_2965 = int(m_button_12);
		int int_2968 = int(m_button_20);
		bool index_ignore_91 = (((int)6) >= gates_dim);
		t_sample div_1865 = (m_knob_24 * ((t_sample)0.016666666666667));
		t_sample mul_1867 = (div_1865 * ((int)1));
		t_sample div_1862 = (mul_1867 * ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample history_31_next_67 = fixdenorm(((t_sample)0.5));
		t_sample mul_8 = (samplerate * (2 * ((t_sample)0.33333333333333)));
		t_sample t_9 = exp(safediv(-6.9077552789821, mul_8));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			int lt_134 = (m_history_1 < ((int)9));
			int plusequals_135 = __m_pluseq_26.post(lt_134, ((int)0), 0);
			int sub_127 = (plusequals_135 - ((int)1));
			t_sample noise_141 = noise();
			__m_latch_27 = ((plusequals_135 != 0) ? noise_141 : __m_latch_27);
			t_sample latch_138 = __m_latch_27;
			t_sample sub_3105 = (latch_138 - (-1));
			t_sample scale_3102 = ((safepow((sub_3105 * ((t_sample)0.5)), ((int)1)) * ((int)12)) + ((int)60));
			t_sample mtof_139 = mtof(scale_3102, ((int)440));
			bool index_ignore_28 = ((sub_127 >= notes_dim) || (sub_127 < 0));
			if ((!index_ignore_28)) {
				m_notes_25.write(mtof_139, sub_127, 0);
				
			};
			int change_88 = __m_change_29(int_87);
			int eqp_89 = ((int_87 == change_88) ? int_87 : 0);
			int change_763 = __m_change_30(eqp_89);
			int delta_762 = __m_delta_31(change_763);
			int gt_761 = (delta_762 > ((t_sample)0.5));
			__m_count_32 = (((int)0) ? 0 : (fixdenorm(__m_count_32 + gt_761)));
			int carry_33 = 0;
			if ((((int)0) != 0)) {
				__m_count_32 = 0;
				__m_carry_34 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_32 >= ((int)2)))) {
				int wraps_35 = (__m_count_32 / ((int)2));
				__m_carry_34 = (__m_carry_34 + wraps_35);
				__m_count_32 = (__m_count_32 - (wraps_35 * ((int)2)));
				carry_33 = 1;
				
			};
			int counter_758 = __m_count_32;
			int counter_759 = carry_33;
			int counter_760 = __m_carry_34;
			if ((!index_ignore_36)) {
				m_gates_16.write(counter_758, ((int)2), 0);
				
			};
			int change_2951 = __m_change_37(int_2952);
			int eqp_2950 = ((int_2952 == change_2951) ? int_2952 : 0);
			int change_923 = __m_change_38(eqp_2950);
			int delta_922 = __m_delta_39(change_923);
			int gt_921 = (delta_922 > ((t_sample)0.5));
			__m_count_40 = (((int)0) ? 0 : (fixdenorm(__m_count_40 + gt_921)));
			int carry_41 = 0;
			if ((((int)0) != 0)) {
				__m_count_40 = 0;
				__m_carry_42 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_40 >= ((int)2)))) {
				int wraps_43 = (__m_count_40 / ((int)2));
				__m_carry_42 = (__m_carry_42 + wraps_43);
				__m_count_40 = (__m_count_40 - (wraps_43 * ((int)2)));
				carry_41 = 1;
				
			};
			int counter_918 = __m_count_40;
			int counter_919 = carry_41;
			int counter_920 = __m_carry_42;
			if ((!index_ignore_44)) {
				m_gates_16.write(counter_918, ((int)8), 0);
				
			};
			int change_2955 = __m_change_45(int_2953);
			int eqp_2954 = ((int_2953 == change_2955) ? int_2953 : 0);
			int change_674 = __m_change_46(eqp_2954);
			int delta_673 = __m_delta_47(change_674);
			int gt_672 = (delta_673 > ((t_sample)0.5));
			__m_count_48 = (((int)0) ? 0 : (fixdenorm(__m_count_48 + gt_672)));
			int carry_49 = 0;
			if ((((int)0) != 0)) {
				__m_count_48 = 0;
				__m_carry_50 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_48 >= ((int)2)))) {
				int wraps_51 = (__m_count_48 / ((int)2));
				__m_carry_50 = (__m_carry_50 + wraps_51);
				__m_count_48 = (__m_count_48 - (wraps_51 * ((int)2)));
				carry_49 = 1;
				
			};
			int counter_669 = __m_count_48;
			int counter_670 = carry_49;
			int counter_671 = __m_carry_50;
			if ((!index_ignore_52)) {
				m_gates_16.write(counter_669, ((int)1), 0);
				
			};
			int change_2958 = __m_change_53(int_2956);
			int eqp_2957 = ((int_2956 == change_2958) ? int_2956 : 0);
			int change_755 = __m_change_54(eqp_2957);
			int delta_754 = __m_delta_55(change_755);
			int gt_753 = (delta_754 > ((t_sample)0.5));
			__m_count_56 = (((int)0) ? 0 : (fixdenorm(__m_count_56 + gt_753)));
			int carry_57 = 0;
			if ((((int)0) != 0)) {
				__m_count_56 = 0;
				__m_carry_58 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_56 >= ((int)2)))) {
				int wraps_59 = (__m_count_56 / ((int)2));
				__m_carry_58 = (__m_carry_58 + wraps_59);
				__m_count_56 = (__m_count_56 - (wraps_59 * ((int)2)));
				carry_57 = 1;
				
			};
			int counter_750 = __m_count_56;
			int counter_751 = carry_57;
			int counter_752 = __m_carry_58;
			if ((!index_ignore_60)) {
				m_gates_16.write(counter_750, ((int)3), 0);
				
			};
			int change_2961 = __m_change_61(int_2959);
			int eqp_2960 = ((int_2959 == change_2961) ? int_2959 : 0);
			int change_947 = __m_change_62(eqp_2960);
			int delta_946 = __m_delta_63(change_947);
			int gt_945 = (delta_946 > ((t_sample)0.5));
			__m_count_64 = (((int)0) ? 0 : (fixdenorm(__m_count_64 + gt_945)));
			int carry_65 = 0;
			if ((((int)0) != 0)) {
				__m_count_64 = 0;
				__m_carry_66 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_64 >= ((int)2)))) {
				int wraps_67 = (__m_count_64 / ((int)2));
				__m_carry_66 = (__m_carry_66 + wraps_67);
				__m_count_64 = (__m_count_64 - (wraps_67 * ((int)2)));
				carry_65 = 1;
				
			};
			int counter_942 = __m_count_64;
			int counter_943 = carry_65;
			int counter_944 = __m_carry_66;
			if ((!index_ignore_68)) {
				m_gates_16.write(counter_942, ((int)4), 0);
				
			};
			int change_2964 = __m_change_69(int_2962);
			int eqp_2963 = ((int_2962 == change_2964) ? int_2962 : 0);
			int change_939 = __m_change_70(eqp_2963);
			int delta_938 = __m_delta_71(change_939);
			int gt_937 = (delta_938 > ((t_sample)0.5));
			__m_count_72 = (((int)0) ? 0 : (fixdenorm(__m_count_72 + gt_937)));
			int carry_73 = 0;
			if ((((int)0) != 0)) {
				__m_count_72 = 0;
				__m_carry_74 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_72 >= ((int)2)))) {
				int wraps_75 = (__m_count_72 / ((int)2));
				__m_carry_74 = (__m_carry_74 + wraps_75);
				__m_count_72 = (__m_count_72 - (wraps_75 * ((int)2)));
				carry_73 = 1;
				
			};
			int counter_934 = __m_count_72;
			int counter_935 = carry_73;
			int counter_936 = __m_carry_74;
			if ((!index_ignore_76)) {
				m_gates_16.write(counter_934, ((int)5), 0);
				
			};
			int change_2967 = __m_change_77(int_2965);
			int eqp_2966 = ((int_2965 == change_2967) ? int_2965 : 0);
			int change_259 = __m_change_78(eqp_2966);
			int delta_302 = __m_delta_79(change_259);
			int gt_345 = (delta_302 > ((t_sample)0.5));
			__m_count_80 = (((int)0) ? 0 : (fixdenorm(__m_count_80 + gt_345)));
			int carry_81 = 0;
			if ((((int)0) != 0)) {
				__m_count_80 = 0;
				__m_carry_82 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_80 >= ((int)2)))) {
				int wraps_83 = (__m_count_80 / ((int)2));
				__m_carry_82 = (__m_carry_82 + wraps_83);
				__m_count_80 = (__m_count_80 - (wraps_83 * ((int)2)));
				carry_81 = 1;
				
			};
			int counter_388 = __m_count_80;
			int counter_389 = carry_81;
			int counter_390 = __m_carry_82;
			m_gates_16.write(counter_388, 0, 0);
			int change_2970 = __m_change_84(int_2968);
			int eqp_2969 = ((int_2968 == change_2970) ? int_2968 : 0);
			int change_931 = __m_change_85(eqp_2969);
			int delta_930 = __m_delta_86(change_931);
			int gt_929 = (delta_930 > ((t_sample)0.5));
			__m_count_87 = (((int)0) ? 0 : (fixdenorm(__m_count_87 + gt_929)));
			int carry_88 = 0;
			if ((((int)0) != 0)) {
				__m_count_87 = 0;
				__m_carry_89 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_87 >= ((int)2)))) {
				int wraps_90 = (__m_count_87 / ((int)2));
				__m_carry_89 = (__m_carry_89 + wraps_90);
				__m_count_87 = (__m_count_87 - (wraps_90 * ((int)2)));
				carry_88 = 1;
				
			};
			int counter_926 = __m_count_87;
			int counter_927 = carry_88;
			int counter_928 = __m_carry_89;
			if ((!index_ignore_91)) {
				m_gates_16.write(counter_926, ((int)6), 0);
				
			};
			t_sample phasor_1863 = __m_phasor_92(div_1862, samples_to_seconds);
			t_sample mul_1861 = (phasor_1863 * ((int)4));
			t_sample wrap_1860 = wrap(mul_1861, ((int)0), ((int)1));
			t_sample gen_1868 = wrap_1860;
			t_sample mul_157 = (gen_1868 * ((int)8));
			t_sample floor_156 = floor(mul_157);
			t_sample beat_1417 = floor_156;
			int index_trunc_93 = fixnan(floor(beat_1417));
			bool index_ignore_94 = ((index_trunc_93 >= gates_dim) || (index_trunc_93 < 0));
			// samples gates channel 1;
			t_sample sample_gates_1331 = (index_ignore_94 ? 0 : m_gates_16.read(index_trunc_93, 0));
			t_sample index_gates_1332 = beat_1417;
			t_sample add_195 = (beat_1417 + ((int)1));
			int index_trunc_95 = fixnan(floor(beat_1417));
			bool index_ignore_96 = ((index_trunc_95 >= gates_dim) || (index_trunc_95 < 0));
			// samples gates channel 1;
			t_sample sample_gates_2603 = (index_ignore_96 ? 0 : m_gates_16.read(index_trunc_95, 0));
			t_sample index_gates_2604 = beat_1417;
			t_sample rsub_2863 = (((int)1) - sample_gates_2603);
			t_sample choice_97 = int(add_195);
			t_sample gate_118 = (((choice_97 >= 1) && (choice_97 < 2)) ? rsub_2863 : 0);
			t_sample gate_119 = (((choice_97 >= 2) && (choice_97 < 3)) ? rsub_2863 : 0);
			t_sample gate_120 = (((choice_97 >= 3) && (choice_97 < 4)) ? rsub_2863 : 0);
			t_sample gate_121 = (((choice_97 >= 4) && (choice_97 < 5)) ? rsub_2863 : 0);
			t_sample gate_122 = (((choice_97 >= 5) && (choice_97 < 6)) ? rsub_2863 : 0);
			t_sample gate_123 = (((choice_97 >= 6) && (choice_97 < 7)) ? rsub_2863 : 0);
			t_sample gate_124 = (((choice_97 >= 7) && (choice_97 < 8)) ? rsub_2863 : 0);
			t_sample gate_125 = ((choice_97 >= 8) ? rsub_2863 : 0);
			t_sample out4 = gate_119;
			t_sample out7 = gate_122;
			t_sample out6 = gate_121;
			t_sample out10 = gate_125;
			t_sample out8 = gate_123;
			t_sample out3 = gate_118;
			t_sample out5 = gate_120;
			t_sample out9 = gate_124;
			int index_trunc_98 = fixnan(floor(floor_156));
			bool index_ignore_99 = ((index_trunc_98 >= notes_dim) || (index_trunc_98 < 0));
			// samples notes channel 1;
			t_sample sample_notes_136 = (index_ignore_99 ? 0 : m_notes_25.read(index_trunc_98, 0));
			t_sample index_notes_137 = floor_156;
			__m_cycle_100.freq(sample_notes_136);
			t_sample cycle_154 = __m_cycle_100(__sinedata);
			t_sample cycleindex_155 = __m_cycle_100.phase();
			t_sample mul_36 = (gen_1868 * ((int)2));
			t_sample sub_52 = (gen_1868 - m_history_10);
			t_sample add_53 = (gen_1868 + m_history_10);
			t_sample div_51 = safediv(sub_52, add_53);
			t_sample abs_50 = fabs(div_51);
			int gt_48 = (abs_50 > ((t_sample)0.5));
			int change_47 = __m_change_101(gt_48);
			int gt_46 = (change_47 > ((int)0));
			int gen_55 = gt_46;
			t_sample history_49_next_54 = fixdenorm(gen_1868);
			t_sample delta_61 = __m_delta_102(gen_1868);
			t_sample wrap_62 = wrap(delta_61, (-0.5), ((t_sample)0.5));
			t_sample gen_63 = wrap_62;
			t_sample mul_58 = (gen_63 * ((int)2));
			t_sample add_56 = (mul_58 + m_history_7);
			t_sample sub_34 = (add_56 - mul_36);
			t_sample round_45 = (trunc((sub_34 * ((t_sample)0.5))) * ((int)2));
			t_sample add_35 = (round_45 + mul_36);
			t_sample sub_65 = (m_history_8 - ((t_sample)0.5));
			t_sample add_66 = (m_history_8 + ((t_sample)0.5));
			t_sample div_64 = safediv(sub_65, add_66);
			t_sample abs_29 = fabs(div_64);
			int gt_30 = (abs_29 > ((t_sample)0.015625));
			int and_33 = (gt_30 && ((int)1));
			t_sample switch_37 = (and_33 ? and_33 : m_history_9);
			t_sample switch_40 = (gen_55 ? switch_37 : ((int)0));
			t_sample gen_43 = switch_40;
			t_sample switch_39 = (switch_40 ? ((int)0) : switch_37);
			t_sample history_41_next_42 = fixdenorm(switch_39);
			int or_32 = (gen_43 || ((int)0));
			t_sample switch_60 = (or_32 ? add_35 : add_56);
			t_sample wrap_57 = wrap(switch_60, ((int)0), ((int)1));
			t_sample gen_145 = wrap_57;
			t_sample history_59_next_68 = fixdenorm(wrap_57);
			t_sample wrap_147 = wrap(gen_145, ((int)0), ((int)1));
			t_sample sub_2978 = (wrap_147 - m_history_6);
			t_sample add_2977 = (wrap_147 + m_history_6);
			t_sample div_2971 = safediv(sub_2978, add_2977);
			t_sample abs_2975 = fabs(div_2971);
			int gt_2974 = (abs_2975 > ((t_sample)0.5));
			int change_2972 = __m_change_103(gt_2974);
			int gt_2973 = (change_2972 > ((int)0));
			int gen_146 = gt_2973;
			t_sample history_49_next_2976 = fixdenorm(wrap_147);
			t_sample sub_2988 = (gen_146 - m_history_5);
			t_sample add_2987 = (gen_146 + m_history_5);
			t_sample div_2981 = safediv(sub_2988, add_2987);
			t_sample abs_2985 = fabs(div_2981);
			int gt_2984 = (abs_2985 > ((t_sample)0.5));
			int change_2982 = __m_change_104(gt_2984);
			int gt_2983 = (change_2982 > ((int)0));
			int gen_76 = gt_2983;
			t_sample history_49_next_2986 = fixdenorm(gen_146);
			t_sample plusequals_75 = __m_pluseq_105.post(safediv(8, samplerate), gen_76, 0);
			t_sample clamp_74 = ((plusequals_75 <= ((int)0)) ? ((int)0) : ((plusequals_75 >= ((int)1)) ? ((int)1) : plusequals_75));
			t_sample sub_3109 = (clamp_74 - ((int)0));
			t_sample scale_3106 = ((safepow((sub_3109 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_77 = scale_3106;
			t_sample sub_3113 = (scale_77 - ((int)1));
			t_sample scale_3110 = ((safepow((sub_3113 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_80 = scale_3110;
			t_sample sin_81 = sin(scale_80);
			t_sample mul_82 = (scale_77 * sin_81);
			t_sample mix_3114 = (mul_82 + (((t_sample)0.9) * (m_history_4 - mul_82)));
			t_sample mix_79 = mix_3114;
			t_sample gen_150 = mix_79;
			t_sample history_78_next_83 = fixdenorm(mix_79);
			t_sample mul_149 = (gen_150 * ((t_sample)0.5));
			int change_132 = __m_change_106(floor_156);
			int abs_130 = abs(change_132);
			int gt_131 = (abs_130 > ((t_sample)0.5));
			t_sample mul_7 = ((m_history_3 + gt_131) * t_9);
			t_sample clamp_3 = ((mul_7 <= ((int)0)) ? ((int)0) : ((mul_7 >= ((int)1)) ? ((int)1) : mul_7));
			t_sample mix_3115 = (clamp_3 + (((t_sample)0.97) * (m_history_2 - clamp_3)));
			t_sample mix_5 = mix_3115;
			t_sample gen_129 = mix_5;
			t_sample history_6_next_10 = fixdenorm(clamp_3);
			t_sample history_4_next_11 = fixdenorm(mix_5);
			t_sample mul_128 = (gen_129 * cycle_154);
			t_sample mul_1587 = (mul_128 * sample_gates_1331);
			t_sample out1 = (mul_1587 + mul_149);
			t_sample out2 = (mul_1587 + mul_149);
			t_sample history_133_next_2991 = fixdenorm(plusequals_135);
			m_history_10 = history_49_next_54;
			m_history_7 = history_59_next_68;
			m_history_8 = history_31_next_67;
			m_history_9 = history_41_next_42;
			m_history_6 = history_49_next_2976;
			m_history_5 = history_49_next_2986;
			m_history_4 = history_78_next_83;
			m_history_3 = history_6_next_10;
			m_history_2 = history_4_next_11;
			m_history_1 = history_133_next_2991;
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
			
		};
		return __exception;
		
	};
	inline void set_knob6(t_param _value) {
		m_knob_11 = (_value < 220 ? 220 : (_value > 880 ? 880 : _value));
	};
	inline void set_button1(t_param _value) {
		m_button_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3(t_param _value) {
		m_knob_13 = (_value < 220 ? 220 : (_value > 880 ? 880 : _value));
	};
	inline void set_button2(t_param _value) {
		m_button_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button3(t_param _value) {
		m_button_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gates(void * _value) {
		m_gates_16.setbuffer(_value);
	};
	inline void set_button4(t_param _value) {
		m_button_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button5(t_param _value) {
		m_button_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4(t_param _value) {
		m_knob_19 = (_value < 220 ? 220 : (_value > 880 ? 880 : _value));
	};
	inline void set_button7(t_param _value) {
		m_button_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2(t_param _value) {
		m_knob_21 = (_value < 220 ? 220 : (_value > 880 ? 880 : _value));
	};
	inline void set_button6(t_param _value) {
		m_button_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button8(t_param _value) {
		m_button_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1(t_param _value) {
		m_knob_24 = (_value < 220 ? 220 : (_value > 880 ? 880 : _value));
	};
	inline void set_notes(void * _value) {
		m_notes_25.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 10;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 15; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8" };

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
		case 0: self->set_button1(value); break;
		case 1: self->set_button2(value); break;
		case 2: self->set_button3(value); break;
		case 3: self->set_button4(value); break;
		case 4: self->set_button5(value); break;
		case 5: self->set_button6(value); break;
		case 6: self->set_button7(value); break;
		case 7: self->set_button8(value); break;
		case 8: self->set_gates(ref); break;
		case 9: self->set_knob1(value); break;
		case 10: self->set_knob2(value); break;
		case 11: self->set_knob3(value); break;
		case 12: self->set_knob4(value); break;
		case 13: self->set_knob6(value); break;
		case 14: self->set_notes(ref); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_12; break;
		case 1: *value = self->m_button_14; break;
		case 2: *value = self->m_button_15; break;
		case 3: *value = self->m_button_17; break;
		case 4: *value = self->m_button_18; break;
		case 5: *value = self->m_button_22; break;
		case 6: *value = self->m_button_20; break;
		case 7: *value = self->m_button_23; break;
		
		case 9: *value = self->m_knob_24; break;
		case 10: *value = self->m_knob_21; break;
		case 11: *value = self->m_knob_13; break;
		case 12: *value = self->m_knob_19; break;
		case 13: *value = self->m_knob_11; break;
		
		
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
	// initialize parameter 0 ("m_button_12")
	pi = self->__commonstate.params + 0;
	pi->name = "button1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_button_14")
	pi = self->__commonstate.params + 1;
	pi->name = "button2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_button_15")
	pi = self->__commonstate.params + 2;
	pi->name = "button3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_button_17")
	pi = self->__commonstate.params + 3;
	pi->name = "button4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_button_18")
	pi = self->__commonstate.params + 4;
	pi->name = "button5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_button_22")
	pi = self->__commonstate.params + 5;
	pi->name = "button6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_button_20")
	pi = self->__commonstate.params + 6;
	pi->name = "button7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_button_23")
	pi = self->__commonstate.params + 7;
	pi->name = "button8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gates_16")
	pi = self->__commonstate.params + 8;
	pi->name = "gates";
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
	// initialize parameter 9 ("m_knob_24")
	pi = self->__commonstate.params + 9;
	pi->name = "knob1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 220;
	pi->outputmax = 880;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob_21")
	pi = self->__commonstate.params + 10;
	pi->name = "knob2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 220;
	pi->outputmax = 880;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_knob_13")
	pi = self->__commonstate.params + 11;
	pi->name = "knob3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 220;
	pi->outputmax = 880;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_knob_19")
	pi = self->__commonstate.params + 12;
	pi->name = "knob4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 220;
	pi->outputmax = 880;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_knob_11")
	pi = self->__commonstate.params + 13;
	pi->name = "knob6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 220;
	pi->outputmax = 880;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_notes_25")
	pi = self->__commonstate.params + 14;
	pi->name = "notes";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // knobtest::
