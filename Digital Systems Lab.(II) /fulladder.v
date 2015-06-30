module fulladder( sum , carry_out ,a , b , c0 );
input[3:0] a, b;
input c0;
output [3:0] sum;
output carry_out;
wire c1 , c2 , c3;

oneBits( sum[0], c1, a[0] , b[0] , c0);
oneBits( sum[1], c2, a[1] , b[1] , c1);
oneBits( sum[2], c3, a[2] , b[2] , c2);
oneBits( sum[3], carry_out, a[3] , b[3] , c3);

endmodule


module oneBits( output sum, c_out, input a, b, c_in );
wire s1, c1, c2;

xor( s1, a, b );
xor( sum, s1, c_in ); 
and( c1 , s1 , c_in );
and( c2 , a , b );
or( c_out , c1, c2  );


endmodule