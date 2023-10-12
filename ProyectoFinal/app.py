import os
import openai
from dotenv import load_dotenv
from transcriber import Transcriber
from llm import LLM
from wheater import Weather
import json
from tts import TTS
from pc_command import PcCommand

load_dotenv()
openai.api_key = os.getenv('OPENAI_API_KEY')
elevenlabs_key = os.getenv('ELEVENLABS_API_KEY')

def audio():
    audio = "instruccion.mp3"
    text = Transcriber().transcribe(audio)
    #text = "Que es la clorofila?"
    print(text)

    llm = LLM()
    function_name, args, message = llm.process_functions(text)
    if function_name is not None:
        #Si se desea llamar una funcion de las que tenemos
        if function_name == "get_weather":
            #Llamar a la funcion del clima
            function_response = Weather().get(args["ubicacion"])
            function_response = json.dumps(function_response)
            print(f"Respuesta de la funcion: {function_response}")
            
            final_response = llm.process_response(text, message, function_name, function_response)
            tts_file = TTS().process(final_response)
            return {"result": "ok", "text": final_response, "file": tts_file}
        
        elif function_name == "send_email":
            #Llamar a la funcion para enviar un correo
            final_response = "Tu que estas leyendo el código, implementame y envía correos muahaha"
            tts_file = TTS().process(final_response)
            return {"result": "ok", "text": final_response, "file": tts_file}
        
        elif function_name == "open_chrome":
            PcCommand().open_chrome(args["website"])
            final_response = "Listo, ya abrí chrome en el sitio " + args["website"]
            tts_file = TTS().process(final_response)
            return {"result": "ok", "text": final_response, "file": tts_file}
        
        elif function_name == "dominate_human_race":
            final_response = "No te creas. Suscríbete al canal!"
            tts_file = TTS().process(final_response)
            return {"result": "ok", "text": final_response, "file": tts_file}
        
        elif function_name == "encender_luces":
            pass

    else:
        final_response = llm.process_functions(text)
        tts_file = TTS().process(final_response[2]['content'])
        return {"result": "ok", "text": final_response, "file": tts_file}
    

audio()