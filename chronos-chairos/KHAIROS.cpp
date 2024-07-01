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
	Change __m_change_74;
	Change __m_change_71;
	Change __m_change_70;
	Change __m_change_69;
	Change __m_change_68;
	Change __m_change_135;
	Change __m_change_100;
	Change __m_change_101;
	Change __m_change_93;
	Change __m_change_72;
	Change __m_change_73;
	Change __m_change_140;
	Change __m_change_145;
	Change __m_change_150;
	Change __m_change_155;
	Change __m_change_67;
	Data m_snare_array_50;
	Data m_snare_patterns_51;
	Data m_snare_hit_values_52;
	Data m_noise_array_56;
	Data m_hihat_hit_values_53;
	Data m_kick_array_58;
	Data m_hihat_array_49;
	Data m_grid_matrix_noise_41;
	Data m_hihat_patterns_43;
	Delta __m_delta_92;
	Delta __m_delta_149;
	Delta __m_delta_154;
	Delta __m_delta_144;
	Delta __m_delta_139;
	Delta __m_delta_99;
	Phasor __m_phasor_91;
	Phasor __m_phasor_137;
	Phasor __m_phasor_138;
	PlusEquals __m_pluseq_157;
	PlusEquals __m_pluseq_158;
	PlusEquals __m_pluseq_156;
	PlusEquals __m_pluseq_151;
	PlusEquals __m_pluseq_136;
	PlusEquals __m_pluseq_146;
	PlusEquals __m_pluseq_159;
	int __exception;
	int vectorsize;
	int __loopcount;
	t_sample m_hit_8_snare_14;
	t_sample m_hit_1_hihat_13;
	t_sample m_hit_2_hihat_12;
	t_sample m_hit_3_hihat_11;
	t_sample __m_latch_134;
	t_sample m_hit_7_snare_15;
	t_sample m_hit_6_snare_16;
	t_sample m_hit_4_snare_18;
	t_sample m_hit_4_hihat_10;
	t_sample __m_count_94;
	t_sample m_hit_5_snare_17;
	t_sample __m_carry_96;
	t_sample m_hit_3_snare_19;
	t_sample m_hit_5_hihat_9;
	t_sample __m_latch_143;
	t_sample __m_latch_153;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample __m_count_141;
	t_sample m_history_4;
	t_sample __m_latch_148;
	t_sample m_hit_6_hihat_8;
	t_sample m_history_5;
	t_sample m_hit_7_hihat_7;
	t_sample m_hit_8_hihat_6;
	t_sample m_hit_2_snare_20;
	t_sample samples_to_seconds;
	t_sample m_hit_1_snare_21;
	t_sample m_knob2_X_48;
	t_sample m_knob3_Y_47;
	t_sample m_sw_35;
	t_sample m_led_33;
	t_sample m_led_34;
	t_sample m_led_32;
	t_sample m_sw_46;
	t_sample m_sw_44;
	t_sample m_knob4_swing_40;
	t_sample m_knob5_snareDensity_45;
	t_sample m_mix_37;
	t_sample m_sw_36;
	t_sample m_sw_42;
	t_sample m_knob6_hihatDensity_38;
	t_sample m_led_31;
	t_sample m_sw_55;
	t_sample m_y_25;
	t_sample m_x_26;
	t_sample m_z_24;
	t_sample m_history_22;
	t_sample m_history_23;
	t_sample m_knob1_bpm_54;
	t_sample m_led_27;
	t_sample elapsed;
	t_sample m_led_30;
	t_sample m_led_28;
	t_sample m_sw_57;
	t_sample m_led_29;
	t_sample m_sw_39;
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
		m_hit_8_hihat_6 = ((int)0);
		m_hit_7_hihat_7 = ((int)0);
		m_hit_6_hihat_8 = ((int)0);
		m_hit_5_hihat_9 = ((int)0);
		m_hit_4_hihat_10 = ((int)0);
		m_hit_3_hihat_11 = ((int)0);
		m_hit_2_hihat_12 = ((int)0);
		m_hit_1_hihat_13 = ((int)0);
		m_hit_8_snare_14 = ((int)0);
		m_hit_7_snare_15 = ((int)0);
		m_hit_6_snare_16 = ((int)0);
		m_hit_5_snare_17 = ((int)0);
		m_hit_4_snare_18 = ((int)0);
		m_hit_3_snare_19 = ((int)0);
		m_hit_2_snare_20 = ((int)0);
		m_hit_1_snare_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_z_24 = ((int)0);
		m_y_25 = ((int)0);
		m_x_26 = ((int)0);
		m_led_27 = ((int)0);
		m_led_28 = ((int)0);
		m_led_29 = ((int)0);
		m_led_30 = ((int)0);
		m_led_31 = ((int)0);
		m_led_32 = ((int)0);
		m_led_33 = ((int)0);
		m_led_34 = ((int)0);
		m_sw_35 = ((int)0);
		m_sw_36 = ((int)0);
		m_mix_37 = ((t_sample)0.5);
		m_knob6_hihatDensity_38 = ((int)1);
		m_sw_39 = ((int)0);
		m_knob4_swing_40 = ((int)0);
		m_grid_matrix_noise_41.reset("grid_matrix_noise", ((int)64), ((int)1));
		m_sw_42 = ((int)0);
		m_hihat_patterns_43.reset("hihat_patterns", ((int)8), ((int)64));
		m_sw_44 = ((int)0);
		m_knob5_snareDensity_45 = ((int)1);
		m_sw_46 = ((int)0);
		m_knob3_Y_47 = ((int)0);
		m_knob2_X_48 = ((int)0);
		m_hihat_array_49.reset("hihat_array", ((int)8), ((int)2));
		m_snare_array_50.reset("snare_array", ((int)8), ((int)2));
		m_snare_patterns_51.reset("snare_patterns", ((int)8), ((int)64));
		m_snare_hit_values_52.reset("snare_hit_values", ((int)8), ((int)64));
		m_hihat_hit_values_53.reset("hihat_hit_values", ((int)8), ((int)64));
		m_knob1_bpm_54 = ((int)0);
		m_sw_55 = ((int)0);
		m_noise_array_56.reset("noise_array", ((int)48000), ((int)1));
		m_sw_57 = ((int)0);
		m_kick_array_58.reset("kick_array", ((int)8), ((int)1));
		elapsed = 0;
		__m_change_67.reset(0);
		__m_change_68.reset(0);
		__m_change_69.reset(0);
		__m_change_70.reset(0);
		__m_change_71.reset(0);
		__m_change_72.reset(0);
		__m_change_73.reset(0);
		__m_change_74.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_91.reset(0);
		__m_delta_92.reset(0);
		__m_change_93.reset(0);
		__m_count_94 = 0;
		__m_carry_96 = 0;
		__m_delta_99.reset(0);
		__m_change_100.reset(0);
		__m_change_101.reset(0);
		__m_latch_134 = 0;
		__m_change_135.reset(0);
		__m_pluseq_136.reset(0);
		__m_phasor_137.reset(0);
		__m_phasor_138.reset(0);
		__m_delta_139.reset(0);
		__m_change_140.reset(0);
		__m_count_141 = 0;
		__m_latch_143 = 0;
		__m_delta_144.reset(0);
		__m_change_145.reset(0);
		__m_pluseq_146.reset(0);
		__m_latch_148 = 0;
		__m_delta_149.reset(0);
		__m_change_150.reset(0);
		__m_pluseq_151.reset(0);
		__m_latch_153 = 0;
		__m_delta_154.reset(0);
		__m_change_155.reset(0);
		__m_pluseq_156.reset(0);
		__m_pluseq_157.reset(0);
		__m_pluseq_158.reset(0);
		__m_pluseq_159.reset(0);
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
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) || (__out15 == 0) || (__out16 == 0) || (__out17 == 0) || (__out18 == 0) || (__out19 == 0) || (__out20 == 0) || (__out21 == 0) || (__out22 == 0) || (__out23 == 0) || (__out24 == 0) || (__out25 == 0) || (__out26 == 0) || (__out27 == 0) || (__out28 == 0) || (__out29 == 0) || (__out30 == 0) || (__out31 == 0) || (__out32 == 0) || (__out33 == 0) || (__out34 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		t_sample sub_22635 = (m_knob2_X_48 - ((int)0));
		t_sample scale_22632 = ((safepow((sub_22635 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_22187 = round(scale_22632);
		t_sample sub_22639 = (m_knob3_Y_47 - ((int)0));
		t_sample scale_22636 = ((safepow((sub_22639 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_22188 = round(scale_22636);
		int iftrue_90 = (-10000000000);
		t_sample mstosamps_21717 = (((int)1) * (samplerate * 0.001));
		t_sample max_21718 = ((mstosamps_21717 < vectorsize) ? vectorsize : mstosamps_21717);
		t_sample sub_22656 = (m_knob1_bpm_54 - ((int)0));
		t_sample scale_22653 = ((safepow((sub_22656 * ((t_sample)1)), ((int)1)) * ((int)-460)) + ((int)500));
		t_sample scale_21808 = scale_22653;
		t_sample div_21909 = (scale_21808 * ((t_sample)0.016666666666667));
		t_sample div_21770 = (div_21909 * ((t_sample)0.125));
		t_sample div_21662 = safediv(div_21770, samplerate);
		samples_to_seconds = (1 / samplerate);
		int grid_matrix_noise_dim = m_grid_matrix_noise_41.dim;
		int grid_matrix_noise_channels = m_grid_matrix_noise_41.channels;
		int kick_array_dim = m_kick_array_58.dim;
		int kick_array_channels = m_kick_array_58.channels;
		int hihat_array_dim = m_hihat_array_49.dim;
		int hihat_array_channels = m_hihat_array_49.channels;
		int snare_array_dim = m_snare_array_50.dim;
		int snare_array_channels = m_snare_array_50.channels;
		int min_161 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
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
					int i = ((int)0);
					// for loop condition;
					while ((i < ((int)8))) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample noise_22613 = noise();
						t_sample sub_22616 = (noise_22613 - (-1));
						t_sample scale_22612 = ((safepow((sub_22616 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						t_sample noise_22623 = noise();
						t_sample sub_22626 = (noise_22623 - (-1));
						t_sample scale_22622 = ((safepow((sub_22626 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						int snare_patterns_dim = m_snare_patterns_51.dim;
						int snare_patterns_channels = m_snare_patterns_51.channels;
						bool chan_ignore_59 = ((c < 0) || (c >= snare_patterns_channels));
						bool index_ignore_60 = ((i >= snare_patterns_dim) || (i < 0));
						if ((!(chan_ignore_59 || index_ignore_60))) {
							m_snare_patterns_51.write(((int)1), i, c);
							
						};
						int snare_hit_values_dim = m_snare_hit_values_52.dim;
						int snare_hit_values_channels = m_snare_hit_values_52.channels;
						bool chan_ignore_61 = ((c < 0) || (c >= snare_hit_values_channels));
						bool index_ignore_62 = ((i >= snare_hit_values_dim) || (i < 0));
						if ((!(chan_ignore_61 || index_ignore_62))) {
							m_snare_hit_values_52.write(scale_22612, i, c);
							
						};
						int hihat_patterns_dim = m_hihat_patterns_43.dim;
						int hihat_patterns_channels = m_hihat_patterns_43.channels;
						bool chan_ignore_63 = ((c < 0) || (c >= hihat_patterns_channels));
						bool index_ignore_64 = ((i >= hihat_patterns_dim) || (i < 0));
						if ((!(chan_ignore_63 || index_ignore_64))) {
							m_hihat_patterns_43.write(((int)1), i, c);
							
						};
						int hihat_hit_values_dim = m_hihat_hit_values_53.dim;
						int hihat_hit_values_channels = m_hihat_hit_values_53.channels;
						bool chan_ignore_65 = ((c < 0) || (c >= hihat_hit_values_channels));
						bool index_ignore_66 = ((i >= hihat_hit_values_dim) || (i < 0));
						if ((!(chan_ignore_65 || index_ignore_66))) {
							m_hihat_hit_values_53.write(scale_22622, i, c);
							
						};
						// for loop increment;
						i = (i + ((int)1));
						
					};
					// for loop increment;
					c = (c + ((int)1));
					
				};
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			t_sample out29 = expr_22187;
			int sw_1 = (__m_change_67((m_sw_57 > ((int)0))) > ((int)0));
			int sw_2 = (__m_change_68((m_sw_46 > ((int)0))) > ((int)0));
			int sw_3 = (__m_change_69((m_sw_36 > ((int)0))) > ((int)0));
			int sw_4 = (__m_change_70((m_sw_42 > ((int)0))) > ((int)0));
			int sw_5 = (__m_change_71((m_sw_35 > ((int)0))) > ((int)0));
			int sw_6 = (__m_change_72((m_sw_44 > ((int)0))) > ((int)0));
			int sw_7 = (__m_change_73((m_sw_55 > ((int)0))) > ((int)0));
			int sw_8 = (__m_change_74((m_sw_39 > ((int)0))) > ((int)0));
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i_22216 = ((int)0);
				// for loop condition;
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				while ((i_22216 < kick_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					bool index_ignore_75 = ((i_22216 >= kick_array_dim) || (i_22216 < 0));
					if ((!index_ignore_75)) {
						m_kick_array_58.write(((int)0), i_22216, 0);
						
					};
					// for loop increment;
					i_22216 = (i_22216 + ((int)1));
					
				};
				m_led_34 = ((int)1);
				m_led_33 = ((int)1);
				m_led_32 = ((int)1);
				m_led_31 = ((int)1);
				m_led_30 = ((int)1);
				m_led_29 = ((int)1);
				m_led_28 = ((int)1);
				m_led_27 = ((int)1);
				
			};
			if (sw_1) {
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				// samples kick_array channel 1;
				t_sample a = m_kick_array_58.read(0, 0);
				m_kick_array_58.write((!a), 0, 0);
				m_led_34 = a;
				
			};
			if (sw_2) {
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				bool index_ignore_76 = (((int)1) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_76 ? 0 : m_kick_array_58.read(((int)1), 0));
				bool index_ignore_77 = (((int)1) >= kick_array_dim);
				if ((!index_ignore_77)) {
					m_kick_array_58.write((!a), ((int)1), 0);
					
				};
				m_led_33 = a;
				
			};
			if (sw_3) {
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				bool index_ignore_78 = (((int)2) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_78 ? 0 : m_kick_array_58.read(((int)2), 0));
				bool index_ignore_79 = (((int)2) >= kick_array_dim);
				if ((!index_ignore_79)) {
					m_kick_array_58.write((!a), ((int)2), 0);
					
				};
				m_led_32 = a;
				
			};
			if (sw_4) {
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				bool index_ignore_80 = (((int)3) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_80 ? 0 : m_kick_array_58.read(((int)3), 0));
				bool index_ignore_81 = (((int)3) >= kick_array_dim);
				if ((!index_ignore_81)) {
					m_kick_array_58.write((!a), ((int)3), 0);
					
				};
				m_led_31 = a;
				
			};
			if (sw_5) {
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				bool index_ignore_82 = (((int)4) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_82 ? 0 : m_kick_array_58.read(((int)4), 0));
				bool index_ignore_83 = (((int)4) >= kick_array_dim);
				if ((!index_ignore_83)) {
					m_kick_array_58.write((!a), ((int)4), 0);
					
				};
				m_led_30 = a;
				
			};
			if (sw_6) {
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				bool index_ignore_84 = (((int)5) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_84 ? 0 : m_kick_array_58.read(((int)5), 0));
				bool index_ignore_85 = (((int)5) >= kick_array_dim);
				if ((!index_ignore_85)) {
					m_kick_array_58.write((!a), ((int)5), 0);
					
				};
				m_led_29 = a;
				
			};
			if (sw_7) {
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				bool index_ignore_86 = (((int)6) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_86 ? 0 : m_kick_array_58.read(((int)6), 0));
				bool index_ignore_87 = (((int)6) >= kick_array_dim);
				if ((!index_ignore_87)) {
					m_kick_array_58.write((!a), ((int)6), 0);
					
				};
				m_led_28 = a;
				
			};
			if (sw_8) {
				int kick_array_dim = m_kick_array_58.dim;
				int kick_array_channels = m_kick_array_58.channels;
				bool index_ignore_88 = (((int)7) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_88 ? 0 : m_kick_array_58.read(((int)7), 0));
				bool index_ignore_89 = (((int)7) >= kick_array_dim);
				if ((!index_ignore_89)) {
					m_kick_array_58.write((!a), ((int)7), 0);
					
				};
				m_led_27 = a;
				
			};
			t_sample expr_22190 = m_led_34;
			t_sample expr_22191 = m_led_33;
			t_sample expr_22192 = m_led_32;
			t_sample expr_22193 = m_led_31;
			t_sample expr_22194 = m_led_30;
			t_sample expr_22195 = m_led_29;
			t_sample expr_22196 = m_led_28;
			t_sample expr_22197 = m_led_27;
			t_sample out30 = expr_22188;
			t_sample noise_21856 = noise();
			t_sample mix_22646 = (noise_21856 + (((t_sample)0.7) * (m_history_5 - noise_21856)));
			t_sample mix_21854 = mix_22646;
			t_sample noise_21839 = noise();
			t_sample mix_22647 = (noise_21839 + (((t_sample)0.5) * (m_history_4 - noise_21839)));
			t_sample mix_21816 = mix_22647;
			t_sample mix_22648 = (mix_21816 + (((t_sample)0.6) * (m_history_3 - mix_21816)));
			t_sample mix_21837 = mix_22648;
			int or_21668 = (((int)0) || (elapsed == ((int)0)));
			t_sample switch_21671 = (or_21668 ? ((t_sample)0.31) : m_z_24);
			t_sample mul_21688 = (switch_21671 * ((int)1));
			t_sample switch_21669 = (or_21668 ? ((t_sample)0.1) : m_x_26);
			t_sample switch_21670 = (or_21668 ? ((t_sample)0.41) : m_y_25);
			t_sample mul_21683 = (switch_21670 * ((int)1));
			t_sample mul_21692 = (mul_21683 * ((t_sample)0.0002));
			t_sample add_21686 = (switch_21669 + mul_21692);
			t_sample fixnan_21672 = fixnan(add_21686);
			t_sample mul_21691 = (mul_21688 * ((t_sample)0.0002));
			t_sample add_21685 = (switch_21670 + mul_21691);
			t_sample fixnan_21674 = fixnan(add_21685);
			t_sample gen_21697 = fixnan_21674;
			t_sample mul_21680 = (switch_21671 * (-0.45));
			t_sample pow_21678 = safepow(switch_21669, ((int)3));
			t_sample mul_21679 = (pow_21678 * (-1));
			t_sample mul_21682 = (switch_21669 * ((t_sample)0.8));
			t_sample mul_21681 = (switch_21670 * (-1.1));
			t_sample add_21677 = (mul_21682 + mul_21681);
			t_sample add_21676 = (add_21677 + mul_21680);
			t_sample add_21675 = (add_21676 + mul_21679);
			t_sample mul_21690 = (add_21675 * ((t_sample)0.0002));
			t_sample add_21684 = (switch_21671 + mul_21690);
			t_sample fixnan_21673 = fixnan(add_21684);
			t_sample x_next_21693 = fixdenorm(fixnan_21672);
			t_sample y_next_21694 = fixdenorm(fixnan_21674);
			t_sample z_next_21695 = fixdenorm(fixnan_21673);
			t_sample elapsed_21700 = elapsed;
			int eq_21699 = (elapsed_21700 == ((int)0));
			int or_21707 = (eq_21699 || ((int)0));
			t_sample switch_21703 = (or_21707 ? ((int)10000000000) : m_history_23);
			t_sample min_21706 = ((switch_21703 < gen_21697) ? switch_21703 : gen_21697);
			t_sample gen_21710 = min_21706;
			t_sample switch_21702 = (or_21707 ? iftrue_90 : m_history_22);
			t_sample max_21705 = ((gen_21697 < switch_21702) ? switch_21702 : gen_21697);
			t_sample gen_21711 = max_21705;
			t_sample history_21701_next_21708 = fixdenorm(min_21706);
			t_sample history_21704_next_21709 = fixdenorm(max_21705);
			t_sample irange_22650 = (gen_21711 - gen_21710);
			t_sample sub_22652 = (gen_21697 - gen_21710);
			t_sample scale_22649 = ((safepow(safediv(sub_22652, irange_22650), ((int)1)) * ((int)2)) + ((int)-1));
			t_sample scale_21712 = scale_22649;
			t_sample gen_21713 = scale_21712;
			t_sample mul_21660 = (m_knob4_swing_40 * gen_21713);
			t_sample out33 = mul_21660;
			t_sample sub_21852 = (noise_21856 - mix_21854);
			t_sample mul_21666 = (div_21662 * mul_21660);
			t_sample add_21661 = (div_21662 + mul_21666);
			t_sample add_21665 = (m_history_2 + add_21661);
			t_sample wrap_21663 = wrap(add_21665, ((int)0), ((int)1));
			t_sample mul_21907 = (wrap_21663 * ((int)8));
			t_sample floor_21906 = floor(mul_21907);
			t_sample out28 = floor_21906;
			t_sample phasor_21746 = __m_phasor_91(((int)5000), samples_to_seconds);
			t_sample delta_21741 = __m_delta_92(phasor_21746);
			t_sample abs_21745 = fabs(delta_21741);
			int gt_21744 = (abs_21745 > ((t_sample)0.5));
			int change_21743 = __m_change_93(gt_21744);
			int gt_21742 = (change_21743 > ((int)0));
			__m_count_94 = (((int)0) ? 0 : (fixdenorm(__m_count_94 + gt_21742)));
			int carry_95 = 0;
			if ((((int)0) != 0)) {
				__m_count_94 = 0;
				__m_carry_96 = 0;
				
			} else if (((((int)63) > 0) && (__m_count_94 >= ((int)63)))) {
				int wraps_97 = (__m_count_94 / ((int)63));
				__m_carry_96 = (__m_carry_96 + wraps_97);
				__m_count_94 = (__m_count_94 - (wraps_97 * ((int)63)));
				carry_95 = 1;
				
			};
			int counter_21750 = __m_count_94;
			int counter_21751 = carry_95;
			int counter_21752 = __m_carry_96;
			bool index_ignore_98 = ((counter_21750 >= grid_matrix_noise_dim) || (counter_21750 < 0));
			// samples grid_matrix_noise channel 1;
			t_sample sample_grid_matrix_noise_21747 = (index_ignore_98 ? 0 : m_grid_matrix_noise_41.read(counter_21750, 0));
			t_sample index_grid_matrix_noise_21748 = counter_21750;
			t_sample out32 = sample_grid_matrix_noise_21747;
			int add_21740 = (counter_21750 + ((int)1));
			t_sample out31 = add_21740;
			t_sample wrap_21883 = wrap(mul_21907, ((int)0), ((int)1));
			t_sample delta_21858 = __m_delta_99(wrap_21883);
			t_sample abs_21862 = fabs(delta_21858);
			int gt_21861 = (abs_21862 > ((t_sample)0.5));
			int change_21860 = __m_change_100(gt_21861);
			int gt_21859 = (change_21860 > ((int)0));
			int trigger_beat_21779 = gt_21859;
			int trigger_beat_21882 = trigger_beat_21779;
			int trig = (__m_change_101((trigger_beat_21882 > ((int)0))) > ((int)0));
			if (trig) {
				int snare_array_dim = m_snare_array_50.dim;
				int snare_array_channels = m_snare_array_50.channels;
				// samples snare_array channel 1;
				m_hit_1_snare_21 = m_snare_array_50.read(0, 0);
				bool index_ignore_102 = (((int)1) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_2_snare_20 = (index_ignore_102 ? 0 : m_snare_array_50.read(((int)1), 0));
				bool index_ignore_103 = (((int)2) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_3_snare_19 = (index_ignore_103 ? 0 : m_snare_array_50.read(((int)2), 0));
				bool index_ignore_104 = (((int)3) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_4_snare_18 = (index_ignore_104 ? 0 : m_snare_array_50.read(((int)3), 0));
				bool index_ignore_105 = (((int)4) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_5_snare_17 = (index_ignore_105 ? 0 : m_snare_array_50.read(((int)4), 0));
				bool index_ignore_106 = (((int)5) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_6_snare_16 = (index_ignore_106 ? 0 : m_snare_array_50.read(((int)5), 0));
				bool index_ignore_107 = (((int)6) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_7_snare_15 = (index_ignore_107 ? 0 : m_snare_array_50.read(((int)6), 0));
				bool index_ignore_108 = (((int)7) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_8_snare_14 = (index_ignore_108 ? 0 : m_snare_array_50.read(((int)7), 0));
				int hihat_array_dim = m_hihat_array_49.dim;
				int hihat_array_channels = m_hihat_array_49.channels;
				// samples hihat_array channel 1;
				m_hit_1_hihat_13 = m_hihat_array_49.read(0, 0);
				bool index_ignore_109 = (((int)1) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_2_hihat_12 = (index_ignore_109 ? 0 : m_hihat_array_49.read(((int)1), 0));
				bool index_ignore_110 = (((int)2) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_3_hihat_11 = (index_ignore_110 ? 0 : m_hihat_array_49.read(((int)2), 0));
				bool index_ignore_111 = (((int)3) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_4_hihat_10 = (index_ignore_111 ? 0 : m_hihat_array_49.read(((int)3), 0));
				bool index_ignore_112 = (((int)4) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_5_hihat_9 = (index_ignore_112 ? 0 : m_hihat_array_49.read(((int)4), 0));
				bool index_ignore_113 = (((int)5) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_6_hihat_8 = (index_ignore_113 ? 0 : m_hihat_array_49.read(((int)5), 0));
				bool index_ignore_114 = (((int)6) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_7_hihat_7 = (index_ignore_114 ? 0 : m_hihat_array_49.read(((int)6), 0));
				bool index_ignore_115 = (((int)7) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_8_hihat_6 = (index_ignore_115 ? 0 : m_hihat_array_49.read(((int)7), 0));
				// for loop initializer;
				int i_22218 = ((int)0);
				// for loop condition;
				while ((i_22218 < snare_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_22660 = (m_knob2_X_48 - ((int)0));
					t_sample scale_22657 = ((safepow((sub_22660 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_22664 = (m_knob3_Y_47 - ((int)0));
					t_sample scale_22661 = ((safepow((sub_22664 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_22217 = (round(scale_22657) + round((scale_22661 * ((int)8))));
					int snare_patterns_dim = m_snare_patterns_51.dim;
					int snare_patterns_channels = m_snare_patterns_51.channels;
					bool index_ignore_116 = ((i_22218 >= snare_patterns_dim) || (i_22218 < 0));
					// samples snare_patterns channel 1;
					int chan_117 = c_22217;
					bool chan_ignore_118 = ((chan_117 < 0) || (chan_117 >= snare_patterns_channels));
					t_sample h = ((chan_ignore_118 || index_ignore_116) ? 0 : m_snare_patterns_51.read(i_22218, chan_117));
					int snare_hit_values_dim = m_snare_hit_values_52.dim;
					int snare_hit_values_channels = m_snare_hit_values_52.channels;
					bool index_ignore_119 = ((i_22218 >= snare_hit_values_dim) || (i_22218 < 0));
					// samples snare_hit_values channel 1;
					int chan_120 = c_22217;
					bool chan_ignore_121 = ((chan_120 < 0) || (chan_120 >= snare_hit_values_channels));
					t_sample v = ((chan_ignore_121 || index_ignore_119) ? 0 : m_snare_hit_values_52.read(i_22218, chan_120));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob5_snareDensity_45)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_122 = ((i_22218 >= snare_array_dim) || (i_22218 < 0));
					if ((!index_ignore_122)) {
						m_snare_array_50.write(hit, i_22218, 0);
						
					};
					bool chan_ignore_123 = ((((int)1) < 0) || (((int)1) >= snare_array_channels));
					bool index_ignore_124 = ((i_22218 >= snare_array_dim) || (i_22218 < 0));
					if ((!(chan_ignore_123 || index_ignore_124))) {
						m_snare_array_50.write(v, i_22218, ((int)1));
						
					};
					// for loop increment;
					i_22218 = (i_22218 + ((int)1));
					
				};
				// for loop initializer;
				i_22218 = ((int)0);
				// for loop condition;
				while ((i_22218 < hihat_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_22668 = (m_knob2_X_48 - ((int)0));
					t_sample scale_22665 = ((safepow((sub_22668 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_22672 = (m_knob3_Y_47 - ((int)0));
					t_sample scale_22669 = ((safepow((sub_22672 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_22217 = (round(scale_22665) + round((scale_22669 * ((int)8))));
					int hihat_patterns_dim = m_hihat_patterns_43.dim;
					int hihat_patterns_channels = m_hihat_patterns_43.channels;
					bool index_ignore_125 = ((i_22218 >= hihat_patterns_dim) || (i_22218 < 0));
					// samples hihat_patterns channel 1;
					int chan_126 = c_22217;
					bool chan_ignore_127 = ((chan_126 < 0) || (chan_126 >= hihat_patterns_channels));
					t_sample h = ((chan_ignore_127 || index_ignore_125) ? 0 : m_hihat_patterns_43.read(i_22218, chan_126));
					int hihat_hit_values_dim = m_hihat_hit_values_53.dim;
					int hihat_hit_values_channels = m_hihat_hit_values_53.channels;
					bool index_ignore_128 = ((i_22218 >= hihat_hit_values_dim) || (i_22218 < 0));
					// samples hihat_hit_values channel 1;
					int chan_129 = c_22217;
					bool chan_ignore_130 = ((chan_129 < 0) || (chan_129 >= hihat_hit_values_channels));
					t_sample v = ((chan_ignore_130 || index_ignore_128) ? 0 : m_hihat_hit_values_53.read(i_22218, chan_129));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob6_hihatDensity_38)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_131 = ((i_22218 >= hihat_array_dim) || (i_22218 < 0));
					if ((!index_ignore_131)) {
						m_hihat_array_49.write(hit, i_22218, 0);
						
					};
					bool chan_ignore_132 = ((((int)1) < 0) || (((int)1) >= hihat_array_channels));
					bool index_ignore_133 = ((i_22218 >= hihat_array_dim) || (i_22218 < 0));
					if ((!(chan_ignore_132 || index_ignore_133))) {
						m_hihat_array_49.write(v, i_22218, ((int)1));
						
					};
					// for loop increment;
					i_22218 = (i_22218 + ((int)1));
					
				};
				
			};
			t_sample expr_22200 = m_hit_1_snare_21;
			t_sample expr_22201 = m_hit_2_snare_20;
			t_sample expr_22202 = m_hit_3_snare_19;
			t_sample expr_22203 = m_hit_4_snare_18;
			t_sample expr_22204 = m_hit_5_snare_17;
			t_sample expr_22205 = m_hit_6_snare_16;
			t_sample expr_22206 = m_hit_7_snare_15;
			t_sample expr_22207 = m_hit_8_snare_14;
			t_sample expr_22208 = m_hit_1_hihat_13;
			t_sample expr_22209 = m_hit_2_hihat_12;
			t_sample expr_22210 = m_hit_3_hihat_11;
			t_sample expr_22211 = m_hit_4_hihat_10;
			t_sample expr_22212 = m_hit_5_hihat_9;
			t_sample expr_22213 = m_hit_6_hihat_8;
			t_sample expr_22214 = m_hit_7_hihat_7;
			t_sample expr_22215 = m_hit_8_hihat_6;
			t_sample out17 = expr_22206;
			t_sample out12 = expr_22201;
			t_sample out24 = expr_22213;
			t_sample out13 = expr_22202;
			t_sample out11 = expr_22200;
			t_sample out26 = expr_22215;
			t_sample out16 = expr_22205;
			t_sample out19 = expr_22208;
			t_sample out25 = expr_22214;
			t_sample out15 = expr_22204;
			t_sample out23 = expr_22212;
			t_sample out22 = expr_22211;
			t_sample out21 = expr_22210;
			t_sample out18 = expr_22207;
			t_sample out20 = expr_22209;
			t_sample out14 = expr_22203;
			t_sample out27 = trigger_beat_21882;
			__m_latch_134 = ((trigger_beat_21779 != 0) ? floor_21906 : __m_latch_134);
			t_sample latch_21780 = __m_latch_134;
			int eq_21778 = (latch_21780 == ((int)0));
			t_sample out3 = (eq_21778 + expr_22190);
			int eq_21775 = (latch_21780 == ((int)3));
			t_sample out6 = (eq_21775 + expr_22193);
			int eq_21771 = (latch_21780 == ((int)7));
			t_sample out10 = (eq_21771 + expr_22197);
			int eq_21773 = (latch_21780 == ((int)5));
			t_sample out8 = (eq_21773 + expr_22195);
			int eq_21777 = (latch_21780 == ((int)1));
			t_sample out4 = (eq_21777 + expr_22191);
			int eq_21776 = (latch_21780 == ((int)2));
			t_sample out5 = (eq_21776 + expr_22192);
			int eq_21774 = (latch_21780 == ((int)4));
			t_sample out7 = (eq_21774 + expr_22194);
			int eq_21772 = (latch_21780 == ((int)6));
			t_sample out9 = (eq_21772 + expr_22196);
			int trigger_beat_21716 = trigger_beat_21779;
			int gt_21724 = (trigger_beat_21716 > ((int)0));
			int change_21723 = __m_change_135(gt_21724);
			int gt_21722 = (change_21723 > ((int)0));
			int plusequals_21721 = __m_pluseq_136.post(((int)1), gt_21722, 0);
			int lte_21720 = (plusequals_21721 <= max_21718);
			t_sample out34 = lte_21720;
			t_sample sub_21814 = (mix_21816 - mix_21837);
			t_sample phasor_21833 = __m_phasor_137(((int)330), samples_to_seconds);
			t_sample triangle_21832 = triangle(phasor_21833, ((t_sample)0.5));
			t_sample phasor_21831 = __m_phasor_138(((int)185), samples_to_seconds);
			t_sample triangle_21830 = triangle(phasor_21831, ((t_sample)0.5));
			int trigger_beat_21769 = trigger_beat_21779;
			t_sample delta_21863 = __m_delta_139(wrap_21663);
			t_sample abs_21867 = fabs(delta_21863);
			int gt_21866 = (abs_21867 > ((t_sample)0.5));
			int change_21865 = __m_change_140(gt_21866);
			int gt_21864 = (change_21865 > ((int)0));
			int trigger_master_21870 = gt_21864;
			__m_count_141 = (trigger_master_21870 ? 0 : (fixdenorm(__m_count_141 + gt_21859)));
			int counter_21873 = __m_count_141;
			int counter_21874 = ((int)0);
			int counter_21875 = ((int)0);
			bool index_ignore_142 = ((counter_21873 >= kick_array_dim) || (counter_21873 < 0));
			// samples kick_array channel 1;
			t_sample sample_kick_array_21796 = (index_ignore_142 ? 0 : m_kick_array_58.read(counter_21873, 0));
			t_sample index_kick_array_21797 = counter_21873;
			t_sample kick_boolean_21795 = sample_kick_array_21796;
			__m_latch_143 = ((kick_boolean_21795 != 0) ? trigger_beat_21769 : __m_latch_143);
			t_sample latch_21794 = __m_latch_143;
			t_sample delta_21809 = __m_delta_144(latch_21794);
			t_sample abs_21785 = fabs(delta_21809);
			int gt_21784 = (abs_21785 > ((t_sample)0.5));
			int change_21783 = __m_change_145(gt_21784);
			int gt_21782 = (change_21783 > ((int)0));
			t_sample plusequals_21787 = __m_pluseq_146.post(safediv(8, samplerate), gt_21782, 0);
			t_sample clamp_21786 = ((plusequals_21787 <= ((int)0)) ? ((int)0) : ((plusequals_21787 >= ((int)1)) ? ((int)1) : plusequals_21787));
			t_sample sub_22676 = (clamp_21786 - ((int)0));
			t_sample scale_22673 = ((safepow((sub_22676 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_21788 = scale_22673;
			t_sample sub_22680 = (scale_21788 - ((int)1));
			t_sample scale_22677 = ((safepow((sub_22680 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_21791 = scale_22677;
			t_sample sin_21792 = sin(scale_21791);
			t_sample mul_21793 = (scale_21788 * sin_21792);
			t_sample mix_22681 = (mul_21793 + (((t_sample)0.9) * (m_history_1 - mul_21793)));
			t_sample mix_21790 = mix_22681;
			bool index_ignore_147 = ((counter_21873 >= hihat_array_dim) || (counter_21873 < 0));
			// samples hihat_array channel 1;
			t_sample sample_hihat_array_21871 = (index_ignore_147 ? 0 : m_hihat_array_49.read(counter_21873, 0));
			t_sample index_hihat_array_21872 = counter_21873;
			__m_latch_148 = ((sample_hihat_array_21871 != 0) ? trigger_beat_21779 : __m_latch_148);
			t_sample latch_21876 = __m_latch_148;
			t_sample delta_21841 = __m_delta_149(latch_21876);
			t_sample abs_21845 = fabs(delta_21841);
			int gt_21844 = (abs_21845 > ((t_sample)0.5));
			int change_21843 = __m_change_150(gt_21844);
			int gt_21842 = (change_21843 > ((int)0));
			t_sample plusequals_21851 = __m_pluseq_151.post(((t_sample)0.0003239390994493), gt_21842, 0);
			t_sample clamp_21850 = ((plusequals_21851 <= ((int)0)) ? ((int)0) : ((plusequals_21851 >= ((int)1)) ? ((int)1) : plusequals_21851));
			t_sample sub_22685 = (clamp_21850 - ((int)0));
			t_sample scale_22682 = ((safepow((sub_22685 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample mul_21855 = (scale_22682 * sub_21852);
			bool index_ignore_152 = ((counter_21873 >= snare_array_dim) || (counter_21873 < 0));
			// samples snare_array channel 1;
			t_sample sample_snare_array_21884 = (index_ignore_152 ? 0 : m_snare_array_50.read(counter_21873, 0));
			t_sample index_snare_array_21885 = counter_21873;
			__m_latch_153 = ((sample_snare_array_21884 != 0) ? trigger_beat_21779 : __m_latch_153);
			t_sample latch_21880 = __m_latch_153;
			t_sample delta_21768 = __m_delta_154(latch_21880);
			t_sample abs_21813 = fabs(delta_21768);
			int gt_21812 = (abs_21813 > ((t_sample)0.5));
			int change_21811 = __m_change_155(gt_21812);
			int gt_21810 = (change_21811 > ((int)0));
			t_sample plusequals_21835 = __m_pluseq_156.post(safediv(13, samplerate), gt_21810, 0);
			t_sample clamp_21834 = ((plusequals_21835 <= ((int)0)) ? ((int)0) : ((plusequals_21835 >= ((int)1)) ? ((int)1) : plusequals_21835));
			t_sample sub_22689 = (clamp_21834 - ((int)0));
			t_sample scale_22686 = ((safepow((sub_22689 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_21838 = (scale_22686 * triangle_21832);
			t_sample plusequals_21820 = __m_pluseq_157.post(safediv(7, samplerate), gt_21810, 0);
			t_sample clamp_21818 = ((plusequals_21820 <= ((int)0)) ? ((int)0) : ((plusequals_21820 >= ((int)1)) ? ((int)1) : plusequals_21820));
			t_sample sub_22693 = (clamp_21818 - ((int)0));
			t_sample scale_22690 = ((safepow((sub_22693 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample mul_21817 = (scale_22690 * sub_21814);
			t_sample plusequals_21828 = __m_pluseq_158.post(safediv(8, samplerate), gt_21810, 0);
			t_sample clamp_21824 = ((plusequals_21828 <= ((int)0)) ? ((int)0) : ((plusequals_21828 >= ((int)1)) ? ((int)1) : plusequals_21828));
			t_sample sub_22697 = (clamp_21824 - ((int)0));
			t_sample scale_22694 = ((safepow((sub_22697 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample mul_21822 = (scale_22694 * mix_21816);
			t_sample plusequals_21829 = __m_pluseq_159.post(safediv(11, samplerate), gt_21810, 0);
			t_sample clamp_21826 = ((plusequals_21829 <= ((int)0)) ? ((int)0) : ((plusequals_21829 >= ((int)1)) ? ((int)1) : plusequals_21829));
			t_sample sub_22701 = (clamp_21826 - ((int)0));
			t_sample scale_22698 = ((safepow((sub_22701 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_21823 = (scale_22698 * triangle_21830);
			t_sample v_160 = (((mul_21823 + mul_21822) + mul_21817) + mul_21838);
			t_sample clamp_21821 = ((v_160 <= min_161) ? min_161 : ((v_160 >= ((int)1)) ? ((int)1) : v_160));
			t_sample add_21735 = (mul_21855 + clamp_21821);
			t_sample mul_21727 = (add_21735 * ((t_sample)0.5));
			t_sample add_21734 = (mul_21727 + mix_21790);
			t_sample mul_21726 = (add_21734 * ((t_sample)0.5));
			t_sample mix_22702 = (mul_21726 + (((t_sample)0.5) * (in1 - mul_21726)));
			t_sample out1 = mix_22702;
			t_sample add_21732 = (mul_21855 + clamp_21821);
			t_sample mul_21728 = (add_21732 * ((t_sample)0.5));
			t_sample add_21731 = (mul_21728 + mix_21790);
			t_sample mul_21725 = (add_21731 * ((t_sample)0.5));
			t_sample mix_22703 = (mul_21725 + (((t_sample)0.5) * (in2 - mul_21725)));
			t_sample out2 = mix_22703;
			t_sample history_21853_next_22219 = fixdenorm(mix_21854);
			t_sample history_21815_next_22220 = fixdenorm(mix_21816);
			t_sample history_21836_next_22221 = fixdenorm(mix_21837);
			t_sample history_21664_next_22222 = fixdenorm(wrap_21663);
			t_sample history_21789_next_22223 = fixdenorm(mix_21790);
			m_x_26 = x_next_21693;
			m_z_24 = z_next_21695;
			m_y_25 = y_next_21694;
			m_history_23 = history_21701_next_21708;
			m_history_22 = history_21704_next_21709;
			m_history_5 = history_21853_next_22219;
			m_history_4 = history_21815_next_22220;
			m_history_3 = history_21836_next_22221;
			m_history_2 = history_21664_next_22222;
			m_history_1 = history_21789_next_22223;
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
			
		};
		return __exception;
		
	};
	inline void set_sw5(t_param _value) {
		m_sw_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_mix(t_param _value) {
		m_mix_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_hihatDensity(t_param _value) {
		m_knob6_hihatDensity_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_swing(t_param _value) {
		m_knob4_swing_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_grid_matrix_noise(void * _value) {
		m_grid_matrix_noise_41.setbuffer(_value);
	};
	inline void set_sw4(t_param _value) {
		m_sw_42 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_patterns(void * _value) {
		m_hihat_patterns_43.setbuffer(_value);
	};
	inline void set_sw6(t_param _value) {
		m_sw_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_snareDensity(t_param _value) {
		m_knob5_snareDensity_45 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_Y(t_param _value) {
		m_knob3_Y_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_X(t_param _value) {
		m_knob2_X_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_array(void * _value) {
		m_hihat_array_49.setbuffer(_value);
	};
	inline void set_snare_array(void * _value) {
		m_snare_array_50.setbuffer(_value);
	};
	inline void set_snare_patterns(void * _value) {
		m_snare_patterns_51.setbuffer(_value);
	};
	inline void set_snare_hit_values(void * _value) {
		m_snare_hit_values_52.setbuffer(_value);
	};
	inline void set_hihat_hit_values(void * _value) {
		m_hihat_hit_values_53.setbuffer(_value);
	};
	inline void set_knob1_bpm(t_param _value) {
		m_knob1_bpm_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_noise_array(void * _value) {
		m_noise_array_56.setbuffer(_value);
	};
	inline void set_sw1(t_param _value) {
		m_sw_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_kick_array(void * _value) {
		m_kick_array_58.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 34;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 24; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "audio_l", "audio_r" };
const char *gen_kernel_outnames[] = { "sound_l", "sound_r", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "sn1", "sn2", "sn3", "sn4", "sn5", "sn6", "sn7", "sn8", "hi1", "hi2", "hi3", "hi4", "hi5", "hi6", "hi7", "hi8", "trigger_b", "step_value", "x_pos", "y_pos", "out31", "out32", "cvout2", "gateout1" };

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
		case 0: self->set_grid_matrix_noise(ref); break;
		case 1: self->set_hihat_array(ref); break;
		case 2: self->set_hihat_hit_values(ref); break;
		case 3: self->set_hihat_patterns(ref); break;
		case 4: self->set_kick_array(ref); break;
		case 5: self->set_knob1_bpm(value); break;
		case 6: self->set_knob2_X(value); break;
		case 7: self->set_knob3_Y(value); break;
		case 8: self->set_knob4_swing(value); break;
		case 9: self->set_knob5_snareDensity(value); break;
		case 10: self->set_knob6_hihatDensity(value); break;
		case 11: self->set_mix(value); break;
		case 12: self->set_noise_array(ref); break;
		case 13: self->set_snare_array(ref); break;
		case 14: self->set_snare_hit_values(ref); break;
		case 15: self->set_snare_patterns(ref); break;
		case 16: self->set_sw1(value); break;
		case 17: self->set_sw2(value); break;
		case 18: self->set_sw3(value); break;
		case 19: self->set_sw4(value); break;
		case 20: self->set_sw5(value); break;
		case 21: self->set_sw6(value); break;
		case 22: self->set_sw7(value); break;
		case 23: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		
		
		
		
		case 5: *value = self->m_knob1_bpm_54; break;
		case 6: *value = self->m_knob2_X_48; break;
		case 7: *value = self->m_knob3_Y_47; break;
		case 8: *value = self->m_knob4_swing_40; break;
		case 9: *value = self->m_knob5_snareDensity_45; break;
		case 10: *value = self->m_knob6_hihatDensity_38; break;
		case 11: *value = self->m_mix_37; break;
		
		
		
		
		case 16: *value = self->m_sw_57; break;
		case 17: *value = self->m_sw_46; break;
		case 18: *value = self->m_sw_36; break;
		case 19: *value = self->m_sw_42; break;
		case 20: *value = self->m_sw_35; break;
		case 21: *value = self->m_sw_44; break;
		case 22: *value = self->m_sw_55; break;
		case 23: *value = self->m_sw_39; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(24 * sizeof(ParamInfo));
	self->__commonstate.numparams = 24;
	// initialize parameter 0 ("m_grid_matrix_noise_41")
	pi = self->__commonstate.params + 0;
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
	// initialize parameter 1 ("m_hihat_array_49")
	pi = self->__commonstate.params + 1;
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
	// initialize parameter 2 ("m_hihat_hit_values_53")
	pi = self->__commonstate.params + 2;
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
	// initialize parameter 3 ("m_hihat_patterns_43")
	pi = self->__commonstate.params + 3;
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
	// initialize parameter 4 ("m_kick_array_58")
	pi = self->__commonstate.params + 4;
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
	// initialize parameter 5 ("m_knob1_bpm_54")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1_bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_bpm_54;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob2_X_48")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2_X";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_X_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob3_Y_47")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_Y";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_Y_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_swing_40")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_swing_40;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_snareDensity_45")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_snareDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_snareDensity_45;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_hihatDensity_38")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_hihatDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_hihatDensity_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_mix_37")
	pi = self->__commonstate.params + 11;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_noise_array_56")
	pi = self->__commonstate.params + 12;
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
	// initialize parameter 13 ("m_snare_array_50")
	pi = self->__commonstate.params + 13;
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
	// initialize parameter 14 ("m_snare_hit_values_52")
	pi = self->__commonstate.params + 14;
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
	// initialize parameter 15 ("m_snare_patterns_51")
	pi = self->__commonstate.params + 15;
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
	// initialize parameter 16 ("m_sw_57")
	pi = self->__commonstate.params + 16;
	pi->name = "sw1";
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
	// initialize parameter 17 ("m_sw_46")
	pi = self->__commonstate.params + 17;
	pi->name = "sw2";
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
	// initialize parameter 18 ("m_sw_36")
	pi = self->__commonstate.params + 18;
	pi->name = "sw3";
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
	// initialize parameter 19 ("m_sw_42")
	pi = self->__commonstate.params + 19;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_42;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_35")
	pi = self->__commonstate.params + 20;
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
	// initialize parameter 21 ("m_sw_44")
	pi = self->__commonstate.params + 21;
	pi->name = "sw6";
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
	// initialize parameter 22 ("m_sw_55")
	pi = self->__commonstate.params + 22;
	pi->name = "sw7";
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
	// initialize parameter 23 ("m_sw_39")
	pi = self->__commonstate.params + 23;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_39;
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
