#include "relays.h"

namespace relays {

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
	Change __m_change_38;
	Change __m_change_69;
	Change __m_change_65;
	Change __m_change_73;
	Change __m_change_76;
	Change __m_change_79;
	Change __m_change_64;
	Change __m_change_56;
	Change __m_change_42;
	Change __m_change_60;
	Change __m_change_48;
	Change __m_change_52;
	Change __m_change_80;
	Change __m_change_74;
	Change __m_change_82;
	Change __m_change_88;
	Change __m_change_94;
	Change __m_change_98;
	Delay m_delay_4;
	Delay m_delay_7;
	Delta __m_delta_77;
	PlusEquals __m_pluseq_55;
	PlusEquals __m_pluseq_51;
	PlusEquals __m_pluseq_97;
	PlusEquals __m_pluseq_59;
	PlusEquals __m_pluseq_45;
	PlusEquals __m_pluseq_91;
	PlusEquals __m_pluseq_63;
	PlusEquals __m_pluseq_101;
	PlusEquals __m_pluseq_81;
	PlusEquals __m_pluseq_85;
	PlusEquals __m_pluseq_72;
	PlusEquals __m_pluseq_41;
	PlusEquals __m_pluseq_68;
	SineCycle __m_cycle_86;
	SineCycle __m_cycle_92;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_knob_36;
	t_sample m_history_13;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_history_10;
	t_sample m_history_14;
	t_sample m_history_15;
	t_sample __m_latch_75;
	t_sample m_history_16;
	t_sample __m_latch_70;
	t_sample __m_latch_83;
	t_sample __m_latch_71;
	t_sample m_history_17;
	t_sample m_history_18;
	t_sample m_history_19;
	t_sample __m_latch_84;
	t_sample m_history_8;
	t_sample __m_latch_95;
	t_sample m_history_1;
	t_sample __m_latch_96;
	t_sample __m_latch_99;
	t_sample samplerate;
	t_sample m_history_9;
	t_sample m_history_2;
	t_sample __m_latch_90;
	t_sample m_history_6;
	t_sample m_history_3;
	t_sample m_history_5;
	t_sample __m_latch_89;
	t_sample m_gate_35;
	t_sample m_history_20;
	t_sample __m_latch_66;
	t_sample m_knob_31;
	t_sample __m_latch_44;
	t_sample m_cvin_30;
	t_sample __m_latch_50;
	t_sample __m_latch_100;
	t_sample m_cvin_29;
	t_sample __m_latch_43;
	t_sample m_cvin_33;
	t_sample m_knob_37;
	t_sample m_cvin_32;
	t_sample m_knob_34;
	t_sample __m_latch_40;
	t_sample __m_latch_39;
	t_sample __m_latch_67;
	t_sample m_gatein_28;
	t_sample __m_latch_54;
	t_sample __m_latch_62;
	t_sample __m_latch_61;
	t_sample m_knob_23;
	t_sample m_history_21;
	t_sample m_history_22;
	t_sample __m_latch_53;
	t_sample m_knob_24;
	t_sample __m_latch_58;
	t_sample m_knob_27;
	t_sample m_knob_25;
	t_sample m_gate_26;
	t_sample __m_latch_57;
	t_sample __m_latch_49;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_delay_4.reset("m_delay_4", samplerate);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_delay_7.reset("m_delay_7", samplerate);
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
		m_knob_23 = ((int)1);
		m_knob_24 = ((int)0);
		m_knob_25 = ((int)1);
		m_gate_26 = ((int)0);
		m_knob_27 = ((int)0);
		m_gatein_28 = ((int)0);
		m_cvin_29 = ((int)0);
		m_cvin_30 = ((int)0);
		m_knob_31 = ((int)0);
		m_cvin_32 = ((int)0);
		m_cvin_33 = ((int)0);
		m_knob_34 = ((int)1);
		m_gate_35 = ((int)0);
		m_knob_36 = ((int)0);
		m_knob_37 = ((int)1);
		__m_change_38.reset(0);
		__m_latch_39 = 0;
		__m_latch_40 = 0;
		__m_pluseq_41.reset(0);
		__m_change_42.reset(0);
		__m_latch_43 = 0;
		__m_latch_44 = 0;
		__m_pluseq_45.reset(0);
		__m_change_48.reset(0);
		__m_latch_49 = 0;
		__m_latch_50 = 0;
		__m_pluseq_51.reset(0);
		__m_change_52.reset(0);
		__m_latch_53 = 0;
		__m_latch_54 = 0;
		__m_pluseq_55.reset(0);
		__m_change_56.reset(0);
		__m_latch_57 = 0;
		__m_latch_58 = 0;
		__m_pluseq_59.reset(0);
		__m_change_60.reset(0);
		__m_latch_61 = 0;
		__m_latch_62 = 0;
		__m_pluseq_63.reset(0);
		__m_change_64.reset(0);
		__m_change_65.reset(0);
		__m_latch_66 = 0;
		__m_latch_67 = 0;
		__m_pluseq_68.reset(0);
		__m_change_69.reset(0);
		__m_latch_70 = 0;
		__m_latch_71 = 0;
		__m_pluseq_72.reset(0);
		__m_change_73.reset(0);
		__m_change_74.reset(0);
		__m_latch_75 = 11025;
		__m_change_76.reset(0);
		__m_delta_77.reset(0);
		__m_change_79.reset(0);
		__m_change_80.reset(0);
		__m_pluseq_81.reset(0);
		__m_change_82.reset(0);
		__m_latch_83 = 0;
		__m_latch_84 = 0;
		__m_pluseq_85.reset(0);
		__m_cycle_86.reset(samplerate, 0);
		__m_change_88.reset(0);
		__m_latch_89 = 0;
		__m_latch_90 = 0;
		__m_pluseq_91.reset(0);
		__m_cycle_92.reset(samplerate, 0);
		__m_change_94.reset(0);
		__m_latch_95 = 0;
		__m_latch_96 = 0;
		__m_pluseq_97.reset(0);
		__m_change_98.reset(0);
		__m_latch_99 = 0;
		__m_latch_100 = 0;
		__m_pluseq_101.reset(0);
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
		t_sample * __out13 = __outs[12];
		t_sample * __out14 = __outs[13];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample min_49 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_42 = safediv(safediv(1000, samplerate), min_49);
		t_sample min_501 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_497 = safediv(safediv(1000, samplerate), min_501);
		int iftrue_46 = (-1);
		int switch_54 = (m_knob_37 ? iftrue_46 : ((int)1));
		int iftrue_47 = (-1);
		int switch_87 = (m_knob_37 ? iftrue_47 : ((int)1));
		t_sample min_510 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_509 = safediv(safediv(1000, samplerate), min_510);
		t_sample min_527 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_524 = safediv(safediv(1000, samplerate), min_527);
		t_sample min_538 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_535 = safediv(safediv(1000, samplerate), min_538);
		t_sample min_549 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_546 = safediv(safediv(1000, samplerate), min_549);
		int int_10 = int(m_gate_35);
		t_sample min_560 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_557 = safediv(safediv(1000, samplerate), min_560);
		t_sample min_571 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_568 = safediv(safediv(1000, samplerate), min_571);
		int int_575 = int(m_gatein_28);
		t_sample history_168_next_212 = fixdenorm(((int)8));
		t_sample mstosamps_14 = (((int)0) * (samplerate * 0.001));
		t_sample max_15 = ((mstosamps_14 < vectorsize) ? vectorsize : mstosamps_14);
		t_sample min_585 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_581 = safediv(safediv(1000, samplerate), min_585);
		t_sample min_596 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_595 = safediv(safediv(1000, samplerate), min_596);
		t_sample min_619 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_620 = safediv(safediv(1000, samplerate), min_619);
		t_sample min_630 = ((m_knob_34 < ((t_sample)0.01)) ? ((t_sample)0.01) : m_knob_34);
		t_sample rdiv_631 = safediv(safediv(1000, samplerate), min_630);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out14 = ((int)0);
			t_sample out13 = ((int)0);
			int change_50 = __m_change_38(m_knob_23);
			__m_latch_39 = ((change_50 != 0) ? m_history_22 : __m_latch_39);
			t_sample latch_47 = __m_latch_39;
			__m_latch_40 = ((change_50 != 0) ? m_knob_23 : __m_latch_40);
			t_sample latch_46 = __m_latch_40;
			t_sample plusequals_48 = __m_pluseq_41.pre(rdiv_42, change_50, 0);
			t_sample clamp_43 = ((plusequals_48 <= ((int)0)) ? ((int)0) : ((plusequals_48 >= ((int)1)) ? ((int)1) : plusequals_48));
			t_sample mix_670 = (latch_47 + (clamp_43 * (latch_46 - latch_47)));
			t_sample mix_45 = mix_670;
			t_sample gen_69 = mix_45;
			t_sample history_44_next_51 = fixdenorm(mix_45);
			int change_503 = __m_change_42(m_knob_23);
			__m_latch_43 = ((change_503 != 0) ? m_history_21 : __m_latch_43);
			t_sample latch_498 = __m_latch_43;
			__m_latch_44 = ((change_503 != 0) ? m_knob_23 : __m_latch_44);
			t_sample latch_504 = __m_latch_44;
			t_sample plusequals_506 = __m_pluseq_45.pre(rdiv_497, change_503, 0);
			t_sample clamp_502 = ((plusequals_506 <= ((int)0)) ? ((int)0) : ((plusequals_506 >= ((int)1)) ? ((int)1) : plusequals_506));
			t_sample mix_671 = (latch_498 + (clamp_502 * (latch_504 - latch_498)));
			t_sample mix_500 = mix_671;
			t_sample gen_93 = mix_500;
			t_sample history_44_next_499 = fixdenorm(mix_500);
			int change_514 = __m_change_48(m_knob_25);
			__m_latch_49 = ((change_514 != 0) ? m_history_20 : __m_latch_49);
			t_sample latch_512 = __m_latch_49;
			__m_latch_50 = ((change_514 != 0) ? m_knob_25 : __m_latch_50);
			t_sample latch_515 = __m_latch_50;
			t_sample plusequals_517 = __m_pluseq_51.pre(rdiv_509, change_514, 0);
			t_sample clamp_513 = ((plusequals_517 <= ((int)0)) ? ((int)0) : ((plusequals_517 >= ((int)1)) ? ((int)1) : plusequals_517));
			t_sample mix_672 = (latch_512 + (clamp_513 * (latch_515 - latch_512)));
			t_sample mix_508 = mix_672;
			t_sample gen_68 = mix_508;
			t_sample history_44_next_511 = fixdenorm(mix_508);
			int change_526 = __m_change_52(m_knob_25);
			__m_latch_53 = ((change_526 != 0) ? m_history_19 : __m_latch_53);
			t_sample latch_519 = __m_latch_53;
			__m_latch_54 = ((change_526 != 0) ? m_knob_25 : __m_latch_54);
			t_sample latch_521 = __m_latch_54;
			t_sample plusequals_528 = __m_pluseq_55.pre(rdiv_524, change_526, 0);
			t_sample clamp_520 = ((plusequals_528 <= ((int)0)) ? ((int)0) : ((plusequals_528 >= ((int)1)) ? ((int)1) : plusequals_528));
			t_sample mix_673 = (latch_519 + (clamp_520 * (latch_521 - latch_519)));
			t_sample mix_523 = mix_673;
			t_sample gen_92 = mix_523;
			t_sample history_44_next_525 = fixdenorm(mix_523);
			int change_537 = __m_change_56(m_knob_31);
			__m_latch_57 = ((change_537 != 0) ? m_history_18 : __m_latch_57);
			t_sample latch_530 = __m_latch_57;
			__m_latch_58 = ((change_537 != 0) ? m_knob_31 : __m_latch_58);
			t_sample latch_532 = __m_latch_58;
			t_sample plusequals_539 = __m_pluseq_59.pre(rdiv_535, change_537, 0);
			t_sample clamp_531 = ((plusequals_539 <= ((int)0)) ? ((int)0) : ((plusequals_539 >= ((int)1)) ? ((int)1) : plusequals_539));
			t_sample mix_674 = (latch_530 + (clamp_531 * (latch_532 - latch_530)));
			t_sample mix_534 = mix_674;
			t_sample gen_71 = mix_534;
			t_sample history_44_next_536 = fixdenorm(mix_534);
			t_sample mstosamps_83 = (gen_71 * (samplerate * 0.001));
			int change_548 = __m_change_60(m_knob_31);
			__m_latch_61 = ((change_548 != 0) ? m_history_17 : __m_latch_61);
			t_sample latch_541 = __m_latch_61;
			__m_latch_62 = ((change_548 != 0) ? m_knob_31 : __m_latch_62);
			t_sample latch_543 = __m_latch_62;
			t_sample plusequals_550 = __m_pluseq_63.pre(rdiv_546, change_548, 0);
			t_sample clamp_542 = ((plusequals_550 <= ((int)0)) ? ((int)0) : ((plusequals_550 >= ((int)1)) ? ((int)1) : plusequals_550));
			t_sample mix_675 = (latch_541 + (clamp_542 * (latch_543 - latch_541)));
			t_sample mix_545 = mix_675;
			t_sample gen_95 = mix_545;
			t_sample history_44_next_547 = fixdenorm(mix_545);
			t_sample mstosamps_108 = (gen_95 * (samplerate * 0.001));
			int change_11 = __m_change_64(int_10);
			int eqp_12 = ((int_10 == change_11) ? int_10 : 0);
			int gen_125 = eqp_12;
			int change_555 = __m_change_65(m_knob_36);
			__m_latch_66 = ((change_555 != 0) ? m_history_16 : __m_latch_66);
			t_sample latch_556 = __m_latch_66;
			__m_latch_67 = ((change_555 != 0) ? m_knob_36 : __m_latch_67);
			t_sample latch_553 = __m_latch_67;
			t_sample plusequals_561 = __m_pluseq_68.pre(rdiv_557, change_555, 0);
			t_sample clamp_552 = ((plusequals_561 <= ((int)0)) ? ((int)0) : ((plusequals_561 >= ((int)1)) ? ((int)1) : plusequals_561));
			t_sample mix_676 = (latch_556 + (clamp_552 * (latch_553 - latch_556)));
			t_sample mix_554 = mix_676;
			t_sample gen_52 = mix_554;
			t_sample history_44_next_558 = fixdenorm(mix_554);
			int change_566 = __m_change_69(m_knob_36);
			__m_latch_70 = ((change_566 != 0) ? m_history_15 : __m_latch_70);
			t_sample latch_567 = __m_latch_70;
			__m_latch_71 = ((change_566 != 0) ? m_knob_36 : __m_latch_71);
			t_sample latch_564 = __m_latch_71;
			t_sample plusequals_572 = __m_pluseq_72.pre(rdiv_568, change_566, 0);
			t_sample clamp_563 = ((plusequals_572 <= ((int)0)) ? ((int)0) : ((plusequals_572 >= ((int)1)) ? ((int)1) : plusequals_572));
			t_sample mix_677 = (latch_567 + (clamp_563 * (latch_564 - latch_567)));
			t_sample mix_565 = mix_677;
			t_sample gen_97 = mix_565;
			t_sample history_44_next_569 = fixdenorm(mix_565);
			int change_574 = __m_change_73(int_575);
			int eqp_576 = ((int_575 == change_574) ? int_575 : 0);
			int gen_129 = eqp_576;
			int gt_138 = (gen_129 > ((int)0));
			int change_137 = __m_change_74(gt_138);
			int gt_136 = (change_137 > ((int)0));
			int gen_140 = gt_136;
			t_sample add_145 = (m_history_14 + ((int)1));
			t_sample switch_142 = (gen_140 ? ((int)0) : add_145);
			__m_latch_75 = ((gen_140 != 0) ? add_145 : __m_latch_75);
			t_sample latch_144 = __m_latch_75;
			t_sample gen_149 = latch_144;
			t_sample history_143_next_148 = fixdenorm(switch_142);
			t_sample rdiv_133 = safediv(((int)1), gen_149);
			t_sample add_135 = (m_history_13 + rdiv_133);
			t_sample switch_132 = (gen_140 ? ((int)0) : add_135);
			t_sample wrap_134 = wrap(switch_132, ((int)0), ((int)1));
			t_sample gen_223 = wrap_134;
			t_sample history_131_next_156 = fixdenorm(wrap_134);
			t_sample mul_173 = (gen_223 * ((t_sample)0.125));
			t_sample sub_191 = (gen_223 - m_history_12);
			t_sample add_192 = (gen_223 + m_history_12);
			t_sample div_190 = safediv(sub_191, add_192);
			t_sample abs_189 = fabs(div_190);
			int gt_187 = (abs_189 > ((t_sample)0.5));
			int change_186 = __m_change_76(gt_187);
			int gt_185 = (change_186 > ((int)0));
			int gen_196 = gt_185;
			t_sample history_188_next_195 = fixdenorm(gen_223);
			t_sample delta_202 = __m_delta_77(gen_223);
			t_sample wrap_203 = wrap(delta_202, (-0.5), ((t_sample)0.5));
			t_sample gen_205 = wrap_203;
			t_sample mul_199 = (gen_205 * ((t_sample)0.125));
			t_sample add_197 = (mul_199 + m_history_9);
			t_sample sub_171 = (add_197 - mul_173);
			t_sample round_184 = (trunc((sub_171 * ((t_sample)8))) * ((t_sample)0.125));
			t_sample add_172 = (round_184 + mul_173);
			t_sample sub_207 = (m_history_10 - ((int)8));
			t_sample add_208 = (m_history_10 + ((int)8));
			t_sample div_206 = safediv(sub_207, add_208);
			t_sample abs_166 = fabs(div_206);
			int gt_167 = (abs_166 > ((t_sample)0.015625));
			int and_170 = (gt_167 && ((int)1));
			t_sample switch_174 = (and_170 ? and_170 : m_history_11);
			t_sample switch_177 = (gen_196 ? switch_174 : ((int)0));
			t_sample gen_182 = switch_177;
			t_sample switch_176 = (switch_177 ? ((int)0) : switch_174);
			t_sample history_178_next_181 = fixdenorm(switch_176);
			int or_169 = (gen_182 || gen_125);
			t_sample switch_201 = (or_169 ? add_172 : add_197);
			t_sample wrap_198 = wrap(switch_201, ((int)0), ((int)1));
			t_sample gen_214 = wrap_198;
			t_sample history_200_next_213 = fixdenorm(wrap_198);
			t_sample mul_128 = (gen_214 * ((int)8));
			t_sample floor_127 = floor(mul_128);
			t_sample add_111 = (floor_127 + ((int)1));
			t_sample choice_78 = int(add_111);
			t_sample gate_117 = (((choice_78 >= 1) && (choice_78 < 2)) ? ((int)1) : 0);
			t_sample gate_118 = (((choice_78 >= 2) && (choice_78 < 3)) ? ((int)1) : 0);
			t_sample gate_119 = (((choice_78 >= 3) && (choice_78 < 4)) ? ((int)1) : 0);
			t_sample gate_120 = (((choice_78 >= 4) && (choice_78 < 5)) ? ((int)1) : 0);
			t_sample gate_121 = (((choice_78 >= 5) && (choice_78 < 6)) ? ((int)1) : 0);
			t_sample gate_122 = (((choice_78 >= 6) && (choice_78 < 7)) ? ((int)1) : 0);
			t_sample gate_123 = (((choice_78 >= 7) && (choice_78 < 8)) ? ((int)1) : 0);
			t_sample gate_124 = ((choice_78 >= 8) ? ((int)1) : 0);
			t_sample out6 = gate_120;
			t_sample out7 = gate_121;
			t_sample out10 = gate_124;
			t_sample out4 = gate_118;
			t_sample out5 = gate_119;
			t_sample out8 = gate_122;
			t_sample out9 = gate_123;
			t_sample out3 = gate_117;
			t_sample add_113 = (add_111 + ((int)1));
			int change_164 = __m_change_79(add_113);
			int neq_163 = (change_164 != ((int)0));
			int gt_20 = (neq_163 > ((int)0));
			int change_19 = __m_change_80(gt_20);
			int gt_18 = (change_19 > ((int)0));
			int plusequals_17 = __m_pluseq_81.post(((int)1), gt_18, 0);
			int lte_16 = (plusequals_17 <= max_15);
			t_sample out11 = lte_16;
			t_sample out12 = lte_16;
			int change_584 = __m_change_82(m_knob_27);
			__m_latch_83 = ((change_584 != 0) ? m_history_8 : __m_latch_83);
			t_sample latch_580 = __m_latch_83;
			__m_latch_84 = ((change_584 != 0) ? m_knob_27 : __m_latch_84);
			t_sample latch_582 = __m_latch_84;
			t_sample plusequals_586 = __m_pluseq_85.pre(rdiv_581, change_584, 0);
			t_sample clamp_579 = ((plusequals_586 <= ((int)0)) ? ((int)0) : ((plusequals_586 >= ((int)1)) ? ((int)1) : plusequals_586));
			t_sample mix_678 = (latch_580 + (clamp_579 * (latch_582 - latch_580)));
			t_sample mix_578 = mix_678;
			t_sample gen_72 = mix_578;
			t_sample history_44_next_583 = fixdenorm(mix_578);
			__m_cycle_86.freq(gen_72);
			t_sample cycle_79 = __m_cycle_86(__sinedata);
			t_sample cycleindex_80 = __m_cycle_86.phase();
			t_sample mul_78 = (cycle_79 * gen_52);
			t_sample mul_55 = (mstosamps_83 * mul_78);
			t_sample maxa_87 = (mul_55 + mstosamps_83);
			t_sample max_74 = ((maxa_87 < ((int)1)) ? ((int)1) : maxa_87);
			t_sample tap_85 = m_delay_7.read_linear(max_74);
			t_sample sub_61 = (tap_85 - m_history_6);
			t_sample abs_63 = fabs(gen_68);
			t_sample clamp_62 = ((abs_63 <= ((int)0)) ? ((int)0) : ((abs_63 >= ((int)1)) ? ((int)1) : abs_63));
			t_sample mul_60 = (sub_61 * clamp_62);
			t_sample add_59 = (mul_60 + m_history_6);
			t_sample gen_65 = add_59;
			t_sample history_58_next_64 = fixdenorm((mul_60 + add_59));
			t_sample mul_81 = (gen_65 * switch_54);
			t_sample mix_679 = (in2 + (gen_69 * (mul_81 - in2)));
			t_sample out2 = mix_679;
			int change_593 = __m_change_88(m_knob_27);
			__m_latch_89 = ((change_593 != 0) ? m_history_5 : __m_latch_89);
			t_sample latch_594 = __m_latch_89;
			__m_latch_90 = ((change_593 != 0) ? m_knob_27 : __m_latch_90);
			t_sample latch_592 = __m_latch_90;
			t_sample plusequals_598 = __m_pluseq_91.pre(rdiv_595, change_593, 0);
			t_sample clamp_591 = ((plusequals_598 <= ((int)0)) ? ((int)0) : ((plusequals_598 >= ((int)1)) ? ((int)1) : plusequals_598));
			t_sample mix_680 = (latch_594 + (clamp_591 * (latch_592 - latch_594)));
			t_sample mix_590 = mix_680;
			t_sample gen_96 = mix_590;
			t_sample history_44_next_597 = fixdenorm(mix_590);
			__m_cycle_92.freq(gen_96);
			t_sample cycle_104 = __m_cycle_92(__sinedata);
			t_sample cycleindex_105 = __m_cycle_92.phase();
			t_sample mul_103 = (cycle_104 * gen_97);
			t_sample mul_88 = (mstosamps_108 * mul_103);
			t_sample maxa_93 = (mstosamps_108 + mul_88);
			t_sample max_99 = ((maxa_93 < ((int)1)) ? ((int)1) : maxa_93);
			t_sample tap_110 = m_delay_4.read_linear(max_99);
			t_sample sub_609 = (tap_110 - m_history_3);
			t_sample abs_606 = fabs(gen_92);
			t_sample clamp_608 = ((abs_606 <= ((int)0)) ? ((int)0) : ((abs_606 >= ((int)1)) ? ((int)1) : abs_606));
			t_sample mul_604 = (sub_609 * clamp_608);
			t_sample add_601 = (mul_604 + m_history_3);
			t_sample gen_89 = add_601;
			t_sample history_58_next_602 = fixdenorm((mul_604 + add_601));
			t_sample mul_106 = (gen_89 * switch_87);
			t_sample mix_681 = (in1 + (gen_93 * (mul_106 - in1)));
			t_sample out1 = mix_681;
			int change_616 = __m_change_94(m_knob_24);
			__m_latch_95 = ((change_616 != 0) ? m_history_2 : __m_latch_95);
			t_sample latch_612 = __m_latch_95;
			__m_latch_96 = ((change_616 != 0) ? m_knob_24 : __m_latch_96);
			t_sample latch_618 = __m_latch_96;
			t_sample plusequals_614 = __m_pluseq_97.pre(rdiv_620, change_616, 0);
			t_sample clamp_617 = ((plusequals_614 <= ((int)0)) ? ((int)0) : ((plusequals_614 >= ((int)1)) ? ((int)1) : plusequals_614));
			t_sample mix_682 = (latch_612 + (clamp_617 * (latch_618 - latch_612)));
			t_sample mix_615 = mix_682;
			t_sample gen_70 = mix_615;
			t_sample history_44_next_613 = fixdenorm(mix_615);
			t_sample mstosamps_73 = (gen_70 * (samplerate * 0.001));
			t_sample div_76 = safediv(mstosamps_73, max_74);
			t_sample t_77 = exp(safediv(-6.9077552789821, div_76));
			t_sample mul_53 = (mul_81 * t_77);
			t_sample add_75 = (in2 + mul_53);
			int change_627 = __m_change_98(m_knob_24);
			__m_latch_99 = ((change_627 != 0) ? m_history_1 : __m_latch_99);
			t_sample latch_623 = __m_latch_99;
			__m_latch_100 = ((change_627 != 0) ? m_knob_24 : __m_latch_100);
			t_sample latch_629 = __m_latch_100;
			t_sample plusequals_625 = __m_pluseq_101.pre(rdiv_631, change_627, 0);
			t_sample clamp_628 = ((plusequals_625 <= ((int)0)) ? ((int)0) : ((plusequals_625 >= ((int)1)) ? ((int)1) : plusequals_625));
			t_sample mix_683 = (latch_623 + (clamp_628 * (latch_629 - latch_623)));
			t_sample mix_626 = mix_683;
			t_sample gen_94 = mix_626;
			t_sample history_44_next_624 = fixdenorm(mix_626);
			t_sample mstosamps_98 = (gen_94 * (samplerate * 0.001));
			t_sample div_101 = safediv(mstosamps_98, max_99);
			t_sample t_102 = exp(safediv(-6.9077552789821, div_101));
			t_sample mul_86 = (mul_106 * t_102);
			t_sample add_100 = (in1 + mul_86);
			m_history_22 = history_44_next_51;
			m_history_21 = history_44_next_499;
			m_history_20 = history_44_next_511;
			m_history_19 = history_44_next_525;
			m_history_18 = history_44_next_536;
			m_history_17 = history_44_next_547;
			m_history_16 = history_44_next_558;
			m_history_15 = history_44_next_569;
			m_history_14 = history_143_next_148;
			m_history_13 = history_131_next_156;
			m_history_12 = history_188_next_195;
			m_history_9 = history_200_next_213;
			m_history_10 = history_168_next_212;
			m_history_11 = history_178_next_181;
			m_history_8 = history_44_next_583;
			m_delay_7.write(add_75);
			m_history_6 = history_58_next_64;
			m_history_5 = history_44_next_597;
			m_delay_4.write(add_100);
			m_history_3 = history_58_next_602;
			m_history_2 = history_44_next_613;
			m_history_1 = history_44_next_624;
			m_delay_4.step();
			m_delay_7.step();
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
			(*(__out13++)) = out13;
			(*(__out14++)) = out14;
			
		};
		return __exception;
		
	};
	inline void set_knob8(t_param _value) {
		m_knob_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1(t_param _value) {
		m_knob_24 = (_value < 0.001 ? 0.001 : (_value > 12000 ? 12000 : _value));
	};
	inline void set_knob6(t_param _value) {
		m_knob_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3(t_param _value) {
		m_knob_27 = (_value < 0.001 ? 0.001 : (_value > 10 ? 10 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin4(t_param _value) {
		m_cvin_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin2(t_param _value) {
		m_cvin_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2(t_param _value) {
		m_knob_31 = (_value < 0 ? 0 : (_value > 2000 ? 2000 : _value));
	};
	inline void set_cvin1(t_param _value) {
		m_cvin_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin3(t_param _value) {
		m_cvin_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5(t_param _value) {
		m_knob_34 = (_value < 0 ? 0 : (_value > 5000 ? 5000 : _value));
	};
	inline void set_gate2(t_param _value) {
		m_gate_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4(t_param _value) {
		m_knob_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob7(t_param _value) {
		m_knob_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 14;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 15; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "gateout1", "gateout2", "cvout1", "cvout2" };

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
		case 0: self->set_cvin1(value); break;
		case 1: self->set_cvin2(value); break;
		case 2: self->set_cvin3(value); break;
		case 3: self->set_cvin4(value); break;
		case 4: self->set_gate1(value); break;
		case 5: self->set_gate2(value); break;
		case 6: self->set_gatein1(value); break;
		case 7: self->set_knob1(value); break;
		case 8: self->set_knob2(value); break;
		case 9: self->set_knob3(value); break;
		case 10: self->set_knob4(value); break;
		case 11: self->set_knob5(value); break;
		case 12: self->set_knob6(value); break;
		case 13: self->set_knob7(value); break;
		case 14: self->set_knob8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_cvin_32; break;
		case 1: *value = self->m_cvin_30; break;
		case 2: *value = self->m_cvin_33; break;
		case 3: *value = self->m_cvin_29; break;
		case 4: *value = self->m_gate_26; break;
		case 5: *value = self->m_gate_35; break;
		case 6: *value = self->m_gatein_28; break;
		case 7: *value = self->m_knob_24; break;
		case 8: *value = self->m_knob_31; break;
		case 9: *value = self->m_knob_27; break;
		case 10: *value = self->m_knob_36; break;
		case 11: *value = self->m_knob_34; break;
		case 12: *value = self->m_knob_25; break;
		case 13: *value = self->m_knob_37; break;
		case 14: *value = self->m_knob_23; break;
		
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
	// initialize parameter 0 ("m_cvin_32")
	pi = self->__commonstate.params + 0;
	pi->name = "cvin1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cvin_30")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_cvin_33")
	pi = self->__commonstate.params + 2;
	pi->name = "cvin3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_cvin_29")
	pi = self->__commonstate.params + 3;
	pi->name = "cvin4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_gate_26")
	pi = self->__commonstate.params + 4;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_gate_35")
	pi = self->__commonstate.params + 5;
	pi->name = "gate2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_gatein_28")
	pi = self->__commonstate.params + 6;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob_24")
	pi = self->__commonstate.params + 7;
	pi->name = "knob1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.001;
	pi->outputmax = 12000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob_31")
	pi = self->__commonstate.params + 8;
	pi->name = "knob2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob_27")
	pi = self->__commonstate.params + 9;
	pi->name = "knob3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.001;
	pi->outputmax = 10;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob_36")
	pi = self->__commonstate.params + 10;
	pi->name = "knob4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_36;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_knob_34")
	pi = self->__commonstate.params + 11;
	pi->name = "knob5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_knob_25")
	pi = self->__commonstate.params + 12;
	pi->name = "knob6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_knob_37")
	pi = self->__commonstate.params + 13;
	pi->name = "knob7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_knob_23")
	pi = self->__commonstate.params + 14;
	pi->name = "knob8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_23;
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


} // relays::
