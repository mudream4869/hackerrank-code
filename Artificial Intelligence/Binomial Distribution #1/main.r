# A blindfolded marksman finds that on the average he hits the target 4 times out of 5. If he fires 4 shots, what is the probability of
# (a) more than 2 hits?
# (b) at least 3 misses?

print <- function(value){
    cat(round(value, digits = 3), "\n")
}

a0 <- 0.2^4
a1 <- (0.2^3)*(0.8)*4
a2 <- (0.2^2)*(0.8^2)*6
a3 <- (0.2)*(0.8^3)*4
a4 <- 0.8^4

print(a3 + a4)
print(a0 + a1)