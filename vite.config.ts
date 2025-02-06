import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [react()],
  base: '/Portfolio/', // Remplacez 'nom-de-votre-repo' par le nom exact de votre dépôt GitHub
  optimizeDeps: {
    exclude: ['lucide-react'],
  },
});
