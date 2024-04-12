# Console Calculator

Hello everyone! This project is a console string calculator written in C++.

## Mathematical Constants:
### Euler's Number (e):
```
Enter a mathematical expression: e
Result is: 2.71828
```
#### Definition:
Euler's number, denoted as 'e', is defined as the limit of the following expression as 'n' approaches infinity:
$$ e = \lim_{{n \to \infty}} \left(1 + \frac{1}{n}\right)^n $$

### Pi (p):
```
Enter a mathematical expression: p
Result is: 3.14159
```
#### Definition:
Pi, denoted as 'π', can be defined using various series and product representations. Here are a few examples:
$$ \pi = 4 \cdot \left(1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \frac{1}{9} - \frac{1}{11} + \ldots\right)$$
$$ \pi = 2 \cdot \left(\frac{1}{2} \cdot \frac{1}{\sqrt{3}} + \frac{1}{2\sqrt{3}} + \frac{1}{2\sqrt{3^2}} + \frac{1}{2\sqrt{3^3}} + \ldots\right) $$
$$\pi = 2 \cdot \left(\frac{2}{1} \cdot \frac{2}{3} \cdot \frac{4}{3} \cdot \frac{4}{5} \cdot \frac{6}{5} \cdot \frac{6}{7} \cdot \ldots\right)$$

## Supported Arithmetic Operations:
### Addition (+)
```
Enter a mathematical expression: 100 + 100
Result is: 200
```
### Subtraction (-)
```
Enter a mathematical expression: 1.1 - 1.1
Result is: 0
```
### Multiplication (*) (Hyperoperation of Addition)
```
Enter a mathematical expression: 13 * 5
Result is: 65
```
### Division (/)
```
Enter a mathematical expression: 3 / 2
Result is: 1.5
```
#### Note:
Expressions of the form $\frac{x}{y}$, where $y = 0$, will result in an **error**. If $x \neq 0$, the error message will be: **"Division by zero."** If $x = 0$, the error message will be: **"Uncertainty of the form 0 / 0."**

### Exponentiation (^) (Hyperoperation of Multiplication)
```
Enter a mathematical expression: 2 ^ 3
Result is: 8
```
#### Note:
Expressions of the form $x^y$, where $y = 0$ and $x = 0$, will result in an **error**: **"Uncertainty of the form 0 ^ 0."**

### Logarithm (ln, lg, lb)
**Natural Logarithm**:
```
Enter a mathematical expression: ln(2.718)
Result is: 0.999896
```
**Decimal Logarithm**:
```
Enter a mathematical expression: lg(100)
Result is: 2
```
**Binary Logarithm**:
```
Enter a mathematical expression: lb(16)
Result is: 4
```
#### Note:
If the user wants to use a logarithm with an arbitrary base, they can use the formula to transition from one logarithm base to another, using the natural logarithm $\ln(x)$. The formula is as follows: $$ {\log_ax}=\frac{{\ln(x)}}{{\ln(a)}}\ $$

For example, to calculate ${\log_39}$, you can enter the expression: `ln(9) / ln(3)`. The result is 2.

Expressions of the form $\log_ax$, where $x \leq 0$, will result in an **error**: **"Invalid argument for '...'."** The specific type of logarithm in which an error was made will be indicated in place of '...'.

## Supported Trigonometric Functions:
### Sine (sin)
```
Enter a mathematical expression: sin(0.01)
Result is: 0.00999983
```
### Cosine (cos)
```
Enter a mathematical expression: cos(4)
Result is: -0.653644
```
### Tangent (tan)
```
Enter a mathematical expression: tan(666)
Result is: -0.0176444
```
#### Note:
Expressions of the form $\tan(x)$, where ${x = \pi/2+\pi k}$; $k \in \mathbb{Z}$, will result in an error: **"Invalid argument for 'tan'."**

### Cotangent (cot)
```
Enter a mathematical expression: cot(69)
Result is: -8.65437
```
#### Note:
Expressions of the form $\cot(x)$, where ${x = \pi k}$; $k \in \mathbb{Z}$, will result in an error: **"Invalid argument for 'cot'."**

The accuracy of the functions $\sin(x)$, $\cos(x)$, $\tan(x)$, and $\cot(x)$ is limited, so it is **recommended where possible** to pass arguments satisfying the inequality: $$ 0 \leq x < 2\pi$$

For example, while $\sin(11\pi) = \sin(\pi)$ mathematically, the calculator may not handle this case correctly due to precision limitations.

## Links
- [Telegram](https://t.me/kamozi2k)
- [GitHub](https://github.com/kamozi2k)
- [Project Repository on GitHub](https://github.com/kamozi2k/console_calc)