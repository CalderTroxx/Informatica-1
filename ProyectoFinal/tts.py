import os
from dotenv import load_dotenv
import requests
from elevenlabs import generate, play, set_api_key, save

#Texto a voz. Esta impl utiliza ElevenLabs
class TTS():
    def __init__(self):
        load_dotenv()
        API_KEY = os.environ.get('ELEVENLABS_API_KEY')
        set_api_key(API_KEY)
    
    def process(self, text):
        url_api = "https://api.elevenlabs.io/v1/text-to-speech/EXAVITQu4vr4xnSDxMaL"

        audio = generate(
            text = text,
            voice = "Bella",
            model='eleven_multilingual_v2'
        )

        save(audio, "output_bella.wav")
        return "output_bella.wav"