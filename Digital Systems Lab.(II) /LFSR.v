`timescale 1ns/100ps
module LFSR(output [6:1] out , output reg write , input clock , enable , seed , fetch);

always @( posedge clock )
begin
	write = fetch ;
end

wire feedback ;
assign feedback = ( enable == 1 ) ? seed : out[6] ;
fsm_a f1( out[1] , clock , feedback ) ;
fsm_a f2( out[2] , clock , out[1] ) ;
fsm_a f3( out[3] , clock , out[2] ) ;
fsm_a f4( out[4] , clock , out[3] ) ;
fsm_a f5( out[5] , clock , out[4] ) ;
fsm_a f6( out[6] , clock , out[5] ) ;

endmodule
