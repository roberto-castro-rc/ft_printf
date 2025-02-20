from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager
import time

options = webdriver.ChromeOptions()
options.add_argument(r"--user-data-dir=C:\\Users\\rober\\AppData\\Local\\Google\\Chrome\\User Data")  # Caminho correto
options.add_argument(r"--profile-directory=Profile 3")  # Nome do perfil
options.add_argument("--start-maximized")  # Maximiza a janela para evitar problemas de carregamento

# Remove o modo headless para permitir o carregamento correto do perfil
# options.add_argument("--headless")  # Só ative se quiser rodar em segundo plano

driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)

def acessar_e_clicar():
    try:
        # Primeiro passo: acessar a página inicial
        driver.get("https://www11.netcombowifi.com.br/portal/netwifi/index.htm")
        time.sleep(5)  # Espera a página carregar

        # Clica no botão para ir para a próxima página
        botao_inicial = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, "/html/body/div[2]/div/div/div/div/div[2]/div/div/div/div[1]/div[2]/a"))
        )
        botao_inicial.click()
        print("Botão inicial clicado com sucesso!")

        time.sleep(5)  # Espera a transição para a nova página

        # Segundo passo: acessar a página do código anterior
        driver.get("https://www11.netcombowifi.com.br/portal/netwifi/login.htm?type=querowifi")
        time.sleep(5)  # Espera a página carregar

        # Preenche o campo de input
        input_field = driver.find_element(By.XPATH, '/html/body/div[3]/div/div[2]/div/div/div/form/div[2]/div[1]/input')
        input_field.send_keys("49249180837")

        # Aguarda e clica no botão de conexão
        botao = WebDriverWait(driver, 10).until(
            EC.element_to_be_clickable((By.ID, "connectButton"))
        )
        botao.click()
        print("Botão de conexão clicado com sucesso!")
    except Exception as e:
        print("Erro durante a execução:", e)

# Executa a cada 11 minutos
while True:
    acessar_e_clicar()
    time.sleep(11 * 60)  # 11 minutos
