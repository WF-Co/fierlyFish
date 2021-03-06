# fierlyFish
= ИДЕЯ ПРОЕКТА =
Создать инструмент по регистрации поступающей оперативной информации о всех
видов выездов подразделений пожарной охраны для последующей ее обработке,
анализу, формированию отчетных документов.

= ОСНОВНАЯ ЦЕЛЬ =
Основной целью является автоматизация процесса регистрации оперативной информации,
ускорение ее обработки и сокращение человеко-часов по обобщению и анализу
зарегистрированной информации.

= ПЛАТФОРМА =
- Клиент-серверное десктопное приложение работающее в среде Linux. Рабочий стол основной LxQt, дополнительный Plasma 5 (KDE).
  (если пойдет успешно, то и другие ОС - Windows, но не обязательно). Предусмотреть кроссплатформенность.
  Клиентское приложение должно потреблять наименьшее количество ресурсов (по возможности).
  Минимальные системные требования для комфортной работы:
    - минимальный процессор Intel® Core™2 Duo Processor E6550 (4M Cache, 2.33 GHz, 1333 MHz FSB);
    - ОЗУ 100 - 150 Мб;
    - HDD SATA II, 5400 rpm, кэш 32 Мб.
- В качестве СУБД PostgreSQL 9.6 не ниже. Доступ к БД по протоколу SSH через проброс портов.
- Данные по сети от клиента к серверу и обратно должны передаваться в зашифрованном виде.

= ГРАФИЧЕСКИЙ ДИЗАЙН =
- построенный на основе фреймворка Qt 5 и выше.
- дизайн элементов управления по умолчанию от фреймворка Qt5. Предусмотреть создание дополнительных тем внешнего вида.
- графический интерфейс должен уметь подстраиваться под различные расширения мониторов.
- минимальное разрешение для комфортной работы 1366 х 768.
- возможность графического интерфейса разделяться на несколько мониторов при работе на расширенном рабочем столе;
- графический интерфейс должен управляться как с применением мышки, так и клавиатурой.

= БЮДЖЕТ ПРОЕКТА =
Бюджет у проекта полностью отсутствует. Голый энтузиазм. Финансирование проекта в будущем - вряд ли. Положение может измениться,
если кто-то заинтересуется в развитии данного проекта в большом масштабе. Проект узкоспециализирован и пригодный к применению
лишь в структуре МЧС на центральном пункте пожарной связи, пункте связи пожарного подразделения и службе пожаротушения.
Но кто знает.

= СРОКИ ВЫПОЛНЕНИЯ ПРОЕКТА =
первый релиз ????????????. Но лениться не стоит.

= ДЕТАЛИ ПРОЕКТА =

- графический интерфейс: наброски отсутствуют, но главное окно MDI с меню и панелями инструментов;
- Отчетсность:
    - динамическое формирование и заполнение готовых отчетных форм в LibreOffice (MS Office - если будет версия Windows).
    - динамичное формирование и заполнение готовых шаблонов в файлах формата PDF;
- Печать: вывод на печать всех отчетных форм;
- Интеграция: - использование API Telegram-ботов для информирования на канале по оперативным событиям и выводу ежесуточной статистики.
              - уметь отправлять сформированные или заполненные отчетные документы по электронной почте;
              - уметь подключаться к фтп-серверу, выкладывать отчетные документы по указанным путям;
              - уметь выкачивать базу данных формата DBF с указанного адреса и импортировать в СУБД;
              - уметь читать информацию с форм сообщений о пожаре (загорании) формат файла xls, xlsx.
                Проверять качество заполнненной информации, ее полноту и опечатки в полях с датами.
                С последующим импортированием информации в СУБД.
              - уметь экспортировать данные из СУБД в базу формата DBF. Структура базы на основе ранее скачанной.
- Геолокация: да, но не в первом релизе. Привязка оперативного события к геолокационным данным. Вообще геолокация, навигация и все, что с этим связано
              за пример взять приложение SASPlanet. Но до этого надо еще вырости.

