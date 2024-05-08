#include "Kronos_2dKhairos.h"

namespace Kronos_2dKhairos {

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
	Change __m_change_104;
	Change __m_change_103;
	Change __m_change_64;
	Change __m_change_139;
	Change __m_change_58;
	Change __m_change_96;
	Change __m_change_61;
	Change __m_change_65;
	Change __m_change_60;
	Change __m_change_62;
	Change __m_change_89;
	Change __m_change_141;
	Change __m_change_59;
	Change __m_change_143;
	Change __m_change_153;
	Change __m_change_148;
	Change __m_change_158;
	Data m_snare_patterns_45;
	Data m_snare_hit_values_41;
	Data m_noise_array_28;
	Data m_grid_matrix_noise_27;
	Data m_hihat_hit_values_32;
	Data m_hihat_array_39;
	Data m_hihat_patterns_43;
	Data m_snare_array_42;
	Data m_kick_array_37;
	Delta __m_delta_147;
	Delta __m_delta_142;
	Delta __m_delta_152;
	Delta __m_delta_95;
	Delta __m_delta_102;
	Delta __m_delta_157;
	Phasor __m_phasor_94;
	Phasor __m_phasor_91;
	Phasor __m_phasor_93;
	Phasor __m_phasor_138;
	Phasor __m_phasor_92;
	PlusEquals __m_pluseq_159;
	PlusEquals __m_pluseq_160;
	PlusEquals __m_pluseq_154;
	PlusEquals __m_pluseq_149;
	PlusEquals __m_pluseq_162;
	PlusEquals __m_pluseq_161;
	PlusEquals __m_pluseq_140;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample m_hit_1_hihat_14;
	t_sample m_X_40;
	t_sample m_hit_2_hihat_13;
	t_sample m_hit_3_hihat_12;
	t_sample m_hit_4_hihat_11;
	t_sample __m_latch_137;
	t_sample m_hit_5_hihat_10;
	t_sample m_hit_8_snare_15;
	t_sample m_hit_6_snare_17;
	t_sample m_hit_5_snare_18;
	t_sample m_hit_7_snare_16;
	t_sample __m_count_97;
	t_sample __m_carry_99;
	t_sample m_hit_6_hihat_9;
	t_sample __m_count_144;
	t_sample __m_latch_146;
	t_sample __m_latch_156;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_hit_4_snare_19;
	t_sample m_history_4;
	t_sample __m_latch_151;
	t_sample m_hit_7_hihat_8;
	t_sample m_history_5;
	t_sample m_hit_8_hihat_7;
	t_sample m_history_6;
	t_sample m_bpm_44;
	t_sample m_hit_3_snare_20;
	t_sample m_hit_1_snare_22;
	t_sample m_led_53;
	t_sample m_led_52;
	t_sample m_led_54;
	t_sample m_led_56;
	t_sample m_led_55;
	t_sample m_led_57;
	t_sample m_Y_38;
	t_sample m_density_snare_49;
	t_sample m_sw_46;
	t_sample m_led_50;
	t_sample m_mix_47;
	t_sample m_sw_48;
	t_sample m_hit_2_snare_21;
	t_sample m_sw_36;
	t_sample m_sw_34;
	t_sample m_swing_24;
	t_sample m_cv_25;
	t_sample __m_latch_90;
	t_sample m_history_23;
	t_sample samples_to_seconds;
	t_sample m_sw_35;
	t_sample elapsed;
	t_sample m_gatein_29;
	t_sample m_density_hihat_33;
	t_sample m_sw_26;
	t_sample m_sw_31;
	t_sample m_sw_30;
	t_sample m_led_51;
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
		m_swing_24 = ((int)0);
		m_cv_25 = ((int)0);
		m_sw_26 = ((int)0);
		m_grid_matrix_noise_27.reset("grid_matrix_noise", ((int)64), ((int)1));
		m_noise_array_28.reset("noise_array", ((int)48000), ((int)1));
		m_gatein_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_hihat_hit_values_32.reset("hihat_hit_values", ((int)8), ((int)64));
		m_density_hihat_33 = ((int)1);
		m_sw_34 = ((int)0);
		m_sw_35 = ((int)0);
		m_sw_36 = ((int)0);
		m_kick_array_37.reset("kick_array", ((int)8), ((int)1));
		m_Y_38 = ((int)0);
		m_hihat_array_39.reset("hihat_array", ((int)8), ((int)2));
		m_X_40 = ((int)0);
		m_snare_hit_values_41.reset("snare_hit_values", ((int)8), ((int)64));
		m_snare_array_42.reset("snare_array", ((int)8), ((int)2));
		m_hihat_patterns_43.reset("hihat_patterns", ((int)8), ((int)64));
		m_bpm_44 = ((int)0);
		m_snare_patterns_45.reset("snare_patterns", ((int)8), ((int)64));
		m_sw_46 = ((int)0);
		m_mix_47 = ((int)0);
		m_sw_48 = ((int)0);
		m_density_snare_49 = ((int)1);
		m_led_50 = ((int)0);
		m_led_51 = ((int)0);
		m_led_52 = ((int)0);
		m_led_53 = ((int)0);
		m_led_54 = ((int)0);
		m_led_55 = ((int)0);
		m_led_56 = ((int)0);
		m_led_57 = ((int)0);
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
		__m_phasor_94.reset(0);
		__m_delta_95.reset(0);
		__m_change_96.reset(0);
		__m_count_97 = 0;
		__m_carry_99 = 0;
		__m_delta_102.reset(0);
		__m_change_103.reset(0);
		__m_change_104.reset(0);
		__m_latch_137 = 0;
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
		t_sample sub_3088 = (m_X_40 - ((int)0));
		t_sample scale_3085 = ((safepow((sub_3088 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_2832 = round(scale_3085);
		t_sample sub_3092 = (m_Y_38 - ((int)0));
		t_sample scale_3089 = ((safepow((sub_3092 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_2833 = round(scale_3089);
		int gt_2603 = (m_gatein_29 > ((int)0));
		samples_to_seconds = (1 / samplerate);
		t_sample sub_3099 = (m_swing_24 - ((int)0));
		t_sample scale_3096 = ((safepow((sub_3099 * ((t_sample)1)), ((int)1)) * ((t_sample)0.25)) + ((t_sample)0.5));
		t_sample scale_2641 = scale_3096;
		int gt_2593 = (m_bpm_44 > ((t_sample)0.01));
		t_sample sub_3103 = (m_bpm_44 - ((int)0));
		t_sample scale_3100 = ((safepow((sub_3103 * ((t_sample)1)), ((int)1)) * ((int)460)) + ((int)40));
		t_sample scale_2727 = scale_3100;
		t_sample clamp_2653 = ((scale_2641 <= ((int)0)) ? ((int)0) : ((scale_2641 >= ((int)1)) ? ((int)1) : scale_2641));
		t_sample rsub_2650 = (((int)1) - clamp_2653);
		t_sample irange_3106 = (rsub_2650 - ((int)0));
		t_sample irange_3110 = (((int)1) - rsub_2650);
		int grid_matrix_noise_dim = m_grid_matrix_noise_27.dim;
		int grid_matrix_noise_channels = m_grid_matrix_noise_27.channels;
		t_sample mstosamps_2615 = (((int)1) * (samplerate * 0.001));
		t_sample max_2616 = ((mstosamps_2615 < vectorsize) ? vectorsize : mstosamps_2615);
		int hihat_array_dim = m_hihat_array_39.dim;
		int hihat_array_channels = m_hihat_array_39.channels;
		int kick_array_dim = m_kick_array_37.dim;
		int kick_array_channels = m_kick_array_37.channels;
		int snare_array_dim = m_snare_array_42.dim;
		int snare_array_channels = m_snare_array_42.channels;
		int min_164 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			int sw_1 = (__m_change_58((m_sw_30 > ((int)0))) > ((int)0));
			int sw_2 = (__m_change_59((m_sw_34 > ((int)0))) > ((int)0));
			int sw_3 = (__m_change_60((m_sw_26 > ((int)0))) > ((int)0));
			int sw_4 = (__m_change_61((m_sw_31 > ((int)0))) > ((int)0));
			int sw_5 = (__m_change_62((m_sw_35 > ((int)0))) > ((int)0));
			int sw_6 = (__m_change_63((m_sw_36 > ((int)0))) > ((int)0));
			int sw_7 = (__m_change_64((m_sw_46 > ((int)0))) > ((int)0));
			int sw_8 = (__m_change_65((m_sw_48 > ((int)0))) > ((int)0));
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				while ((i < kick_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					bool index_ignore_66 = ((i >= kick_array_dim) || (i < 0));
					if ((!index_ignore_66)) {
						m_kick_array_37.write(((int)0), i, 0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_led_57 = ((int)1);
				m_led_56 = ((int)1);
				m_led_55 = ((int)1);
				m_led_54 = ((int)1);
				m_led_53 = ((int)1);
				m_led_52 = ((int)1);
				m_led_51 = ((int)1);
				m_led_50 = ((int)1);
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			if (sw_1) {
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				// samples kick_array channel 1;
				t_sample a = m_kick_array_37.read(0, 0);
				m_kick_array_37.write((!a), 0, 0);
				m_led_57 = a;
				
			};
			if (sw_2) {
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				bool index_ignore_67 = (((int)1) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_67 ? 0 : m_kick_array_37.read(((int)1), 0));
				bool index_ignore_68 = (((int)1) >= kick_array_dim);
				if ((!index_ignore_68)) {
					m_kick_array_37.write((!a), ((int)1), 0);
					
				};
				m_led_56 = a;
				
			};
			if (sw_3) {
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				bool index_ignore_69 = (((int)2) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_69 ? 0 : m_kick_array_37.read(((int)2), 0));
				bool index_ignore_70 = (((int)2) >= kick_array_dim);
				if ((!index_ignore_70)) {
					m_kick_array_37.write((!a), ((int)2), 0);
					
				};
				m_led_55 = a;
				
			};
			if (sw_4) {
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				bool index_ignore_71 = (((int)3) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_71 ? 0 : m_kick_array_37.read(((int)3), 0));
				bool index_ignore_72 = (((int)3) >= kick_array_dim);
				if ((!index_ignore_72)) {
					m_kick_array_37.write((!a), ((int)3), 0);
					
				};
				m_led_54 = a;
				
			};
			if (sw_5) {
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				bool index_ignore_73 = (((int)4) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_73 ? 0 : m_kick_array_37.read(((int)4), 0));
				bool index_ignore_74 = (((int)4) >= kick_array_dim);
				if ((!index_ignore_74)) {
					m_kick_array_37.write((!a), ((int)4), 0);
					
				};
				m_led_53 = a;
				
			};
			if (sw_6) {
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				bool index_ignore_75 = (((int)5) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_75 ? 0 : m_kick_array_37.read(((int)5), 0));
				bool index_ignore_76 = (((int)5) >= kick_array_dim);
				if ((!index_ignore_76)) {
					m_kick_array_37.write((!a), ((int)5), 0);
					
				};
				m_led_52 = a;
				
			};
			if (sw_7) {
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				bool index_ignore_77 = (((int)6) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_77 ? 0 : m_kick_array_37.read(((int)6), 0));
				bool index_ignore_78 = (((int)6) >= kick_array_dim);
				if ((!index_ignore_78)) {
					m_kick_array_37.write((!a), ((int)6), 0);
					
				};
				m_led_51 = a;
				
			};
			if (sw_8) {
				int kick_array_dim = m_kick_array_37.dim;
				int kick_array_channels = m_kick_array_37.channels;
				bool index_ignore_79 = (((int)7) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_79 ? 0 : m_kick_array_37.read(((int)7), 0));
				bool index_ignore_80 = (((int)7) >= kick_array_dim);
				if ((!index_ignore_80)) {
					m_kick_array_37.write((!a), ((int)7), 0);
					
				};
				m_led_50 = a;
				
			};
			t_sample expr_2834 = m_led_57;
			t_sample expr_2835 = m_led_56;
			t_sample expr_2836 = m_led_55;
			t_sample expr_2837 = m_led_54;
			t_sample expr_2838 = m_led_53;
			t_sample expr_2839 = m_led_52;
			t_sample expr_2840 = m_led_51;
			t_sample expr_2841 = m_led_50;
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
					int i_2860 = ((int)0);
					// for loop condition;
					while ((i_2860 < ((int)8))) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample noise_3066 = noise();
						t_sample sub_3069 = (noise_3066 - (-1));
						t_sample scale_3065 = ((safepow((sub_3069 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						t_sample noise_3076 = noise();
						t_sample sub_3079 = (noise_3076 - (-1));
						t_sample scale_3075 = ((safepow((sub_3079 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						int snare_patterns_dim = m_snare_patterns_45.dim;
						int snare_patterns_channels = m_snare_patterns_45.channels;
						bool chan_ignore_81 = ((c < 0) || (c >= snare_patterns_channels));
						bool index_ignore_82 = ((i_2860 >= snare_patterns_dim) || (i_2860 < 0));
						if ((!(chan_ignore_81 || index_ignore_82))) {
							m_snare_patterns_45.write(((int)1), i_2860, c);
							
						};
						int snare_hit_values_dim = m_snare_hit_values_41.dim;
						int snare_hit_values_channels = m_snare_hit_values_41.channels;
						bool chan_ignore_83 = ((c < 0) || (c >= snare_hit_values_channels));
						bool index_ignore_84 = ((i_2860 >= snare_hit_values_dim) || (i_2860 < 0));
						if ((!(chan_ignore_83 || index_ignore_84))) {
							m_snare_hit_values_41.write(scale_3065, i_2860, c);
							
						};
						int hihat_patterns_dim = m_hihat_patterns_43.dim;
						int hihat_patterns_channels = m_hihat_patterns_43.channels;
						bool chan_ignore_85 = ((c < 0) || (c >= hihat_patterns_channels));
						bool index_ignore_86 = ((i_2860 >= hihat_patterns_dim) || (i_2860 < 0));
						if ((!(chan_ignore_85 || index_ignore_86))) {
							m_hihat_patterns_43.write(((int)1), i_2860, c);
							
						};
						int hihat_hit_values_dim = m_hihat_hit_values_32.dim;
						int hihat_hit_values_channels = m_hihat_hit_values_32.channels;
						bool chan_ignore_87 = ((c < 0) || (c >= hihat_hit_values_channels));
						bool index_ignore_88 = ((i_2860 >= hihat_hit_values_dim) || (i_2860 < 0));
						if ((!(chan_ignore_87 || index_ignore_88))) {
							m_hihat_hit_values_32.write(scale_3075, i_2860, c);
							
						};
						// for loop increment;
						i_2860 = (i_2860 + ((int)1));
						
					};
					// for loop increment;
					c = (c + ((int)1));
					
				};
				
			};
			t_sample out30 = expr_2833;
			t_sample out29 = expr_2832;
			int change_2602 = __m_change_89(gt_2603);
			int gt_2601 = (change_2602 > ((int)0));
			int gen_2604 = gt_2601;
			t_sample out37 = gen_2604;
			t_sample add_2627 = (m_history_2 + ((int)1));
			t_sample noise_2758 = noise();
			t_sample mix_3093 = (noise_2758 + (((t_sample)0.5) * (m_history_6 - noise_2758)));
			t_sample mix_2735 = mix_3093;
			t_sample mix_3094 = (mix_2735 + (((t_sample)0.6) * (m_history_5 - mix_2735)));
			t_sample mix_2756 = mix_3094;
			t_sample noise_2775 = noise();
			t_sample mix_3095 = (noise_2775 + (((t_sample)0.7) * (m_history_4 - noise_2775)));
			t_sample mix_2773 = mix_3095;
			t_sample sub_2771 = (noise_2775 - mix_2773);
			t_sample add_2609 = (m_history_23 + ((int)1));
			__m_latch_90 = ((gen_2604 != 0) ? add_2609 : __m_latch_90);
			t_sample latch_2608 = __m_latch_90;
			t_sample gen_2611 = latch_2608;
			t_sample switch_2606 = (gen_2604 ? ((int)0) : add_2609);
			t_sample history_2607_next_2610 = fixdenorm(switch_2606);
			t_sample rdiv_2605 = safediv(samplerate, gen_2611);
			t_sample mul_2592 = (rdiv_2605 * ((int)60));
			t_sample out36 = mul_2592;
			t_sample sub_2733 = (mix_2735 - mix_2756);
			t_sample phasor_2752 = __m_phasor_91(((int)330), samples_to_seconds);
			t_sample triangle_2751 = triangle(phasor_2752, ((t_sample)0.5));
			t_sample phasor_2750 = __m_phasor_92(((int)185), samples_to_seconds);
			t_sample triangle_2749 = triangle(phasor_2750, ((t_sample)0.5));
			t_sample rdiv_2598 = safediv(((int)1), gen_2611);
			t_sample add_2600 = (m_history_3 + rdiv_2598);
			t_sample switch_2597 = (gen_2604 ? ((int)0) : add_2600);
			t_sample wrap_2599 = wrap(switch_2597, ((int)0), ((int)1));
			t_sample switch_2594 = (gt_2593 ? scale_2727 : mul_2592);
			t_sample div_2828 = (switch_2594 * ((t_sample)0.016666666666667));
			t_sample div_2689 = (div_2828 * ((t_sample)0.125));
			t_sample phasor_2827 = __m_phasor_93(div_2689, samples_to_seconds);
			t_sample phasor_measure_2639 = phasor_2827;
			t_sample out33 = phasor_measure_2639;
			t_sample mul_2638 = (phasor_measure_2639 * ((int)8));
			t_sample wrap_2636 = wrap(mul_2638, ((int)3), ((int)0));
			t_sample div_2634 = (wrap_2636 * ((t_sample)0.33333333333333));
			t_sample out34 = div_2634;
			t_sample mix_3104 = (div_2634 + (m_mix_47 * (phasor_measure_2639 - div_2634)));
			t_sample out35 = mix_3104;
			t_sample clamp_2645 = ((phasor_2827 <= ((int)0)) ? ((int)0) : ((phasor_2827 >= ((int)1)) ? ((int)1) : phasor_2827));
			int lt_2649 = (clamp_2645 < rsub_2650);
			t_sample sub_3108 = (clamp_2645 - ((int)0));
			t_sample scale_3105 = ((safepow(safediv(sub_3108, irange_3106), ((int)1)) * ((t_sample)0.5)) + ((int)0));
			t_sample scale_2654 = scale_3105;
			t_sample sub_3112 = (clamp_2645 - rsub_2650);
			t_sample scale_3109 = ((safepow(safediv(sub_3112, irange_3110), ((int)1)) * ((t_sample)0.5)) + ((t_sample)0.5));
			t_sample scale_2652 = scale_3109;
			t_sample switch_2648 = (lt_2649 ? scale_2654 : scale_2652);
			t_sample gen_2655 = switch_2648;
			t_sample mul_2826 = (gen_2655 * ((int)8));
			t_sample floor_2825 = floor(mul_2826);
			t_sample out28 = floor_2825;
			t_sample phasor_2666 = __m_phasor_94(((int)5000), samples_to_seconds);
			t_sample delta_2661 = __m_delta_95(phasor_2666);
			t_sample abs_2665 = fabs(delta_2661);
			int gt_2664 = (abs_2665 > ((t_sample)0.5));
			int change_2663 = __m_change_96(gt_2664);
			int gt_2662 = (change_2663 > ((int)0));
			__m_count_97 = (((int)0) ? 0 : (fixdenorm(__m_count_97 + gt_2662)));
			int carry_98 = 0;
			if ((((int)0) != 0)) {
				__m_count_97 = 0;
				__m_carry_99 = 0;
				
			} else if (((((int)63) > 0) && (__m_count_97 >= ((int)63)))) {
				int wraps_100 = (__m_count_97 / ((int)63));
				__m_carry_99 = (__m_carry_99 + wraps_100);
				__m_count_97 = (__m_count_97 - (wraps_100 * ((int)63)));
				carry_98 = 1;
				
			};
			int counter_2670 = __m_count_97;
			int counter_2671 = carry_98;
			int counter_2672 = __m_carry_99;
			int add_2660 = (counter_2670 + ((int)1));
			t_sample out31 = add_2660;
			bool index_ignore_101 = ((counter_2670 >= grid_matrix_noise_dim) || (counter_2670 < 0));
			// samples grid_matrix_noise channel 1;
			t_sample sample_grid_matrix_noise_2667 = (index_ignore_101 ? 0 : m_grid_matrix_noise_27.read(counter_2670, 0));
			t_sample index_grid_matrix_noise_2668 = counter_2670;
			t_sample out32 = sample_grid_matrix_noise_2667;
			t_sample wrap_2802 = wrap(mul_2826, ((int)0), ((int)1));
			t_sample delta_2777 = __m_delta_102(wrap_2802);
			t_sample abs_2781 = fabs(delta_2777);
			int gt_2780 = (abs_2781 > ((t_sample)0.5));
			int change_2779 = __m_change_103(gt_2780);
			int gt_2778 = (change_2779 > ((int)0));
			int trigger_beat_2688 = gt_2778;
			int trigger_beat_2801 = trigger_beat_2688;
			int trig = (__m_change_104((trigger_beat_2801 > ((int)0))) > ((int)0));
			if (trig) {
				int snare_array_dim = m_snare_array_42.dim;
				int snare_array_channels = m_snare_array_42.channels;
				// samples snare_array channel 1;
				m_hit_1_snare_22 = m_snare_array_42.read(0, 0);
				bool index_ignore_105 = (((int)1) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_2_snare_21 = (index_ignore_105 ? 0 : m_snare_array_42.read(((int)1), 0));
				bool index_ignore_106 = (((int)2) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_3_snare_20 = (index_ignore_106 ? 0 : m_snare_array_42.read(((int)2), 0));
				bool index_ignore_107 = (((int)3) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_4_snare_19 = (index_ignore_107 ? 0 : m_snare_array_42.read(((int)3), 0));
				bool index_ignore_108 = (((int)4) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_5_snare_18 = (index_ignore_108 ? 0 : m_snare_array_42.read(((int)4), 0));
				bool index_ignore_109 = (((int)5) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_6_snare_17 = (index_ignore_109 ? 0 : m_snare_array_42.read(((int)5), 0));
				bool index_ignore_110 = (((int)6) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_7_snare_16 = (index_ignore_110 ? 0 : m_snare_array_42.read(((int)6), 0));
				bool index_ignore_111 = (((int)7) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_8_snare_15 = (index_ignore_111 ? 0 : m_snare_array_42.read(((int)7), 0));
				int hihat_array_dim = m_hihat_array_39.dim;
				int hihat_array_channels = m_hihat_array_39.channels;
				// samples hihat_array channel 1;
				m_hit_1_hihat_14 = m_hihat_array_39.read(0, 0);
				bool index_ignore_112 = (((int)1) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_2_hihat_13 = (index_ignore_112 ? 0 : m_hihat_array_39.read(((int)1), 0));
				bool index_ignore_113 = (((int)2) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_3_hihat_12 = (index_ignore_113 ? 0 : m_hihat_array_39.read(((int)2), 0));
				bool index_ignore_114 = (((int)3) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_4_hihat_11 = (index_ignore_114 ? 0 : m_hihat_array_39.read(((int)3), 0));
				bool index_ignore_115 = (((int)4) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_5_hihat_10 = (index_ignore_115 ? 0 : m_hihat_array_39.read(((int)4), 0));
				bool index_ignore_116 = (((int)5) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_6_hihat_9 = (index_ignore_116 ? 0 : m_hihat_array_39.read(((int)5), 0));
				bool index_ignore_117 = (((int)6) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_7_hihat_8 = (index_ignore_117 ? 0 : m_hihat_array_39.read(((int)6), 0));
				bool index_ignore_118 = (((int)7) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_8_hihat_7 = (index_ignore_118 ? 0 : m_hihat_array_39.read(((int)7), 0));
				// for loop initializer;
				int i_2862 = ((int)0);
				// for loop condition;
				while ((i_2862 < snare_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_3116 = (m_X_40 - ((int)0));
					t_sample scale_3113 = ((safepow((sub_3116 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_3120 = (m_Y_38 - ((int)0));
					t_sample scale_3117 = ((safepow((sub_3120 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_2861 = (round(scale_3113) + round((scale_3117 * ((int)8))));
					int snare_patterns_dim = m_snare_patterns_45.dim;
					int snare_patterns_channels = m_snare_patterns_45.channels;
					bool index_ignore_119 = ((i_2862 >= snare_patterns_dim) || (i_2862 < 0));
					// samples snare_patterns channel 1;
					int chan_120 = c_2861;
					bool chan_ignore_121 = ((chan_120 < 0) || (chan_120 >= snare_patterns_channels));
					t_sample h = ((chan_ignore_121 || index_ignore_119) ? 0 : m_snare_patterns_45.read(i_2862, chan_120));
					int snare_hit_values_dim = m_snare_hit_values_41.dim;
					int snare_hit_values_channels = m_snare_hit_values_41.channels;
					bool index_ignore_122 = ((i_2862 >= snare_hit_values_dim) || (i_2862 < 0));
					// samples snare_hit_values channel 1;
					int chan_123 = c_2861;
					bool chan_ignore_124 = ((chan_123 < 0) || (chan_123 >= snare_hit_values_channels));
					t_sample v = ((chan_ignore_124 || index_ignore_122) ? 0 : m_snare_hit_values_41.read(i_2862, chan_123));
					int hit = ((int)0);
					if (((v < (((int)1) - m_density_snare_49)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_125 = ((i_2862 >= snare_array_dim) || (i_2862 < 0));
					if ((!index_ignore_125)) {
						m_snare_array_42.write(hit, i_2862, 0);
						
					};
					bool chan_ignore_126 = ((((int)1) < 0) || (((int)1) >= snare_array_channels));
					bool index_ignore_127 = ((i_2862 >= snare_array_dim) || (i_2862 < 0));
					if ((!(chan_ignore_126 || index_ignore_127))) {
						m_snare_array_42.write(v, i_2862, ((int)1));
						
					};
					// for loop increment;
					i_2862 = (i_2862 + ((int)1));
					
				};
				// for loop initializer;
				i_2862 = ((int)0);
				// for loop condition;
				while ((i_2862 < hihat_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_3124 = (m_X_40 - ((int)0));
					t_sample scale_3121 = ((safepow((sub_3124 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_3128 = (m_Y_38 - ((int)0));
					t_sample scale_3125 = ((safepow((sub_3128 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_2861 = (round(scale_3121) + round((scale_3125 * ((int)8))));
					int hihat_patterns_dim = m_hihat_patterns_43.dim;
					int hihat_patterns_channels = m_hihat_patterns_43.channels;
					bool index_ignore_128 = ((i_2862 >= hihat_patterns_dim) || (i_2862 < 0));
					// samples hihat_patterns channel 1;
					int chan_129 = c_2861;
					bool chan_ignore_130 = ((chan_129 < 0) || (chan_129 >= hihat_patterns_channels));
					t_sample h = ((chan_ignore_130 || index_ignore_128) ? 0 : m_hihat_patterns_43.read(i_2862, chan_129));
					int hihat_hit_values_dim = m_hihat_hit_values_32.dim;
					int hihat_hit_values_channels = m_hihat_hit_values_32.channels;
					bool index_ignore_131 = ((i_2862 >= hihat_hit_values_dim) || (i_2862 < 0));
					// samples hihat_hit_values channel 1;
					int chan_132 = c_2861;
					bool chan_ignore_133 = ((chan_132 < 0) || (chan_132 >= hihat_hit_values_channels));
					t_sample v = ((chan_ignore_133 || index_ignore_131) ? 0 : m_hihat_hit_values_32.read(i_2862, chan_132));
					int hit = ((int)0);
					if (((v < (((int)1) - m_density_hihat_33)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_134 = ((i_2862 >= hihat_array_dim) || (i_2862 < 0));
					if ((!index_ignore_134)) {
						m_hihat_array_39.write(hit, i_2862, 0);
						
					};
					bool chan_ignore_135 = ((((int)1) < 0) || (((int)1) >= hihat_array_channels));
					bool index_ignore_136 = ((i_2862 >= hihat_array_dim) || (i_2862 < 0));
					if ((!(chan_ignore_135 || index_ignore_136))) {
						m_hihat_array_39.write(v, i_2862, ((int)1));
						
					};
					// for loop increment;
					i_2862 = (i_2862 + ((int)1));
					
				};
				
			};
			t_sample expr_2844 = m_hit_1_snare_22;
			t_sample expr_2845 = m_hit_2_snare_21;
			t_sample expr_2846 = m_hit_3_snare_20;
			t_sample expr_2847 = m_hit_4_snare_19;
			t_sample expr_2848 = m_hit_5_snare_18;
			t_sample expr_2849 = m_hit_6_snare_17;
			t_sample expr_2850 = m_hit_7_snare_16;
			t_sample expr_2851 = m_hit_8_snare_15;
			t_sample expr_2852 = m_hit_1_hihat_14;
			t_sample expr_2853 = m_hit_2_hihat_13;
			t_sample expr_2854 = m_hit_3_hihat_12;
			t_sample expr_2855 = m_hit_4_hihat_11;
			t_sample expr_2856 = m_hit_5_hihat_10;
			t_sample expr_2857 = m_hit_6_hihat_9;
			t_sample expr_2858 = m_hit_7_hihat_8;
			t_sample expr_2859 = m_hit_8_hihat_7;
			t_sample out13 = expr_2846;
			t_sample out11 = expr_2844;
			t_sample out20 = expr_2853;
			t_sample out14 = expr_2847;
			t_sample out19 = expr_2852;
			t_sample out21 = expr_2854;
			t_sample out26 = expr_2859;
			t_sample out18 = expr_2851;
			t_sample out15 = expr_2848;
			t_sample out17 = expr_2850;
			t_sample out12 = expr_2845;
			t_sample out25 = expr_2858;
			t_sample out23 = expr_2856;
			t_sample out22 = expr_2855;
			t_sample out24 = expr_2857;
			t_sample out16 = expr_2849;
			t_sample out27 = trigger_beat_2801;
			int trigger_beat_2698 = trigger_beat_2688;
			__m_latch_137 = ((trigger_beat_2698 != 0) ? floor_2825 : __m_latch_137);
			t_sample latch_2699 = __m_latch_137;
			int eq_2690 = (latch_2699 == ((int)7));
			t_sample out10 = (eq_2690 + expr_2841);
			int eq_2694 = (latch_2699 == ((int)3));
			t_sample out6 = (eq_2694 + expr_2837);
			int eq_2691 = (latch_2699 == ((int)6));
			t_sample out9 = (eq_2691 + expr_2840);
			int eq_2697 = (latch_2699 == ((int)0));
			t_sample out3 = (eq_2697 + expr_2834);
			int eq_2695 = (latch_2699 == ((int)2));
			t_sample out5 = (eq_2695 + expr_2836);
			int eq_2692 = (latch_2699 == ((int)5));
			t_sample out8 = (eq_2692 + expr_2839);
			int eq_2696 = (latch_2699 == ((int)1));
			t_sample out4 = (eq_2696 + expr_2835);
			int eq_2693 = (latch_2699 == ((int)4));
			t_sample out7 = (eq_2693 + expr_2838);
			t_sample phasor_2623 = __m_phasor_138(((int)2), samples_to_seconds);
			int gt_2622 = (phasor_2623 > ((int)0));
			int change_2621 = __m_change_139(gt_2622);
			int gt_2620 = (change_2621 > ((int)0));
			int plusequals_2619 = __m_pluseq_140.post(((int)1), gt_2620, 0);
			int lte_2618 = (plusequals_2619 <= max_2616);
			int gt_2630 = (lte_2618 > ((int)0));
			int change_2629 = __m_change_141(gt_2630);
			int gt_2628 = (change_2629 > ((int)0));
			t_sample switch_2624 = (gt_2628 ? ((int)0) : add_2627);
			int trigger_beat_2787 = trigger_beat_2688;
			int trigger_beat_2798 = trigger_beat_2688;
			t_sample delta_2782 = __m_delta_142(phasor_2827);
			t_sample abs_2786 = fabs(delta_2782);
			int gt_2785 = (abs_2786 > ((t_sample)0.5));
			int change_2784 = __m_change_143(gt_2785);
			int gt_2783 = (change_2784 > ((int)0));
			int trigger_master_2789 = gt_2783;
			__m_count_144 = (trigger_master_2789 ? 0 : (fixdenorm(__m_count_144 + gt_2778)));
			int counter_2792 = __m_count_144;
			int counter_2793 = ((int)0);
			int counter_2794 = ((int)0);
			bool index_ignore_145 = ((counter_2792 >= hihat_array_dim) || (counter_2792 < 0));
			// samples hihat_array channel 1;
			t_sample sample_hihat_array_2790 = (index_ignore_145 ? 0 : m_hihat_array_39.read(counter_2792, 0));
			t_sample index_hihat_array_2791 = counter_2792;
			__m_latch_146 = ((sample_hihat_array_2790 != 0) ? trigger_beat_2787 : __m_latch_146);
			t_sample latch_2795 = __m_latch_146;
			t_sample delta_2760 = __m_delta_147(latch_2795);
			t_sample abs_2764 = fabs(delta_2760);
			int gt_2763 = (abs_2764 > ((t_sample)0.5));
			int change_2762 = __m_change_148(gt_2763);
			int gt_2761 = (change_2762 > ((int)0));
			t_sample plusequals_2770 = __m_pluseq_149.post(((t_sample)0.0003239390994493), gt_2761, 0);
			t_sample clamp_2769 = ((plusequals_2770 <= ((int)0)) ? ((int)0) : ((plusequals_2770 >= ((int)1)) ? ((int)1) : plusequals_2770));
			t_sample sub_3132 = (clamp_2769 - ((int)0));
			t_sample scale_3129 = ((safepow((sub_3132 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample mul_2774 = (scale_3129 * sub_2771);
			bool index_ignore_150 = ((counter_2792 >= kick_array_dim) || (counter_2792 < 0));
			// samples kick_array channel 1;
			t_sample sample_kick_array_2715 = (index_ignore_150 ? 0 : m_kick_array_37.read(counter_2792, 0));
			t_sample index_kick_array_2716 = counter_2792;
			t_sample kick_boolean_2714 = sample_kick_array_2715;
			__m_latch_151 = ((kick_boolean_2714 != 0) ? trigger_beat_2688 : __m_latch_151);
			t_sample latch_2713 = __m_latch_151;
			t_sample delta_2728 = __m_delta_152(latch_2713);
			t_sample abs_2704 = fabs(delta_2728);
			int gt_2703 = (abs_2704 > ((t_sample)0.5));
			int change_2702 = __m_change_153(gt_2703);
			int gt_2701 = (change_2702 > ((int)0));
			t_sample plusequals_2706 = __m_pluseq_154.post(safediv(8, samplerate), gt_2701, 0);
			t_sample clamp_2705 = ((plusequals_2706 <= ((int)0)) ? ((int)0) : ((plusequals_2706 >= ((int)1)) ? ((int)1) : plusequals_2706));
			t_sample sub_3136 = (clamp_2705 - ((int)0));
			t_sample scale_3133 = ((safepow((sub_3136 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_2707 = scale_3133;
			t_sample sub_3140 = (scale_2707 - ((int)1));
			t_sample scale_3137 = ((safepow((sub_3140 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_2710 = scale_3137;
			t_sample sin_2711 = sin(scale_2710);
			t_sample mul_2712 = (scale_2707 * sin_2711);
			t_sample mix_3141 = (mul_2712 + (((t_sample)0.9) * (m_history_1 - mul_2712)));
			t_sample mix_2709 = mix_3141;
			bool index_ignore_155 = ((counter_2792 >= snare_array_dim) || (counter_2792 < 0));
			// samples snare_array channel 1;
			t_sample sample_snare_array_2803 = (index_ignore_155 ? 0 : m_snare_array_42.read(counter_2792, 0));
			t_sample index_snare_array_2804 = counter_2792;
			__m_latch_156 = ((sample_snare_array_2803 != 0) ? trigger_beat_2798 : __m_latch_156);
			t_sample latch_2799 = __m_latch_156;
			t_sample delta_2687 = __m_delta_157(latch_2799);
			t_sample abs_2732 = fabs(delta_2687);
			int gt_2731 = (abs_2732 > ((t_sample)0.5));
			int change_2730 = __m_change_158(gt_2731);
			int gt_2729 = (change_2730 > ((int)0));
			t_sample plusequals_2754 = __m_pluseq_159.post(safediv(13, samplerate), gt_2729, 0);
			t_sample clamp_2753 = ((plusequals_2754 <= ((int)0)) ? ((int)0) : ((plusequals_2754 >= ((int)1)) ? ((int)1) : plusequals_2754));
			t_sample sub_3145 = (clamp_2753 - ((int)0));
			t_sample scale_3142 = ((safepow((sub_3145 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_2757 = (scale_3142 * triangle_2751);
			t_sample plusequals_2739 = __m_pluseq_160.post(safediv(7, samplerate), gt_2729, 0);
			t_sample clamp_2737 = ((plusequals_2739 <= ((int)0)) ? ((int)0) : ((plusequals_2739 >= ((int)1)) ? ((int)1) : plusequals_2739));
			t_sample sub_3149 = (clamp_2737 - ((int)0));
			t_sample scale_3146 = ((safepow((sub_3149 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample mul_2736 = (scale_3146 * sub_2733);
			t_sample plusequals_2747 = __m_pluseq_161.post(safediv(8, samplerate), gt_2729, 0);
			t_sample clamp_2743 = ((plusequals_2747 <= ((int)0)) ? ((int)0) : ((plusequals_2747 >= ((int)1)) ? ((int)1) : plusequals_2747));
			t_sample sub_3153 = (clamp_2743 - ((int)0));
			t_sample scale_3150 = ((safepow((sub_3153 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample mul_2741 = (scale_3150 * mix_2735);
			t_sample plusequals_2748 = __m_pluseq_162.post(safediv(11, samplerate), gt_2729, 0);
			t_sample clamp_2745 = ((plusequals_2748 <= ((int)0)) ? ((int)0) : ((plusequals_2748 >= ((int)1)) ? ((int)1) : plusequals_2748));
			t_sample sub_3157 = (clamp_2745 - ((int)0));
			t_sample scale_3154 = ((safepow((sub_3157 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_2742 = (scale_3154 * triangle_2749);
			t_sample v_163 = (((mul_2742 + mul_2741) + mul_2736) + mul_2757);
			t_sample clamp_2740 = ((v_163 <= min_164) ? min_164 : ((v_163 >= ((int)1)) ? ((int)1) : v_163));
			t_sample out1 = ((clamp_2740 + mul_2774) + mix_2709);
			t_sample out2 = ((clamp_2740 + mul_2774) + mix_2709);
			t_sample history_2734_next_2863 = fixdenorm(mix_2735);
			t_sample history_2755_next_2864 = fixdenorm(mix_2756);
			t_sample history_2772_next_2865 = fixdenorm(mix_2773);
			t_sample history_2596_next_2866 = fixdenorm(wrap_2599);
			t_sample history_2625_next_2867 = fixdenorm(switch_2624);
			t_sample history_2708_next_2868 = fixdenorm(mix_2709);
			m_history_23 = history_2607_next_2610;
			m_history_6 = history_2734_next_2863;
			m_history_5 = history_2755_next_2864;
			m_history_4 = history_2772_next_2865;
			m_history_3 = history_2596_next_2866;
			m_history_2 = history_2625_next_2867;
			m_history_1 = history_2708_next_2868;
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
	inline void set_swing(t_param _value) {
		m_swing_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cv2(t_param _value) {
		m_cv_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_grid_matrix_noise(void * _value) {
		m_grid_matrix_noise_27.setbuffer(_value);
	};
	inline void set_noise_array(void * _value) {
		m_noise_array_28.setbuffer(_value);
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_hit_values(void * _value) {
		m_hihat_hit_values_32.setbuffer(_value);
	};
	inline void set_density_hihat(t_param _value) {
		m_density_hihat_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_kick_array(void * _value) {
		m_kick_array_37.setbuffer(_value);
	};
	inline void set_Y(t_param _value) {
		m_Y_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_array(void * _value) {
		m_hihat_array_39.setbuffer(_value);
	};
	inline void set_X(t_param _value) {
		m_X_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_hit_values(void * _value) {
		m_snare_hit_values_41.setbuffer(_value);
	};
	inline void set_snare_array(void * _value) {
		m_snare_array_42.setbuffer(_value);
	};
	inline void set_hihat_patterns(void * _value) {
		m_hihat_patterns_43.setbuffer(_value);
	};
	inline void set_bpm(t_param _value) {
		m_bpm_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_patterns(void * _value) {
		m_snare_patterns_45.setbuffer(_value);
	};
	inline void set_sw7(t_param _value) {
		m_sw_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_mix(t_param _value) {
		m_mix_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_density_snare(t_param _value) {
		m_density_snare_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_X_40; break;
		case 1: *value = self->m_Y_38; break;
		case 2: *value = self->m_bpm_44; break;
		case 3: *value = self->m_cv_25; break;
		case 4: *value = self->m_density_hihat_33; break;
		case 5: *value = self->m_density_snare_49; break;
		case 6: *value = self->m_gatein_29; break;
		
		
		
		
		
		case 12: *value = self->m_mix_47; break;
		
		
		
		
		case 17: *value = self->m_sw_30; break;
		case 18: *value = self->m_sw_34; break;
		case 19: *value = self->m_sw_26; break;
		case 20: *value = self->m_sw_31; break;
		case 21: *value = self->m_sw_35; break;
		case 22: *value = self->m_sw_36; break;
		case 23: *value = self->m_sw_46; break;
		case 24: *value = self->m_sw_48; break;
		case 25: *value = self->m_swing_24; break;
		
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
	// initialize parameter 0 ("m_X_40")
	pi = self->__commonstate.params + 0;
	pi->name = "X";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_X_40;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_Y_38")
	pi = self->__commonstate.params + 1;
	pi->name = "Y";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Y_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_bpm_44")
	pi = self->__commonstate.params + 2;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_cv_25")
	pi = self->__commonstate.params + 3;
	pi->name = "cv2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_density_hihat_33")
	pi = self->__commonstate.params + 4;
	pi->name = "density_hihat";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_density_hihat_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_density_snare_49")
	pi = self->__commonstate.params + 5;
	pi->name = "density_snare";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_density_snare_49;
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
	// initialize parameter 7 ("m_grid_matrix_noise_27")
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
	// initialize parameter 8 ("m_hihat_array_39")
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
	// initialize parameter 9 ("m_hihat_hit_values_32")
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
	// initialize parameter 10 ("m_hihat_patterns_43")
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
	// initialize parameter 11 ("m_kick_array_37")
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
	// initialize parameter 12 ("m_mix_47")
	pi = self->__commonstate.params + 12;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_noise_array_28")
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
	// initialize parameter 14 ("m_snare_array_42")
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
	// initialize parameter 15 ("m_snare_hit_values_41")
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
	// initialize parameter 16 ("m_snare_patterns_45")
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
	// initialize parameter 17 ("m_sw_30")
	pi = self->__commonstate.params + 17;
	pi->name = "sw1";
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
	// initialize parameter 18 ("m_sw_34")
	pi = self->__commonstate.params + 18;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_26")
	pi = self->__commonstate.params + 19;
	pi->name = "sw3";
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
	// initialize parameter 20 ("m_sw_31")
	pi = self->__commonstate.params + 20;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_sw_35")
	pi = self->__commonstate.params + 21;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_35;
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
	// initialize parameter 23 ("m_sw_46")
	pi = self->__commonstate.params + 23;
	pi->name = "sw7";
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
	// initialize parameter 24 ("m_sw_48")
	pi = self->__commonstate.params + 24;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 25 ("m_swing_24")
	pi = self->__commonstate.params + 25;
	pi->name = "swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_swing_24;
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


} // Kronos_2dKhairos::
