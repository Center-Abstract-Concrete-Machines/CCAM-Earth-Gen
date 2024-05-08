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
	Change __m_change_63;
	Change __m_change_89;
	Change __m_change_85;
	Change __m_change_61;
	Change __m_change_105;
	Data m_euclidean_patterns_60;
	Delay m_delay_27;
	Delay m_delay_25;
	Delay m_delay_20;
	Delay m_delay_29;
	Delay m_delay_23;
	Delay m_delay_18;
	Delay m_delay_21;
	Delay m_delay_31;
	Delay m_delay_37;
	Delay m_delay_35;
	Delay m_delay_19;
	Delay m_delay_33;
	Phasor __m_phasor_84;
	Phasor __m_phasor_62;
	SineCycle __m_cycle_107;
	SineData __sinedata;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample m_history_2;
	t_sample m_history_22;
	t_sample __m_latch_83;
	t_sample m_history_3;
	t_sample m_history_1;
	t_sample __m_latch_87;
	t_sample __m_latch_86;
	t_sample elapsed;
	t_sample __m_latch_64;
	t_sample m_history_4;
	t_sample m_history_7;
	t_sample m_fb_59;
	t_sample __m_latch_88;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample __m_latch_90;
	t_sample __m_latch_91;
	t_sample __m_latch_102;
	t_sample __m_latch_101;
	t_sample __m_latch_100;
	t_sample __m_latch_103;
	t_sample __m_latch_106;
	t_sample __m_latch_104;
	t_sample m_gatein_58;
	t_sample __m_latch_99;
	t_sample __m_latch_97;
	t_sample __m_latch_93;
	t_sample __m_latch_92;
	t_sample __m_latch_98;
	t_sample __m_latch_94;
	t_sample __m_latch_96;
	t_sample __m_latch_95;
	t_sample m_history_17;
	t_sample m_fb_57;
	t_sample m_bpm_55;
	t_sample m_history_11;
	t_sample m_history_32;
	t_sample m_history_12;
	t_sample m_history_34;
	t_sample m_history_36;
	t_sample m_history_10;
	t_sample m_history_9;
	t_sample m_history_30;
	t_sample m_history_28;
	t_sample m_history_24;
	t_sample m_history_16;
	t_sample m_history_13;
	t_sample m_history_15;
	t_sample m_history_14;
	t_sample m_history_26;
	t_sample m_euclid_p_56;
	t_sample m_history_38;
	t_sample m_history_40;
	t_sample m_density_snare_51;
	t_sample m_envelope_length_50;
	t_sample m_numer_49;
	t_sample m_denom_52;
	t_sample m_cv_54;
	t_sample m_density_hihat_53;
	t_sample m_history_39;
	t_sample m_spread_48;
	t_sample m_damp_46;
	t_sample m_hits_42;
	t_sample m_shift_41;
	t_sample m_swing_47;
	t_sample m_events_43;
	t_sample m_history_8;
	t_sample m_beats_44;
	t_sample m_history_45;
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
		m_delay_18.reset("m_delay_18", ((int)2000));
		m_delay_19.reset("m_delay_19", ((int)2000));
		m_delay_20.reset("m_delay_20", ((int)2000));
		m_delay_21.reset("m_delay_21", ((int)2000));
		m_history_22 = ((int)0);
		m_delay_23.reset("m_delay_23", ((int)2000));
		m_history_24 = ((int)0);
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
		m_history_39 = ((int)0);
		m_history_40 = ((int)0);
		m_shift_41 = ((int)0);
		m_hits_42 = ((int)0);
		m_events_43 = ((int)0);
		m_beats_44 = ((int)0);
		m_history_45 = ((int)0);
		m_damp_46 = ((t_sample)0.7);
		m_swing_47 = ((int)0);
		m_spread_48 = ((int)0);
		m_numer_49 = ((int)5);
		m_envelope_length_50 = ((int)0);
		m_density_snare_51 = ((int)1);
		m_denom_52 = ((int)12);
		m_density_hihat_53 = ((int)1);
		m_cv_54 = ((int)0);
		m_bpm_55 = ((int)0);
		m_euclid_p_56 = ((int)0);
		m_fb_57 = ((t_sample)0.9);
		m_gatein_58 = ((int)0);
		m_fb_59 = ((t_sample)0.2);
		m_euclidean_patterns_60.reset("euclidean_patterns", ((int)64), ((int)4));
		__m_change_61.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_62.reset(0);
		__m_change_63.reset(0);
		__m_latch_64 = 0;
		elapsed = 0;
		__m_latch_83 = 12000;
		__m_phasor_84.reset(0);
		__m_change_85.reset(0);
		__m_latch_86 = 0;
		__m_latch_87 = 0;
		__m_latch_88 = 0;
		__m_change_89.reset(0);
		__m_latch_90 = 0;
		__m_latch_91 = 0;
		__m_latch_92 = 0;
		__m_latch_93 = 0;
		__m_latch_94 = 0;
		__m_latch_95 = 0;
		__m_latch_96 = 0;
		__m_latch_97 = 0;
		__m_latch_98 = 0;
		__m_latch_99 = 0;
		__m_latch_100 = 0;
		__m_latch_101 = 0;
		__m_latch_102 = 0;
		__m_latch_103 = 0;
		__m_latch_104 = 0;
		__m_change_105.reset(0);
		__m_latch_106 = 0;
		__m_cycle_107.reset(samplerate, 0);
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
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int gt_58412 = (m_gatein_58 > ((int)0));
		samples_to_seconds = (1 / samplerate);
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		int euclidean_patterns_dim = m_euclidean_patterns_60.dim;
		int euclidean_patterns_channels = m_euclidean_patterns_60.channels;
		bool chan_ignore_76 = ((1 < 0) || (1 >= euclidean_patterns_channels));
		bool chan_ignore_79 = ((2 < 0) || (2 >= euclidean_patterns_channels));
		bool chan_ignore_82 = ((3 < 0) || (3 >= euclidean_patterns_channels));
		t_sample mul_58554 = (m_fb_57 * ((t_sample)0.5));
		t_sample mul_58480 = (samplerate * m_envelope_length_50);
		t_sample t_58481 = exp(safediv(-6.9077552789821, mul_58480));
		t_sample add_58540 = (((int)225) + m_spread_48);
		t_sample add_58542 = (((int)341) + m_spread_48);
		t_sample add_58552 = (((int)441) + m_spread_48);
		t_sample add_58538 = (((int)556) + m_spread_48);
		t_sample damp_58525 = m_damp_46;
		t_sample damp_58529 = damp_58525;
		t_sample damp_58528 = damp_58525;
		t_sample damp_58527 = damp_58525;
		t_sample damp_58526 = damp_58525;
		t_sample damp_58524 = damp_58525;
		t_sample damp_58523 = damp_58525;
		t_sample damp_58522 = damp_58525;
		t_sample add_58551 = (((int)1116) + m_spread_48);
		t_sample add_58550 = (((int)1188) + m_spread_48);
		t_sample add_58549 = (((int)1277) + m_spread_48);
		t_sample add_58548 = (((int)1356) + m_spread_48);
		t_sample add_58547 = (((int)1422) + m_spread_48);
		t_sample add_58546 = (((int)1491) + m_spread_48);
		t_sample add_58545 = (((int)1557) + m_spread_48);
		t_sample add_58544 = (((int)1617) + m_spread_48);
		int gt_58402 = (m_bpm_55 > ((t_sample)0.99));
		t_sample sub_58950 = (m_bpm_55 - ((int)0));
		t_sample scale_58947 = ((safepow((sub_58950 * ((t_sample)1)), ((int)1)) * ((int)-160)) + ((int)200));
		t_sample scale_58484 = scale_58947;
		t_sample div_58483 = (scale_58484 * ((t_sample)0.016666666666667));
		int int_58563 = int(m_numer_49);
		int int_58561 = int(m_denom_52);
		t_sample div_58560 = safediv(int_58563, int_58561);
		t_sample rsub_58491 = (((int)1) - damp_58529);
		t_sample rsub_58746 = (((int)1) - damp_58528);
		t_sample rsub_58758 = (((int)1) - damp_58527);
		t_sample rsub_58768 = (((int)1) - damp_58526);
		t_sample rsub_58783 = (((int)1) - damp_58525);
		t_sample rsub_58794 = (((int)1) - damp_58524);
		t_sample rsub_58805 = (((int)1) - damp_58523);
		t_sample rsub_58818 = (((int)1) - damp_58522);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample noise_58482 = noise();
			t_sample noise_58422 = noise();
			int gt_58421 = (noise_58422 > ((t_sample)0.5));
			int change_58411 = __m_change_61(gt_58412);
			int gt_58410 = (change_58411 > ((int)0));
			int gen_58413 = gt_58410;
			t_sample phasor_58461 = __m_phasor_62(((int)10), samples_to_seconds);
			t_sample sub_58457 = (phasor_58461 - m_history_45);
			t_sample add_58458 = (phasor_58461 + m_history_45);
			t_sample div_58456 = safediv(sub_58457, add_58458);
			t_sample abs_58455 = fabs(div_58456);
			int gt_58453 = (abs_58455 > ((t_sample)0.5));
			int change_58452 = __m_change_63(gt_58453);
			int gt_58451 = (change_58452 > ((int)0));
			int gen_58460 = gt_58451;
			t_sample history_58454_next_58459 = fixdenorm(phasor_58461);
			__m_latch_64 = ((gen_58460 != 0) ? m_euclid_p_56 : __m_latch_64);
			t_sample latch_58462 = __m_latch_64;
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				int euclidean_patterns_dim = m_euclidean_patterns_60.dim;
				int euclidean_patterns_channels = m_euclidean_patterns_60.channels;
				while ((i < euclidean_patterns_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample n2 = noise();
					t_sample n3 = noise();
					t_sample n4 = noise();
					t_sample sub_58934 = (n2 - (-1));
					t_sample scale_58931 = ((safepow((sub_58934 * ((t_sample)0.5)), ((int)1)) * ((int)8)) + ((int)8));
					t_sample b = round(scale_58931);
					t_sample sub_58938 = (n3 - (-1));
					t_sample scale_58935 = ((safepow((sub_58938 * ((t_sample)0.5)), ((int)1)) * ((int)7)) + ((int)1));
					t_sample c = round(scale_58935);
					t_sample sub_58942 = (n4 - (-1));
					t_sample scale_58939 = ((safepow((sub_58942 * ((t_sample)0.5)), ((int)1)) * ((int)5)) + ((int)1));
					t_sample d = round(scale_58939);
					bool index_ignore_65 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!index_ignore_65)) {
						m_euclidean_patterns_60.write(((int)8), i, 0);
						
					};
					bool chan_ignore_66 = ((((int)1) < 0) || (((int)1) >= euclidean_patterns_channels));
					bool index_ignore_67 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_66 || index_ignore_67))) {
						m_euclidean_patterns_60.write(b, i, ((int)1));
						
					};
					bool chan_ignore_68 = ((((int)2) < 0) || (((int)2) >= euclidean_patterns_channels));
					bool index_ignore_69 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_68 || index_ignore_69))) {
						m_euclidean_patterns_60.write(c, i, ((int)2));
						
					};
					bool chan_ignore_70 = ((((int)3) < 0) || (((int)3) >= euclidean_patterns_channels));
					bool index_ignore_71 = ((i >= euclidean_patterns_dim) || (i < 0));
					if ((!(chan_ignore_70 || index_ignore_71))) {
						m_euclidean_patterns_60.write(d, i, ((int)3));
						
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
			t_sample sub_58946 = (latch_58462 - ((int)0));
			t_sample scale_58943 = ((safepow((sub_58946 * ((t_sample)1)), ((int)1)) * ((int)63)) + ((int)1));
			t_sample selection = round(scale_58943);
			int index_trunc_72 = fixnan(floor(selection));
			bool index_ignore_73 = ((index_trunc_72 >= euclidean_patterns_dim) || (index_trunc_72 < 0));
			// samples euclidean_patterns channel 1;
			m_beats_44 = (index_ignore_73 ? 0 : m_euclidean_patterns_60.read(index_trunc_72, 0));
			int index_trunc_74 = fixnan(floor(selection));
			bool index_ignore_75 = ((index_trunc_74 >= euclidean_patterns_dim) || (index_trunc_74 < 0));
			// samples euclidean_patterns channel 1;
			m_events_43 = ((chan_ignore_76 || index_ignore_75) ? 0 : m_euclidean_patterns_60.read(index_trunc_74, 1));
			int index_trunc_77 = fixnan(floor(selection));
			bool index_ignore_78 = ((index_trunc_77 >= euclidean_patterns_dim) || (index_trunc_77 < 0));
			// samples euclidean_patterns channel 1;
			m_hits_42 = ((chan_ignore_79 || index_ignore_78) ? 0 : m_euclidean_patterns_60.read(index_trunc_77, 2));
			int index_trunc_80 = fixnan(floor(selection));
			bool index_ignore_81 = ((index_trunc_80 >= euclidean_patterns_dim) || (index_trunc_80 < 0));
			// samples euclidean_patterns channel 1;
			m_shift_41 = ((chan_ignore_82 || index_ignore_81) ? 0 : m_euclidean_patterns_60.read(index_trunc_80, 3));
			t_sample add_58418 = (m_history_40 + ((int)1));
			__m_latch_83 = ((gen_58413 != 0) ? add_58418 : __m_latch_83);
			t_sample latch_58417 = __m_latch_83;
			t_sample gen_58420 = latch_58417;
			t_sample switch_58415 = (gen_58413 ? ((int)0) : add_58418);
			t_sample history_58416_next_58419 = fixdenorm(switch_58415);
			t_sample rdiv_58407 = safediv(((int)1), gen_58420);
			t_sample add_58409 = (m_history_17 + rdiv_58407);
			t_sample switch_58406 = (gen_58413 ? ((int)0) : add_58409);
			t_sample wrap_58408 = wrap(switch_58406, ((int)0), ((int)1));
			t_sample floor_58679 = floor(m_shift_41);
			t_sample floor_58680 = floor(m_events_43);
			t_sample floor_58681 = floor(m_hits_42);
			t_sample phasor_58698 = __m_phasor_84(div_58483, samples_to_seconds);
			t_sample switch_58401 = (gt_58402 ? wrap_58408 : phasor_58698);
			t_sample mul_58684 = (switch_58401 * m_beats_44);
			t_sample wrap_58683 = wrap(mul_58684, ((int)0), ((int)1));
			t_sample sub_58730 = (wrap_58683 - m_history_39);
			t_sample add_58727 = (wrap_58683 + m_history_39);
			t_sample div_58725 = safediv(sub_58730, add_58727);
			t_sample abs_58728 = fabs(div_58725);
			int gt_58729 = (abs_58728 > ((t_sample)0.5));
			int change_58723 = __m_change_85(gt_58729);
			int gt_58722 = (change_58723 > ((int)0));
			int gen_58686 = gt_58722;
			t_sample history_58454_next_58724 = fixdenorm(wrap_58683);
			__m_latch_86 = ((gen_58686 != 0) ? floor_58679 : __m_latch_86);
			t_sample latch_58687 = __m_latch_86;
			t_sample sub_58696 = (mul_58684 - latch_58687);
			__m_latch_87 = ((gen_58686 != 0) ? floor_58680 : __m_latch_87);
			t_sample latch_58689 = __m_latch_87;
			t_sample abs_58671 = fabs(latch_58689);
			__m_latch_88 = ((gen_58686 != 0) ? floor_58681 : __m_latch_88);
			t_sample latch_58688 = __m_latch_88;
			t_sample abs_58670 = fabs(latch_58688);
			t_sample max_58669 = ((abs_58671 < abs_58670) ? abs_58670 : abs_58671);
			t_sample min_58668 = ((abs_58670 < abs_58671) ? abs_58670 : abs_58671);
			t_sample div_58672 = safediv(min_58668, max_58669);
			t_sample mul_58667 = (latch_58689 * latch_58688);
			int sign_58674 = ((mul_58667 > 0) ? 1 : ((mul_58667 < 0) ? -1 : 0));
			t_sample mul_58673 = (sub_58696 * sign_58674);
			t_sample wrap_58690 = wrap(mul_58673, ((int)0), max_58669);
			t_sample floor_58697 = floor(wrap_58690);
			t_sample mul_58692 = (floor_58697 * div_58672);
			t_sample floor_58695 = floor(mul_58692);
			t_sample div_58694 = safediv(floor_58695, div_58672);
			t_sample ceil_58693 = ceil(div_58694);
			t_sample sub_58691 = (wrap_58690 - ceil_58693);
			t_sample add_58676 = (floor_58695 + ((int)1));
			t_sample div_58678 = safediv(add_58676, div_58672);
			t_sample ceil_58677 = ceil(div_58678);
			t_sample sub_58675 = (ceil_58677 - ceil_58693);
			t_sample div_58685 = safediv(sub_58691, sub_58675);
			t_sample sub_58740 = (div_58685 - m_history_38);
			t_sample add_58736 = (div_58685 + m_history_38);
			t_sample div_58734 = safediv(sub_58740, add_58736);
			t_sample abs_58737 = fabs(div_58734);
			int gt_58738 = (abs_58737 > ((t_sample)0.5));
			int change_58739 = __m_change_89(gt_58738);
			int gt_58732 = (change_58739 > ((int)0));
			int gen_58565 = gt_58732;
			t_sample history_58454_next_58733 = fixdenorm(div_58685);
			int trig_58437 = gen_58565;
			__m_latch_90 = ((trig_58437 != 0) ? gt_58421 : __m_latch_90);
			int latch_58438 = __m_latch_90;
			t_sample out3 = latch_58438;
			__m_latch_91 = ((trig_58437 != 0) ? m_history_11 : __m_latch_91);
			t_sample latch_58427 = __m_latch_91;
			t_sample out9 = latch_58427;
			__m_latch_92 = ((trig_58437 != 0) ? m_history_13 : __m_latch_92);
			t_sample latch_58430 = __m_latch_92;
			t_sample out7 = latch_58430;
			__m_latch_93 = ((trig_58437 != 0) ? m_history_10 : __m_latch_93);
			t_sample latch_58432 = __m_latch_93;
			t_sample out6 = latch_58432;
			__m_latch_94 = ((trig_58437 != 0) ? m_history_16 : __m_latch_94);
			t_sample latch_58436 = __m_latch_94;
			t_sample out4 = latch_58436;
			__m_latch_95 = ((trig_58437 != 0) ? m_history_14 : __m_latch_95);
			t_sample latch_58429 = __m_latch_95;
			t_sample out8 = latch_58429;
			__m_latch_96 = ((trig_58437 != 0) ? m_history_15 : __m_latch_96);
			t_sample latch_58425 = __m_latch_96;
			t_sample out10 = latch_58425;
			__m_latch_97 = ((trig_58437 != 0) ? m_history_12 : __m_latch_97);
			t_sample latch_58434 = __m_latch_97;
			t_sample out5 = latch_58434;
			int trig_58713 = trig_58437;
			__m_latch_98 = ((trig_58713 != 0) ? m_history_6 : __m_latch_98);
			t_sample latch_58708 = __m_latch_98;
			__m_latch_99 = ((trig_58713 != 0) ? noise_58482 : __m_latch_99);
			t_sample latch_58714 = __m_latch_99;
			__m_latch_100 = ((trig_58713 != 0) ? m_history_4 : __m_latch_100);
			t_sample latch_58703 = __m_latch_100;
			__m_latch_101 = ((trig_58713 != 0) ? m_history_3 : __m_latch_101);
			t_sample latch_58710 = __m_latch_101;
			__m_latch_102 = ((trig_58713 != 0) ? m_history_9 : __m_latch_102);
			t_sample latch_58706 = __m_latch_102;
			__m_latch_103 = ((trig_58713 != 0) ? m_history_5 : __m_latch_103);
			t_sample latch_58705 = __m_latch_103;
			__m_latch_104 = ((trig_58713 != 0) ? m_history_8 : __m_latch_104);
			t_sample latch_58712 = __m_latch_104;
			int neq_58475 = (gen_58565 != ((int)0));
			int change_58474 = __m_change_105(neq_58475);
			int gt_58473 = (change_58474 > ((int)0));
			t_sample mul_58479 = ((m_history_2 + gt_58473) * t_58481);
			t_sample clamp_58472 = ((mul_58479 <= ((int)0)) ? ((int)0) : ((mul_58479 >= ((int)1)) ? ((int)1) : mul_58479));
			t_sample mix_58951 = (clamp_58472 + (((t_sample)0.97) * (m_history_1 - clamp_58472)));
			t_sample mix_58477 = mix_58951;
			__m_latch_106 = ((trig_58713 != 0) ? m_history_7 : __m_latch_106);
			t_sample latch_58701 = __m_latch_106;
			t_sample mul_58566 = (latch_58701 * ((int)12));
			int int_58557 = int(mul_58566);
			t_sample mul_58559 = (int_58557 * div_58560);
			t_sample round_58562 = round(mul_58559);
			t_sample div_58558 = safediv(round_58562, div_58560);
			t_sample add_58573 = (div_58558 + ((int)60));
			t_sample mtof_58572 = mtof(add_58573, ((int)440));
			__m_cycle_107.freq(mtof_58572);
			t_sample cycle_58391 = __m_cycle_107(__sinedata);
			t_sample cycleindex_58392 = __m_cycle_107.phase();
			t_sample mul_58570 = (cycle_58391 * mix_58477);
			t_sample mul_58568 = (mul_58570 * ((int)2));
			t_sample tanh_58569 = tanh(mul_58568);
			t_sample div_58567 = (tanh_58569 * ((t_sample)0.5));
			t_sample mul_58556 = (div_58567 * ((t_sample)0.015));
			t_sample tap_58498 = m_delay_37.read_linear(add_58551);
			t_sample gen_58530 = tap_58498;
			t_sample mul_58496 = (tap_58498 * damp_58529);
			t_sample mul_58494 = (m_history_36 * rsub_58491);
			t_sample add_58495 = (mul_58496 + mul_58494);
			t_sample mul_58492 = (add_58495 * m_fb_59);
			t_sample add_58499 = (mul_58556 + mul_58492);
			t_sample history_58493_next_58500 = fixdenorm(add_58495);
			t_sample tap_58748 = m_delay_35.read_linear(add_58550);
			t_sample gen_58531 = tap_58748;
			t_sample mul_58747 = (tap_58748 * damp_58528);
			t_sample mul_58749 = (m_history_34 * rsub_58746);
			t_sample add_58745 = (mul_58747 + mul_58749);
			t_sample mul_58744 = (add_58745 * m_fb_59);
			t_sample add_58751 = (mul_58556 + mul_58744);
			t_sample history_58493_next_58742 = fixdenorm(add_58745);
			t_sample tap_58760 = m_delay_33.read_linear(add_58549);
			t_sample gen_58532 = tap_58760;
			t_sample mul_58759 = (tap_58760 * damp_58527);
			t_sample mul_58761 = (m_history_32 * rsub_58758);
			t_sample add_58757 = (mul_58759 + mul_58761);
			t_sample mul_58756 = (add_58757 * m_fb_59);
			t_sample add_58763 = (mul_58556 + mul_58756);
			t_sample history_58493_next_58754 = fixdenorm(add_58757);
			t_sample tap_58772 = m_delay_31.read_linear(add_58548);
			t_sample gen_58533 = tap_58772;
			t_sample mul_58771 = (tap_58772 * damp_58526);
			t_sample mul_58773 = (m_history_30 * rsub_58768);
			t_sample add_58770 = (mul_58771 + mul_58773);
			t_sample mul_58769 = (add_58770 * m_fb_59);
			t_sample add_58775 = (mul_58556 + mul_58769);
			t_sample history_58493_next_58766 = fixdenorm(add_58770);
			t_sample tap_58785 = m_delay_29.read_linear(add_58547);
			t_sample gen_58534 = tap_58785;
			t_sample mul_58784 = (tap_58785 * damp_58525);
			t_sample mul_58786 = (m_history_28 * rsub_58783);
			t_sample add_58782 = (mul_58784 + mul_58786);
			t_sample mul_58781 = (add_58782 * m_fb_59);
			t_sample add_58787 = (mul_58556 + mul_58781);
			t_sample history_58493_next_58778 = fixdenorm(add_58782);
			t_sample tap_58796 = m_delay_27.read_linear(add_58546);
			t_sample gen_58535 = tap_58796;
			t_sample mul_58795 = (tap_58796 * damp_58524);
			t_sample mul_58797 = (m_history_26 * rsub_58794);
			t_sample add_58793 = (mul_58795 + mul_58797);
			t_sample mul_58792 = (add_58793 * m_fb_59);
			t_sample add_58799 = (mul_58556 + mul_58792);
			t_sample history_58493_next_58790 = fixdenorm(add_58793);
			t_sample tap_58809 = m_delay_25.read_linear(add_58545);
			t_sample gen_58536 = tap_58809;
			t_sample mul_58808 = (tap_58809 * damp_58523);
			t_sample mul_58803 = (m_history_24 * rsub_58805);
			t_sample add_58811 = (mul_58808 + mul_58803);
			t_sample mul_58807 = (add_58811 * m_fb_59);
			t_sample add_58810 = (mul_58556 + mul_58807);
			t_sample history_58493_next_58802 = fixdenorm(add_58811);
			t_sample tap_58820 = m_delay_23.read_linear(add_58544);
			t_sample gen_58555 = tap_58820;
			t_sample mul_58819 = (tap_58820 * damp_58522);
			t_sample mul_58815 = (m_history_22 * rsub_58818);
			t_sample add_58823 = (mul_58819 + mul_58815);
			t_sample mul_58817 = (add_58823 * m_fb_59);
			t_sample add_58821 = (mul_58556 + mul_58817);
			t_sample history_58493_next_58814 = fixdenorm(add_58823);
			t_sample add_58553 = ((((((((gen_58555 + gen_58536) + gen_58535) + gen_58534) + gen_58533) + gen_58532) + gen_58531) + gen_58530) + ((int)0));
			t_sample tap_58489 = m_delay_21.read_linear(add_58538);
			t_sample sub_58485 = (add_58553 - tap_58489);
			t_sample mul_58487 = (tap_58489 * mul_58554);
			t_sample add_58486 = (add_58553 + mul_58487);
			t_sample tap_58827 = m_delay_20.read_linear(add_58552);
			t_sample sub_58828 = (sub_58485 - tap_58827);
			t_sample mul_58826 = (tap_58827 * mul_58554);
			t_sample add_58830 = (sub_58485 + mul_58826);
			t_sample tap_58833 = m_delay_19.read_linear(add_58542);
			t_sample sub_58834 = (sub_58828 - tap_58833);
			t_sample mul_58832 = (tap_58833 * mul_58554);
			t_sample add_58836 = (sub_58828 + mul_58832);
			t_sample tap_58839 = m_delay_18.read_linear(add_58540);
			t_sample sub_58840 = (sub_58834 - tap_58839);
			t_sample mul_58838 = (tap_58839 * mul_58554);
			t_sample add_58842 = (sub_58834 + mul_58838);
			t_sample add_58396 = (sub_58840 + in1);
			t_sample mul_58394 = (add_58396 * ((t_sample)0.5));
			t_sample out1 = mul_58394;
			t_sample add_58395 = (sub_58840 + in2);
			t_sample mul_58393 = (add_58395 * ((t_sample)0.5));
			t_sample out2 = mul_58393;
			t_sample history_58405_next_58844 = fixdenorm(wrap_58408);
			t_sample history_58435_next_58845 = fixdenorm(latch_58438);
			t_sample history_58424_next_58846 = fixdenorm(latch_58427);
			t_sample history_58428_next_58847 = fixdenorm(latch_58430);
			t_sample history_58423_next_58848 = fixdenorm(latch_58432);
			t_sample history_58433_next_58849 = fixdenorm(latch_58436);
			t_sample history_58426_next_58850 = fixdenorm(latch_58429);
			t_sample history_58431_next_58851 = fixdenorm(latch_58434);
			t_sample history_58699_next_58852 = fixdenorm(latch_58708);
			t_sample history_58711_next_58853 = fixdenorm(latch_58714);
			t_sample history_58700_next_58854 = fixdenorm(latch_58703);
			t_sample history_58707_next_58855 = fixdenorm(latch_58710);
			t_sample history_58704_next_58856 = fixdenorm(latch_58706);
			t_sample history_58702_next_58857 = fixdenorm(latch_58705);
			t_sample history_58709_next_58858 = fixdenorm(latch_58712);
			t_sample history_58478_next_58859 = fixdenorm(clamp_58472);
			t_sample history_58476_next_58860 = fixdenorm(mix_58477);
			m_history_45 = history_58454_next_58459;
			m_history_40 = history_58416_next_58419;
			m_history_39 = history_58454_next_58724;
			m_history_38 = history_58454_next_58733;
			m_delay_37.write(add_58499);
			m_history_36 = history_58493_next_58500;
			m_delay_35.write(add_58751);
			m_history_34 = history_58493_next_58742;
			m_delay_33.write(add_58763);
			m_history_32 = history_58493_next_58754;
			m_delay_31.write(add_58775);
			m_history_30 = history_58493_next_58766;
			m_delay_29.write(add_58787);
			m_history_28 = history_58493_next_58778;
			m_delay_27.write(add_58799);
			m_history_26 = history_58493_next_58790;
			m_delay_25.write(add_58810);
			m_history_24 = history_58493_next_58802;
			m_delay_23.write(add_58821);
			m_history_22 = history_58493_next_58814;
			m_delay_21.write(add_58486);
			m_delay_20.write(add_58830);
			m_delay_19.write(add_58836);
			m_delay_18.write(add_58842);
			m_history_17 = history_58405_next_58844;
			m_history_16 = history_58435_next_58845;
			m_history_15 = history_58424_next_58846;
			m_history_14 = history_58428_next_58847;
			m_history_13 = history_58423_next_58848;
			m_history_12 = history_58433_next_58849;
			m_history_11 = history_58426_next_58850;
			m_history_10 = history_58431_next_58851;
			m_history_9 = history_58699_next_58852;
			m_history_8 = history_58711_next_58853;
			m_history_7 = history_58700_next_58854;
			m_history_6 = history_58707_next_58855;
			m_history_5 = history_58704_next_58856;
			m_history_4 = history_58702_next_58857;
			m_history_3 = history_58709_next_58858;
			m_history_2 = history_58478_next_58859;
			m_history_1 = history_58476_next_58860;
			m_delay_18.step();
			m_delay_19.step();
			m_delay_20.step();
			m_delay_21.step();
			m_delay_23.step();
			m_delay_25.step();
			m_delay_27.step();
			m_delay_29.step();
			m_delay_31.step();
			m_delay_33.step();
			m_delay_35.step();
			m_delay_37.step();
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
			
		};
		return __exception;
		
	};
	inline void set_damp(t_param _value) {
		m_damp_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_swing(t_param _value) {
		m_swing_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_spread(t_param _value) {
		m_spread_48 = (_value < 0 ? 0 : (_value > 400 ? 400 : _value));
	};
	inline void set_numer(t_param _value) {
		m_numer_49 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_envelope_length(t_param _value) {
		m_envelope_length_50 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_density_snare(t_param _value) {
		m_density_snare_51 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_denom(t_param _value) {
		m_denom_52 = (_value < 1 ? 1 : (_value > 24 ? 24 : _value));
	};
	inline void set_density_hihat(t_param _value) {
		m_density_hihat_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cv1(t_param _value) {
		m_cv_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bpm(t_param _value) {
		m_bpm_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_euclid_p(t_param _value) {
		m_euclid_p_56 = (_value < 0 ? 0 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_fb2(t_param _value) {
		m_fb_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_58 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_fb1(t_param _value) {
		m_fb_59 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_euclidean_patterns(void * _value) {
		m_euclidean_patterns_60.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 10;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 15; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
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
		case 0: self->set_bpm(value); break;
		case 1: self->set_cv1(value); break;
		case 2: self->set_damp(value); break;
		case 3: self->set_denom(value); break;
		case 4: self->set_density_hihat(value); break;
		case 5: self->set_density_snare(value); break;
		case 6: self->set_envelope_length(value); break;
		case 7: self->set_euclid_p(value); break;
		case 8: self->set_euclidean_patterns(ref); break;
		case 9: self->set_fb1(value); break;
		case 10: self->set_fb2(value); break;
		case 11: self->set_gatein1(value); break;
		case 12: self->set_numer(value); break;
		case 13: self->set_spread(value); break;
		case 14: self->set_swing(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_bpm_55; break;
		case 1: *value = self->m_cv_54; break;
		case 2: *value = self->m_damp_46; break;
		case 3: *value = self->m_denom_52; break;
		case 4: *value = self->m_density_hihat_53; break;
		case 5: *value = self->m_density_snare_51; break;
		case 6: *value = self->m_envelope_length_50; break;
		case 7: *value = self->m_euclid_p_56; break;
		
		case 9: *value = self->m_fb_59; break;
		case 10: *value = self->m_fb_57; break;
		case 11: *value = self->m_gatein_58; break;
		case 12: *value = self->m_numer_49; break;
		case 13: *value = self->m_spread_48; break;
		case 14: *value = self->m_swing_47; break;
		
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
	// initialize parameter 0 ("m_bpm_55")
	pi = self->__commonstate.params + 0;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_55;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cv_54")
	pi = self->__commonstate.params + 1;
	pi->name = "cv1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv_54;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_damp_46")
	pi = self->__commonstate.params + 2;
	pi->name = "damp";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_damp_46;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_denom_52")
	pi = self->__commonstate.params + 3;
	pi->name = "denom";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_denom_52;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 24;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_density_hihat_53")
	pi = self->__commonstate.params + 4;
	pi->name = "density_hihat";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_density_hihat_53;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_density_snare_51")
	pi = self->__commonstate.params + 5;
	pi->name = "density_snare";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_density_snare_51;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_envelope_length_50")
	pi = self->__commonstate.params + 6;
	pi->name = "envelope_length";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_envelope_length_50;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_euclid_p_56")
	pi = self->__commonstate.params + 7;
	pi->name = "euclid_p";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_euclid_p_56;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_euclidean_patterns_60")
	pi = self->__commonstate.params + 8;
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
	// initialize parameter 9 ("m_fb_59")
	pi = self->__commonstate.params + 9;
	pi->name = "fb1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_fb_59;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_fb_57")
	pi = self->__commonstate.params + 10;
	pi->name = "fb2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_fb_57;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_gatein_58")
	pi = self->__commonstate.params + 11;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_58;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_numer_49")
	pi = self->__commonstate.params + 12;
	pi->name = "numer";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_numer_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 24;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_spread_48")
	pi = self->__commonstate.params + 13;
	pi->name = "spread";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_spread_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 400;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_swing_47")
	pi = self->__commonstate.params + 14;
	pi->name = "swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_swing_47;
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
