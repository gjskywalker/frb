# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7z020clg400-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_msg_config -source 4 -id {IP_Flow 19-2162} -severity warning -new_severity info
set_property webtalk.parent_dir C:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.cache/wt [current_project]
set_property parent.project_path C:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.xpr [current_project]
set_property XPM_LIBRARIES {XPM_CDC XPM_MEMORY} [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_repo_paths {
  c:/Users/Caiyujie/Desktop/gongkaike/PYNQ-2.3/boards/ip
  c:/Users/Caiyujie/Desktop/gongkaike/hls
} [current_project]
add_files C:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/base.bd
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_ps7_0_0/base_ps7_0_0.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_axi_gpio_0_0/base_axi_gpio_0_0_board.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_axi_gpio_0_0/base_axi_gpio_0_0_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_axi_gpio_0_0/base_axi_gpio_0_0.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_rst_ps7_0_100M_0/base_rst_ps7_0_100M_0_board.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_rst_ps7_0_100M_0/base_rst_ps7_0_100M_0.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_rst_ps7_0_100M_0/base_rst_ps7_0_100M_0_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_axi_dma_0_0/base_axi_dma_0_0_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_axi_dma_0_0/base_axi_dma_0_0.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_axi_dma_0_0/base_axi_dma_0_0_clocks.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_xbar_0/base_xbar_0_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_Conv_0_0/constraints/Conv_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_Pool_0_0/constraints/Pool_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_pc_0/base_auto_pc_0_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_pc_1/base_auto_pc_1_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_us_0/base_auto_us_0_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_us_0/base_auto_us_0_clocks.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_pc_2/base_auto_pc_2_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_us_1/base_auto_us_1_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_us_1/base_auto_us_1_clocks.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_pc_3/base_auto_pc_3_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_us_2/base_auto_us_2_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_us_2/base_auto_us_2_clocks.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_pc_4/base_auto_pc_4_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_us_3/base_auto_us_3_ooc.xdc]
set_property used_in_implementation false [get_files -all c:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/ip/base_auto_us_3/base_auto_us_3_clocks.xdc]
set_property used_in_implementation false [get_files -all C:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/base_ooc.xdc]
set_property is_locked true [get_files C:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/base.bd]

read_verilog -library xil_defaultlib C:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/sources_1/bd/base/hdl/base_wrapper.v
foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}
read_xdc C:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/constrs_1/imports/constraints/base.xdc
set_property used_in_implementation false [get_files C:/Users/Caiyujie/Desktop/gongkaike/PYNQ/base/base.srcs/constrs_1/imports/constraints/base.xdc]

read_xdc dont_touch.xdc
set_property used_in_implementation false [get_files dont_touch.xdc]

synth_design -top base_wrapper -part xc7z020clg400-1


write_checkpoint -force -noxdef base_wrapper.dcp

catch { report_utilization -file base_wrapper_utilization_synth.rpt -pb base_wrapper_utilization_synth.pb }