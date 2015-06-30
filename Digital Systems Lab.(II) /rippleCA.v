module rippleCA( sum , carry , a,b,c);
	output [15:0]sum;
	output carry;
	input [15:0] a , b;
	input c;
	wire c2,c3,c4;
	fourBits( sum[3:0] , c2 , a[3:0] , b[3:0] , c );
	fourBits( sum[7:4] , c3 , a[7:4] , b[7:4] , c2 );
	fourBits( sum[11:8] , c4, a[11:8] , b[11:8] , c3 );
	fourBits( sum[15:12] , carry , a[15:12] , b[15:12] , c4 );


endmodule


module fourBits( sum , carry , a,b,c);
	output [3:0]sum;
	output carry;
	input [3:0] a , b;
	input c;
	wire c2,c3,c4;
	oneBit( sum[0] , c2 , a[0] , b[0] , c );
	oneBit( sum[1] , c3 , a[1] , b[1] , c2 );
	oneBit( sum[2] , c4 , a[2] , b[2] , c3 );
	oneBit( sum[3] , carry , a[3] , b[3] , c4 );


endmodule


module oneBit( output sum , carry , input a , b , c );

	assign sum = a ^ b ^c;
	assign carry = (( a ^ b ) &  c )  | ( a & b );
 
endmodule