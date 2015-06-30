module ram(data, address, read, write, reset, clk);
    input read, write, reset, clk; 
    input [4:0] address;
    inout [7:0] data;
    reg [7:0]memory[0:31];
    integer i;
	wire [3:0] high;
	wire [3:0] low;
	reg [5:0] write_adr;
	reg [31:0] flag;
	initial begin
		i = 0;
		for ( i = 0 ; i < 32 ; i = i + 1 ) begin
			memory[ i ] = 0;
			flag[ i ] = 0;
		end
	end
	
	assign high = data[7:4];
	assign low = data[3:0];
	always@( posedge clk or posedge reset ) begin	
		if( reset == 1 )begin
			for ( i = 0 ; i < 32 ; i = i+ 1 )begin
				memory[ i ] = 0;
				flag[ i ] = 0;
			end
		end
		else if( write == 1 && read == 0 )begin //write
			write_adr = high + low;
			for ( i = 0 ; i < 32 ; i = i + 1 ) begin
				if( flag[ write_adr ] != 0 )begin					
					write_adr = write_adr + 1;
					if ( write_adr == 32 )
						write_adr = 0;
				end
			end
			flag[ write_adr ] = 1;
			memory[write_adr] = data;
		end
		/*else if ( write == 0 && read == 1 )begin 
			data = memory[address];
		end*/
	end
	assign data = ( read && !write ) ? ( flag[address]== 1 ? memory[address] : 8'bz ) : 8'bz;//read
endmodule