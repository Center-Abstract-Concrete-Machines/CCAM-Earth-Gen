#include "test.h"

namespace test {

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
	Delay m_delay_14;
	Delay m_delay_18;
	Delay m_delay_19;
	Delay m_delay_20;
	Delay m_delay_17;
	Delay m_delay_15;
	Delay m_delay_16;
	Delay m_delay_30;
	Delay m_delay_34;
	Delay m_delay_23;
	Delay m_delay_27;
	Delay m_delay_33;
	Delay m_delay_26;
	Delay m_delay_24;
	Delay m_delay_25;
	Delay m_delay_28;
	Delay m_delay_13;
	Delay m_delay_36;
	Delay m_delay_37;
	Delay m_delay_3;
	Delay m_delay_38;
	Delay m_delay_40;
	Delay m_delay_39;
	Delay m_delay_35;
	Delay m_delay_4;
	Delay m_delay_6;
	Delay m_delay_10;
	Delay m_delay_5;
	Delay m_delay_9;
	Delay m_delay_7;
	Delay m_delay_8;
	Delay m_delay_29;
	Phasor __m_phasor_67;
	Phasor __m_phasor_66;
	Phasor __m_phasor_55;
	Phasor __m_phasor_63;
	Phasor __m_phasor_59;
	Phasor __m_phasor_58;
	Phasor __m_phasor_54;
	Phasor __m_phasor_62;
	SineCycle __m_cycle_51;
	SineCycle __m_cycle_50;
	SineCycle __m_cycle_52;
	SineCycle __m_cycle_53;
	SineCycle __m_cycle_49;
	SineCycle __m_cycle_61;
	SineCycle __m_cycle_65;
	SineCycle __m_cycle_57;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_am_lfo_amt_48;
	t_sample m_history_11;
	t_sample m_history_12;
	t_sample m_history_21;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_knob_47;
	t_sample m_history_22;
	t_sample samples_to_seconds;
	t_sample m_knob_45;
	t_sample m_knob_46;
	t_sample m_history_31;
	t_sample m_knob_44;
	t_sample m_knob_42;
	t_sample m_knob_43;
	t_sample m_am_lfo_amt_41;
	t_sample m_history_32;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_delay_3.reset("m_delay_3", ((int)5419));
		m_delay_4.reset("m_delay_4", ((int)3469));
		m_delay_5.reset("m_delay_5", ((int)7351));
		m_delay_6.reset("m_delay_6", ((int)5167));
		m_delay_7.reset("m_delay_7", ((int)4447));
		m_delay_8.reset("m_delay_8", ((int)2791));
		m_delay_9.reset("m_delay_9", ((int)8269));
		m_delay_10.reset("m_delay_10", ((int)3571));
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_delay_13.reset("m_delay_13", ((int)5419));
		m_delay_14.reset("m_delay_14", ((int)3469));
		m_delay_15.reset("m_delay_15", ((int)7351));
		m_delay_16.reset("m_delay_16", ((int)5167));
		m_delay_17.reset("m_delay_17", ((int)4447));
		m_delay_18.reset("m_delay_18", ((int)2791));
		m_delay_19.reset("m_delay_19", ((int)8269));
		m_delay_20.reset("m_delay_20", ((int)3571));
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_delay_23.reset("m_delay_23", ((int)5419));
		m_delay_24.reset("m_delay_24", ((int)3469));
		m_delay_25.reset("m_delay_25", ((int)7351));
		m_delay_26.reset("m_delay_26", ((int)5167));
		m_delay_27.reset("m_delay_27", ((int)4447));
		m_delay_28.reset("m_delay_28", ((int)2791));
		m_delay_29.reset("m_delay_29", ((int)8269));
		m_delay_30.reset("m_delay_30", ((int)3571));
		m_history_31 = ((int)0);
		m_history_32 = ((int)0);
		m_delay_33.reset("m_delay_33", ((int)5419));
		m_delay_34.reset("m_delay_34", ((int)3469));
		m_delay_35.reset("m_delay_35", ((int)7351));
		m_delay_36.reset("m_delay_36", ((int)5167));
		m_delay_37.reset("m_delay_37", ((int)4447));
		m_delay_38.reset("m_delay_38", ((int)2791));
		m_delay_39.reset("m_delay_39", ((int)8269));
		m_delay_40.reset("m_delay_40", ((int)3571));
		m_am_lfo_amt_41 = 0.5;
		m_knob_42 = 0.03;
		m_knob_43 = 0.05;
		m_knob_44 = 0.03;
		m_knob_45 = 0.05;
		m_knob_46 = 0.05;
		m_knob_47 = 0.05;
		m_am_lfo_amt_48 = 0.5;
		__m_cycle_49.reset(samplerate, 0);
		__m_cycle_50.reset(samplerate, 0);
		__m_cycle_51.reset(samplerate, 0);
		__m_cycle_52.reset(samplerate, 0);
		__m_cycle_53.reset(samplerate, 0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_54.reset(0);
		__m_phasor_55.reset(0);
		__m_cycle_57.reset(samplerate, 0);
		__m_phasor_58.reset(0);
		__m_phasor_59.reset(0);
		__m_cycle_61.reset(samplerate, 0);
		__m_phasor_62.reset(0);
		__m_phasor_63.reset(0);
		__m_cycle_65.reset(samplerate, 0);
		__m_phasor_66.reset(0);
		__m_phasor_67.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		samples_to_seconds = (1 / samplerate);
		t_sample min_56 = (-0.99);
		t_sample min_60 = (-0.99);
		t_sample min_64 = (-0.99);
		t_sample min_68 = (-0.99);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			__m_cycle_49.freq(m_knob_42);
			t_sample cycle_41268 = __m_cycle_49(__sinedata);
			t_sample cycleindex_41269 = __m_cycle_49.phase();
			t_sample mul_41255 = (cycle_41268 * ((t_sample)0.5));
			__m_cycle_50.freq(m_knob_42);
			t_sample cycle_41250 = __m_cycle_50(__sinedata);
			t_sample cycleindex_41251 = __m_cycle_50.phase();
			t_sample mul_41256 = (cycle_41250 * ((t_sample)0.1));
			__m_cycle_51.freq(m_knob_44);
			t_sample cycle_41232 = __m_cycle_51(__sinedata);
			t_sample cycleindex_41233 = __m_cycle_51.phase();
			t_sample mul_41219 = (cycle_41232 * ((t_sample)0.5));
			__m_cycle_52.freq(m_knob_44);
			t_sample cycle_41214 = __m_cycle_52(__sinedata);
			t_sample cycleindex_41215 = __m_cycle_52.phase();
			t_sample mul_41220 = (cycle_41214 * ((t_sample)0.1));
			__m_cycle_53.freq(m_knob_47);
			t_sample cycle_41265 = __m_cycle_53(__sinedata);
			t_sample cycleindex_41266 = __m_cycle_53.phase();
			t_sample mul_41253 = (cycle_41265 * m_am_lfo_amt_41);
			t_sample add_41254 = (mul_41253 + ((int)1));
			t_sample mul_2077 = (add_41254 * ((t_sample)3.1415926535898));
			t_sample cos_2076 = cos(mul_2077);
			t_sample mul_2075 = (cos_2076 * (-0.46164));
			t_sample add_2074 = (mul_2075 + ((t_sample)0.53836));
			t_sample gen_41272 = add_2074;
			t_sample mul_41271 = (gen_41272 * ((int)10));
			t_sample mul_2095 = (mul_41271 * ((int)1));
			t_sample phasor_2100 = __m_phasor_54(((t_sample)46.24930292312), samples_to_seconds);
			t_sample mul_2101 = (phasor_2100 * ((t_sample)6.2831853071796));
			t_sample phasor_2097 = __m_phasor_55(((t_sample)46.24930292312), samples_to_seconds);
			t_sample mul_2098 = (phasor_2097 * ((t_sample)6.2831853071796));
			t_sample sin_2099 = sin(mul_2098);
			t_sample mul_2102 = (sin_2099 * mul_2095);
			t_sample sin_2104 = sin((mul_2101 + mul_2102));
			t_sample mul_2094 = (sin_2104 * add_41254);
			t_sample gen_41276 = mul_2094;
			t_sample tap_1746 = m_delay_40.read_step(((int)3571));
			t_sample tap_1774 = m_delay_39.read_step(((int)8269));
			t_sample tap_1765 = m_delay_38.read_step(((int)2791));
			t_sample clamp_1738 = ((mul_41255 <= min_56) ? min_56 : ((mul_41255 >= ((t_sample)0.99)) ? ((t_sample)0.99) : mul_41255));
			t_sample gen_1759 = clamp_1738;
			t_sample mul_1744 = (tap_1746 * gen_1759);
			t_sample gen_1787 = clamp_1738;
			t_sample tap_1793 = m_delay_37.read_step(((int)4447));
			t_sample mul_1772 = (tap_1774 * gen_1787);
			t_sample tap_1758 = m_delay_36.read_step(((int)5167));
			t_sample mul_1763 = (tap_1765 * gen_1759);
			t_sample tap_1786 = m_delay_35.read_step(((int)7351));
			t_sample mul_1791 = (tap_1793 * gen_1787);
			t_sample mix_48132 = (gen_41276 + (((t_sample)0.7) * (m_history_32 - gen_41276)));
			t_sample mix_1767 = mix_48132;
			t_sample add_1743 = (mix_1767 + mul_1744);
			t_sample mul_1742 = (add_1743 * gen_1759);
			t_sample sub_1741 = (tap_1746 - mul_1742);
			t_sample gen_41274 = sub_1741;
			t_sample add_1762 = (add_1743 + mul_1763);
			t_sample mul_1761 = (add_1762 * gen_1759);
			t_sample sub_1760 = (tap_1765 - mul_1761);
			t_sample mix_48133 = (gen_41276 + (((t_sample)0.7) * (m_history_31 - gen_41276)));
			t_sample mix_1796 = mix_48133;
			t_sample add_1771 = (mix_1796 + mul_1772);
			t_sample mul_1770 = (add_1771 * gen_1787);
			t_sample sub_1769 = (tap_1774 - mul_1770);
			t_sample gen_41273 = sub_1769;
			t_sample add_1790 = (add_1771 + mul_1791);
			t_sample mul_1789 = (add_1790 * gen_1787);
			t_sample sub_1788 = (tap_1793 - mul_1789);
			t_sample tap_1752 = m_delay_34.read_step(((int)3469));
			t_sample mul_1756 = (tap_1758 * gen_1759);
			t_sample add_1755 = (add_1762 + mul_1756);
			t_sample mul_1754 = (add_1755 * gen_1759);
			t_sample sub_1753 = (tap_1758 - mul_1754);
			t_sample tap_1780 = m_delay_33.read_step(((int)5419));
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
			t_sample mul_45650 = (gen_41274 * ((t_sample)0.25));
			t_sample mul_45301 = (gen_41273 * ((t_sample)0.25));
			__m_cycle_57.freq(m_knob_46);
			t_sample cycle_41248 = __m_cycle_57(__sinedata);
			t_sample cycleindex_41249 = __m_cycle_57.phase();
			t_sample mul_41246 = (cycle_41248 * m_am_lfo_amt_48);
			t_sample add_41247 = (mul_41246 + ((int)1));
			t_sample mul_47745 = (add_41247 * ((t_sample)3.1415926535898));
			t_sample cos_47746 = cos(mul_47745);
			t_sample mul_47747 = (cos_47746 * (-0.46164));
			t_sample add_47748 = (mul_47747 + ((t_sample)0.53836));
			t_sample gen_41259 = add_47748;
			t_sample mul_41258 = (gen_41259 * ((int)10));
			t_sample mul_47758 = (mul_41258 * ((int)1));
			t_sample phasor_47755 = __m_phasor_58(((t_sample)164.81377858717), samples_to_seconds);
			t_sample mul_47751 = (phasor_47755 * ((t_sample)6.2831853071796));
			t_sample phasor_47750 = __m_phasor_59(((t_sample)164.81377858717), samples_to_seconds);
			t_sample mul_47753 = (phasor_47750 * ((t_sample)6.2831853071796));
			t_sample sin_47763 = sin(mul_47753);
			t_sample mul_47760 = (sin_47763 * mul_47758);
			t_sample sin_47756 = sin((mul_47751 + mul_47760));
			t_sample mul_47754 = (sin_47756 * add_41247);
			t_sample gen_41263 = mul_47754;
			t_sample tap_47789 = m_delay_30.read_step(((int)3571));
			t_sample tap_47784 = m_delay_29.read_step(((int)8269));
			t_sample tap_47779 = m_delay_28.read_step(((int)2791));
			t_sample clamp_47781 = ((mul_41256 <= min_60) ? min_60 : ((mul_41256 >= ((t_sample)0.99)) ? ((t_sample)0.99) : mul_41256));
			t_sample gen_47802 = clamp_47781;
			t_sample mul_47819 = (tap_47789 * gen_47802);
			t_sample gen_47824 = clamp_47781;
			t_sample tap_47787 = m_delay_27.read_step(((int)4447));
			t_sample mul_47796 = (tap_47784 * gen_47824);
			t_sample tap_47816 = m_delay_26.read_step(((int)5167));
			t_sample mul_47799 = (tap_47779 * gen_47802);
			t_sample tap_47778 = m_delay_25.read_step(((int)7351));
			t_sample mul_47771 = (tap_47787 * gen_47824);
			t_sample mix_48134 = (gen_41263 + (((t_sample)0.3) * (m_history_22 - gen_41263)));
			t_sample mix_47770 = mix_48134;
			t_sample add_47815 = (mix_47770 + mul_47819);
			t_sample mul_47785 = (add_47815 * gen_47802);
			t_sample sub_47782 = (tap_47789 - mul_47785);
			t_sample gen_41261 = sub_47782;
			t_sample add_47773 = (add_47815 + mul_47799);
			t_sample mul_47807 = (add_47773 * gen_47802);
			t_sample sub_47798 = (tap_47779 - mul_47807);
			t_sample mix_48135 = (gen_41263 + (((t_sample)0.3) * (m_history_21 - gen_41263)));
			t_sample mix_47768 = mix_48135;
			t_sample add_47791 = (mix_47768 + mul_47796);
			t_sample mul_47788 = (add_47791 * gen_47824);
			t_sample sub_47810 = (tap_47784 - mul_47788);
			t_sample gen_41260 = sub_47810;
			t_sample add_47792 = (add_47791 + mul_47771);
			t_sample mul_47803 = (add_47792 * gen_47824);
			t_sample sub_47806 = (tap_47787 - mul_47803);
			t_sample tap_47774 = m_delay_24.read_step(((int)3469));
			t_sample mul_47823 = (tap_47816 * gen_47802);
			t_sample add_47822 = (add_47773 + mul_47823);
			t_sample mul_47783 = (add_47822 * gen_47802);
			t_sample sub_47793 = (tap_47816 - mul_47783);
			t_sample tap_47777 = m_delay_23.read_step(((int)5419));
			t_sample mul_47821 = (tap_47778 * gen_47824);
			t_sample add_47765 = (add_47792 + mul_47821);
			t_sample mul_47809 = (add_47765 * gen_47824);
			t_sample sub_47776 = (tap_47778 - mul_47809);
			t_sample mul_47766 = (tap_47774 * gen_47802);
			t_sample add_47790 = (add_47822 + mul_47766);
			t_sample mul_47786 = (add_47790 * gen_47802);
			t_sample sub_47794 = (tap_47774 - mul_47786);
			t_sample mul_47817 = (tap_47777 * gen_47824);
			t_sample add_47800 = (add_47765 + mul_47817);
			t_sample mul_47814 = (add_47800 * gen_47824);
			t_sample sub_47804 = (tap_47777 - mul_47814);
			t_sample history_1766_next_47811 = fixdenorm(sub_47782);
			t_sample history_1795_next_47820 = fixdenorm(sub_47810);
			t_sample mul_46348 = (gen_41261 * ((t_sample)0.25));
			t_sample mul_45999 = (gen_41260 * ((t_sample)0.25));
			__m_cycle_61.freq(m_knob_43);
			t_sample cycle_41229 = __m_cycle_61(__sinedata);
			t_sample cycleindex_41230 = __m_cycle_61.phase();
			t_sample mul_41217 = (cycle_41229 * m_am_lfo_amt_41);
			t_sample add_41218 = (mul_41217 + ((int)1));
			t_sample mul_47836 = (add_41218 * ((t_sample)3.1415926535898));
			t_sample cos_47837 = cos(mul_47836);
			t_sample mul_47838 = (cos_47837 * (-0.46164));
			t_sample add_47835 = (mul_47838 + ((t_sample)0.53836));
			t_sample gen_41236 = add_47835;
			t_sample mul_41235 = (gen_41236 * ((int)10));
			t_sample mul_47845 = (mul_41235 * ((int)1));
			t_sample phasor_47843 = __m_phasor_62(((t_sample)82.406889339731), samples_to_seconds);
			t_sample mul_47848 = (phasor_47843 * ((t_sample)6.2831853071796));
			t_sample phasor_47840 = __m_phasor_63(((t_sample)82.406889339731), samples_to_seconds);
			t_sample mul_47849 = (phasor_47840 * ((t_sample)6.2831853071796));
			t_sample sin_47852 = sin(mul_47849);
			t_sample mul_47839 = (sin_47852 * mul_47845);
			t_sample sin_47844 = sin((mul_47848 + mul_47839));
			t_sample mul_47842 = (sin_47844 * add_41218);
			t_sample gen_41240 = mul_47842;
			t_sample tap_47913 = m_delay_20.read_step(((int)3571));
			t_sample tap_47891 = m_delay_19.read_step(((int)8269));
			t_sample tap_47869 = m_delay_18.read_step(((int)2791));
			t_sample clamp_47871 = ((mul_41219 <= min_64) ? min_64 : ((mul_41219 >= ((t_sample)0.99)) ? ((t_sample)0.99) : mul_41219));
			t_sample gen_47892 = clamp_47871;
			t_sample mul_47908 = (tap_47913 * gen_47892);
			t_sample gen_47914 = clamp_47871;
			t_sample tap_47876 = m_delay_17.read_step(((int)4447));
			t_sample mul_47885 = (tap_47891 * gen_47914);
			t_sample tap_47884 = m_delay_16.read_step(((int)5167));
			t_sample mul_47889 = (tap_47869 * gen_47892);
			t_sample tap_47868 = m_delay_15.read_step(((int)7351));
			t_sample mul_47861 = (tap_47876 * gen_47914);
			t_sample mix_48136 = (gen_41240 + (((t_sample)0.7) * (m_history_12 - gen_41240)));
			t_sample mix_47860 = mix_48136;
			t_sample add_47904 = (mix_47860 + mul_47908);
			t_sample mul_47874 = (add_47904 * gen_47892);
			t_sample sub_47872 = (tap_47913 - mul_47874);
			t_sample gen_41238 = sub_47872;
			t_sample add_47863 = (add_47904 + mul_47889);
			t_sample mul_47898 = (add_47863 * gen_47892);
			t_sample sub_47888 = (tap_47869 - mul_47898);
			t_sample mix_48137 = (gen_41240 + (((t_sample)0.7) * (m_history_11 - gen_41240)));
			t_sample mix_47858 = mix_48137;
			t_sample add_47906 = (mix_47858 + mul_47885);
			t_sample mul_47877 = (add_47906 * gen_47914);
			t_sample sub_47901 = (tap_47891 - mul_47877);
			t_sample gen_41237 = sub_47901;
			t_sample add_47880 = (add_47906 + mul_47861);
			t_sample mul_47893 = (add_47880 * gen_47914);
			t_sample sub_47897 = (tap_47876 - mul_47893);
			t_sample tap_47864 = m_delay_14.read_step(((int)3469));
			t_sample mul_47912 = (tap_47884 * gen_47892);
			t_sample add_47911 = (add_47863 + mul_47912);
			t_sample mul_47873 = (add_47911 * gen_47892);
			t_sample sub_47881 = (tap_47884 - mul_47873);
			t_sample tap_47867 = m_delay_13.read_step(((int)5419));
			t_sample mul_47896 = (tap_47868 * gen_47914);
			t_sample add_47855 = (add_47880 + mul_47896);
			t_sample mul_47900 = (add_47855 * gen_47914);
			t_sample sub_47866 = (tap_47868 - mul_47900);
			t_sample mul_47856 = (tap_47864 * gen_47892);
			t_sample add_47878 = (add_47911 + mul_47856);
			t_sample mul_47875 = (add_47878 * gen_47892);
			t_sample sub_47882 = (tap_47864 - mul_47875);
			t_sample mul_47907 = (tap_47867 * gen_47914);
			t_sample add_47910 = (add_47855 + mul_47907);
			t_sample mul_47887 = (add_47910 * gen_47914);
			t_sample sub_47894 = (tap_47867 - mul_47887);
			t_sample history_1766_next_47909 = fixdenorm(sub_47872);
			t_sample history_1795_next_47879 = fixdenorm(sub_47901);
			t_sample mul_47046 = (gen_41238 * ((t_sample)0.25));
			t_sample mul_46697 = (gen_41237 * ((t_sample)0.25));
			__m_cycle_65.freq(m_knob_45);
			t_sample cycle_41212 = __m_cycle_65(__sinedata);
			t_sample cycleindex_41213 = __m_cycle_65.phase();
			t_sample mul_41210 = (cycle_41212 * m_am_lfo_amt_48);
			t_sample add_41211 = (mul_41210 + ((int)1));
			t_sample mul_47926 = (add_41211 * ((t_sample)3.1415926535898));
			t_sample cos_47927 = cos(mul_47926);
			t_sample mul_47928 = (cos_47927 * (-0.46164));
			t_sample add_47925 = (mul_47928 + ((t_sample)0.53836));
			t_sample gen_41223 = add_47925;
			t_sample mul_41222 = (gen_41223 * ((int)10));
			t_sample mul_47942 = (mul_41222 * ((int)1));
			t_sample phasor_47937 = __m_phasor_66(((t_sample)207.65234891594), samples_to_seconds);
			t_sample mul_47943 = (phasor_47937 * ((t_sample)6.2831853071796));
			t_sample phasor_47936 = __m_phasor_67(((t_sample)207.65234891594), samples_to_seconds);
			t_sample mul_47939 = (phasor_47936 * ((t_sample)6.2831853071796));
			t_sample sin_47935 = sin(mul_47939);
			t_sample mul_47938 = (sin_47935 * mul_47942);
			t_sample sin_47930 = sin((mul_47943 + mul_47938));
			t_sample mul_47929 = (sin_47930 * add_41211);
			t_sample gen_41227 = mul_47929;
			t_sample tap_47956 = m_delay_10.read_step(((int)3571));
			t_sample tap_47982 = m_delay_9.read_step(((int)8269));
			t_sample tap_47950 = m_delay_8.read_step(((int)2791));
			t_sample clamp_47951 = ((mul_41220 <= min_68) ? min_68 : ((mul_41220 >= ((t_sample)0.99)) ? ((t_sample)0.99) : mul_41220));
			t_sample gen_47994 = clamp_47951;
			t_sample mul_47974 = (tap_47956 * gen_47994);
			t_sample gen_48003 = clamp_47951;
			t_sample tap_47954 = m_delay_7.read_step(((int)4447));
			t_sample mul_47990 = (tap_47982 * gen_48003);
			t_sample tap_48002 = m_delay_6.read_step(((int)5167));
			t_sample mul_47962 = (tap_47950 * gen_47994);
			t_sample tap_47981 = m_delay_5.read_step(((int)7351));
			t_sample mul_47997 = (tap_47954 * gen_48003);
			t_sample mix_48138 = (gen_41227 + (((t_sample)0.3) * (m_history_2 - gen_41227)));
			t_sample mix_47945 = mix_48138;
			t_sample add_47988 = (mix_47945 + mul_47974);
			t_sample mul_47983 = (add_47988 * gen_47994);
			t_sample sub_47952 = (tap_47956 - mul_47983);
			t_sample gen_41225 = sub_47952;
			t_sample add_47998 = (add_47988 + mul_47962);
			t_sample mul_47996 = (add_47998 * gen_47994);
			t_sample sub_47961 = (tap_47950 - mul_47996);
			t_sample mix_48139 = (gen_41227 + (((t_sample)0.3) * (m_history_1 - gen_41227)));
			t_sample mix_47978 = mix_48139;
			t_sample add_48001 = (mix_47978 + mul_47990);
			t_sample mul_47955 = (add_48001 * gen_48003);
			t_sample sub_48000 = (tap_47982 - mul_47955);
			t_sample gen_41224 = sub_48000;
			t_sample add_47958 = (add_48001 + mul_47997);
			t_sample mul_47993 = (add_47958 * gen_48003);
			t_sample sub_47967 = (tap_47954 - mul_47993);
			t_sample tap_47947 = m_delay_4.read_step(((int)3469));
			t_sample mul_47970 = (tap_48002 * gen_47994);
			t_sample add_47948 = (add_47998 + mul_47970);
			t_sample mul_47953 = (add_47948 * gen_47994);
			t_sample sub_47987 = (tap_48002 - mul_47953);
			t_sample tap_47949 = m_delay_3.read_step(((int)5419));
			t_sample mul_47985 = (tap_47981 * gen_48003);
			t_sample add_47976 = (add_47958 + mul_47985);
			t_sample mul_47969 = (add_47976 * gen_48003);
			t_sample sub_47999 = (tap_47981 - mul_47969);
			t_sample mul_47977 = (tap_47947 * gen_47994);
			t_sample add_47986 = (add_47948 + mul_47977);
			t_sample mul_47984 = (add_47986 * gen_47994);
			t_sample sub_47959 = (tap_47947 - mul_47984);
			t_sample mul_47973 = (tap_47949 * gen_48003);
			t_sample add_47963 = (add_47976 + mul_47973);
			t_sample mul_47960 = (add_47963 * gen_48003);
			t_sample sub_47965 = (tap_47949 - mul_47960);
			t_sample history_1766_next_48004 = fixdenorm(sub_47952);
			t_sample history_1795_next_47957 = fixdenorm(sub_48000);
			t_sample mul_47744 = (gen_41225 * ((t_sample)0.25));
			t_sample out2 = (((mul_47744 + mul_47046) + mul_46348) + mul_45650);
			t_sample mul_47395 = (gen_41224 * ((t_sample)0.25));
			t_sample out1 = (((mul_47395 + mul_46697) + mul_45999) + mul_45301);
			m_delay_40.write(sub_1760);
			m_history_31 = history_1795_next_1798;
			m_history_32 = history_1766_next_1797;
			m_delay_33.write(add_1777);
			m_delay_34.write(add_1749);
			m_delay_35.write(sub_1775);
			m_delay_36.write(sub_1747);
			m_delay_37.write(sub_1781);
			m_delay_38.write(sub_1753);
			m_delay_39.write(sub_1788);
			m_delay_30.write(sub_47798);
			m_history_21 = history_1795_next_47820;
			m_history_22 = history_1766_next_47811;
			m_delay_23.write(add_47800);
			m_delay_24.write(add_47790);
			m_delay_25.write(sub_47804);
			m_delay_26.write(sub_47794);
			m_delay_27.write(sub_47776);
			m_delay_28.write(sub_47793);
			m_delay_29.write(sub_47806);
			m_delay_20.write(sub_47888);
			m_history_11 = history_1795_next_47879;
			m_history_12 = history_1766_next_47909;
			m_delay_13.write(add_47910);
			m_delay_14.write(add_47878);
			m_delay_15.write(sub_47894);
			m_delay_16.write(sub_47882);
			m_delay_17.write(sub_47866);
			m_delay_18.write(sub_47881);
			m_delay_19.write(sub_47897);
			m_delay_10.write(sub_47961);
			m_history_1 = history_1795_next_47957;
			m_history_2 = history_1766_next_48004;
			m_delay_3.write(add_47963);
			m_delay_4.write(add_47986);
			m_delay_5.write(sub_47965);
			m_delay_6.write(sub_47959);
			m_delay_7.write(sub_47999);
			m_delay_8.write(sub_47987);
			m_delay_9.write(sub_47967);
			m_delay_3.step();
			m_delay_4.step();
			m_delay_5.step();
			m_delay_6.step();
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_10.step();
			m_delay_13.step();
			m_delay_14.step();
			m_delay_15.step();
			m_delay_16.step();
			m_delay_17.step();
			m_delay_18.step();
			m_delay_19.step();
			m_delay_20.step();
			m_delay_23.step();
			m_delay_24.step();
			m_delay_25.step();
			m_delay_26.step();
			m_delay_27.step();
			m_delay_28.step();
			m_delay_29.step();
			m_delay_30.step();
			m_delay_33.step();
			m_delay_34.step();
			m_delay_35.step();
			m_delay_36.step();
			m_delay_37.step();
			m_delay_38.step();
			m_delay_39.step();
			m_delay_40.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_am_lfo_amt1(t_param _value) {
		m_am_lfo_amt_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob_3(t_param _value) {
		m_knob_42 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob_4(t_param _value) {
		m_knob_43 = (_value < 0.01 ? 0.01 : (_value > 8 ? 8 : _value));
	};
	inline void set_knob_6(t_param _value) {
		m_knob_44 = (_value < 0 ? 0 : (_value > 2 ? 2 : _value));
	};
	inline void set_knob_5(t_param _value) {
		m_knob_45 = (_value < 0.01 ? 0.01 : (_value > 8 ? 8 : _value));
	};
	inline void set_knob_2(t_param _value) {
		m_knob_46 = (_value < 0.01 ? 0.01 : (_value > 8 ? 8 : _value));
	};
	inline void set_knob_1(t_param _value) {
		m_knob_47 = (_value < 0.01 ? 0.01 : (_value > 8 ? 8 : _value));
	};
	inline void set_am_lfo_amt2(t_param _value) {
		m_am_lfo_amt_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 8; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

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
		case 0: self->set_am_lfo_amt1(value); break;
		case 1: self->set_am_lfo_amt2(value); break;
		case 2: self->set_knob_1(value); break;
		case 3: self->set_knob_2(value); break;
		case 4: self->set_knob_3(value); break;
		case 5: self->set_knob_4(value); break;
		case 6: self->set_knob_5(value); break;
		case 7: self->set_knob_6(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_am_lfo_amt_41; break;
		case 1: *value = self->m_am_lfo_amt_48; break;
		case 2: *value = self->m_knob_47; break;
		case 3: *value = self->m_knob_46; break;
		case 4: *value = self->m_knob_42; break;
		case 5: *value = self->m_knob_43; break;
		case 6: *value = self->m_knob_45; break;
		case 7: *value = self->m_knob_44; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(8 * sizeof(ParamInfo));
	self->__commonstate.numparams = 8;
	// initialize parameter 0 ("m_am_lfo_amt_41")
	pi = self->__commonstate.params + 0;
	pi->name = "am_lfo_amt1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_am_lfo_amt_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_am_lfo_amt_48")
	pi = self->__commonstate.params + 1;
	pi->name = "am_lfo_amt2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_am_lfo_amt_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob_47")
	pi = self->__commonstate.params + 2;
	pi->name = "knob_1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 8;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob_46")
	pi = self->__commonstate.params + 3;
	pi->name = "knob_2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_46;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 8;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob_42")
	pi = self->__commonstate.params + 4;
	pi->name = "knob_3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_42;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob_43")
	pi = self->__commonstate.params + 5;
	pi->name = "knob_4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_43;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 8;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob_45")
	pi = self->__commonstate.params + 6;
	pi->name = "knob_5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_45;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.01;
	pi->outputmax = 8;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob_44")
	pi = self->__commonstate.params + 7;
	pi->name = "knob_6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 2;
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


} // test::
