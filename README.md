# Консольное Приложение для Обмена Сообщениями на C++

## Описание

Это консольное приложение представляет собой эффективную систему обмена сообщениями между пользователями. Оно позволяет им регистрироваться, проходить авторизацию и общаться как в личных, так и в общих чатах. Программа хранит все сообщения в текстовых файлах и предоставляет возможность просматривать историю чатов.

## Основные Функции

### Регистрация и Авторизация

- **Создание аккаунта:** Пользователи могут зарегистрироваться, указав свои логин, имя, фамилию и пароль.
- **Авторизация:** Пользователи могут авторизоваться, введя свои логин и пароль. 

### Личный Чат

- **Обмен сообщениями:** Пользователи могут отправлять личные сообщения другим участникам.

### Общий Чат

- **Публичные сообщения:** Пользователи могут отправлять сообщения, которые будут доступны всем участникам.

## Структура Проекта

- **Authorization.h / Authorization.cpp:** В данном файле хранятся аккаунты. Здесь осуществляется вход в определенный аккаунт и управление им.
  
- **Chat.h / Chat.cpp:** Этот класс отвечает за обмен сообщениями и включает функции для отправки и чтения сообщений, а также для отображения истории чатов.

- **main.cpp:** Этот файл является главным в проекте, он запускает приложение и инициализирует все его компоненты. Устанавливает кодировку консоли на UTF-8 для корректного отображения символов.


## Установка и запуск

Чтобы приступить к работе с приложением, выполните следующие шаги:

1. Склонируйте репозиторий на свой компьютер.
2. Откройте проект в вашей предпочитаемой интегрированной среде разработки (IDE), такой как Visual Studio или Code::Blocks.
3. Скомпилируйте проект и запустите его.

Теперь вы готовы к работе с нашим приложением!