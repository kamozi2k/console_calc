# Консольный Калькулятор

Всем привет! Этот проект представляет собой консольный строковый калькулятор на языке программирования C++.
## Математические константы:
### Число Эйлера (e):
```
Enter a mathematical expression: e
Result is: 2.71828
```
#### Определение:
$$ e = \lim_{{n \to \infty}} \left(1 + \frac{1}{n}\right)^n $$
### Число Пи (p):
```
Enter a mathematical expression: p
Result is: 3.14159
```
#### Определение:

$$ \pi = 4 \cdot \left(1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \frac{1}{9} - \frac{1}{11} + \ldots\right)$$
 $$ \pi = 2 \cdot \left(\frac{1}{2} \cdot \frac{1}{\sqrt{3}} + \frac{1}{2\sqrt{3}} + \frac{1}{2\sqrt{3^2}} + \frac{1}{2\sqrt{3^3}} + \ldots\right)
 $$
 $$\pi = 2 \cdot \left(\frac{2}{1} \cdot \frac{2}{3} \cdot \frac{4}{3} \cdot \frac{4}{5} \cdot \frac{6}{5} \cdot \frac{6}{7} \cdot \ldots\right)$$


## Поддерживаемые арифметические операции:
### Сложение (+)
```
Enter a mathematical expression: 100 + 100
Result is: 200
```
### Вычитание (-)
```
Enter a mathematical expression: 1.1 - 1.1
Result is: 0
```
### Умножение (*) (гипероперация сложения)
```
Enter a mathematical expression: 13 * 5
Result is: 65
```
### Деление (/)
```
Enter a mathematical expression: 3 / 2
Result is: 1.5
```
#### Примечание:
Выражение вида: $\frac{x}{y}$, где $y = 0$, $x \neq 0$ выдаст **ошибку**:

**<div style="color:red">Division by zero.</div>**

Выражение вида: $\frac{x}{y}$, где $y = 0$, $x = 0$ выдаст **ошибку**:

**<div style="color:red">Uncertainty of the form 0 / 0.</div>**
### Возведение в степень (^) (гипероперация умножения)
```
	Enter a mathematical expression: 2 ^ 3
	Result is: 8
```
#### Примечание:
Выражение вида: $x^y$, где $y = 0$, $x = 0$ выдаст **ошибку**:

**<div style="color:red">Uncertainty of the form 0 ^ 0.</div>**

### Логарифмирование (ln, lg, lb)
**Натуральный** **логарифм**:
```
Enter a mathematical expression: ln(2.718)
Result is: 0.999896
```
**Десятичный** **логарифм**:
```
Enter a mathematical expression: lg(100)
Result is: 2
```
**Двоичный** (**бинарный**) **логарифм**
```
Enter a mathematical expression: lb(16)
Result is: 4
```
#### Примечание №1:

Если пользователь хочет использовать логарифм с произвольным основанием, то можно воспользоваться формулой перехода от одного основания логарифма к другому, используя натуральный логарифм $\ln(x)$.


**Формула имеет следующий вид: $$ {\log_ax}=\frac{{\ln(x)}}{{\ln(a)}}\ $$**
**Пример использования:**
 $$ {\log_39}=\frac{{\ln(9)}}{{\ln(3)}}\ $$ 

```
Enter a mathematical expression: ln(9) / ln(3)
Result is: 2
```
#### Примечание №2:
Выражение вида: $\log_ax$, где $x \leq 0$ выдаст **ошибку**:

**<div style="color:red">Invalid argument for "...".</div>**

Вместо **"..."** будет указан конкретный вид логарифма, в котором была допущена ошибка.
## Поддерживаемые тригонометрические функции:
### Синус (sin)
```
Enter a mathematical expression: sin(0.01)
Result is: 0.00999983
```
### Косинус (cos)
```
Enter a mathematical expression: cos(4)
Result is: -0.653644
```
### Тангенс (tan)
```
Enter a mathematical expression: tan(666)
Result is: -0.0176444
```
#### Примечание:
Выражение вида: $\tan(x)$, где ${x = \pi/2+\pi k}$; $k \in \mathbb{Z}$ выдаст ошибку:
**<div style="color:red">Invalid argument for \"tan\".</div>**
### Котангенс cot()
```
Enter a mathematical expression: ctg(69)
Result is: -8.65437
```
#### Примечание:
Выражение вида: $\cot(x)$, где ${x = \pi k}$; $k \in \mathbb{Z}$ выдаст ошибку:**<div style="color:red">Invalid argument for \"cot\".</div>**
### Примечание:
Точность функций $\sin(x)$, $\cos(x)$, $\tan(x)$ и $\cot(x)$ ограничена, поэтому **рекомендуется по возможности** передавать аргументы удовлетворяющие неравенству:
$$ 0 \leq x < 2\pi$$
Пример:
$$ \sin(11\pi) = \sin(\pi) $$
Калькулятор обрабатывает случай $\sin(11\pi)$ некорректно:
```
Enter a mathematical expression: sin(p*11)
Result is: 4.89978e-15
```
## Ссылки

[Telegram](https://t.me/kamozi2k)
[GitHub](https://github.com/kamozi2k)
[Репозиторий проекта на GitHub](https://github.com/kamozi2k/console_calc)
