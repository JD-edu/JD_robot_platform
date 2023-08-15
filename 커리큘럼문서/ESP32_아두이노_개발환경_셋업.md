## ESP32 아두이노 개발환경

### ESP32 마이크로커트롤러의 소개 
JD 로봇 플랫폼은 ESP32 마이크로컨트롤러를 메인 컨트롤러로 사용합니다. ESP32 마이크로컨트롤러는 WiFI와 블루투스를 내장한 마이크로컨트롤러 입니다.  
ESP32 마이크로컨트롤러에 대한 상세한 내용은 다음 [링크](https://www.espressif.com/en/products/socs/esp32)를 참고하면 됩니다. 
JD 로봇 플랫폼은 ESP32 DevKit 보드를 사용합니다. ESP32 DevKit은 ESP32-WROOM-32 모듈을 기반으로 제작된 키트 형태의 보드입ㄴ다. 
ESP32는 Wifi와 블루투스 등 RF 기능을 내장하고 있어서 칩을 직접 사용하기 보다는 모듈을 사용합니다. ESP32-WROOM-32는 ESP32칩과 안테나 등을 내장한 모듈입니다. 이 모듈을 적용해서 키트 형태의 보드로 만든 것이 ESP32 DevKit 입니다. ESP32 DevKit의 상세한 내용은 다음 [링크](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/user-guide-devkitm-1.html)를 참고하면 됩니다.  

### ESP32 DevKit의 핀 아웃 구성 
ESP32 DevKit은 아두이노 우노 등과 같은 보드와 같이 여러 GPIO가 제공되며, 각각의 GPIO는 여러가지 기능을 가집니다. 이 기능은 다음 그림을 참고하면 됩니다. 

![ESP32 DevKit 핀 구성도](https://github.com/JD-edu/JD_robot_platform/assets/96219601/6e1b1d45-2421-49db-bc5f-6f7fe4d508e5)

### ESP32 아두이노 개발환경 셋업 
JD 로봇 플랫폼에 사용되는 ESP32 마이크로컨트롤러는 아두이노 개발환경과 아두이노 코딩언어인 C++을 사용하여 코딩이 가능합니다. 그래서 먼저 ESP32 아두이노 개발환경을 설치합니다. 

#### ESP32 보드 패키지 URL 등록 
일반적으로 아드이노 IDE를 설치하면 아두이노 우노 같은 AVR 계열의 MCU를 코딩하고 컴파일 해주는 개발환경만 설치됩니다. 아두이노 우노에 사용되는 AVR 계얄의 MCU와 ESP32는 전혀 다른 마이크로컨트롤러 입니다. 아두이노 IDE는 AVR계열 MCU 말고도 다른 종류의 MCU로 개발을 랄 수 있습니다. 다만 아두이노 IDE에서 ESP32로 코딩을 하려면 몇가지 소프트웨어를 설치해야 합니다. 제일 먼저 해야 할 것은 ESP32 보드 패키지를 설치할 URL을 등록 합니다.  

![아두이노 IDE 기본설정 선택](https://github.com/JD-edu/JD_robot_platform/assets/96219601/6874b292-9ae0-4e2a-8085-aa530ef9064b)

아두이노 IDE에서 파일 -> 기존설정 을 선택합니다. 

![아두이노_추가보드관리자_URL](https://github.com/JD-edu/JD_robot_platform/assets/96219601/076796bc-8929-487b-b8b1-3f4da946f33a)

추가 보드 관리자URL을 찾고 노란색 원으로 표시된 아이콘을 클릭합니다. 

![ESP32 보드 패키지 URL 입력](https://github.com/JD-edu/JD_robot_platform/assets/96219601/12ce305f-2bdf-4d5c-a3de-95bf9c5463d5)

"각 항에 하나씩 추가 URL을 입력하세요" 문구 밑에 입력창에 ESP32 보드 패키지 주소를 입력합니다. 주소는 다음과 같습니다. 

<pre><code>
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
</code></pre>

#### ESP32 보드 패키지 설치 
ESP32 보드 패키지 URL을 등록햇으면 이제 우리는 ESP32 개발환경을 다운로드 받을 수 있게 되었습니다. 다음에는 실제로 ESP32 보드 패키지를 다운로드해서 설치해 보도록 하겠습니다. 도구 -> 보드 -> 보드 매니저 를 선택합니다. 

![보드매니저 실행](https://github.com/JD-edu/JD_robot_platform/assets/96219601/0dce6db5-7548-4db8-af36-a6934a0487ad)

보드 매니저를 실행하면 다음과 같이 아두이노 IDE 좌측에 보드 매니저가 실행이 됩니다. 보드매니저 우족 노란색 원에 'esp32'라고 입력해서 EPS32 보드 패키지를 검색합니다. 

![보드 매니저에서 ESP32 검색 및 설치](https://github.com/JD-edu/JD_robot_platform/assets/96219601/db53d904-b44e-4df1-b3f2-cb8ce5b553f4)

몇개의 검색 결과 중에서 흰색 원으로 표시된 Espressif의 ESP32 보드 패키지를 선택하고, 역시 흰색 원에 있는 녹색 "설치" 버튼을 클릭해서 보트 패키지를 설치하면 됩니다. Espressif는 ESP32 마이크로컨틀러를 제작한 회사이름 입니다. 이 회사에서 컴파일러 등 보드 패키지를 제공합니다. 

#### ESP32 DevKit보드 선택 
ESP32는 다양한 모듈과 보드가 존재하기 대문에 우리가 사용하려는 ESP32 DevKit를 찾아서 선택해 주어야 합니다. ESP32 DevKit 보드를 선택하는 방법은 다음과 같습니다. 도구 -> 보드 를 선택하면 이전에는 없었던 ESP32 보드 항목이 추가되어 있습니다. 이중에서 우리가 선택할 보드는 ESP32 Dev Module 입니다. 이것을 선택해 주면 됩니다. 

![esp32_dev_module_선택](https://github.com/JD-edu/JD_robot_platform/assets/96219601/cfbb4ef5-2f90-487d-ab1e-293e8f54cbd3)

이렇게 해서 ESP32 개발환경 및 ESP32 DevKit 선택이 끝이 났습니다. 













