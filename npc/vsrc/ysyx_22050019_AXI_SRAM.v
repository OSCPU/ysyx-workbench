//import "DPI-C" function void pmem_read(
//  input longint raddr, output longint rdata);
//目前实现仅仅实现握手
module axi_lite_sram(
  input                            clk,
  input                            rst_n,
  //读地址通道
  input                            s_axi_arvalid,
  input         [63:0]             s_axi_araddr,
  output                           s_axi_arready,
  //读数据通道
  input                           s_axi_rready,
  output                          s_axi_rvalid,
  output       [31:0]             s_axi_rdata
);

  localparam IDLE = 2'd0;
  localparam READ_ADDR = 2'd1;
  localparam READ_DATA = 2'd2;

  reg [63:0] araddr_reg;

/* verilator lint_off UNUSED */reg [63:0] rdata_reg;

  reg [1:0] state_reg;
  reg [1:0] next_state;

  always @(posedge clk) begin
    if (rst_n) begin
      state_reg <= IDLE;
    end else begin
      state_reg <= next_state;
    end
  end



  always @(*) begin
    case (state_reg)
      IDLE: begin
        if (s_axi_arvalid) begin
          araddr_reg    <= s_axi_araddr;
          next_state    <= READ_ADDR;
        end else begin
          next_state  <= IDLE;
        end
      end
      READ_ADDR: begin
          pmem_read(araddr_reg,rdata_reg);
          next_state <= READ_DATA;
      end
      READ_DATA: begin
        if (s_axi_rready) begin
          next_state <= IDLE;
        end else begin
          next_state <= READ_DATA;
        end
      end
      default: begin
        next_state <= IDLE;
      end
    endcase
  end

  assign s_axi_arready =  state_reg == IDLE ;
  assign s_axi_rvalid  =  state_reg == READ_DATA ;
  assign s_axi_rdata   = (state_reg == READ_DATA) ? rdata_reg[31:0] : 32'b0;

endmodule
