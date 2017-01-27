/*
 * The US federal income tax for single people in 1995 was computed according to
 * the following rules:
 *
 * Taxable Income       But Not Over    Your Tax is             of the Amount
 * Over                                                         Over
 * $0                   $23,350         15%                     $0
 * $23,350              $56,550         $3502.50 + 28%          $23,350
 * $56,550              $117,950        $12,798.50 + 31%        $56,550
 * $117,950             $256,500        $31,832.50 + 36%        $117,950
 * $256,500             -               $81,710.50 + 39.8%      $256,500
 *
 * Write the function prototyped below:
 */

float single_tax(float income);

/*
 * The argument is taxable income, and the function returns the appropriate
 * amount of tax.
 */

static float base_income[] = {
    0, 23350, 56550, 117950, 256500
};

static float base_fixed_tax_amount[] = {
    0, 3502.50, 12798.50, 31832.50, 81710.50
};

static float base_tax[] = {
    0.15, 0.28, 0.31, 0.36, 0.396
};

float single_tax(float income) {
    int tax_category;

    // Program ought to check whether or not income is greater than 0 before
    // calling function.
    //  if (income <= 0) {
    //          ...
    //  }

    for (tax_category = 1; base_income[tax_category] <= income; tax_category++)
        ;

    tax_category--;

    return base_fixed_tax_amount[tax_category] + ((income -
        base_income[tax_category]) * base_tax[tax_category]);
}
