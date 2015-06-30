module  traffic_light( Clk , Cnt , Red , Yellow , Green , currStage ) ;
	input		Clk ;
	output		Red , Yellow , Green ;
	output[4:0]	Cnt ;
	output[1:0]	currStage ;
	wire		Clk ;
	reg			Red , Yellow , Green ;
	reg[4:0]	Cnt ;
	reg[1:0]	currStage ;
	
	parameter stateR = 2'b00 , stateG = 2'b01 , stateY = 2'b10 ;
	
	initial begin
		currStage = 2'b00 ;
		Red = 1'b1 ;
		Yellow = 1'b0 ;
		Green = 1'b0 ;
		Cnt = 5'b11110 ; //30
	end
	
	always@( posedge Clk ) begin
		if ( Cnt != 0 )
			begin
				Cnt = Cnt - 1 ;
			end
		else if ( Cnt == 0 )
			begin
				case ( currStage )
					stateR :
						begin
							Red = 0 ;
							Green = 1 ;
							currStage = stateG ;
							Cnt = 24 ;
						end
					stateG: 
						begin
							Green = 0 ;
							Yellow = 1 ;
							currStage = stateY ;
							Cnt = 6 ;
						end
					stateY: 
						begin
							Yellow = 0 ;
							Red = 1 ;
							currStage = stateR ;
							Cnt = 30 ;
						end
				endcase
			end
	end	
endmodule