import time
from pynq import Overlay
import numpy as np
from pynq import Xlnk

xlnk=Xlnk();

ol=Overlay("dma.bit")
ol.ip_dict
ol.download()
print("Overlay download finish");

dma=ol.axi_dma_0;

input_buffer=xlnk.cma_array(shape=(400,),cacheable=1,dtype=np.int32);
output_buffer=xlnk.cma_array(shape=(400,),cacheable=1,dtype=np.int32);

print("input_buffer.physical_address=%x"%input_buffer.physical_address);

for i in range(input_buffer.shape[0]):
    input_buffer[i]=i;
    output_buffer[i]=0;

output_buffer.invalidate();

input_buffer.flush();

dma.sendchannel.transfer(input_buffer);
dma.recvchannel.transfer(output_buffer);
dma.sendchannel.wait()
dma.recvchannel.wait()

#output_buffer.invalidate();

flag=1;
for i in range(input_buffer.shape[0]):
    #print("output_buffer[%d]=%d"%(i,output_buffer[i]));
    if(output_buffer[i]!=input_buffer[i]):
        flag=0;
        print("input_buffer[%d] =%d"%(i,input_buffer[i]));
        print("output_buffer[%d]=%d"%(i,output_buffer[i]));

if(flag==1):
    print("=================================\n     result match\n=================================");
else:
    print("=================================\n     result mismatch\n=================================");
