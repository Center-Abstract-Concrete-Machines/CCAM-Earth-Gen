#include "roaches.h"

namespace roaches {

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
	Change __m_change_103;
	Change __m_change_99;
	Change __m_change_102;
	Change __m_change_69;
	Change __m_change_84;
	Change __m_change_98;
	Change __m_change_94;
	Change __m_change_96;
	Change __m_change_91;
	Change __m_change_86;
	Change __m_change_105;
	Change __m_change_87;
	Change __m_change_110;
	Change __m_change_107;
	Change __m_change_74;
	Change __m_change_108;
	Change __m_change_114;
	Delay m_delay_17;
	Delay m_delay_16;
	Delay m_delay_10;
	Delay m_delay_14;
	Delay m_delay_11;
	Delay m_delay_12;
	Delay m_delay_15;
	Delay m_delay_13;
	Delta __m_delta_85;
	Delta __m_delta_97;
	MulEquals __m_muleq_90;
	MulEquals __m_muleq_93;
	Phasor __m_phasor_73;
	Phasor __m_phasor_80;
	Phasor __m_phasor_112;
	Phasor __m_phasor_81;
	Phasor __m_phasor_113;
	PlusEquals __m_pluseq_72;
	PlusEquals __m_pluseq_118;
	PlusEquals __m_pluseq_95;
	PlusEquals __m_pluseq_115;
	PlusEquals __m_pluseq_116;
	PlusEquals __m_pluseq_92;
	PlusEquals __m_pluseq_111;
	PlusEquals __m_pluseq_106;
	PlusEquals __m_pluseq_109;
	PlusEquals __m_pluseq_104;
	PlusEquals __m_pluseq_117;
	int __exception;
	int vectorsize;
	t_sample m_history_44;
	t_sample m_history_28;
	t_sample m_history_29;
	t_sample m_history_27;
	t_sample m_history_26;
	t_sample m_history_25;
	t_sample m_history_30;
	t_sample m_history_24;
	t_sample m_history_23;
	t_sample m_history_31;
	t_sample m_history_32;
	t_sample __m_latch_83;
	t_sample elapsed;
	t_sample __m_latch_88;
	t_sample m_history_35;
	t_sample m_history_33;
	t_sample m_history_34;
	t_sample m_history_36;
	t_sample m_history_22;
	t_sample __m_latch_101;
	t_sample m_history_3;
	t_sample m_history_4;
	t_sample m_history_5;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample __m_latch_100;
	t_sample m_history_6;
	t_sample m_history_8;
	t_sample m_history_20;
	t_sample m_history_21;
	t_sample m_history_7;
	t_sample m_history_19;
	t_sample m_history_9;
	t_sample m_history_18;
	t_sample m_history_43;
	t_sample m_history_37;
	t_sample __m_latch_78;
	t_sample m_sw_55;
	t_sample m_sw_54;
	t_sample m_sw_53;
	t_sample m_sw_56;
	t_sample m_history_42;
	t_sample m_sw_57;
	t_sample m_knob_59;
	t_sample m_knob_60;
	t_sample m_sw_52;
	t_sample m_history_50;
	t_sample m_x_46;
	t_sample m_z_45;
	t_sample m_history_51;
	t_sample m_y_47;
	t_sample m_history_49;
	t_sample m_history_48;
	t_sample __m_latch_79;
	t_sample m_sw_61;
	t_sample m_cvin_63;
	t_sample m_history_39;
	t_sample samples_to_seconds;
	t_sample m_history_40;
	t_sample m_history_38;
	t_sample __m_latch_76;
	t_sample __m_latch_75;
	t_sample __m_latch_77;
	t_sample m_knob_62;
	t_sample __m_latch_71;
	t_sample m_history_41;
	t_sample m_sw_65;
	t_sample m_knob_64;
	t_sample __m_latch_70;
	t_sample m_chance_66;
	t_sample m_gate_68;
	t_sample m_knob_67;
	t_sample m_knob_58;
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
		m_delay_10.reset("m_delay_10", ((int)5419));
		m_delay_11.reset("m_delay_11", ((int)3469));
		m_delay_12.reset("m_delay_12", ((int)7351));
		m_delay_13.reset("m_delay_13", ((int)5167));
		m_delay_14.reset("m_delay_14", ((int)4447));
		m_delay_15.reset("m_delay_15", ((int)2791));
		m_delay_16.reset("m_delay_16", ((int)8269));
		m_delay_17.reset("m_delay_17", ((int)3571));
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
		m_history_43 = ((int)0);
		m_history_44 = ((int)0);
		m_z_45 = ((int)0);
		m_x_46 = ((int)0);
		m_y_47 = ((int)0);
		m_history_48 = ((int)0);
		m_history_49 = ((int)0);
		m_history_50 = ((int)0);
		m_history_51 = ((int)0);
		m_sw_52 = ((int)0);
		m_sw_53 = ((int)0);
		m_sw_54 = ((int)0);
		m_sw_55 = ((int)0);
		m_sw_56 = ((int)0);
		m_sw_57 = ((int)0);
		m_knob_58 = ((int)0);
		m_knob_59 = ((int)0);
		m_knob_60 = ((int)0);
		m_sw_61 = ((int)0);
		m_knob_62 = ((int)1);
		m_cvin_63 = ((int)0);
		m_knob_64 = ((int)0);
		m_sw_65 = ((int)0);
		m_chance_66 = ((t_sample)0.25);
		m_knob_67 = ((int)0);
		m_gate_68 = ((int)0);
		__m_change_69.reset(0);
		__m_latch_70 = 0;
		__m_latch_71 = 0;
		__m_pluseq_72.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_73.reset(0);
		__m_change_74.reset(0);
		__m_latch_75 = 0;
		__m_latch_76 = 0;
		__m_latch_77 = 0;
		__m_latch_78 = 0;
		__m_latch_79 = 0;
		__m_phasor_80.reset(0);
		__m_phasor_81.reset(0);
		elapsed = 0;
		__m_latch_83 = 0;
		__m_change_84.reset(0);
		__m_delta_85.reset(0);
		__m_change_86.reset(0);
		__m_change_87.reset(0);
		__m_latch_88 = 0;
		__m_muleq_90.reset(0);
		__m_change_91.reset(0);
		__m_pluseq_92.reset(0);
		__m_muleq_93.reset(0);
		__m_change_94.reset(0);
		__m_pluseq_95.reset(0);
		__m_change_96.reset(0);
		__m_delta_97.reset(0);
		__m_change_98.reset(0);
		__m_change_99.reset(0);
		__m_latch_100 = 0;
		__m_latch_101 = 0;
		__m_change_102.reset(0);
		__m_change_103.reset(0);
		__m_pluseq_104.reset(0);
		__m_change_105.reset(0);
		__m_pluseq_106.reset(0);
		__m_change_107.reset(0);
		__m_change_108.reset(0);
		__m_pluseq_109.reset(0);
		__m_change_110.reset(0);
		__m_pluseq_111.reset(0);
		__m_phasor_112.reset(0);
		__m_phasor_113.reset(0);
		__m_change_114.reset(0);
		__m_pluseq_115.reset(0);
		__m_pluseq_116.reset(0);
		__m_pluseq_117.reset(0);
		__m_pluseq_118.reset(0);
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
		t_sample div_37021 = (m_knob_58 * ((t_sample)0.016666666666667));
		int iftrue_82 = (-10000000000);
		t_sample history_36890_next_36917 = fixdenorm(((t_sample)0.125));
		t_sample mul_37041 = (((t_sample)0.3) * samplerate);
		t_sample t_37042 = exp(safediv(-6.9077552789821, mul_37041));
		t_sample mstosamps_14001 = (((int)0) * (samplerate * 0.001));
		t_sample max_14002 = ((mstosamps_14001 < vectorsize) ? vectorsize : mstosamps_14001);
		t_sample mul_37030 = (((t_sample)0.07) * samplerate);
		t_sample t_37031 = exp(safediv(-6.9077552789821, mul_37030));
		t_sample mstosamps_39945 = (((int)0) * (samplerate * 0.001));
		t_sample max_39940 = ((mstosamps_39945 < vectorsize) ? vectorsize : mstosamps_39945);
		t_sample history_36890_next_39960 = fixdenorm(((int)4));
		t_sample mstosamps_40029 = (((int)0) * (samplerate * 0.001));
		t_sample max_40024 = ((mstosamps_40029 < vectorsize) ? vectorsize : mstosamps_40029);
		t_sample mstosamps_40068 = (((int)0) * (samplerate * 0.001));
		t_sample max_40063 = ((mstosamps_40068 < vectorsize) ? vectorsize : mstosamps_40068);
		int min_120 = (-1);
		t_sample min_121 = (-0.99);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out12 = ((int)0);
			t_sample out11 = ((int)0);
			t_sample noise_36955 = noise();
			int change_36778 = __m_change_69(m_knob_60);
			__m_latch_70 = ((change_36778 != 0) ? m_history_51 : __m_latch_70);
			t_sample latch_36775 = __m_latch_70;
			__m_latch_71 = ((change_36778 != 0) ? m_knob_60 : __m_latch_71);
			t_sample latch_36774 = __m_latch_71;
			t_sample plusequals_36776 = __m_pluseq_72.pre(((t_sample)2.2675736961451e-05), change_36778, 0);
			t_sample clamp_36771 = ((plusequals_36776 <= ((int)0)) ? ((int)0) : ((plusequals_36776 >= ((int)1)) ? ((int)1) : plusequals_36776));
			t_sample mix_40799 = (latch_36775 + (clamp_36771 * (latch_36774 - latch_36775)));
			t_sample mix_36773 = mix_40799;
			t_sample gen_36780 = mix_36773;
			t_sample history_36772_next_36779 = fixdenorm(mix_36773);
			t_sample phasor_36954 = __m_phasor_73(((int)1), samples_to_seconds);
			t_sample sub_36756 = (phasor_36954 - m_history_50);
			t_sample add_36757 = (phasor_36954 + m_history_50);
			t_sample div_36755 = safediv(sub_36756, add_36757);
			t_sample abs_36754 = fabs(div_36755);
			int gt_36752 = (abs_36754 > ((t_sample)0.5));
			int change_36751 = __m_change_74(gt_36752);
			int gt_36750 = (change_36751 > ((int)0));
			int gen_36953 = gt_36750;
			t_sample history_36753_next_36758 = fixdenorm(phasor_36954);
			__m_latch_75 = ((gen_36953 != 0) ? m_history_4 : __m_latch_75);
			t_sample latch_36948 = __m_latch_75;
			__m_latch_76 = ((gen_36953 != 0) ? m_history_7 : __m_latch_76);
			t_sample latch_36945 = __m_latch_76;
			__m_latch_77 = ((gen_36953 != 0) ? noise_36955 : __m_latch_77);
			t_sample latch_36957 = __m_latch_77;
			__m_latch_78 = ((gen_36953 != 0) ? m_history_3 : __m_latch_78);
			t_sample latch_36950 = __m_latch_78;
			__m_latch_79 = ((gen_36953 != 0) ? m_history_5 : __m_latch_79);
			t_sample latch_36952 = __m_latch_79;
			t_sample noise_37051 = noise();
			t_sample mix_40800 = (noise_37051 + (((t_sample)0.7) * (m_history_49 - noise_37051)));
			t_sample mix_37047 = mix_40800;
			t_sample sub_37045 = (noise_37051 - mix_37047);
			t_sample gen_37049 = sub_37045;
			t_sample history_37046_next_37048 = fixdenorm(mix_37047);
			t_sample noise_37040 = noise();
			t_sample mix_40801 = (noise_37040 + (((t_sample)0.7) * (m_history_48 - noise_37040)));
			t_sample mix_37036 = mix_40801;
			t_sample sub_37034 = (noise_37040 - mix_37036);
			t_sample gen_37038 = sub_37034;
			t_sample history_37035_next_37037 = fixdenorm(mix_37036);
			t_sample mul_36870 = (m_history_1 * ((int)2));
			t_sample phasor_36804 = __m_phasor_80(((t_sample)3.141), samples_to_seconds);
			t_sample phasor_36803 = __m_phasor_81(((int)123), samples_to_seconds);
			int gt_36802 = (phasor_36804 > phasor_36803);
			t_sample noise_36881 = noise();
			t_sample abs_36880 = fabs(noise_36881);
			t_sample mod_36872 = safemod(mul_36870, ((int)65536));
			int gte_36873 = (mul_36870 >= ((int)65536));
			t_sample noise_36800 = noise();
			int or_36971 = (((int)0) || (elapsed == ((int)0)));
			t_sample switch_36973 = (or_36971 ? ((t_sample)0.41) : m_y_47);
			t_sample mul_36986 = (switch_36973 * ((int)1));
			t_sample switch_36974 = (or_36971 ? ((t_sample)0.31) : m_z_45);
			t_sample mul_36991 = (switch_36974 * ((int)1));
			t_sample switch_36972 = (or_36971 ? ((t_sample)0.1) : m_x_46);
			t_sample mul_36994 = (mul_36991 * ((t_sample)0.0002));
			t_sample add_36988 = (switch_36973 + mul_36994);
			t_sample fixnan_36977 = fixnan(add_36988);
			t_sample gen_37000 = fixnan_36977;
			t_sample mul_36995 = (mul_36986 * ((t_sample)0.0002));
			t_sample add_36989 = (switch_36972 + mul_36995);
			t_sample fixnan_36975 = fixnan(add_36989);
			t_sample mul_36983 = (switch_36974 * (-0.45));
			t_sample pow_36981 = safepow(switch_36972, ((int)3));
			t_sample mul_36982 = (pow_36981 * (-1));
			t_sample mul_36985 = (switch_36972 * ((t_sample)0.8));
			t_sample mul_36984 = (switch_36973 * (-1.1));
			t_sample add_36980 = (mul_36985 + mul_36984);
			t_sample add_36979 = (add_36980 + mul_36983);
			t_sample add_36978 = (add_36979 + mul_36982);
			t_sample mul_36993 = (add_36978 * ((t_sample)0.0002));
			t_sample add_36987 = (switch_36974 + mul_36993);
			t_sample fixnan_36976 = fixnan(add_36987);
			t_sample y_next_36996 = fixdenorm(fixnan_36977);
			t_sample x_next_36997 = fixdenorm(fixnan_36975);
			t_sample z_next_36998 = fixdenorm(fixnan_36976);
			t_sample elapsed_37003 = elapsed;
			int eq_37002 = (elapsed_37003 == ((int)0));
			int or_37010 = (eq_37002 || ((int)0));
			t_sample switch_37006 = (or_37010 ? ((int)10000000000) : m_history_44);
			t_sample min_37009 = ((switch_37006 < gen_37000) ? switch_37006 : gen_37000);
			t_sample gen_37013 = min_37009;
			t_sample switch_37005 = (or_37010 ? iftrue_82 : m_history_43);
			t_sample max_37008 = ((gen_37000 < switch_37005) ? switch_37005 : gen_37000);
			t_sample gen_37014 = max_37008;
			t_sample history_37004_next_37011 = fixdenorm(min_37009);
			t_sample history_37007_next_37012 = fixdenorm(max_37008);
			t_sample irange_40803 = (gen_37014 - gen_37013);
			t_sample sub_40805 = (gen_37000 - gen_37013);
			t_sample scale_40802 = ((safepow(safediv(sub_40805, irange_40803), ((int)1)) * ((int)2)) + ((int)-1));
			t_sample scale_37015 = scale_40802;
			t_sample gen_37016 = scale_37015;
			t_sample mul_36962 = (m_knob_64 * gen_37016);
			__m_latch_83 = ((gen_36953 != 0) ? m_history_6 : __m_latch_83);
			t_sample latch_36943 = __m_latch_83;
			t_sample spline_36947 = spline6_interp(phasor_36954, latch_36943, latch_36945, latch_36948, latch_36950, latch_36952, latch_36957);
			t_sample sub_40809 = (spline_36947 - (-1));
			t_sample scale_40806 = ((safepow((sub_40809 * ((t_sample)0.5)), ((int)1)) * ((int)7)) + ((int)1));
			t_sample scale_36958 = scale_40806;
			t_sample floor_37020 = floor(scale_36958);
			t_sample mul_36782 = (floor_37020 * m_knob_59);
			t_sample add_36781 = (mul_36782 + ((int)1));
			t_sample div_37019 = safediv(div_37021, add_36781);
			t_sample div_36964 = safediv(div_37019, samplerate);
			t_sample mul_36969 = (div_36964 * mul_36962);
			t_sample add_36963 = (div_36964 + mul_36969);
			t_sample add_36967 = (m_history_2 + add_36963);
			t_sample switch_36968 = (((int)0) ? ((int)0) : add_36967);
			t_sample wrap_36965 = wrap(switch_36968, ((int)0), ((int)1));
			t_sample mul_36895 = (wrap_36965 * ((int)8));
			t_sample sub_39916 = (wrap_36965 - m_history_42);
			t_sample add_39913 = (wrap_36965 + m_history_42);
			t_sample div_39915 = safediv(sub_39916, add_39913);
			t_sample abs_39914 = fabs(div_39915);
			int gt_39910 = (abs_39914 > ((t_sample)0.5));
			int change_39917 = __m_change_84(gt_39910);
			int gt_39918 = (change_39917 > ((int)0));
			int gen_36905 = gt_39918;
			t_sample history_36753_next_39911 = fixdenorm(wrap_36965);
			t_sample delta_36911 = __m_delta_85(wrap_36965);
			t_sample wrap_36912 = wrap(delta_36911, (-0.5), ((t_sample)0.5));
			t_sample gen_36913 = wrap_36912;
			t_sample mul_36908 = (gen_36913 * ((int)8));
			t_sample add_36906 = (mul_36908 + m_history_39);
			t_sample sub_36893 = (add_36906 - mul_36895);
			t_sample round_36904 = (trunc((sub_36893 * ((t_sample)0.125))) * ((int)8));
			t_sample add_36894 = (round_36904 + mul_36895);
			t_sample sub_36915 = (m_history_40 - ((t_sample)0.125));
			t_sample add_36916 = (m_history_40 + ((t_sample)0.125));
			t_sample div_36914 = safediv(sub_36915, add_36916);
			t_sample abs_36888 = fabs(div_36914);
			int gt_36889 = (abs_36888 > ((t_sample)0.015625));
			int and_36892 = (gt_36889 && ((int)1));
			t_sample switch_36896 = (and_36892 ? and_36892 : m_history_41);
			t_sample switch_36899 = (gen_36905 ? switch_36896 : ((int)0));
			t_sample gen_36902 = switch_36899;
			t_sample switch_36898 = (switch_36899 ? ((int)0) : switch_36896);
			t_sample history_36900_next_36901 = fixdenorm(switch_36898);
			int or_36891 = (gen_36902 || ((int)0));
			t_sample switch_36910 = (or_36891 ? add_36894 : add_36906);
			t_sample wrap_36907 = wrap(switch_36910, ((int)0), ((int)1));
			t_sample gen_36960 = wrap_36907;
			t_sample history_36909_next_36918 = fixdenorm(wrap_36907);
			t_sample sub_39927 = (gen_36960 - m_history_38);
			t_sample add_39921 = (gen_36960 + m_history_38);
			t_sample div_39925 = safediv(sub_39927, add_39921);
			t_sample abs_39924 = fabs(div_39925);
			int gt_39922 = (abs_39924 > ((t_sample)0.5));
			int change_39928 = __m_change_86(gt_39922);
			int gt_39926 = (change_39928 > ((int)0));
			int gen_36865 = gt_39926;
			t_sample history_36753_next_39920 = fixdenorm(gen_36960);
			t_sample sub_39938 = (gen_36960 - m_history_37);
			t_sample add_39930 = (gen_36960 + m_history_37);
			t_sample div_39933 = safediv(sub_39938, add_39930);
			t_sample abs_39935 = fabs(div_39933);
			int gt_39932 = (abs_39935 > ((t_sample)0.5));
			int change_39931 = __m_change_87(gt_39932);
			int gt_39937 = (change_39931 > ((int)0));
			int gen_36961 = gt_39937;
			t_sample history_36753_next_39936 = fixdenorm(gen_36960);
			t_sample noise_37025 = noise();
			t_sample abs_37026 = fabs(noise_37025);
			int lt_37027 = (abs_37026 < m_chance_66);
			__m_latch_88 = ((gen_36961 != 0) ? lt_37027 : __m_latch_88);
			int latch_37028 = __m_latch_88;
			int gen_37029 = latch_37028;
			int add_37022 = (gen_37029 + ((int)1));
			int choice_89 = add_37022;
			int gate_37023 = (((choice_89 >= 1) && (choice_89 < 2)) ? gen_36961 : 0);
			int gate_37024 = ((choice_89 >= 2) ? gen_36961 : 0);
			t_sample mulequals_37043 = __m_muleq_90.post(t_37042, gate_37023, 1);
			t_sample gen_37044 = mulequals_37043;
			t_sample mul_37050 = (gen_37049 * gen_37044);
			int gt_14007 = (mul_37050 > ((int)0));
			int change_14006 = __m_change_91(gt_14007);
			int gt_14005 = (change_14006 > ((int)0));
			int plusequals_14004 = __m_pluseq_92.post(((int)1), gt_14005, 0);
			int lte_14003 = (plusequals_14004 <= max_14002);
			t_sample out9 = lte_14003;
			t_sample out10 = lte_14003;
			t_sample mul_37052 = (mul_37050 * ((t_sample)0.5));
			t_sample mulequals_37032 = __m_muleq_93.post(t_37031, gate_37024, 1);
			t_sample gen_37033 = mulequals_37032;
			t_sample mul_37039 = (gen_37038 * gen_37033);
			int gt_39944 = (mul_37039 > ((int)0));
			int change_39943 = __m_change_94(gt_39944);
			int gt_39947 = (change_39943 > ((int)0));
			int plusequals_39942 = __m_pluseq_95.post(((int)1), gt_39947, 0);
			int lte_39941 = (plusequals_39942 <= max_39940);
			t_sample out4 = lte_39941;
			t_sample out3 = lte_39941;
			t_sample mul_37053 = (mul_37039 * ((t_sample)0.5));
			t_sample pass_37054 = mul_37053;
			t_sample mul_39972 = (wrap_36965 * ((t_sample)0.25));
			t_sample sub_39989 = (wrap_36965 - m_history_36);
			t_sample add_39964 = (wrap_36965 + m_history_36);
			t_sample div_39985 = safediv(sub_39989, add_39964);
			t_sample abs_39984 = fabs(div_39985);
			int gt_39981 = (abs_39984 > ((t_sample)0.5));
			int change_39958 = __m_change_96(gt_39981);
			int gt_39988 = (change_39958 > ((int)0));
			int gen_39975 = gt_39988;
			t_sample history_36753_next_39951 = fixdenorm(wrap_36965);
			t_sample delta_39974 = __m_delta_97(wrap_36965);
			t_sample wrap_39973 = wrap(delta_39974, (-0.5), ((t_sample)0.5));
			t_sample gen_39957 = wrap_39973;
			t_sample mul_39965 = (gen_39957 * ((t_sample)0.25));
			t_sample add_39959 = (mul_39965 + m_history_33);
			t_sample sub_39979 = (add_39959 - mul_39972);
			t_sample round_39976 = (trunc((sub_39979 * ((t_sample)4))) * ((t_sample)0.25));
			t_sample add_39971 = (round_39976 + mul_39972);
			t_sample sub_39970 = (m_history_34 - ((int)4));
			t_sample add_39948 = (m_history_34 + ((int)4));
			t_sample div_39961 = safediv(sub_39970, add_39948);
			t_sample abs_39949 = fabs(div_39961);
			int gt_39969 = (abs_39949 > ((t_sample)0.015625));
			int and_39955 = (gt_39969 && ((int)1));
			t_sample switch_39968 = (and_39955 ? and_39955 : m_history_35);
			t_sample switch_39950 = (gen_39975 ? switch_39968 : ((int)0));
			t_sample gen_39967 = switch_39950;
			t_sample switch_39966 = (switch_39950 ? ((int)0) : switch_39968);
			t_sample history_36900_next_39987 = fixdenorm(switch_39966);
			int or_39963 = (gen_39967 || ((int)0));
			t_sample switch_39962 = (or_39963 ? add_39971 : add_39959);
			t_sample wrap_39952 = wrap(switch_39962, ((int)0), ((int)1));
			t_sample gen_36919 = wrap_39952;
			t_sample history_36909_next_39953 = fixdenorm(wrap_39952);
			t_sample sub_39998 = (gen_36919 - m_history_32);
			t_sample add_39996 = (gen_36919 + m_history_32);
			t_sample div_39999 = safediv(sub_39998, add_39996);
			t_sample abs_39997 = fabs(div_39999);
			int gt_39994 = (abs_39997 > ((t_sample)0.5));
			int change_40002 = __m_change_98(gt_39994);
			int gt_40001 = (change_40002 > ((int)0));
			int gen_36942 = gt_40001;
			t_sample history_36753_next_40000 = fixdenorm(gen_36919);
			t_sample noise_36928 = noise();
			t_sample sub_40008 = (gen_36942 - m_history_31);
			t_sample add_40006 = (gen_36942 + m_history_31);
			t_sample div_40009 = safediv(sub_40008, add_40006);
			t_sample abs_40007 = fabs(div_40009);
			int gt_40004 = (abs_40007 > ((t_sample)0.5));
			int change_40012 = __m_change_99(gt_40004);
			int gt_40011 = (change_40012 > ((int)0));
			int gen_36936 = gt_40011;
			t_sample history_36753_next_40010 = fixdenorm(gen_36942);
			int gt_36932 = (gen_36936 > ((int)0));
			t_sample switch_36933 = (gt_36932 ? ((int)1) : ((t_sample)2e-05));
			t_sample mix_40810 = (m_history_30 + (switch_36933 * (gen_36936 - m_history_30)));
			t_sample mix_36934 = mix_40810;
			t_sample mix_40811 = (mix_36934 + (((t_sample)0.95) * (m_history_29 - mix_36934)));
			t_sample mix_36930 = mix_40811;
			t_sample mul_36926 = (mix_36930 * noise_36928);
			t_sample mix_40812 = (mul_36926 + (((t_sample)0.99) * (m_history_28 - mul_36926)));
			t_sample mix_36929 = mix_40812;
			t_sample sub_36922 = (mul_36926 - mix_36929);
			t_sample mix_40813 = (sub_36922 + (((t_sample)0.99) * (m_history_27 - sub_36922)));
			t_sample mix_36924 = mix_40813;
			t_sample sub_36925 = (sub_36922 - mix_36924);
			t_sample mul_36921 = (sub_36925 * ((t_sample)0.5));
			t_sample gen_36941 = mul_36921;
			t_sample history_36935_next_36937 = fixdenorm(mix_36934);
			t_sample history_36931_next_36938 = fixdenorm(mix_36930);
			t_sample history_36927_next_36939 = fixdenorm(mix_36929);
			t_sample history_36923_next_36940 = fixdenorm(mix_36924);
			__m_latch_100 = ((gen_36942 != 0) ? noise_36800 : __m_latch_100);
			t_sample latch_36801 = __m_latch_100;
			int gt_36799 = (latch_36801 > ((int)0));
			int abs_36878 = abs(gt_36799);
			int lt_36879 = (abs_36880 < abs_36878);
			int lt_36876 = (gt_36799 < ((int)0));
			int xor_36877 = (!!lt_36876 ^ !!gte_36873);
			int switch_36875 = (lt_36879 ? xor_36877 : gt_36802);
			t_sample add_36874 = (switch_36875 + mod_36872);
			__m_latch_101 = ((gen_36865 != 0) ? add_36874 : __m_latch_101);
			t_sample latch_36866 = __m_latch_101;
			int int_36845 = int(latch_36866);
			t_sample mul_36850 = (int_36845 * ((t_sample)0.25));
			t_sample floor_36847 = floor(mul_36850);
			t_sample wrap_36840 = wrap(floor_36847, ((int)0), ((int)2));
			t_sample gen_36861 = wrap_36840;
			t_sample sub_40019 = (gen_36861 - m_history_26);
			t_sample add_40017 = (gen_36861 + m_history_26);
			t_sample div_40020 = safediv(sub_40019, add_40017);
			t_sample abs_40018 = fabs(div_40020);
			int gt_40014 = (abs_40018 > ((t_sample)0.5));
			int change_40022 = __m_change_102(gt_40014);
			int gt_40021 = (change_40022 > ((int)0));
			int gen_36882 = gt_40021;
			t_sample history_36753_next_40016 = fixdenorm(gen_36861);
			int gt_40030 = (gen_36882 > ((int)0));
			int change_40028 = __m_change_103(gt_40030);
			int gt_40031 = (change_40028 > ((int)0));
			int plusequals_40026 = __m_pluseq_104.post(((int)1), gt_40031, 0);
			int lte_40027 = (plusequals_40026 <= max_40024);
			t_sample out5 = lte_40027;
			t_sample out6 = lte_40027;
			t_sample sub_40036 = (gen_36882 - m_history_25);
			t_sample add_40034 = (gen_36882 + m_history_25);
			t_sample div_40038 = safediv(sub_40036, add_40034);
			t_sample abs_40035 = fabs(div_40038);
			int gt_40032 = (abs_40035 > ((t_sample)0.5));
			int change_40040 = __m_change_105(gt_40032);
			int gt_40039 = (change_40040 > ((int)0));
			int gen_36759 = gt_40039;
			t_sample history_36753_next_40037 = fixdenorm(gen_36882);
			t_sample plusequals_36749 = __m_pluseq_106.post(safediv(8, samplerate), gen_36759, 0);
			t_sample clamp_36748 = ((plusequals_36749 <= ((int)0)) ? ((int)0) : ((plusequals_36749 >= ((int)1)) ? ((int)1) : plusequals_36749));
			t_sample sub_40817 = (clamp_36748 - ((int)0));
			t_sample scale_40814 = ((safepow((sub_40817 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_36760 = scale_40814;
			t_sample sub_40821 = (scale_36760 - ((int)1));
			t_sample scale_40818 = ((safepow((sub_40821 * ((t_sample)-1)), ((int)1)) * ((int)50)) + ((int)0));
			t_sample scale_36763 = scale_40818;
			t_sample sin_36764 = sin(scale_36763);
			t_sample mul_36765 = (scale_36760 * sin_36764);
			t_sample mix_40822 = (mul_36765 + (((t_sample)0.9) * (m_history_24 - mul_36765)));
			t_sample mix_36762 = mix_40822;
			t_sample gen_36767 = mix_36762;
			t_sample history_36761_next_36766 = fixdenorm(mix_36762);
			int int_40052 = int(latch_36866);
			t_sample mul_40043 = (int_40052 * ((t_sample)0.0625));
			t_sample floor_40050 = floor(mul_40043);
			t_sample wrap_40049 = wrap(floor_40050, ((int)0), ((int)2));
			t_sample gen_36851 = wrap_40049;
			t_sample sub_40056 = (gen_36851 - m_history_23);
			t_sample add_40059 = (gen_36851 + m_history_23);
			t_sample div_40057 = safediv(sub_40056, add_40059);
			t_sample abs_40055 = fabs(div_40057);
			int gt_40053 = (abs_40055 > ((t_sample)0.5));
			int change_40061 = __m_change_107(gt_40053);
			int gt_40060 = (change_40061 > ((int)0));
			int gen_36805 = gt_40060;
			t_sample history_36753_next_40058 = fixdenorm(gen_36851);
			int gt_40069 = (gen_36805 > ((int)0));
			int change_40067 = __m_change_108(gt_40069);
			int gt_40070 = (change_40067 > ((int)0));
			int plusequals_40065 = __m_pluseq_109.post(((int)1), gt_40070, 0);
			int lte_40066 = (plusequals_40065 <= max_40063);
			t_sample out7 = lte_40066;
			t_sample out8 = lte_40066;
			int int_36853 = int(latch_36866);
			int wrap_36857 = wrap(int_36853, ((int)0), ((int)32));
			int gen_36862 = wrap_36857;
			t_sample div_36797 = (gen_36862 * ((t_sample)0.03125));
			t_sample mul_40084 = (div_36797 * ((int)150));
			t_sample sub_40076 = (gen_36882 - m_history_22);
			t_sample add_40088 = (gen_36882 + m_history_22);
			t_sample div_40086 = safediv(sub_40076, add_40088);
			t_sample abs_40075 = fabs(div_40086);
			int gt_40071 = (abs_40075 > ((t_sample)0.5));
			int change_40091 = __m_change_110(gt_40071);
			int gt_40090 = (change_40091 > ((int)0));
			int gen_40082 = gt_40090;
			t_sample history_36753_next_40085 = fixdenorm(gen_36882);
			t_sample plusequals_40073 = __m_pluseq_111.post(safediv(8, samplerate), gen_40082, 0);
			t_sample clamp_40083 = ((plusequals_40073 <= ((int)0)) ? ((int)0) : ((plusequals_40073 >= ((int)1)) ? ((int)1) : plusequals_40073));
			t_sample sub_40826 = (clamp_40083 - ((int)0));
			t_sample scale_40823 = ((safepow((sub_40826 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_40080 = scale_40823;
			t_sample orange_40829 = (((int)50) - mul_40084);
			t_sample sub_40830 = (scale_40080 - ((int)1));
			t_sample scale_40827 = ((safepow((sub_40830 * ((t_sample)-1)), ((int)1)) * orange_40829) + mul_40084);
			t_sample scale_40087 = scale_40827;
			t_sample sin_40079 = sin(scale_40087);
			t_sample mul_40078 = (scale_40080 * sin_40079);
			t_sample mix_40831 = (mul_40078 + (((t_sample)0.9) * (m_history_21 - mul_40078)));
			t_sample mix_40077 = mix_40831;
			t_sample gen_36883 = mix_40077;
			t_sample history_36761_next_40074 = fixdenorm(mix_40077);
			int int_40099 = int(latch_36866);
			int wrap_40096 = wrap(int_40099, ((int)0), ((int)16));
			int gen_36858 = wrap_40096;
			t_sample div_36798 = (gen_36858 * ((t_sample)0.03125));
			t_sample noise_36834 = noise();
			t_sample mix_40832 = (noise_36834 + (((t_sample)0.5) * (m_history_19 - noise_36834)));
			t_sample mix_36810 = mix_40832;
			t_sample mix_40833 = (mix_36810 + (((t_sample)0.6) * (m_history_18 - mix_36810)));
			t_sample mix_36832 = mix_40833;
			t_sample sub_36808 = (mix_36810 - mix_36832);
			t_sample mul_36806 = (div_36798 * ((int)185));
			t_sample phasor_36825 = __m_phasor_112(mul_36806, samples_to_seconds);
			t_sample triangle_36824 = triangle(phasor_36825, ((t_sample)0.5));
			t_sample mul_36807 = (div_36798 * ((int)330));
			t_sample phasor_36827 = __m_phasor_113(mul_36807, samples_to_seconds);
			t_sample triangle_36826 = triangle(phasor_36827, ((t_sample)0.5));
			t_sample sub_40103 = (gen_36805 - m_history_20);
			t_sample add_40105 = (gen_36805 + m_history_20);
			t_sample div_40104 = safediv(sub_40103, add_40105);
			t_sample abs_40106 = fabs(div_40104);
			int gt_40100 = (abs_40106 > ((t_sample)0.5));
			int change_40108 = __m_change_114(gt_40100);
			int gt_40107 = (change_40108 > ((int)0));
			int gen_36830 = gt_40107;
			t_sample history_36753_next_40102 = fixdenorm(gen_36805);
			t_sample plusequals_36823 = __m_pluseq_115.post(safediv(11, samplerate), gen_36830, 0);
			t_sample clamp_36820 = ((plusequals_36823 <= ((int)0)) ? ((int)0) : ((plusequals_36823 >= ((int)1)) ? ((int)1) : plusequals_36823));
			t_sample sub_40837 = (clamp_36820 - ((int)0));
			t_sample scale_40834 = ((safepow((sub_40837 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample scale_36821 = scale_40834;
			t_sample mul_36817 = (scale_36821 * triangle_36824);
			t_sample plusequals_36822 = __m_pluseq_116.post(safediv(8, samplerate), gen_36830, 0);
			t_sample clamp_36818 = ((plusequals_36822 <= ((int)0)) ? ((int)0) : ((plusequals_36822 >= ((int)1)) ? ((int)1) : plusequals_36822));
			t_sample sub_40841 = (clamp_36818 - ((int)0));
			t_sample scale_40838 = ((safepow((sub_40841 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample scale_36819 = scale_40838;
			t_sample mul_36816 = (scale_36819 * mix_36810);
			t_sample plusequals_36814 = __m_pluseq_117.post(safediv(7, samplerate), gen_36830, 0);
			t_sample clamp_36812 = ((plusequals_36814 <= ((int)0)) ? ((int)0) : ((plusequals_36814 >= ((int)1)) ? ((int)1) : plusequals_36814));
			t_sample sub_40845 = (clamp_36812 - ((int)0));
			t_sample scale_40842 = ((safepow((sub_40845 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample scale_36813 = scale_40842;
			t_sample mul_36811 = (scale_36813 * sub_36808);
			t_sample plusequals_36829 = __m_pluseq_118.post(safediv(13, samplerate), gen_36830, 0);
			t_sample clamp_36828 = ((plusequals_36829 <= ((int)0)) ? ((int)0) : ((plusequals_36829 >= ((int)1)) ? ((int)1) : plusequals_36829));
			t_sample sub_40849 = (clamp_36828 - ((int)0));
			t_sample scale_40846 = ((safepow((sub_40849 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample scale_36835 = scale_40846;
			t_sample mul_36833 = (scale_36835 * triangle_36826);
			t_sample v_119 = (((mul_36833 + mul_36811) + mul_36816) + mul_36817);
			t_sample clamp_36815 = ((v_119 <= min_120) ? min_120 : ((v_119 >= ((int)1)) ? ((int)1) : v_119));
			t_sample gen_36838 = clamp_36815;
			t_sample history_36809_next_36836 = fixdenorm(mix_36810);
			t_sample history_36831_next_36837 = fixdenorm(mix_36832);
			t_sample tap_1746 = m_delay_17.read_step(((int)3571));
			t_sample tap_1774 = m_delay_16.read_step(((int)8269));
			t_sample tap_1765 = m_delay_15.read_step(((int)2791));
			t_sample clamp_1738 = ((gen_36780 <= min_121) ? min_121 : ((gen_36780 >= ((t_sample)0.99)) ? ((t_sample)0.99) : gen_36780));
			t_sample gen_1759 = clamp_1738;
			t_sample mul_1744 = (tap_1746 * gen_1759);
			t_sample gen_1787 = clamp_1738;
			t_sample tap_1793 = m_delay_14.read_step(((int)4447));
			t_sample mul_1772 = (tap_1774 * gen_1787);
			t_sample tap_1758 = m_delay_13.read_step(((int)5167));
			t_sample mul_1763 = (tap_1765 * gen_1759);
			t_sample tap_1786 = m_delay_12.read_step(((int)7351));
			t_sample mul_1791 = (tap_1793 * gen_1787);
			t_sample add_40851 = ((((mul_37052 + gen_36767) + gen_36838) + gen_36883) + gen_36941);
			t_sample mix_40850 = (add_40851 + (((t_sample)0.5) * (m_history_9 - add_40851)));
			t_sample mix_1767 = mix_40850;
			t_sample add_1743 = (mix_1767 + mul_1744);
			t_sample mul_1742 = (add_1743 * gen_1759);
			t_sample sub_1741 = (tap_1746 - mul_1742);
			t_sample gen_36886 = sub_1741;
			t_sample add_1762 = (add_1743 + mul_1763);
			t_sample mul_1761 = (add_1762 * gen_1759);
			t_sample sub_1760 = (tap_1765 - mul_1761);
			t_sample add_40853 = ((((gen_36767 + gen_36838) + gen_36883) + gen_36941) + pass_37054);
			t_sample mix_40852 = (add_40853 + (((t_sample)0.5) * (m_history_8 - add_40853)));
			t_sample mix_1796 = mix_40852;
			t_sample add_1771 = (mix_1796 + mul_1772);
			t_sample mul_1770 = (add_1771 * gen_1787);
			t_sample sub_1769 = (tap_1774 - mul_1770);
			t_sample gen_36885 = sub_1769;
			t_sample add_1790 = (add_1771 + mul_1791);
			t_sample mul_1789 = (add_1790 * gen_1787);
			t_sample sub_1788 = (tap_1793 - mul_1789);
			t_sample tap_1752 = m_delay_11.read_step(((int)3469));
			t_sample mul_1756 = (tap_1758 * gen_1759);
			t_sample add_1755 = (add_1762 + mul_1756);
			t_sample mul_1754 = (add_1755 * gen_1759);
			t_sample sub_1753 = (tap_1758 - mul_1754);
			t_sample tap_1780 = m_delay_10.read_step(((int)5419));
			t_sample mul_1784 = (tap_1786 * gen_1787);
			t_sample add_1783 = (add_1790 + mul_1784);
			t_sample mul_1782 = (add_1783 * gen_1787);
			t_sample sub_1781 = (tap_1786 - mul_1782);
			t_sample mul_1750 = (tap_1752 * gen_1759);
			t_sample add_1749 = (add_1755 + mul_1750);
			t_sample mul_1748 = (add_1749 * gen_1759);
			t_sample sub_1747 = (tap_1752 - mul_1748);
			t_sample mul_1778 = (tap_1780 * gen_1787);
			t_sample add_1777 = (add_1783 + mul_1778);
			t_sample mul_1776 = (add_1777 * gen_1787);
			t_sample sub_1775 = (tap_1780 - mul_1776);
			t_sample history_1766_next_1797 = fixdenorm(sub_1741);
			t_sample history_1795_next_1798 = fixdenorm(sub_1769);
			t_sample out2 = gen_36886;
			t_sample out1 = gen_36885;
			t_sample history_36946_next_40110 = fixdenorm(latch_36948);
			t_sample history_36944_next_40111 = fixdenorm(latch_36945);
			t_sample history_36956_next_40112 = fixdenorm(latch_36957);
			t_sample history_36949_next_40113 = fixdenorm(latch_36950);
			t_sample history_36951_next_40114 = fixdenorm(latch_36952);
			t_sample history_36966_next_40115 = fixdenorm(wrap_36965);
			t_sample history_36867_next_40116 = fixdenorm(latch_36866);
			m_history_51 = history_36772_next_36779;
			m_history_50 = history_36753_next_36758;
			m_history_49 = history_37046_next_37048;
			m_history_48 = history_37035_next_37037;
			m_y_47 = y_next_36996;
			m_z_45 = z_next_36998;
			m_x_46 = x_next_36997;
			m_history_44 = history_37004_next_37011;
			m_history_43 = history_37007_next_37012;
			m_history_42 = history_36753_next_39911;
			m_history_39 = history_36909_next_36918;
			m_history_40 = history_36890_next_36917;
			m_history_41 = history_36900_next_36901;
			m_history_38 = history_36753_next_39920;
			m_history_37 = history_36753_next_39936;
			m_history_36 = history_36753_next_39951;
			m_history_33 = history_36909_next_39953;
			m_history_34 = history_36890_next_39960;
			m_history_35 = history_36900_next_39987;
			m_history_32 = history_36753_next_40000;
			m_history_31 = history_36753_next_40010;
			m_history_27 = history_36923_next_36940;
			m_history_28 = history_36927_next_36939;
			m_history_29 = history_36931_next_36938;
			m_history_30 = history_36935_next_36937;
			m_history_26 = history_36753_next_40016;
			m_history_25 = history_36753_next_40037;
			m_history_24 = history_36761_next_36766;
			m_history_23 = history_36753_next_40058;
			m_history_22 = history_36753_next_40085;
			m_history_21 = history_36761_next_40074;
			m_history_20 = history_36753_next_40102;
			m_history_18 = history_36831_next_36837;
			m_history_19 = history_36809_next_36836;
			m_delay_17.write(sub_1760);
			m_history_8 = history_1795_next_1798;
			m_history_9 = history_1766_next_1797;
			m_delay_10.write(add_1777);
			m_delay_11.write(add_1749);
			m_delay_12.write(sub_1775);
			m_delay_13.write(sub_1747);
			m_delay_14.write(sub_1781);
			m_delay_15.write(sub_1753);
			m_delay_16.write(sub_1788);
			m_history_7 = history_36946_next_40110;
			m_history_6 = history_36944_next_40111;
			m_history_5 = history_36956_next_40112;
			m_history_4 = history_36949_next_40113;
			m_history_3 = history_36951_next_40114;
			m_history_2 = history_36966_next_40115;
			m_history_1 = history_36867_next_40116;
			m_delay_10.step();
			m_delay_11.step();
			m_delay_12.step();
			m_delay_13.step();
			m_delay_14.step();
			m_delay_15.step();
			m_delay_16.step();
			m_delay_17.step();
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
	inline void set_sw5(t_param _value) {
		m_sw_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_56 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1(t_param _value) {
		m_knob_58 = (_value < 1 ? 1 : (_value > 500 ? 500 : _value));
	};
	inline void set_knob3(t_param _value) {
		m_knob_59 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6(t_param _value) {
		m_knob_60 = (_value < -0.99 ? -0.99 : (_value > 0.99 ? 0.99 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_61 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5(t_param _value) {
		m_knob_62 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin1(t_param _value) {
		m_cvin_63 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2(t_param _value) {
		m_knob_64 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_65 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_chance(t_param _value) {
		m_chance_66 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4(t_param _value) {
		m_knob_67 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_68 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 17; }

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
		case 0: self->set_chance(value); break;
		case 1: self->set_cvin1(value); break;
		case 2: self->set_gate1(value); break;
		case 3: self->set_knob1(value); break;
		case 4: self->set_knob2(value); break;
		case 5: self->set_knob3(value); break;
		case 6: self->set_knob4(value); break;
		case 7: self->set_knob5(value); break;
		case 8: self->set_knob6(value); break;
		case 9: self->set_sw1(value); break;
		case 10: self->set_sw2(value); break;
		case 11: self->set_sw3(value); break;
		case 12: self->set_sw4(value); break;
		case 13: self->set_sw5(value); break;
		case 14: self->set_sw6(value); break;
		case 15: self->set_sw7(value); break;
		case 16: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_chance_66; break;
		case 1: *value = self->m_cvin_63; break;
		case 2: *value = self->m_gate_68; break;
		case 3: *value = self->m_knob_58; break;
		case 4: *value = self->m_knob_64; break;
		case 5: *value = self->m_knob_59; break;
		case 6: *value = self->m_knob_67; break;
		case 7: *value = self->m_knob_62; break;
		case 8: *value = self->m_knob_60; break;
		case 9: *value = self->m_sw_56; break;
		case 10: *value = self->m_sw_65; break;
		case 11: *value = self->m_sw_57; break;
		case 12: *value = self->m_sw_54; break;
		case 13: *value = self->m_sw_52; break;
		case 14: *value = self->m_sw_55; break;
		case 15: *value = self->m_sw_61; break;
		case 16: *value = self->m_sw_53; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(17 * sizeof(ParamInfo));
	self->__commonstate.numparams = 17;
	// initialize parameter 0 ("m_chance_66")
	pi = self->__commonstate.params + 0;
	pi->name = "chance";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_chance_66;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cvin_63")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_63;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_gate_68")
	pi = self->__commonstate.params + 2;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_68;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob_58")
	pi = self->__commonstate.params + 3;
	pi->name = "knob1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_58;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 500;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob_64")
	pi = self->__commonstate.params + 4;
	pi->name = "knob2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_64;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob_59")
	pi = self->__commonstate.params + 5;
	pi->name = "knob3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_59;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob_67")
	pi = self->__commonstate.params + 6;
	pi->name = "knob4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_67;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob_62")
	pi = self->__commonstate.params + 7;
	pi->name = "knob5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_62;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob_60")
	pi = self->__commonstate.params + 8;
	pi->name = "knob6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_60;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -0.99;
	pi->outputmax = 0.99;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_56")
	pi = self->__commonstate.params + 9;
	pi->name = "sw1";
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
	// initialize parameter 10 ("m_sw_65")
	pi = self->__commonstate.params + 10;
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
	// initialize parameter 11 ("m_sw_57")
	pi = self->__commonstate.params + 11;
	pi->name = "sw3";
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
	// initialize parameter 12 ("m_sw_54")
	pi = self->__commonstate.params + 12;
	pi->name = "sw4";
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
	// initialize parameter 13 ("m_sw_52")
	pi = self->__commonstate.params + 13;
	pi->name = "sw5";
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
	// initialize parameter 14 ("m_sw_55")
	pi = self->__commonstate.params + 14;
	pi->name = "sw6";
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
	// initialize parameter 15 ("m_sw_61")
	pi = self->__commonstate.params + 15;
	pi->name = "sw7";
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
	// initialize parameter 16 ("m_sw_53")
	pi = self->__commonstate.params + 16;
	pi->name = "sw8";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // roaches::
