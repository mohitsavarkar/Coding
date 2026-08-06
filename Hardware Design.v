// 4-Bit Counter Module
module counter (
    input wire clk,        // Clock signal
    input wire reset,      // Active-high synchronous reset
    input wire enable,     // Enable counting
    output reg [3:0] count // 4-bit output registered value
);

    // Trigger logic on the rising edge of the clock
    always @(posedge clk) begin
        if (reset) begin
            count <= 4'b0000;      // Reset counter to 0
        end else if (enable) begin
            count <= count + 1'b1; // Increment counter by 1
        end
        // If enable is 0, count implicitly holds its value
    end

endmodule
