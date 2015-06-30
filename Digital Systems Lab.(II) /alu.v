module alu(input [7:0] data, input [7:0] accum,input reset,input clk,
           input [2:0] op, output reg [7:0] y, output reg zero);
           
always@(posedge clk) begin
  case(op)
    3'b000: y = accum;
    3'b001: y = accum + data;
    3'b010: y = accum - data;
    3'b011: y = accum | data;
    3'b100: y = accum ^ data;
    3'b101: if(accum[7] == 1)
				y = 1+(~accum);
			else
				y = accum[7:0];
    3'b110: y = accum*5 + accum/8;
    3'b111: if(accum > 128)
				y=~accum+1;
			else
				y=~accum;
  endcase
	if	(reset == 1)
		y = 0;
	if(y == 0)
		zero = 1;
	else
		zero = 0;
end
endmodule

