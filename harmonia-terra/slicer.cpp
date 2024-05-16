#include "slicer.h"

namespace slicer {

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
	Change __m_change_39;
	Change __m_change_46;
	Change __m_change_32;
	Change __m_change_25;
	Change __m_change_60;
	Change __m_change_53;
	Change __m_change_66;
	Change __m_change_81;
	Change __m_change_18;
	Data m_loop_10;
	Data m_offsets_6;
	Phasor __m_phasor_80;
	PlusEquals __m_pluseq_58;
	PlusEquals __m_pluseq_30;
	PlusEquals __m_pluseq_37;
	PlusEquals __m_pluseq_65;
	PlusEquals __m_pluseq_44;
	PlusEquals __m_pluseq_51;
	PlusEquals __m_pluseq_71;
	PlusEquals __m_pluseq_23;
	int __exception;
	int vectorsize;
	t_sample __m_count_19;
	t_sample __m_carry_69;
	t_sample m_history_1;
	t_sample __m_count_73;
	t_sample __m_count_67;
	t_sample m_gate_3;
	t_sample m_bpm_2;
	t_sample __m_count_61;
	t_sample __m_carry_63;
	t_sample __m_carry_75;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample m_z_96;
	t_sample m_z_97;
	t_sample m_z_98;
	t_sample m_sw_4;
	t_sample m_y_95;
	t_sample __m_latch_83;
	t_sample m_mf_94;
	t_sample __m_latch_82;
	t_sample m_sw_17;
	t_sample m_sw_5;
	t_sample __m_count_54;
	t_sample m_sw_14;
	t_sample m_sw_13;
	t_sample __m_count_33;
	t_sample __m_carry_35;
	t_sample __m_carry_28;
	t_sample m_randomness_15;
	t_sample __m_count_26;
	t_sample __m_carry_21;
	t_sample m_sw_16;
	t_sample __m_carry_56;
	t_sample m_sw_12;
	t_sample __m_count_40;
	t_sample __m_carry_49;
	t_sample m_jump_8;
	t_sample m_sw_7;
	t_sample m_z_99;
	t_sample __m_count_47;
	t_sample m_q_11;
	t_sample m_overdub_9;
	t_sample __m_carry_42;
	t_sample m_z_100;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_bpm_2 = ((int)0);
		m_gate_3 = ((int)0);
		m_sw_4 = ((int)0);
		m_sw_5 = ((int)0);
		m_offsets_6.reset("offsets", ((int)512), ((int)1));
		m_sw_7 = ((int)0);
		m_jump_8 = 1.25;
		m_overdub_9 = ((int)0);
		m_loop_10.reset("loop", ((int)384000), ((int)2));
		m_q_11 = ((int)0);
		m_sw_12 = ((int)0);
		m_sw_13 = ((int)0);
		m_sw_14 = ((int)0);
		m_randomness_15 = 1;
		m_sw_16 = ((int)0);
		m_sw_17 = ((int)0);
		__m_change_18.reset(0);
		__m_count_19 = 0;
		__m_carry_21 = 0;
		__m_pluseq_23.reset(0);
		__m_change_25.reset(0);
		__m_count_26 = 0;
		__m_carry_28 = 0;
		__m_pluseq_30.reset(0);
		__m_change_32.reset(0);
		__m_count_33 = 0;
		__m_carry_35 = 0;
		__m_pluseq_37.reset(0);
		__m_change_39.reset(0);
		__m_count_40 = 0;
		__m_carry_42 = 0;
		__m_pluseq_44.reset(0);
		__m_change_46.reset(0);
		__m_count_47 = 0;
		__m_carry_49 = 0;
		__m_pluseq_51.reset(0);
		__m_change_53.reset(0);
		__m_count_54 = 0;
		__m_carry_56 = 0;
		__m_pluseq_58.reset(0);
		__m_change_60.reset(0);
		__m_count_61 = 0;
		__m_carry_63 = 0;
		__m_pluseq_65.reset(0);
		__m_change_66.reset(0);
		__m_count_67 = 0;
		__m_carry_69 = 0;
		__m_pluseq_71.reset(0);
		__m_count_73 = 0;
		__m_carry_75 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_80.reset(0);
		__m_change_81.reset(0);
		__m_latch_82 = 0;
		__m_latch_83 = 0;
		m_mf_94 = ((int)0);
		m_y_95 = ((int)0);
		m_z_96 = ((int)0);
		m_z_97 = ((int)0);
		m_z_98 = ((int)0);
		m_z_99 = ((int)0);
		m_z_100 = ((int)0);
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
		t_sample rsub_34690 = (((int)1) - m_overdub_9);
		int int_82 = int(m_sw_4);
		int offsets_dim = m_offsets_6.dim;
		int offsets_channels = m_offsets_6.channels;
		bool chan_ignore_24 = ((((int)1) < 0) || (((int)1) >= offsets_channels));
		int int_47895 = int(m_sw_5);
		bool chan_ignore_31 = ((((int)6) < 0) || (((int)6) >= offsets_channels));
		int int_47918 = int(m_sw_14);
		bool chan_ignore_38 = ((((int)3) < 0) || (((int)3) >= offsets_channels));
		int int_47940 = int(m_sw_7);
		bool chan_ignore_45 = ((((int)7) < 0) || (((int)7) >= offsets_channels));
		int int_47963 = int(m_sw_17);
		bool chan_ignore_52 = ((((int)5) < 0) || (((int)5) >= offsets_channels));
		int int_47986 = int(m_sw_16);
		bool chan_ignore_59 = ((((int)4) < 0) || (((int)4) >= offsets_channels));
		int int_48009 = int(m_sw_12);
		int int_48032 = int(m_sw_13);
		bool chan_ignore_72 = ((((int)2) < 0) || (((int)2) >= offsets_channels));
		int loop_dim = m_loop_10.dim;
		int loop_channels = m_loop_10.channels;
		bool chan_ignore_78 = ((((int)1) < 0) || (((int)1) >= loop_channels));
		t_sample div_37 = (m_bpm_2 * ((t_sample)0.016666666666667));
		t_sample mul_39 = (div_37 * ((int)1));
		t_sample div_34 = (mul_39 * ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		t_sample max_93 = (samplerate * ((t_sample)0.25));
		t_sample res = ((m_q_11 <= ((int)0)) ? ((int)0) : ((m_q_11 >= ((int)1)) ? ((int)1) : m_q_11));
		int expr_47892 = samplerate;
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out11 = ((int)0);
			t_sample out12 = ((int)0);
			int change_83 = __m_change_18(int_82);
			int eqp_84 = ((int_82 == change_83) ? int_82 : 0);
			__m_count_19 = (((int)0) ? 0 : (fixdenorm(__m_count_19 + eqp_84)));
			int carry_20 = 0;
			if ((((int)0) != 0)) {
				__m_count_19 = 0;
				__m_carry_21 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_19 >= ((int)14)))) {
				int wraps_22 = (__m_count_19 / ((int)14));
				__m_carry_21 = (__m_carry_21 + wraps_22);
				__m_count_19 = (__m_count_19 - (wraps_22 * ((int)14)));
				carry_20 = 1;
				
			};
			int counter_57 = __m_count_19;
			int counter_58 = carry_20;
			int counter_59 = __m_carry_21;
			t_sample div_46 = (counter_57 * ((t_sample)0.071428571428571));
			t_sample div_47 = (counter_57 * ((t_sample)0.14285714285714));
			int plusequals_65 = __m_pluseq_23.post(((int)1), ((int)0), 0);
			int lt_63 = (plusequals_65 < ((int)100));
			t_sample noise_62 = noise();
			t_sample add_48 = (noise_62 + ((int)1));
			t_sample floor_61 = floor(add_48);
			t_sample switch_60 = (lt_63 ? floor_61 : div_47);
			t_sample mul_55 = (switch_60 * ((int)7));
			t_sample add_53 = (mul_55 + ((int)12));
			t_sample round_51 = round(add_53);
			t_sample div_52 = (round_51 * ((t_sample)0.14285714285714));
			if ((!chan_ignore_24)) {
				m_offsets_6.write(div_52, 0, ((int)1));
				
			};
			t_sample out4 = div_46;
			int change_47894 = __m_change_25(int_47895);
			int eqp_47893 = ((int_47895 == change_47894) ? int_47895 : 0);
			__m_count_26 = (((int)0) ? 0 : (fixdenorm(__m_count_26 + eqp_47893)));
			int carry_27 = 0;
			if ((((int)0) != 0)) {
				__m_count_26 = 0;
				__m_carry_28 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_26 >= ((int)14)))) {
				int wraps_29 = (__m_count_26 / ((int)14));
				__m_carry_28 = (__m_carry_28 + wraps_29);
				__m_count_26 = (__m_count_26 - (wraps_29 * ((int)14)));
				carry_27 = 1;
				
			};
			int counter_47915 = __m_count_26;
			int counter_47902 = carry_27;
			int counter_47912 = __m_carry_28;
			t_sample div_47901 = (counter_47915 * ((t_sample)0.071428571428571));
			t_sample div_47905 = (counter_47915 * ((t_sample)0.14285714285714));
			int plusequals_47908 = __m_pluseq_30.post(((int)1), ((int)0), 0);
			int lt_47906 = (plusequals_47908 < ((int)100));
			t_sample noise_47904 = noise();
			t_sample add_47913 = (noise_47904 + ((int)1));
			t_sample floor_47898 = floor(add_47913);
			t_sample switch_47896 = (lt_47906 ? floor_47898 : div_47905);
			t_sample mul_47903 = (switch_47896 * ((int)7));
			t_sample add_47899 = (mul_47903 + ((int)12));
			t_sample round_47911 = round(add_47899);
			t_sample div_47909 = (round_47911 * ((t_sample)0.14285714285714));
			t_sample out9 = div_47901;
			if ((!chan_ignore_31)) {
				m_offsets_6.write(div_47909, 0, ((int)6));
				
			};
			int change_47917 = __m_change_32(int_47918);
			int eqp_47916 = ((int_47918 == change_47917) ? int_47918 : 0);
			__m_count_33 = (((int)0) ? 0 : (fixdenorm(__m_count_33 + eqp_47916)));
			int carry_34 = 0;
			if ((((int)0) != 0)) {
				__m_count_33 = 0;
				__m_carry_35 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_33 >= ((int)14)))) {
				int wraps_36 = (__m_count_33 / ((int)14));
				__m_carry_35 = (__m_carry_35 + wraps_36);
				__m_count_33 = (__m_count_33 - (wraps_36 * ((int)14)));
				carry_34 = 1;
				
			};
			int counter_47929 = __m_count_33;
			int counter_47935 = carry_34;
			int counter_47927 = __m_carry_35;
			t_sample div_47921 = (counter_47929 * ((t_sample)0.071428571428571));
			t_sample div_47922 = (counter_47929 * ((t_sample)0.14285714285714));
			int plusequals_47926 = __m_pluseq_37.post(((int)1), ((int)0), 0);
			int lt_47923 = (plusequals_47926 < ((int)100));
			t_sample noise_47936 = noise();
			t_sample add_47934 = (noise_47936 + ((int)1));
			t_sample floor_47932 = floor(add_47934);
			t_sample switch_47930 = (lt_47923 ? floor_47932 : div_47922);
			t_sample mul_47933 = (switch_47930 * ((int)7));
			t_sample add_47919 = (mul_47933 + ((int)12));
			t_sample round_47937 = round(add_47919);
			t_sample div_47938 = (round_47937 * ((t_sample)0.14285714285714));
			if ((!chan_ignore_38)) {
				m_offsets_6.write(div_47938, 0, ((int)3));
				
			};
			t_sample out6 = div_47921;
			int change_47939 = __m_change_39(int_47940);
			int eqp_47941 = ((int_47940 == change_47939) ? int_47940 : 0);
			__m_count_40 = (((int)0) ? 0 : (fixdenorm(__m_count_40 + eqp_47941)));
			int carry_41 = 0;
			if ((((int)0) != 0)) {
				__m_count_40 = 0;
				__m_carry_42 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_40 >= ((int)14)))) {
				int wraps_43 = (__m_count_40 / ((int)14));
				__m_carry_42 = (__m_carry_42 + wraps_43);
				__m_count_40 = (__m_count_40 - (wraps_43 * ((int)14)));
				carry_41 = 1;
				
			};
			int counter_47952 = __m_count_40;
			int counter_47958 = carry_41;
			int counter_47950 = __m_carry_42;
			t_sample div_47944 = (counter_47952 * ((t_sample)0.071428571428571));
			t_sample div_47945 = (counter_47952 * ((t_sample)0.14285714285714));
			int plusequals_47949 = __m_pluseq_44.post(((int)1), ((int)0), 0);
			int lt_47946 = (plusequals_47949 < ((int)100));
			t_sample noise_47959 = noise();
			t_sample add_47957 = (noise_47959 + ((int)1));
			t_sample floor_47955 = floor(add_47957);
			t_sample switch_47953 = (lt_47946 ? floor_47955 : div_47945);
			t_sample mul_47956 = (switch_47953 * ((int)7));
			t_sample add_47942 = (mul_47956 + ((int)12));
			t_sample round_47960 = round(add_47942);
			t_sample div_47961 = (round_47960 * ((t_sample)0.14285714285714));
			if ((!chan_ignore_45)) {
				m_offsets_6.write(div_47961, 0, ((int)7));
				
			};
			t_sample out10 = div_47944;
			int change_47962 = __m_change_46(int_47963);
			int eqp_47964 = ((int_47963 == change_47962) ? int_47963 : 0);
			__m_count_47 = (((int)0) ? 0 : (fixdenorm(__m_count_47 + eqp_47964)));
			int carry_48 = 0;
			if ((((int)0) != 0)) {
				__m_count_47 = 0;
				__m_carry_49 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_47 >= ((int)14)))) {
				int wraps_50 = (__m_count_47 / ((int)14));
				__m_carry_49 = (__m_carry_49 + wraps_50);
				__m_count_47 = (__m_count_47 - (wraps_50 * ((int)14)));
				carry_48 = 1;
				
			};
			int counter_47976 = __m_count_47;
			int counter_47982 = carry_48;
			int counter_47974 = __m_carry_49;
			t_sample div_47967 = (counter_47976 * ((t_sample)0.071428571428571));
			t_sample div_47968 = (counter_47976 * ((t_sample)0.14285714285714));
			int plusequals_47972 = __m_pluseq_51.post(((int)1), ((int)0), 0);
			int lt_47969 = (plusequals_47972 < ((int)100));
			t_sample noise_47973 = noise();
			t_sample add_47981 = (noise_47973 + ((int)1));
			t_sample floor_47979 = floor(add_47981);
			t_sample switch_47977 = (lt_47969 ? floor_47979 : div_47968);
			t_sample mul_47980 = (switch_47977 * ((int)7));
			t_sample add_47965 = (mul_47980 + ((int)12));
			t_sample round_47983 = round(add_47965);
			t_sample div_47984 = (round_47983 * ((t_sample)0.14285714285714));
			t_sample out8 = div_47967;
			if ((!chan_ignore_52)) {
				m_offsets_6.write(div_47984, 0, ((int)5));
				
			};
			int change_47985 = __m_change_53(int_47986);
			int eqp_47987 = ((int_47986 == change_47985) ? int_47986 : 0);
			__m_count_54 = (((int)0) ? 0 : (fixdenorm(__m_count_54 + eqp_47987)));
			int carry_55 = 0;
			if ((((int)0) != 0)) {
				__m_count_54 = 0;
				__m_carry_56 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_54 >= ((int)14)))) {
				int wraps_57 = (__m_count_54 / ((int)14));
				__m_carry_56 = (__m_carry_56 + wraps_57);
				__m_count_54 = (__m_count_54 - (wraps_57 * ((int)14)));
				carry_55 = 1;
				
			};
			int counter_48006 = __m_count_54;
			int counter_47995 = carry_55;
			int counter_47990 = __m_carry_56;
			t_sample div_47988 = (counter_48006 * ((t_sample)0.071428571428571));
			t_sample div_47996 = (counter_48006 * ((t_sample)0.14285714285714));
			int plusequals_47998 = __m_pluseq_58.post(((int)1), ((int)0), 0);
			int lt_47997 = (plusequals_47998 < ((int)100));
			t_sample noise_47993 = noise();
			t_sample add_48007 = (noise_47993 + ((int)1));
			t_sample floor_47992 = floor(add_48007);
			t_sample switch_48000 = (lt_47997 ? floor_47992 : div_47996);
			t_sample mul_48001 = (switch_48000 * ((int)7));
			t_sample add_48002 = (mul_48001 + ((int)12));
			t_sample round_47994 = round(add_48002);
			t_sample div_47999 = (round_47994 * ((t_sample)0.14285714285714));
			t_sample out7 = div_47988;
			if ((!chan_ignore_59)) {
				m_offsets_6.write(div_47999, 0, ((int)4));
				
			};
			int change_48008 = __m_change_60(int_48009);
			int eqp_48010 = ((int_48009 == change_48008) ? int_48009 : 0);
			__m_count_61 = (((int)0) ? 0 : (fixdenorm(__m_count_61 + eqp_48010)));
			int carry_62 = 0;
			if ((((int)0) != 0)) {
				__m_count_61 = 0;
				__m_carry_63 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_61 >= ((int)14)))) {
				int wraps_64 = (__m_count_61 / ((int)14));
				__m_carry_63 = (__m_carry_63 + wraps_64);
				__m_count_61 = (__m_count_61 - (wraps_64 * ((int)14)));
				carry_62 = 1;
				
			};
			int counter_48029 = __m_count_61;
			int counter_48018 = carry_62;
			int counter_48013 = __m_carry_63;
			t_sample div_48011 = (counter_48029 * ((t_sample)0.071428571428571));
			t_sample div_48019 = (counter_48029 * ((t_sample)0.14285714285714));
			int plusequals_48021 = __m_pluseq_65.post(((int)1), ((int)0), 0);
			int lt_48020 = (plusequals_48021 < ((int)100));
			t_sample noise_48016 = noise();
			t_sample add_48030 = (noise_48016 + ((int)1));
			t_sample floor_48015 = floor(add_48030);
			t_sample switch_48023 = (lt_48020 ? floor_48015 : div_48019);
			t_sample mul_48024 = (switch_48023 * ((int)7));
			t_sample add_48025 = (mul_48024 + ((int)12));
			t_sample round_48017 = round(add_48025);
			t_sample div_48022 = (round_48017 * ((t_sample)0.14285714285714));
			t_sample out3 = div_48011;
			m_offsets_6.write(div_48022, 0, 0);
			int change_48031 = __m_change_66(int_48032);
			int eqp_48033 = ((int_48032 == change_48031) ? int_48032 : 0);
			__m_count_67 = (((int)0) ? 0 : (fixdenorm(__m_count_67 + eqp_48033)));
			int carry_68 = 0;
			if ((((int)0) != 0)) {
				__m_count_67 = 0;
				__m_carry_69 = 0;
				
			} else if (((((int)14) > 0) && (__m_count_67 >= ((int)14)))) {
				int wraps_70 = (__m_count_67 / ((int)14));
				__m_carry_69 = (__m_carry_69 + wraps_70);
				__m_count_67 = (__m_count_67 - (wraps_70 * ((int)14)));
				carry_68 = 1;
				
			};
			int counter_48052 = __m_count_67;
			int counter_48041 = carry_68;
			int counter_48036 = __m_carry_69;
			t_sample div_48034 = (counter_48052 * ((t_sample)0.071428571428571));
			t_sample div_48043 = (counter_48052 * ((t_sample)0.14285714285714));
			int plusequals_48045 = __m_pluseq_71.post(((int)1), ((int)0), 0);
			int lt_48044 = (plusequals_48045 < ((int)100));
			t_sample noise_48039 = noise();
			t_sample add_48053 = (noise_48039 + ((int)1));
			t_sample floor_48038 = floor(add_48053);
			t_sample switch_48047 = (lt_48044 ? floor_48038 : div_48043);
			t_sample mul_48048 = (switch_48047 * ((int)7));
			t_sample add_48049 = (mul_48048 + ((int)12));
			t_sample round_48040 = round(add_48049);
			t_sample div_48046 = (round_48040 * ((t_sample)0.14285714285714));
			t_sample out5 = div_48034;
			if ((!chan_ignore_72)) {
				m_offsets_6.write(div_48046, 0, ((int)2));
				
			};
			__m_count_73 = (((int)0) ? 0 : (fixdenorm(__m_count_73 + ((int)1))));
			int carry_74 = 0;
			if ((((int)0) != 0)) {
				__m_count_73 = 0;
				__m_carry_75 = 0;
				
			} else if (((((int)384000) > 0) && (__m_count_73 >= ((int)384000)))) {
				int wraps_76 = (__m_count_73 / ((int)384000));
				__m_carry_75 = (__m_carry_75 + wraps_76);
				__m_count_73 = (__m_count_73 - (wraps_76 * ((int)384000)));
				carry_74 = 1;
				
			};
			int counter_35581 = __m_count_73;
			int counter_35582 = carry_74;
			int counter_35583 = __m_carry_75;
			bool index_ignore_77 = ((counter_35581 >= loop_dim) || (counter_35581 < 0));
			if ((!index_ignore_77)) {
				m_loop_10.write((in2 + (m_loop_10.read(counter_35581, 0) * rsub_34690)), counter_35581, 0);
				
			};
			bool index_ignore_79 = ((counter_35581 >= loop_dim) || (counter_35581 < 0));
			if ((!(chan_ignore_78 || index_ignore_79))) {
				m_loop_10.write((in1 + (m_loop_10.read(counter_35581, ((int)1)) * rsub_34690)), counter_35581, ((int)1));
				
			};
			t_sample noise_43061 = noise();
			t_sample sub_48078 = (noise_43061 - (-1));
			t_sample scale_48075 = ((safepow((sub_48078 * ((t_sample)0.5)), ((int)1)) * ((int)22)) + ((int)60));
			t_sample phasor_35 = __m_phasor_80(div_34, samples_to_seconds);
			t_sample gen_41 = phasor_35;
			t_sample mul_635 = (gen_41 * ((int)16));
			t_sample wrap_633 = wrap(mul_635, ((int)0), ((int)1));
			t_sample gen_30595 = wrap_633;
			t_sample mul_630 = (wrap_633 * ((t_sample)0.0625));
			t_sample sub_197 = (gen_30595 - m_history_1);
			t_sample add_198 = (gen_30595 + m_history_1);
			t_sample div_196 = safediv(sub_197, add_198);
			t_sample abs_195 = fabs(div_196);
			int gt_193 = (abs_195 > ((t_sample)0.5));
			int change_192 = __m_change_81(gt_193);
			int gt_191 = (change_192 > ((int)0));
			t_sample history_194_next_199 = fixdenorm(gen_30595);
			__m_latch_82 = ((gt_191 != 0) ? scale_48075 : __m_latch_82);
			t_sample latch_42865 = __m_latch_82;
			t_sample mtof_42083 = mtof(latch_42865, ((int)440));
			t_sample mul_33087 = (gen_41 * m_jump_8);
			t_sample noise_31482 = noise();
			t_sample mul_31661 = (noise_31482 * m_randomness_15);
			t_sample div_39103 = (mul_31661 * ((t_sample)0.25));
			t_sample mul_48056 = ((div_39103 + mul_33087) * ((int)16));
			t_sample floor_48059 = floor(mul_48056);
			t_sample mul_48058 = (floor_48059 * ((t_sample)0.0625));
			__m_latch_83 = ((gt_191 != 0) ? mul_48058 : __m_latch_83);
			t_sample latch_28525 = __m_latch_83;
			t_sample add_29215 = (latch_28525 + mul_630);
			t_sample wrap_29560 = wrap(add_29215, ((int)0), ((int)1));
			double sample_index_84 = (wrap_29560 * (loop_dim - 1));
			int index_trunc_85 = fixnan(floor(sample_index_84));
			double index_fract_86 = (sample_index_84 - index_trunc_85);
			int index_trunc_87 = (index_trunc_85 + 1);
			bool index_ignore_88 = ((index_trunc_85 >= loop_dim) || (index_trunc_85 < 0));
			bool index_ignore_89 = ((index_trunc_87 >= loop_dim) || (index_trunc_87 < 0));
			// phase loop channel 1;
			double read_loop_90 = (index_ignore_88 ? 0 : m_loop_10.read(index_trunc_85, 0));
			double read_loop_91 = (index_ignore_89 ? 0 : m_loop_10.read(index_trunc_87, 0));
			double readinterp_92 = linear_interp(index_fract_86, read_loop_90, read_loop_91);
			t_sample sample_loop_26083 = readinterp_92;
			t_sample index_loop_26084 = sample_index_84;
			t_sample cf = ((mtof_42083 <= ((int)20)) ? ((int)20) : ((mtof_42083 >= max_93) ? max_93 : mtof_42083));
			t_sample expr_47891 = moogLadder_d_d_d(sample_loop_26083, cf, res);
			t_sample out1 = expr_47891;
			t_sample out2 = expr_47892;
			m_history_1 = history_194_next_199;
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
		m_bpm_2 = (_value < 40 ? 40 : (_value > 200 ? 200 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_offsets(void * _value) {
		m_offsets_6.setbuffer(_value);
	};
	inline void set_sw8(t_param _value) {
		m_sw_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_jump(t_param _value) {
		m_jump_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_overdub(t_param _value) {
		m_overdub_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loop(void * _value) {
		m_loop_10.setbuffer(_value);
	};
	inline void set_q(t_param _value) {
		m_q_11 = (_value < 0 ? 0 : (_value > 0.999 ? 0.999 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_randomness(t_param _value) {
		m_randomness_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample moogLadder_d_d_d(t_sample asig, t_sample cf, t_sample res) {
		int i2v = ((int)40000);
		t_sample akfc = safediv(cf, (samplerate * ((t_sample)0.5)));
		t_sample akf = safediv(cf, samplerate);
		t_sample fcr = ((((((t_sample)1.873) * safepow(akfc, ((int)3))) + (((t_sample)0.4955) * safepow(akfc, ((int)2)))) - (((t_sample)0.649) * akfc)) + ((t_sample)0.9988));
		t_sample acr = ((((-((t_sample)3.9364)) * safepow(akfc, ((int)2))) + (((t_sample)1.8409) * akfc)) + ((t_sample)0.9968));
		t_sample twovg = (i2v * (((int)1) - exp(((((-((int)2)) * ((t_sample)3.1415926535898)) * fcr) * akf))));
		t_sample y1 = (m_z_100 + (twovg * (tanh(safediv((asig - (((((int)4) * res) * m_mf_94) * acr)), i2v)) - tanh(safediv(m_z_100, i2v)))));
		m_z_100 = y1;
		t_sample y2 = (m_z_99 + (twovg * (tanh(safediv(y1, i2v)) - tanh(safediv(m_z_99, i2v)))));
		m_z_99 = y2;
		t_sample y3 = (m_z_98 + (twovg * (tanh(safediv(y2, i2v)) - tanh(safediv(m_z_98, i2v)))));
		m_z_98 = y3;
		m_y_95 = (m_z_97 + (twovg * (tanh(safediv(y3, i2v)) - tanh(safediv(m_z_97, i2v)))));
		m_z_97 = m_y_95;
		m_mf_94 = ((m_y_95 + m_z_96) * ((t_sample)0.5));
		m_z_96 = m_y_95;
		return m_mf_94;
		
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
		case 1: self->set_gate1(value); break;
		case 2: self->set_jump(value); break;
		case 3: self->set_loop(ref); break;
		case 4: self->set_offsets(ref); break;
		case 5: self->set_overdub(value); break;
		case 6: self->set_q(value); break;
		case 7: self->set_randomness(value); break;
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
		case 0: *value = self->m_bpm_2; break;
		case 1: *value = self->m_gate_3; break;
		case 2: *value = self->m_jump_8; break;
		
		
		case 5: *value = self->m_overdub_9; break;
		case 6: *value = self->m_q_11; break;
		case 7: *value = self->m_randomness_15; break;
		case 8: *value = self->m_sw_12; break;
		case 9: *value = self->m_sw_4; break;
		case 10: *value = self->m_sw_13; break;
		case 11: *value = self->m_sw_14; break;
		case 12: *value = self->m_sw_16; break;
		case 13: *value = self->m_sw_17; break;
		case 14: *value = self->m_sw_5; break;
		case 15: *value = self->m_sw_7; break;
		
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
	// initialize parameter 0 ("m_bpm_2")
	pi = self->__commonstate.params + 0;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 40;
	pi->outputmax = 200;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_gate_3")
	pi = self->__commonstate.params + 1;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_jump_8")
	pi = self->__commonstate.params + 2;
	pi->name = "jump";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_jump_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_loop_10")
	pi = self->__commonstate.params + 3;
	pi->name = "loop";
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
	// initialize parameter 4 ("m_offsets_6")
	pi = self->__commonstate.params + 4;
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
	// initialize parameter 5 ("m_overdub_9")
	pi = self->__commonstate.params + 5;
	pi->name = "overdub";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_overdub_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_q_11")
	pi = self->__commonstate.params + 6;
	pi->name = "q";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_q_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.999;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_randomness_15")
	pi = self->__commonstate.params + 7;
	pi->name = "randomness";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_randomness_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_sw_12")
	pi = self->__commonstate.params + 8;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_4")
	pi = self->__commonstate.params + 9;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_13")
	pi = self->__commonstate.params + 10;
	pi->name = "sw3";
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
	// initialize parameter 11 ("m_sw_14")
	pi = self->__commonstate.params + 11;
	pi->name = "sw4";
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
	// initialize parameter 12 ("m_sw_16")
	pi = self->__commonstate.params + 12;
	pi->name = "sw5";
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
	// initialize parameter 13 ("m_sw_17")
	pi = self->__commonstate.params + 13;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_sw_5")
	pi = self->__commonstate.params + 14;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_7")
	pi = self->__commonstate.params + 15;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_7;
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


} // slicer::
