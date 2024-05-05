#include "KHAIROS.h"

namespace KHAIROS {

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
	Change __m_change_95;
	Change __m_change_61;
	Change __m_change_139;
	Change __m_change_60;
	Change __m_change_141;
	Change __m_change_132;
	Change __m_change_63;
	Change __m_change_62;
	Change __m_change_64;
	Change __m_change_96;
	Change __m_change_65;
	Change __m_change_143;
	Change __m_change_89;
	Change __m_change_59;
	Change __m_change_153;
	Change __m_change_158;
	Change __m_change_58;
	Change __m_change_148;
	Data m_hihat_hit_values_37;
	Data m_kick_array_53;
	Data m_snare_array_35;
	Data m_hihat_array_57;
	Data m_snare_patterns_54;
	Data m_hihat_patterns_31;
	Data m_noise_array_51;
	Data m_grid_matrix_noise_48;
	Data m_snare_hit_values_50;
	Delta __m_delta_142;
	Delta __m_delta_152;
	Delta __m_delta_157;
	Delta __m_delta_131;
	Delta __m_delta_147;
	Delta __m_delta_94;
	Phasor __m_phasor_93;
	Phasor __m_phasor_91;
	Phasor __m_phasor_92;
	Phasor __m_phasor_130;
	Phasor __m_phasor_138;
	PlusEquals __m_pluseq_161;
	PlusEquals __m_pluseq_160;
	PlusEquals __m_pluseq_154;
	PlusEquals __m_pluseq_149;
	PlusEquals __m_pluseq_159;
	PlusEquals __m_pluseq_140;
	PlusEquals __m_pluseq_162;
	int __exception;
	int vectorsize;
	int __loopcount;
	t_sample m_hit_1_hihat_14;
	t_sample __m_carry_135;
	t_sample m_hit_2_hihat_13;
	t_sample m_hit_4_hihat_11;
	t_sample m_hit_3_hihat_12;
	t_sample __m_count_133;
	t_sample m_hit_8_snare_15;
	t_sample m_hit_7_snare_16;
	t_sample m_hit_5_snare_18;
	t_sample m_hit_5_hihat_10;
	t_sample __m_latch_129;
	t_sample m_hit_6_snare_17;
	t_sample m_hit_4_snare_19;
	t_sample m_hit_6_hihat_9;
	t_sample __m_latch_146;
	t_sample __m_latch_156;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample __m_count_144;
	t_sample m_history_4;
	t_sample __m_latch_151;
	t_sample m_hit_7_hihat_8;
	t_sample m_history_5;
	t_sample m_hit_8_hihat_7;
	t_sample m_history_6;
	t_sample m_hit_3_snare_20;
	t_sample m_hit_2_snare_21;
	t_sample m_hit_1_snare_22;
	t_sample m_bpm_52;
	t_sample m_led_39;
	t_sample m_sw_38;
	t_sample m_sw_55;
	t_sample m_sw_36;
	t_sample m_sw_56;
	t_sample m_led_40;
	t_sample m_led_41;
	t_sample m_led_44;
	t_sample m_Y_49;
	t_sample m_led_45;
	t_sample m_X_47;
	t_sample m_led_46;
	t_sample m_led_42;
	t_sample m_density_hihat_34;
	t_sample m_density_snare_32;
	t_sample m_mix_24;
	t_sample elapsed;
	t_sample __m_latch_90;
	t_sample m_history_23;
	t_sample samples_to_seconds;
	t_sample m_swing_33;
	t_sample m_sw_25;
	t_sample m_cv_27;
	t_sample m_sw_30;
	t_sample m_sw_26;
	t_sample m_gatein_29;
	t_sample m_sw_28;
	t_sample m_led_43;
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
		m_hit_8_hihat_7 = ((int)0);
		m_hit_7_hihat_8 = ((int)0);
		m_hit_6_hihat_9 = ((int)0);
		m_hit_5_hihat_10 = ((int)0);
		m_hit_4_hihat_11 = ((int)0);
		m_hit_3_hihat_12 = ((int)0);
		m_hit_2_hihat_13 = ((int)0);
		m_hit_1_hihat_14 = ((int)0);
		m_hit_8_snare_15 = ((int)0);
		m_hit_7_snare_16 = ((int)0);
		m_hit_6_snare_17 = ((int)0);
		m_hit_5_snare_18 = ((int)0);
		m_hit_4_snare_19 = ((int)0);
		m_hit_3_snare_20 = ((int)0);
		m_hit_2_snare_21 = ((int)0);
		m_hit_1_snare_22 = ((int)0);
		m_history_23 = ((int)0);
		m_mix_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_sw_26 = ((int)0);
		m_cv_27 = ((int)0);
		m_sw_28 = ((int)0);
		m_gatein_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_hihat_patterns_31.reset("hihat_patterns", ((int)8), ((int)64));
		m_density_snare_32 = ((int)1);
		m_swing_33 = ((int)0);
		m_density_hihat_34 = ((int)1);
		m_snare_array_35.reset("snare_array", ((int)8), ((int)2));
		m_sw_36 = ((int)0);
		m_hihat_hit_values_37.reset("hihat_hit_values", ((int)8), ((int)64));
		m_sw_38 = ((int)0);
		m_led_39 = ((int)0);
		m_led_40 = ((int)0);
		m_led_41 = ((int)0);
		m_led_42 = ((int)0);
		m_led_43 = ((int)0);
		m_led_44 = ((int)0);
		m_led_45 = ((int)0);
		m_led_46 = ((int)0);
		m_X_47 = ((int)0);
		m_grid_matrix_noise_48.reset("grid_matrix_noise", ((int)64), ((int)1));
		m_Y_49 = ((int)0);
		m_snare_hit_values_50.reset("snare_hit_values", ((int)8), ((int)64));
		m_noise_array_51.reset("noise_array", ((int)48000), ((int)1));
		m_bpm_52 = ((int)0);
		m_kick_array_53.reset("kick_array", ((int)8), ((int)1));
		m_snare_patterns_54.reset("snare_patterns", ((int)8), ((int)64));
		m_sw_55 = ((int)0);
		m_sw_56 = ((int)0);
		m_hihat_array_57.reset("hihat_array", ((int)8), ((int)2));
		__m_change_58.reset(0);
		__m_change_59.reset(0);
		__m_change_60.reset(0);
		__m_change_61.reset(0);
		__m_change_62.reset(0);
		__m_change_63.reset(0);
		__m_change_64.reset(0);
		__m_change_65.reset(0);
		elapsed = 0;
		__m_change_89.reset(0);
		__m_latch_90 = 11025;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_91.reset(0);
		__m_phasor_92.reset(0);
		__m_phasor_93.reset(0);
		__m_delta_94.reset(0);
		__m_change_95.reset(0);
		__m_change_96.reset(0);
		__m_latch_129 = 0;
		__m_phasor_130.reset(0);
		__m_delta_131.reset(0);
		__m_change_132.reset(0);
		__m_count_133 = 0;
		__m_carry_135 = 0;
		__m_phasor_138.reset(0);
		__m_change_139.reset(0);
		__m_pluseq_140.reset(0);
		__m_change_141.reset(0);
		__m_delta_142.reset(0);
		__m_change_143.reset(0);
		__m_count_144 = 0;
		__m_latch_146 = 0;
		__m_delta_147.reset(0);
		__m_change_148.reset(0);
		__m_pluseq_149.reset(0);
		__m_latch_151 = 0;
		__m_delta_152.reset(0);
		__m_change_153.reset(0);
		__m_pluseq_154.reset(0);
		__m_latch_156 = 0;
		__m_delta_157.reset(0);
		__m_change_158.reset(0);
		__m_pluseq_159.reset(0);
		__m_pluseq_160.reset(0);
		__m_pluseq_161.reset(0);
		__m_pluseq_162.reset(0);
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
		t_sample * __out15 = __outs[14];
		t_sample * __out16 = __outs[15];
		t_sample * __out17 = __outs[16];
		t_sample * __out18 = __outs[17];
		t_sample * __out19 = __outs[18];
		t_sample * __out20 = __outs[19];
		t_sample * __out21 = __outs[20];
		t_sample * __out22 = __outs[21];
		t_sample * __out23 = __outs[22];
		t_sample * __out24 = __outs[23];
		t_sample * __out25 = __outs[24];
		t_sample * __out26 = __outs[25];
		t_sample * __out27 = __outs[26];
		t_sample * __out28 = __outs[27];
		t_sample * __out29 = __outs[28];
		t_sample * __out30 = __outs[29];
		t_sample * __out31 = __outs[30];
		t_sample * __out32 = __outs[31];
		t_sample * __out33 = __outs[32];
		t_sample * __out34 = __outs[33];
		t_sample * __out35 = __outs[34];
		t_sample * __out36 = __outs[35];
		t_sample * __out37 = __outs[36];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) || (__out15 == 0) || (__out16 == 0) || (__out17 == 0) || (__out18 == 0) || (__out19 == 0) || (__out20 == 0) || (__out21 == 0) || (__out22 == 0) || (__out23 == 0) || (__out24 == 0) || (__out25 == 0) || (__out26 == 0) || (__out27 == 0) || (__out28 == 0) || (__out29 == 0) || (__out30 == 0) || (__out31 == 0) || (__out32 == 0) || (__out33 == 0) || (__out34 == 0) || (__out35 == 0) || (__out36 == 0) || (__out37 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		t_sample sub_20909 = (m_X_47 - ((int)0));
		t_sample scale_20906 = ((safepow((sub_20909 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_20555 = round(scale_20906);
		t_sample sub_20913 = (m_Y_49 - ((int)0));
		t_sample scale_20910 = ((safepow((sub_20913 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_20556 = round(scale_20910);
		int gt_20326 = (m_gatein_29 > ((int)0));
		samples_to_seconds = (1 / samplerate);
		int gt_20316 = (m_bpm_52 > ((t_sample)0.01));
		t_sample sub_20920 = (m_bpm_52 - ((int)0));
		t_sample scale_20917 = ((safepow((sub_20920 * ((t_sample)1)), ((int)1)) * ((int)460)) + ((int)40));
		t_sample scale_20450 = scale_20917;
		t_sample sub_20925 = (m_swing_33 - ((int)0));
		t_sample scale_20922 = ((safepow((sub_20925 * ((t_sample)1)), ((int)1)) * ((t_sample)0.25)) + ((t_sample)0.5));
		t_sample scale_20364 = scale_20922;
		t_sample clamp_20376 = ((scale_20364 <= ((int)0)) ? ((int)0) : ((scale_20364 >= ((int)1)) ? ((int)1) : scale_20364));
		t_sample rsub_20373 = (((int)1) - clamp_20376);
		t_sample irange_20927 = (rsub_20373 - ((int)0));
		t_sample irange_20931 = (((int)1) - rsub_20373);
		t_sample mstosamps_20338 = (((int)1) * (samplerate * 0.001));
		t_sample max_20339 = ((mstosamps_20338 < vectorsize) ? vectorsize : mstosamps_20338);
		int grid_matrix_noise_dim = m_grid_matrix_noise_48.dim;
		int grid_matrix_noise_channels = m_grid_matrix_noise_48.channels;
		int hihat_array_dim = m_hihat_array_57.dim;
		int hihat_array_channels = m_hihat_array_57.channels;
		int kick_array_dim = m_kick_array_53.dim;
		int kick_array_channels = m_kick_array_53.channels;
		int snare_array_dim = m_snare_array_35.dim;
		int snare_array_channels = m_snare_array_35.channels;
		int min_164 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			int sw_1 = (__m_change_58((m_sw_28 > ((int)0))) > ((int)0));
			int sw_2 = (__m_change_59((m_sw_30 > ((int)0))) > ((int)0));
			int sw_3 = (__m_change_60((m_sw_56 > ((int)0))) > ((int)0));
			int sw_4 = (__m_change_61((m_sw_38 > ((int)0))) > ((int)0));
			int sw_5 = (__m_change_62((m_sw_26 > ((int)0))) > ((int)0));
			int sw_6 = (__m_change_63((m_sw_36 > ((int)0))) > ((int)0));
			int sw_7 = (__m_change_64((m_sw_25 > ((int)0))) > ((int)0));
			int sw_8 = (__m_change_65((m_sw_55 > ((int)0))) > ((int)0));
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				while ((i < kick_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					bool index_ignore_66 = ((i >= kick_array_dim) || (i < 0));
					if ((!index_ignore_66)) {
						m_kick_array_53.write(((int)0), i, 0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_led_46 = ((int)1);
				m_led_45 = ((int)1);
				m_led_44 = ((int)1);
				m_led_43 = ((int)1);
				m_led_42 = ((int)1);
				m_led_41 = ((int)1);
				m_led_40 = ((int)1);
				m_led_39 = ((int)1);
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			if (sw_1) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				// samples kick_array channel 1;
				t_sample a = m_kick_array_53.read(0, 0);
				m_kick_array_53.write((!a), 0, 0);
				m_led_46 = a;
				
			};
			if (sw_2) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_67 = (((int)1) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_67 ? 0 : m_kick_array_53.read(((int)1), 0));
				bool index_ignore_68 = (((int)1) >= kick_array_dim);
				if ((!index_ignore_68)) {
					m_kick_array_53.write((!a), ((int)1), 0);
					
				};
				m_led_45 = a;
				
			};
			if (sw_3) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_69 = (((int)2) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_69 ? 0 : m_kick_array_53.read(((int)2), 0));
				bool index_ignore_70 = (((int)2) >= kick_array_dim);
				if ((!index_ignore_70)) {
					m_kick_array_53.write((!a), ((int)2), 0);
					
				};
				m_led_44 = a;
				
			};
			if (sw_4) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_71 = (((int)3) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_71 ? 0 : m_kick_array_53.read(((int)3), 0));
				bool index_ignore_72 = (((int)3) >= kick_array_dim);
				if ((!index_ignore_72)) {
					m_kick_array_53.write((!a), ((int)3), 0);
					
				};
				m_led_43 = a;
				
			};
			if (sw_5) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_73 = (((int)4) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_73 ? 0 : m_kick_array_53.read(((int)4), 0));
				bool index_ignore_74 = (((int)4) >= kick_array_dim);
				if ((!index_ignore_74)) {
					m_kick_array_53.write((!a), ((int)4), 0);
					
				};
				m_led_42 = a;
				
			};
			if (sw_6) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_75 = (((int)5) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_75 ? 0 : m_kick_array_53.read(((int)5), 0));
				bool index_ignore_76 = (((int)5) >= kick_array_dim);
				if ((!index_ignore_76)) {
					m_kick_array_53.write((!a), ((int)5), 0);
					
				};
				m_led_41 = a;
				
			};
			if (sw_7) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_77 = (((int)6) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_77 ? 0 : m_kick_array_53.read(((int)6), 0));
				bool index_ignore_78 = (((int)6) >= kick_array_dim);
				if ((!index_ignore_78)) {
					m_kick_array_53.write((!a), ((int)6), 0);
					
				};
				m_led_40 = a;
				
			};
			if (sw_8) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_79 = (((int)7) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_79 ? 0 : m_kick_array_53.read(((int)7), 0));
				bool index_ignore_80 = (((int)7) >= kick_array_dim);
				if ((!index_ignore_80)) {
					m_kick_array_53.write((!a), ((int)7), 0);
					
				};
				m_led_39 = a;
				
			};
			t_sample expr_20557 = m_led_46;
			t_sample expr_20558 = m_led_45;
			t_sample expr_20559 = m_led_44;
			t_sample expr_20560 = m_led_43;
			t_sample expr_20561 = m_led_42;
			t_sample expr_20562 = m_led_41;
			t_sample expr_20563 = m_led_40;
			t_sample expr_20564 = m_led_39;
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int c = ((int)0);
				// for loop condition;
				while ((c < ((int)64))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					// for loop initializer;
					int i_20583 = ((int)0);
					// for loop condition;
					while ((i_20583 < ((int)8))) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample noise_20887 = noise();
						t_sample sub_20890 = (noise_20887 - (-1));
						t_sample scale_20886 = ((safepow((sub_20890 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						t_sample noise_20897 = noise();
						t_sample sub_20900 = (noise_20897 - (-1));
						t_sample scale_20896 = ((safepow((sub_20900 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						int snare_patterns_dim = m_snare_patterns_54.dim;
						int snare_patterns_channels = m_snare_patterns_54.channels;
						bool chan_ignore_81 = ((c < 0) || (c >= snare_patterns_channels));
						bool index_ignore_82 = ((i_20583 >= snare_patterns_dim) || (i_20583 < 0));
						if ((!(chan_ignore_81 || index_ignore_82))) {
							m_snare_patterns_54.write(((int)1), i_20583, c);
							
						};
						int snare_hit_values_dim = m_snare_hit_values_50.dim;
						int snare_hit_values_channels = m_snare_hit_values_50.channels;
						bool chan_ignore_83 = ((c < 0) || (c >= snare_hit_values_channels));
						bool index_ignore_84 = ((i_20583 >= snare_hit_values_dim) || (i_20583 < 0));
						if ((!(chan_ignore_83 || index_ignore_84))) {
							m_snare_hit_values_50.write(scale_20886, i_20583, c);
							
						};
						int hihat_patterns_dim = m_hihat_patterns_31.dim;
						int hihat_patterns_channels = m_hihat_patterns_31.channels;
						bool chan_ignore_85 = ((c < 0) || (c >= hihat_patterns_channels));
						bool index_ignore_86 = ((i_20583 >= hihat_patterns_dim) || (i_20583 < 0));
						if ((!(chan_ignore_85 || index_ignore_86))) {
							m_hihat_patterns_31.write(((int)1), i_20583, c);
							
						};
						int hihat_hit_values_dim = m_hihat_hit_values_37.dim;
						int hihat_hit_values_channels = m_hihat_hit_values_37.channels;
						bool chan_ignore_87 = ((c < 0) || (c >= hihat_hit_values_channels));
						bool index_ignore_88 = ((i_20583 >= hihat_hit_values_dim) || (i_20583 < 0));
						if ((!(chan_ignore_87 || index_ignore_88))) {
							m_hihat_hit_values_37.write(scale_20896, i_20583, c);
							
						};
						// for loop increment;
						i_20583 = (i_20583 + ((int)1));
						
					};
					// for loop increment;
					c = (c + ((int)1));
					
				};
				
			};
			t_sample out29 = expr_20555;
			t_sample out30 = expr_20556;
			int change_20325 = __m_change_89(gt_20326);
			int gt_20324 = (change_20325 > ((int)0));
			int gen_20327 = gt_20324;
			t_sample out37 = gen_20327;
			t_sample noise_20498 = noise();
			t_sample mix_20914 = (noise_20498 + (((t_sample)0.7) * (m_history_6 - noise_20498)));
			t_sample mix_20496 = mix_20914;
			t_sample sub_20494 = (noise_20498 - mix_20496);
			t_sample add_20350 = (m_history_2 + ((int)1));
			t_sample noise_20481 = noise();
			t_sample mix_20915 = (noise_20481 + (((t_sample)0.5) * (m_history_5 - noise_20481)));
			t_sample mix_20458 = mix_20915;
			t_sample mix_20916 = (mix_20458 + (((t_sample)0.6) * (m_history_4 - mix_20458)));
			t_sample mix_20479 = mix_20916;
			t_sample add_20332 = (m_history_23 + ((int)1));
			t_sample switch_20329 = (gen_20327 ? ((int)0) : add_20332);
			__m_latch_90 = ((gen_20327 != 0) ? add_20332 : __m_latch_90);
			t_sample latch_20331 = __m_latch_90;
			t_sample gen_20334 = latch_20331;
			t_sample history_20330_next_20333 = fixdenorm(switch_20329);
			t_sample rdiv_20328 = safediv(samplerate, gen_20334);
			t_sample mul_20315 = (rdiv_20328 * ((int)60));
			t_sample out36 = mul_20315;
			t_sample sub_20456 = (mix_20458 - mix_20479);
			t_sample phasor_20475 = __m_phasor_91(((int)330), samples_to_seconds);
			t_sample triangle_20474 = triangle(phasor_20475, ((t_sample)0.5));
			t_sample phasor_20473 = __m_phasor_92(((int)185), samples_to_seconds);
			t_sample triangle_20472 = triangle(phasor_20473, ((t_sample)0.5));
			t_sample rdiv_20321 = safediv(((int)1), gen_20334);
			t_sample add_20323 = (m_history_3 + rdiv_20321);
			t_sample switch_20320 = (gen_20327 ? ((int)0) : add_20323);
			t_sample wrap_20322 = wrap(switch_20320, ((int)0), ((int)1));
			t_sample switch_20317 = (gt_20316 ? scale_20450 : mul_20315);
			t_sample div_20551 = (switch_20317 * ((t_sample)0.016666666666667));
			t_sample div_20412 = (div_20551 * ((t_sample)0.125));
			t_sample phasor_20550 = __m_phasor_93(div_20412, samples_to_seconds);
			t_sample phasor_measure_20362 = phasor_20550;
			t_sample out33 = phasor_measure_20362;
			t_sample mul_20361 = (phasor_measure_20362 * ((int)8));
			t_sample wrap_20359 = wrap(mul_20361, ((int)3), ((int)0));
			t_sample div_20357 = (wrap_20359 * ((t_sample)0.33333333333333));
			t_sample out34 = div_20357;
			t_sample mix_20921 = (div_20357 + (m_mix_24 * (phasor_measure_20362 - div_20357)));
			t_sample out35 = mix_20921;
			t_sample clamp_20368 = ((phasor_20550 <= ((int)0)) ? ((int)0) : ((phasor_20550 >= ((int)1)) ? ((int)1) : phasor_20550));
			int lt_20372 = (clamp_20368 < rsub_20373);
			t_sample sub_20929 = (clamp_20368 - ((int)0));
			t_sample scale_20926 = ((safepow(safediv(sub_20929, irange_20927), ((int)1)) * ((t_sample)0.5)) + ((int)0));
			t_sample scale_20377 = scale_20926;
			t_sample sub_20933 = (clamp_20368 - rsub_20373);
			t_sample scale_20930 = ((safepow(safediv(sub_20933, irange_20931), ((int)1)) * ((t_sample)0.5)) + ((t_sample)0.5));
			t_sample scale_20375 = scale_20930;
			t_sample switch_20371 = (lt_20372 ? scale_20377 : scale_20375);
			t_sample gen_20378 = switch_20371;
			t_sample mul_20549 = (gen_20378 * ((int)8));
			t_sample floor_20548 = floor(mul_20549);
			t_sample out28 = floor_20548;
			t_sample wrap_20525 = wrap(mul_20549, ((int)0), ((int)1));
			t_sample delta_20500 = __m_delta_94(wrap_20525);
			t_sample abs_20504 = fabs(delta_20500);
			int gt_20503 = (abs_20504 > ((t_sample)0.5));
			int change_20502 = __m_change_95(gt_20503);
			int gt_20501 = (change_20502 > ((int)0));
			int trigger_beat_20510 = gt_20501;
			int trigger_beat_20524 = trigger_beat_20510;
			int trig = (__m_change_96((trigger_beat_20524 > ((int)0))) > ((int)0));
			if (trig) {
				int snare_array_dim = m_snare_array_35.dim;
				int snare_array_channels = m_snare_array_35.channels;
				// samples snare_array channel 1;
				m_hit_1_snare_22 = m_snare_array_35.read(0, 0);
				bool index_ignore_97 = (((int)1) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_2_snare_21 = (index_ignore_97 ? 0 : m_snare_array_35.read(((int)1), 0));
				bool index_ignore_98 = (((int)2) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_3_snare_20 = (index_ignore_98 ? 0 : m_snare_array_35.read(((int)2), 0));
				bool index_ignore_99 = (((int)3) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_4_snare_19 = (index_ignore_99 ? 0 : m_snare_array_35.read(((int)3), 0));
				bool index_ignore_100 = (((int)4) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_5_snare_18 = (index_ignore_100 ? 0 : m_snare_array_35.read(((int)4), 0));
				bool index_ignore_101 = (((int)5) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_6_snare_17 = (index_ignore_101 ? 0 : m_snare_array_35.read(((int)5), 0));
				bool index_ignore_102 = (((int)6) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_7_snare_16 = (index_ignore_102 ? 0 : m_snare_array_35.read(((int)6), 0));
				bool index_ignore_103 = (((int)7) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_8_snare_15 = (index_ignore_103 ? 0 : m_snare_array_35.read(((int)7), 0));
				int hihat_array_dim = m_hihat_array_57.dim;
				int hihat_array_channels = m_hihat_array_57.channels;
				// samples hihat_array channel 1;
				m_hit_1_hihat_14 = m_hihat_array_57.read(0, 0);
				bool index_ignore_104 = (((int)1) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_2_hihat_13 = (index_ignore_104 ? 0 : m_hihat_array_57.read(((int)1), 0));
				bool index_ignore_105 = (((int)2) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_3_hihat_12 = (index_ignore_105 ? 0 : m_hihat_array_57.read(((int)2), 0));
				bool index_ignore_106 = (((int)3) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_4_hihat_11 = (index_ignore_106 ? 0 : m_hihat_array_57.read(((int)3), 0));
				bool index_ignore_107 = (((int)4) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_5_hihat_10 = (index_ignore_107 ? 0 : m_hihat_array_57.read(((int)4), 0));
				bool index_ignore_108 = (((int)5) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_6_hihat_9 = (index_ignore_108 ? 0 : m_hihat_array_57.read(((int)5), 0));
				bool index_ignore_109 = (((int)6) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_7_hihat_8 = (index_ignore_109 ? 0 : m_hihat_array_57.read(((int)6), 0));
				bool index_ignore_110 = (((int)7) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_8_hihat_7 = (index_ignore_110 ? 0 : m_hihat_array_57.read(((int)7), 0));
				// for loop initializer;
				int i_20585 = ((int)0);
				// for loop condition;
				while ((i_20585 < snare_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_20937 = (m_X_47 - ((int)0));
					t_sample scale_20934 = ((safepow((sub_20937 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_20941 = (m_Y_49 - ((int)0));
					t_sample scale_20938 = ((safepow((sub_20941 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_20584 = (round(scale_20934) + round((scale_20938 * ((int)8))));
					int snare_patterns_dim = m_snare_patterns_54.dim;
					int snare_patterns_channels = m_snare_patterns_54.channels;
					bool index_ignore_111 = ((i_20585 >= snare_patterns_dim) || (i_20585 < 0));
					// samples snare_patterns channel 1;
					int chan_112 = c_20584;
					bool chan_ignore_113 = ((chan_112 < 0) || (chan_112 >= snare_patterns_channels));
					t_sample h = ((chan_ignore_113 || index_ignore_111) ? 0 : m_snare_patterns_54.read(i_20585, chan_112));
					int snare_hit_values_dim = m_snare_hit_values_50.dim;
					int snare_hit_values_channels = m_snare_hit_values_50.channels;
					bool index_ignore_114 = ((i_20585 >= snare_hit_values_dim) || (i_20585 < 0));
					// samples snare_hit_values channel 1;
					int chan_115 = c_20584;
					bool chan_ignore_116 = ((chan_115 < 0) || (chan_115 >= snare_hit_values_channels));
					t_sample v = ((chan_ignore_116 || index_ignore_114) ? 0 : m_snare_hit_values_50.read(i_20585, chan_115));
					int hit = ((int)0);
					if (((v < (((int)1) - m_density_snare_32)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_117 = ((i_20585 >= snare_array_dim) || (i_20585 < 0));
					if ((!index_ignore_117)) {
						m_snare_array_35.write(hit, i_20585, 0);
						
					};
					bool chan_ignore_118 = ((((int)1) < 0) || (((int)1) >= snare_array_channels));
					bool index_ignore_119 = ((i_20585 >= snare_array_dim) || (i_20585 < 0));
					if ((!(chan_ignore_118 || index_ignore_119))) {
						m_snare_array_35.write(v, i_20585, ((int)1));
						
					};
					// for loop increment;
					i_20585 = (i_20585 + ((int)1));
					
				};
				// for loop initializer;
				i_20585 = ((int)0);
				// for loop condition;
				while ((i_20585 < hihat_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_20945 = (m_X_47 - ((int)0));
					t_sample scale_20942 = ((safepow((sub_20945 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_20949 = (m_Y_49 - ((int)0));
					t_sample scale_20946 = ((safepow((sub_20949 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_20584 = (round(scale_20942) + round((scale_20946 * ((int)8))));
					int hihat_patterns_dim = m_hihat_patterns_31.dim;
					int hihat_patterns_channels = m_hihat_patterns_31.channels;
					bool index_ignore_120 = ((i_20585 >= hihat_patterns_dim) || (i_20585 < 0));
					// samples hihat_patterns channel 1;
					int chan_121 = c_20584;
					bool chan_ignore_122 = ((chan_121 < 0) || (chan_121 >= hihat_patterns_channels));
					t_sample h = ((chan_ignore_122 || index_ignore_120) ? 0 : m_hihat_patterns_31.read(i_20585, chan_121));
					int hihat_hit_values_dim = m_hihat_hit_values_37.dim;
					int hihat_hit_values_channels = m_hihat_hit_values_37.channels;
					bool index_ignore_123 = ((i_20585 >= hihat_hit_values_dim) || (i_20585 < 0));
					// samples hihat_hit_values channel 1;
					int chan_124 = c_20584;
					bool chan_ignore_125 = ((chan_124 < 0) || (chan_124 >= hihat_hit_values_channels));
					t_sample v = ((chan_ignore_125 || index_ignore_123) ? 0 : m_hihat_hit_values_37.read(i_20585, chan_124));
					int hit = ((int)0);
					if (((v < (((int)1) - m_density_hihat_34)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_126 = ((i_20585 >= hihat_array_dim) || (i_20585 < 0));
					if ((!index_ignore_126)) {
						m_hihat_array_57.write(hit, i_20585, 0);
						
					};
					bool chan_ignore_127 = ((((int)1) < 0) || (((int)1) >= hihat_array_channels));
					bool index_ignore_128 = ((i_20585 >= hihat_array_dim) || (i_20585 < 0));
					if ((!(chan_ignore_127 || index_ignore_128))) {
						m_hihat_array_57.write(v, i_20585, ((int)1));
						
					};
					// for loop increment;
					i_20585 = (i_20585 + ((int)1));
					
				};
				
			};
			t_sample expr_20567 = m_hit_1_snare_22;
			t_sample expr_20568 = m_hit_2_snare_21;
			t_sample expr_20569 = m_hit_3_snare_20;
			t_sample expr_20570 = m_hit_4_snare_19;
			t_sample expr_20571 = m_hit_5_snare_18;
			t_sample expr_20572 = m_hit_6_snare_17;
			t_sample expr_20573 = m_hit_7_snare_16;
			t_sample expr_20574 = m_hit_8_snare_15;
			t_sample expr_20575 = m_hit_1_hihat_14;
			t_sample expr_20576 = m_hit_2_hihat_13;
			t_sample expr_20577 = m_hit_3_hihat_12;
			t_sample expr_20578 = m_hit_4_hihat_11;
			t_sample expr_20579 = m_hit_5_hihat_10;
			t_sample expr_20580 = m_hit_6_hihat_9;
			t_sample expr_20581 = m_hit_7_hihat_8;
			t_sample expr_20582 = m_hit_8_hihat_7;
			t_sample out15 = expr_20571;
			t_sample out24 = expr_20580;
			t_sample out23 = expr_20579;
			t_sample out18 = expr_20574;
			t_sample out11 = expr_20567;
			t_sample out25 = expr_20581;
			t_sample out19 = expr_20575;
			t_sample out12 = expr_20568;
			t_sample out13 = expr_20569;
			t_sample out14 = expr_20570;
			t_sample out26 = expr_20582;
			t_sample out20 = expr_20576;
			t_sample out22 = expr_20578;
			t_sample out16 = expr_20572;
			t_sample out21 = expr_20577;
			t_sample out17 = expr_20573;
			t_sample out27 = trigger_beat_20524;
			int trigger_beat_20421 = trigger_beat_20510;
			__m_latch_129 = ((trigger_beat_20421 != 0) ? floor_20548 : __m_latch_129);
			t_sample latch_20422 = __m_latch_129;
			int eq_20413 = (latch_20422 == ((int)7));
			t_sample out10 = (eq_20413 + expr_20564);
			int eq_20420 = (latch_20422 == ((int)0));
			t_sample out3 = (eq_20420 + expr_20557);
			int eq_20418 = (latch_20422 == ((int)2));
			t_sample out5 = (eq_20418 + expr_20559);
			int eq_20419 = (latch_20422 == ((int)1));
			t_sample out4 = (eq_20419 + expr_20558);
			int eq_20416 = (latch_20422 == ((int)4));
			t_sample out7 = (eq_20416 + expr_20561);
			int eq_20417 = (latch_20422 == ((int)3));
			t_sample out6 = (eq_20417 + expr_20560);
			int eq_20414 = (latch_20422 == ((int)6));
			t_sample out9 = (eq_20414 + expr_20563);
			int eq_20415 = (latch_20422 == ((int)5));
			t_sample out8 = (eq_20415 + expr_20562);
			t_sample phasor_20389 = __m_phasor_130(((int)5000), samples_to_seconds);
			t_sample delta_20384 = __m_delta_131(phasor_20389);
			t_sample abs_20388 = fabs(delta_20384);
			int gt_20387 = (abs_20388 > ((t_sample)0.5));
			int change_20386 = __m_change_132(gt_20387);
			int gt_20385 = (change_20386 > ((int)0));
			__m_count_133 = (((int)0) ? 0 : (fixdenorm(__m_count_133 + gt_20385)));
			int carry_134 = 0;
			if ((((int)0) != 0)) {
				__m_count_133 = 0;
				__m_carry_135 = 0;
				
			} else if (((((int)63) > 0) && (__m_count_133 >= ((int)63)))) {
				int wraps_136 = (__m_count_133 / ((int)63));
				__m_carry_135 = (__m_carry_135 + wraps_136);
				__m_count_133 = (__m_count_133 - (wraps_136 * ((int)63)));
				carry_134 = 1;
				
			};
			int counter_20393 = __m_count_133;
			int counter_20394 = carry_134;
			int counter_20395 = __m_carry_135;
			bool index_ignore_137 = ((counter_20393 >= grid_matrix_noise_dim) || (counter_20393 < 0));
			// samples grid_matrix_noise channel 1;
			t_sample sample_grid_matrix_noise_20390 = (index_ignore_137 ? 0 : m_grid_matrix_noise_48.read(counter_20393, 0));
			t_sample index_grid_matrix_noise_20391 = counter_20393;
			t_sample out32 = sample_grid_matrix_noise_20390;
			int add_20383 = (counter_20393 + ((int)1));
			t_sample out31 = add_20383;
			t_sample phasor_20346 = __m_phasor_138(((int)2), samples_to_seconds);
			int gt_20345 = (phasor_20346 > ((int)0));
			int change_20344 = __m_change_139(gt_20345);
			int gt_20343 = (change_20344 > ((int)0));
			int plusequals_20342 = __m_pluseq_140.post(((int)1), gt_20343, 0);
			int lte_20341 = (plusequals_20342 <= max_20339);
			int gt_20353 = (lte_20341 > ((int)0));
			int change_20352 = __m_change_141(gt_20353);
			int gt_20351 = (change_20352 > ((int)0));
			t_sample switch_20347 = (gt_20351 ? ((int)0) : add_20350);
			int trigger_beat_20411 = trigger_beat_20510;
			t_sample delta_20505 = __m_delta_142(phasor_20550);
			t_sample abs_20509 = fabs(delta_20505);
			int gt_20508 = (abs_20509 > ((t_sample)0.5));
			int change_20507 = __m_change_143(gt_20508);
			int gt_20506 = (change_20507 > ((int)0));
			int trigger_master_20512 = gt_20506;
			__m_count_144 = (trigger_master_20512 ? 0 : (fixdenorm(__m_count_144 + gt_20501)));
			int counter_20515 = __m_count_144;
			int counter_20516 = ((int)0);
			int counter_20517 = ((int)0);
			bool index_ignore_145 = ((counter_20515 >= hihat_array_dim) || (counter_20515 < 0));
			// samples hihat_array channel 1;
			t_sample sample_hihat_array_20513 = (index_ignore_145 ? 0 : m_hihat_array_57.read(counter_20515, 0));
			t_sample index_hihat_array_20514 = counter_20515;
			__m_latch_146 = ((sample_hihat_array_20513 != 0) ? trigger_beat_20510 : __m_latch_146);
			t_sample latch_20518 = __m_latch_146;
			t_sample delta_20483 = __m_delta_147(latch_20518);
			t_sample abs_20487 = fabs(delta_20483);
			int gt_20486 = (abs_20487 > ((t_sample)0.5));
			int change_20485 = __m_change_148(gt_20486);
			int gt_20484 = (change_20485 > ((int)0));
			t_sample plusequals_20493 = __m_pluseq_149.post(((t_sample)0.0003239390994493), gt_20484, 0);
			t_sample clamp_20492 = ((plusequals_20493 <= ((int)0)) ? ((int)0) : ((plusequals_20493 >= ((int)1)) ? ((int)1) : plusequals_20493));
			t_sample sub_20953 = (clamp_20492 - ((int)0));
			t_sample scale_20950 = ((safepow((sub_20953 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample mul_20497 = (scale_20950 * sub_20494);
			bool index_ignore_150 = ((counter_20515 >= kick_array_dim) || (counter_20515 < 0));
			// samples kick_array channel 1;
			t_sample sample_kick_array_20438 = (index_ignore_150 ? 0 : m_kick_array_53.read(counter_20515, 0));
			t_sample index_kick_array_20439 = counter_20515;
			t_sample kick_boolean_20437 = sample_kick_array_20438;
			__m_latch_151 = ((kick_boolean_20437 != 0) ? trigger_beat_20411 : __m_latch_151);
			t_sample latch_20436 = __m_latch_151;
			t_sample delta_20451 = __m_delta_152(latch_20436);
			t_sample abs_20427 = fabs(delta_20451);
			int gt_20426 = (abs_20427 > ((t_sample)0.5));
			int change_20425 = __m_change_153(gt_20426);
			int gt_20424 = (change_20425 > ((int)0));
			t_sample plusequals_20429 = __m_pluseq_154.post(safediv(8, samplerate), gt_20424, 0);
			t_sample clamp_20428 = ((plusequals_20429 <= ((int)0)) ? ((int)0) : ((plusequals_20429 >= ((int)1)) ? ((int)1) : plusequals_20429));
			t_sample sub_20957 = (clamp_20428 - ((int)0));
			t_sample scale_20954 = ((safepow((sub_20957 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_20430 = scale_20954;
			t_sample sub_20961 = (scale_20430 - ((int)1));
			t_sample scale_20958 = ((safepow((sub_20961 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_20433 = scale_20958;
			t_sample sin_20434 = sin(scale_20433);
			t_sample mul_20435 = (scale_20430 * sin_20434);
			t_sample mix_20962 = (mul_20435 + (((t_sample)0.9) * (m_history_1 - mul_20435)));
			t_sample mix_20432 = mix_20962;
			bool index_ignore_155 = ((counter_20515 >= snare_array_dim) || (counter_20515 < 0));
			// samples snare_array channel 1;
			t_sample sample_snare_array_20526 = (index_ignore_155 ? 0 : m_snare_array_35.read(counter_20515, 0));
			t_sample index_snare_array_20527 = counter_20515;
			__m_latch_156 = ((sample_snare_array_20526 != 0) ? trigger_beat_20510 : __m_latch_156);
			t_sample latch_20522 = __m_latch_156;
			t_sample delta_20410 = __m_delta_157(latch_20522);
			t_sample abs_20455 = fabs(delta_20410);
			int gt_20454 = (abs_20455 > ((t_sample)0.5));
			int change_20453 = __m_change_158(gt_20454);
			int gt_20452 = (change_20453 > ((int)0));
			t_sample plusequals_20477 = __m_pluseq_159.post(safediv(13, samplerate), gt_20452, 0);
			t_sample clamp_20476 = ((plusequals_20477 <= ((int)0)) ? ((int)0) : ((plusequals_20477 >= ((int)1)) ? ((int)1) : plusequals_20477));
			t_sample sub_20966 = (clamp_20476 - ((int)0));
			t_sample scale_20963 = ((safepow((sub_20966 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_20480 = (scale_20963 * triangle_20474);
			t_sample plusequals_20462 = __m_pluseq_160.post(safediv(7, samplerate), gt_20452, 0);
			t_sample clamp_20460 = ((plusequals_20462 <= ((int)0)) ? ((int)0) : ((plusequals_20462 >= ((int)1)) ? ((int)1) : plusequals_20462));
			t_sample sub_20970 = (clamp_20460 - ((int)0));
			t_sample scale_20967 = ((safepow((sub_20970 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample mul_20459 = (scale_20967 * sub_20456);
			t_sample plusequals_20470 = __m_pluseq_161.post(safediv(8, samplerate), gt_20452, 0);
			t_sample clamp_20466 = ((plusequals_20470 <= ((int)0)) ? ((int)0) : ((plusequals_20470 >= ((int)1)) ? ((int)1) : plusequals_20470));
			t_sample sub_20974 = (clamp_20466 - ((int)0));
			t_sample scale_20971 = ((safepow((sub_20974 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample mul_20464 = (scale_20971 * mix_20458);
			t_sample plusequals_20471 = __m_pluseq_162.post(safediv(11, samplerate), gt_20452, 0);
			t_sample clamp_20468 = ((plusequals_20471 <= ((int)0)) ? ((int)0) : ((plusequals_20471 >= ((int)1)) ? ((int)1) : plusequals_20471));
			t_sample sub_20978 = (clamp_20468 - ((int)0));
			t_sample scale_20975 = ((safepow((sub_20978 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_20465 = (scale_20975 * triangle_20472);
			t_sample v_163 = (((mul_20465 + mul_20464) + mul_20459) + mul_20480);
			t_sample clamp_20463 = ((v_163 <= min_164) ? min_164 : ((v_163 >= ((int)1)) ? ((int)1) : v_163));
			t_sample out1 = ((clamp_20463 + mul_20497) + mix_20432);
			t_sample out2 = ((clamp_20463 + mul_20497) + mix_20432);
			t_sample history_20495_next_20586 = fixdenorm(mix_20496);
			t_sample history_20457_next_20587 = fixdenorm(mix_20458);
			t_sample history_20478_next_20588 = fixdenorm(mix_20479);
			t_sample history_20319_next_20589 = fixdenorm(wrap_20322);
			t_sample history_20348_next_20590 = fixdenorm(switch_20347);
			t_sample history_20431_next_20591 = fixdenorm(mix_20432);
			m_history_23 = history_20330_next_20333;
			m_history_6 = history_20495_next_20586;
			m_history_5 = history_20457_next_20587;
			m_history_4 = history_20478_next_20588;
			m_history_3 = history_20319_next_20589;
			m_history_2 = history_20348_next_20590;
			m_history_1 = history_20431_next_20591;
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
			(*(__out13++)) = out13;
			(*(__out14++)) = out14;
			(*(__out15++)) = out15;
			(*(__out16++)) = out16;
			(*(__out17++)) = out17;
			(*(__out18++)) = out18;
			(*(__out19++)) = out19;
			(*(__out20++)) = out20;
			(*(__out21++)) = out21;
			(*(__out22++)) = out22;
			(*(__out23++)) = out23;
			(*(__out24++)) = out24;
			(*(__out25++)) = out25;
			(*(__out26++)) = out26;
			(*(__out27++)) = out27;
			(*(__out28++)) = out28;
			(*(__out29++)) = out29;
			(*(__out30++)) = out30;
			(*(__out31++)) = out31;
			(*(__out32++)) = out32;
			(*(__out33++)) = out33;
			(*(__out34++)) = out34;
			(*(__out35++)) = out35;
			(*(__out36++)) = out36;
			(*(__out37++)) = out37;
			
		};
		return __exception;
		
	};
	inline void set_mix(t_param _value) {
		m_mix_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cv2(t_param _value) {
		m_cv_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_patterns(void * _value) {
		m_hihat_patterns_31.setbuffer(_value);
	};
	inline void set_density_snare(t_param _value) {
		m_density_snare_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_swing(t_param _value) {
		m_swing_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_density_hihat(t_param _value) {
		m_density_hihat_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_array(void * _value) {
		m_snare_array_35.setbuffer(_value);
	};
	inline void set_sw6(t_param _value) {
		m_sw_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_hit_values(void * _value) {
		m_hihat_hit_values_37.setbuffer(_value);
	};
	inline void set_sw4(t_param _value) {
		m_sw_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_X(t_param _value) {
		m_X_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_grid_matrix_noise(void * _value) {
		m_grid_matrix_noise_48.setbuffer(_value);
	};
	inline void set_Y(t_param _value) {
		m_Y_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_hit_values(void * _value) {
		m_snare_hit_values_50.setbuffer(_value);
	};
	inline void set_noise_array(void * _value) {
		m_noise_array_51.setbuffer(_value);
	};
	inline void set_bpm(t_param _value) {
		m_bpm_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_kick_array(void * _value) {
		m_kick_array_53.setbuffer(_value);
	};
	inline void set_snare_patterns(void * _value) {
		m_snare_patterns_54.setbuffer(_value);
	};
	inline void set_sw8(t_param _value) {
		m_sw_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_56 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_array(void * _value) {
		m_hihat_array_57.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 37;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 26; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "sound_l", "sound_r", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "sn1", "sn2", "sn3", "sn4", "sn5", "sn6", "sn7", "sn8", "hi1", "hi2", "hi3", "hi4", "hi5", "hi6", "hi7", "hi8", "trigger_b", "step_value", "x_pos", "y_pos", "out31", "out32", "out33", "out34", "out35", "out36", "out37" };

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
		case 0: self->set_X(value); break;
		case 1: self->set_Y(value); break;
		case 2: self->set_bpm(value); break;
		case 3: self->set_cv2(value); break;
		case 4: self->set_density_hihat(value); break;
		case 5: self->set_density_snare(value); break;
		case 6: self->set_gatein1(value); break;
		case 7: self->set_grid_matrix_noise(ref); break;
		case 8: self->set_hihat_array(ref); break;
		case 9: self->set_hihat_hit_values(ref); break;
		case 10: self->set_hihat_patterns(ref); break;
		case 11: self->set_kick_array(ref); break;
		case 12: self->set_mix(value); break;
		case 13: self->set_noise_array(ref); break;
		case 14: self->set_snare_array(ref); break;
		case 15: self->set_snare_hit_values(ref); break;
		case 16: self->set_snare_patterns(ref); break;
		case 17: self->set_sw1(value); break;
		case 18: self->set_sw2(value); break;
		case 19: self->set_sw3(value); break;
		case 20: self->set_sw4(value); break;
		case 21: self->set_sw5(value); break;
		case 22: self->set_sw6(value); break;
		case 23: self->set_sw7(value); break;
		case 24: self->set_sw8(value); break;
		case 25: self->set_swing(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_X_47; break;
		case 1: *value = self->m_Y_49; break;
		case 2: *value = self->m_bpm_52; break;
		case 3: *value = self->m_cv_27; break;
		case 4: *value = self->m_density_hihat_34; break;
		case 5: *value = self->m_density_snare_32; break;
		case 6: *value = self->m_gatein_29; break;
		
		
		
		
		
		case 12: *value = self->m_mix_24; break;
		
		
		
		
		case 17: *value = self->m_sw_28; break;
		case 18: *value = self->m_sw_30; break;
		case 19: *value = self->m_sw_56; break;
		case 20: *value = self->m_sw_38; break;
		case 21: *value = self->m_sw_26; break;
		case 22: *value = self->m_sw_36; break;
		case 23: *value = self->m_sw_25; break;
		case 24: *value = self->m_sw_55; break;
		case 25: *value = self->m_swing_33; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(26 * sizeof(ParamInfo));
	self->__commonstate.numparams = 26;
	// initialize parameter 0 ("m_X_47")
	pi = self->__commonstate.params + 0;
	pi->name = "X";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_X_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_Y_49")
	pi = self->__commonstate.params + 1;
	pi->name = "Y";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Y_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_bpm_52")
	pi = self->__commonstate.params + 2;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_52;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_cv_27")
	pi = self->__commonstate.params + 3;
	pi->name = "cv2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_density_hihat_34")
	pi = self->__commonstate.params + 4;
	pi->name = "density_hihat";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_density_hihat_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_density_snare_32")
	pi = self->__commonstate.params + 5;
	pi->name = "density_snare";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_density_snare_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_gatein_29")
	pi = self->__commonstate.params + 6;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_grid_matrix_noise_48")
	pi = self->__commonstate.params + 7;
	pi->name = "grid_matrix_noise";
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
	// initialize parameter 8 ("m_hihat_array_57")
	pi = self->__commonstate.params + 8;
	pi->name = "hihat_array";
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
	// initialize parameter 9 ("m_hihat_hit_values_37")
	pi = self->__commonstate.params + 9;
	pi->name = "hihat_hit_values";
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
	// initialize parameter 10 ("m_hihat_patterns_31")
	pi = self->__commonstate.params + 10;
	pi->name = "hihat_patterns";
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
	// initialize parameter 11 ("m_kick_array_53")
	pi = self->__commonstate.params + 11;
	pi->name = "kick_array";
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
	// initialize parameter 12 ("m_mix_24")
	pi = self->__commonstate.params + 12;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_noise_array_51")
	pi = self->__commonstate.params + 13;
	pi->name = "noise_array";
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
	// initialize parameter 14 ("m_snare_array_35")
	pi = self->__commonstate.params + 14;
	pi->name = "snare_array";
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
	// initialize parameter 15 ("m_snare_hit_values_50")
	pi = self->__commonstate.params + 15;
	pi->name = "snare_hit_values";
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
	// initialize parameter 16 ("m_snare_patterns_54")
	pi = self->__commonstate.params + 16;
	pi->name = "snare_patterns";
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
	// initialize parameter 17 ("m_sw_28")
	pi = self->__commonstate.params + 17;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_30")
	pi = self->__commonstate.params + 18;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_56")
	pi = self->__commonstate.params + 19;
	pi->name = "sw3";
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
	// initialize parameter 20 ("m_sw_38")
	pi = self->__commonstate.params + 20;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_sw_26")
	pi = self->__commonstate.params + 21;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_sw_36")
	pi = self->__commonstate.params + 22;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_36;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_sw_25")
	pi = self->__commonstate.params + 23;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 24 ("m_sw_55")
	pi = self->__commonstate.params + 24;
	pi->name = "sw8";
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
	// initialize parameter 25 ("m_swing_33")
	pi = self->__commonstate.params + 25;
	pi->name = "swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_swing_33;
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


} // KHAIROS::
