module led(clk, light, rst, state);

input clk,rst;
output[15:0] light;	//1~16LED
output[1:0] state;

reg[15:0] light;
reg[24:0] counter;
reg[3:0] count; 
reg[1:0] state;
reg[1:0] nextState;

parameter s0 = 2'b00, s1 = 2'b01, s2 = 2'b11, s3 = 2'b10;
initial begin
	count = 4'b0000;
	state = 2'b00;
	nextState = 0;
	counter = 0;
	light = 0;
end
always@(posedge clk)

begin
	if(rst)
		begin
			state = s0;
			light = 16'b0000000000000000;
		end
	else
		begin
			state = nextState;
		end
	
	
	case(state)
		//Left to Right
		s0:
			begin
				if(light == 16'b0000000000000000)
					begin
						light = 'b1000000000000000;
					end
				else
					begin
					if(count == 'b1111)
						begin
							count = 0;
							light = 'b0000000000000001;
							nextState = s1;
						end
					else
						begin
							counter = counter + 1;
							if(counter != 25'b1_0111_1101_0111_1000_0100_0000)
								begin
									light = light >> 1;
									counter =0;
									count = count + 1;
									nextState = s0;
								end
						end
					end
			end
		//Right to Left.
		s1:
			begin
				if(count == 'b1111)
					begin
						count = 0;
						light = 'b0000000110000000;
						nextState = s2;
					end
				else
					begin
						counter = counter + 1;
						if(counter != 25'b1_0111_1101_0111_1000_0100_0000)
							begin
								light = light << 1;
								counter = 0;
								count = count +1;
								nextState = s1;
							end
					end
			end
		//Insidt to Outside
		s2:
			begin
				if(count == 'b0111)
					begin
						count = 0;
						light = 'b1000000000000001;
						nextState = s3;
					end
				else
					begin
						counter = counter + 1;
						if(counter != 25'b1_0111_1101_0111_1000_0100_0000)
							begin
								light[15:8] = light[15:8] << 1;
								light[7:0] = light[7:0] >> 1;
								counter = 0;
								count = count+1;
								nextState = s2;
							end
					end
			end
			
		//Insidt to Outside
		s3:
			begin
				if(count == 'b0111)
					begin
						count = 0;
						light = 'b1000000000000000;
						nextState = s0;
					end
				else
					begin
						counter = counter + 1;
						if(counter != 25'b1_0111_1101_0111_1000_0100_0000)
							begin
								light[15:8] = light[15:8] >> 1;
								light[7:0] = light[7:0]<<1;
								counter = 0;
								count = count + 1;	
								nextState = s3;							 
							end
					end
			end
	endcase
end
endmodule

module test;
reg clk,rst;
wire[15:0] light;	//1~16LED
wire[1:0] state;

led test(clk, light, rst, state);

initial begin
	clk = 0;
	rst = 0;
end

always #5 clk = ~clk;

initial #2000 $finish;

endmodule
