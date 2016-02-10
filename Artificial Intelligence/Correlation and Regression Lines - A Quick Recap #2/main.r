# Here are the test scores of 10 students in physics and history:

# Physics Scores  15  12  8   8   7   7   7   6   5   3
# History Scores  10  25  17  11  13  17  20  13  9   15
# Compute Karl Pearson’s coefficient of correlation between these scores. 
# Compute the answer correct to three decimal places.

phys <- c(15, 12, 8, 8, 7, 7, 7, 6, 5, 3)
hist <- c(10, 25, 17, 11, 13, 17, 20, 13, 9, 15)
fit <- lm(hist ~ phys)
cat(round(
    coef(fit)["phys"]
, digits = 3), "\n")
